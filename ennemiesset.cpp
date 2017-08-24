#include "ennemiesset.h"
#include "ui_ennemiesset.h"

extern int ATTAQUES_ID = 12001;

EnnemiesSet::EnnemiesSet(Personnage &toSet, QColor &toSetColor, QVector<Personnage> presets, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnnemiesSet)
{
    ui->setupUi(this);
    m_toSet = &toSet;
    m_presets = presets;
    m_toSetColor = &toSetColor;
    this->updateGUI();
}

void EnnemiesSet::updateGUI()
{
    ui->nameLineEdit->setText(m_toSet->getName());
    ui->vieSpinBox->setValue(m_toSet->getVie());
    ui->maxLifeSpinBox->setValue(m_toSet->getVieMax());
    ui->manaSpinBox->setValue(m_toSet->getMp());
    ui->manaMaxSpinBox->setValue(m_toSet->getMpMax());
    ui->dodgeSpinBox->setValue(m_toSet->getDodge());
    ui->critiqueSpinBox->setValue(m_toSet->getCritiqueHit());
    ui->absoDoubleSpinBox->setValue(m_toSet->getAbso());

    QPalette *palette = new QPalette ();
    palette->setColor(QPalette::Base, *m_toSetColor);
    ui->colorLineEdit->setPalette(*palette);
    updateAttaquesList();
}

void EnnemiesSet::updateAttaquesList()
{
    QVector <QString> names;
    QVector <Attaque*> attaques = m_toSet->getAttaques();

    ui->attaquesList->clear();
    int loop = 0;
    while (loop != attaques.count())
    {
        names.push_back(attaques[loop]->getName());
        loop++;
    }

    loop = 0;
    while (loop != attaques.count())
    {
        ui->attaquesList->addItem(new QListWidgetItem(names[loop]));
        loop++;
    }
}

void EnnemiesSet::on_addAttaqueCommandLinkButton_clicked()
{
    QVector <Attaque*> attaques = m_toSet->getAttaques();
    //gestion des effets
    QVector<int> effects;
    QVector<int> effectsLuck;

    effects.push_back(ui->fireSpinBox->value());
    effects.push_back(ui->freezeSpinBox->value());
    effects.push_back(ui->poisonSpinBox->value());
    effects.push_back(ui->stunSpinBox->value());

    effectsLuck.push_back(ui->fireLuckSpinBox->value());
    effectsLuck.push_back(ui->freezeLuckSpinBox->value());
    effectsLuck.push_back(ui->poisonLuckSpinBox->value());
    effectsLuck.push_back(ui->stunLuckSpinBox->value());

    QVector<int> blank;
    blank.push_back(0);
    blank.push_back(0);
    blank.push_back(0);
    blank.push_back(0);

    attaques.push_back(new Attaque(ui->attaqueDegatsSpinBox->value(), ui->attaqueNameLineEdit->text(), ui->attaqueHealSpinBox->value(),ui->attaqueMpCostSpinBox->value(),ui->attaquePersistenceSpinBox->value(),
                                   ui->attaqueChargeSpinBox->value(),ui->attaqueDegatsModifierDoubleSpinBox->value(),ui->attaqueArmureModifierDoubleSpinBox->value(),
                                   ui->attaqueMpCostModifierDoubleSpinBox->value(),ui->attaqueAbsoModifierDoubleSpinBox->value(),ui->attaqueDodgeHitModifierSpinBox->value(),
                                   ui->attaqueCritHitModifierSpinBox->value(),ui->attaqueCritModifierSpinBox->value(),effects,effectsLuck,blank,ATTAQUES_ID,0));
    m_toSet->setAttaque(attaques);
    ATTAQUES_ID++;
    updateAttaquesList();
}

void EnnemiesSet::on_pushButton_2_clicked()
{
    m_toSet->setName(ui->nameLineEdit->text());
    m_toSet->setVieMax(ui->maxLifeSpinBox->value());
    m_toSet->setVie(ui->vieSpinBox->value());
    m_toSet->setMpMax(ui->manaMaxSpinBox->value());
    m_toSet->setMp(ui->manaSpinBox->value());
    m_toSet->setDodge(ui->dodgeSpinBox->value());
    m_toSet->setCritiqueHit(ui->critiqueSpinBox->value());
    m_toSet->setAbso(ui->absoDoubleSpinBox->value());
    this->close();
}

void EnnemiesSet::on_setColorPushButton_clicked()
{
    *m_toSetColor = QColorDialog::getColor(*m_toSetColor);
    this->updateGUI();
}

void EnnemiesSet::on_pushButton_clicked()//c'est le bouton supprimer
{
    QVector <Attaque*> attaques = m_toSet->getAttaques();
    attaques.erase(attaques.begin() + ui->attaquesList->currentRow());
    m_toSet->setAttaque(attaques);
    updateGUI();
}

void EnnemiesSet::on_attaquesList_currentRowChanged(int currentRow)
{

}
