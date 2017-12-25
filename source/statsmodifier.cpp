#include "statsmodifier.h"
#include "ui_statsmodifier.h"

StatsModifier::StatsModifier(Personnage &cible, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatsModifier)
{
    ui->setupUi(this);
    m_cible = &cible;

    ui->maxVieSpinBox->setMaximum(cible.getVieMax());
    ui->maxMpSpinBox->setMaximum(cible.getMpMax());
    ui->maxVieSpinBox->setValue(cible.getVieMax());
    ui->maxMpSpinBox->setValue(cible.getMpMax());

    ui->vieSpinBox->setMaximum(cible.getVieMax());
    ui->mpSpinBox->setMaximum(cible.getMpMax());

    ui->vieSpinBox->setValue(cible.getVie());
    ui->mpSpinBox->setValue(cible.getMp());
    ui->absoSpinBox->setValue(cible.getAbso());
    ui->critSpinBox->setValue(cible.getCritique());

    ui->maxVieSpinBox->setValue(cible.getVieMax());


    ui->maxMpSpinBox->setValue(cible.getMpMax());

    ui->levelSpinBox->setValue(cible.getLevel());

}

StatsModifier::~StatsModifier()
{
    delete ui;
}

void StatsModifier::on_pushButton_clicked()//oops, c'est le bouton OK
{

    m_cible->setVieMax(ui->maxVieSpinBox->value());
    m_cible->setMpMax(ui->maxMpSpinBox->value());

    m_cible->setVie(ui->vieSpinBox->value());
    m_cible->setMp(ui->mpSpinBox->value());
    m_cible->setAbso(ui->absoSpinBox->value());
    m_cible->setCritique(ui->critSpinBox->value()); 
    m_cible->setLevel(ui->levelSpinBox->value());

    emit truc();
    this->close();
}

void StatsModifier::on_maxVieSpinBox_valueChanged(int arg1)
{
    ui->vieSpinBox->setMaximum(arg1);
}

void StatsModifier::on_maxMpSpinBox_valueChanged(int arg1)
{
    ui->mpSpinBox->setMaximum(arg1);
}




void StatsModifier::on_pushButton_2_clicked()
{
    this->close();
}
