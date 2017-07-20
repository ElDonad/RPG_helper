#include "combat.h"
#include "ui_combat.h"


Combat::Combat(QVector<Heros *> &personnages, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Combat)
{
    ui->setupUi(this);
    //ui->ennemisCount->setText("0");
    m_personnages = personnages;
    this->updateGUI();
}

Combat::~Combat()
{
    delete ui;
}

void Combat::updateGUI()
{
    ui->lifeBourrin->setMaximum(m_personnages[0]->getVieMax());
    ui->mpBourrin->setMaximum(m_personnages[0]->getMpMax());
    ui->lifeBourrin->setValue(m_personnages[0]->getVie());
    ui->mpBourrin->setValue(m_personnages[0]->getMp());

    //afficher warning si jamais personnage attaque
    int loop = 0;
    while (loop != m_attaquants.count())
    {
        QString name = m_attaquants[loop]->getName();

        ui->warningBourrin->setEnabled(false);
        ui->warningAssassin->setEnabled(false);
        ui->warningArcher->setEnabled(false);
        ui->warningChaman->setEnabled(false);
        ui->warningHealer->setEnabled(false);
        ui->warningMage->setEnabled(false);



        if (name == "Bourrin")
        {
            ui->warningBourrin->setEnabled(true);

        }

        if (name == "Assassin")
        {
            ui->warningAssassin->setEnabled(true);
        }

        if (name == "Archer")
        {
            ui->warningArcher->setEnabled(true);
        }

        if (name == "Shaman")
        {
            ui->warningChaman->setEnabled(true);
        }

        if (name == "Healer")
        {
            ui->warningHealer->setEnabled(true);
        }
        if (name == "Healer")
        {
            ui->warningMage->setEnabled(true);
        }

        loop++;
    }

    //mettre à jour les tables d'attaque et d'ennemis
    this->updateEnnemisList();
    loop = ui->attaquesTableWidget->rowCount();
    while (loop != m_attaquants.count())
    {
        ui->attaquesTableWidget->setRowCount(ui->attaquesTableWidget->rowCount() + 1);
        ui->attaquesTableWidget->setItem(ui->attaquesTableWidget->rowCount() - 1,0, new QTableWidgetItem(m_attaquants[loop]->getName()));
        ui->attaquesTableWidget->setItem(ui->attaquesTableWidget->rowCount() - 1,1,new QTableWidgetItem(m_turnAttaques[loop]->getName()));
        loop++;
    }

    //mettre à jour la couleur des cases ennemis
    loop = 0;
    while (loop != m_mechants.count())
    {
        ui->ennemyTable->item(loop,0)->setBackgroundColor(m_ennemiesColor[loop]);
        loop++;
    }




}

void Combat::updateEnnemisList()
{
    if (ui->ennemyCount->value() > 0)
    {
        while (ui->ennemyCount->value() != ui->ennemyTable->rowCount())
        {
            if (ui->ennemyCount->value() > ui->ennemyTable->rowCount())
            {
                m_mechants.push_back(new Personnage ());
                m_ennemiesColor.push_back(QColor("#FFFFFF"));
                ui->ennemyTable->setRowCount(ui->ennemyTable->rowCount() + 1);
                ui->ennemyTable->setItem(ui->ennemyTable->rowCount() - 1, 0, new QTableWidgetItem(m_mechants[ui->ennemyTable->rowCount() - 1]->getName()));
            }

            if (ui->ennemyCount->value() < ui->ennemyTable->rowCount())
            {
                delete m_mechants[m_mechants.size() - 1];
                m_mechants.pop_back();
                m_ennemiesColor.pop_back();
                ui->ennemyTable->setRowCount(ui->ennemyTable->rowCount() - 1);
            }
        }

        //traiter le cas du tableau
        while (m_mechants.size() != ui->ennemyTable->rowCount())
        {
            if (m_mechants.size() > ui->ennemyTable->rowCount())
            {
                ui->ennemyTable->setRowCount(ui->ennemyTable->rowCount() + 1);
                int loop = 0;
                while (loop != ui->ennemyTable->rowCount() - 1)
                {
                    ui->ennemyTable->setItem(loop, 0, new QTableWidgetItem(m_mechants[loop]->getName()));
                    loop++;
                }
            }

            if (m_mechants.size() < ui->ennemyTable->rowCount())
            {
                delete m_mechants[m_mechants.size() - 1];
                m_mechants.pop_back();
                m_ennemiesColor.pop_back();
                ui->ennemyTable->setRowCount(ui->ennemyTable->rowCount() - 1);
            }
        }
    }
    int loop = 0;
    if (ui->ennemyTable->rowCount() > 0)
    {
        while (loop != ui->ennemyTable->rowCount() - 1)
        {
            ui->ennemyTable->setItem(loop, 0, new QTableWidgetItem(m_mechants[loop]->getName()));
            loop++;
        }
    }

}


void Combat::on_ennemyCount_valueChanged(int arg1)
{
    this->updateEnnemisList();
}

void Combat::on_ennemyTable_cellDoubleClicked(int row, int column)
{

}



void Combat::on_bourrinAttaque_clicked()
{

    clicked(m_personnages[0]);

}

void Combat::clicked(Personnage *traite)
{
    setAttaque *bourrinSetAttaque = new setAttaque(dynamic_cast <Personnage*> (traite),m_mechants,m_personnages, m_turnAttaques, m_ciblesAttaque);
    bourrinSetAttaque->exec();
    bourrinSetAttaque->close();
    delete bourrinSetAttaque;
    m_attaquants.push_back(traite);
    //DEBUG : vérifier m_turnAttaques

    //cette partie
    if (m_ciblesAttaque.count() < m_attaquants.count())
    {
        QVector <Personnage*> blankPerso;
        QVector <QVector <Personnage*>> blankTablePerso;
        blankTablePerso.push_back(blankPerso);
        m_ciblesAttaque.push_back(blankPerso);
    }

     if (m_turnAttaques.count() < m_attaquants.count())
     {
         QVector <int> blankEffect;
         blankEffect.push_back(0);
         blankEffect.push_back(0);
         blankEffect.push_back(0);
         blankEffect.push_back(0);

         QVector <double> blankEffectDouble;
         blankEffectDouble.push_back(0);
         blankEffectDouble.push_back(0);
         blankEffectDouble.push_back(0);
         blankEffectDouble.push_back(0);
         m_turnAttaques.push_back(traite->getAttaques()[0]);
     }
     this->updateGUI();
}

void Combat::on_eraseAttaqueButton_clicked()
{
    int attaqueSelected = ui->attaquesTableWidget->currentRow();
    ui->attaquesTableWidget->removeRow(attaqueSelected);

    m_turnAttaques.erase(m_turnAttaques.begin() + attaqueSelected);
    m_ciblesAttaque.erase(m_ciblesAttaque.begin() + attaqueSelected);
    m_attaquants.erase(m_attaquants.begin() + attaqueSelected);
    this->updateGUI();
}

void Combat::on_copieButton_clicked()
{
    int selectedEnnemy = ui->ennemyTable->currentRow();
    Personnage *newEnnemy = new Personnage(m_mechants[selectedEnnemy]);
    m_mechants.insert(m_mechants.begin() + selectedEnnemy,newEnnemy);
    ui->ennemyTable->insertRow(selectedEnnemy + 1);
    ui->ennemyTable->setItem(selectedEnnemy + 1,0,new QTableWidgetItem(m_mechants[selectedEnnemy + 1]->getName()));
    ui->ennemyCount->setValue(ui->ennemyCount->value() + 1);
    m_ennemiesColor.insert(m_ennemiesColor.begin() + selectedEnnemy + 1,m_ennemiesColor[selectedEnnemy]);
    this->updateGUI();
}

void Combat::on_ennemyTable_doubleClicked(const QModelIndex &index)
{
    if (m_mechants[ui->ennemyTable->currentRow()]->getAttaques().count() < 1)
    {
        QVector <int> blankEffect;
        blankEffect.push_back(0);
        blankEffect.push_back(0);
        blankEffect.push_back(0);
        blankEffect.push_back(0);

        QVector <double> blankEffectDouble;
        blankEffectDouble.push_back(0);
        blankEffectDouble.push_back(0);
        blankEffectDouble.push_back(0);
        blankEffectDouble.push_back(0);
        QVector <Attaque *> selectedAttaque = m_mechants[ui->ennemyTable->currentRow()]->getAttaques();
        selectedAttaque.push_back(new Attaque (0,"Passer son tour",0,0,1,0,0,0,0,0,0,0,0,blankEffect,blankEffectDouble,blankEffect,9999,0,"Passer son tour"));
        m_mechants[ui->ennemyTable->currentRow()]->setAttaque(selectedAttaque);
    clicked(m_mechants[ui->ennemyTable->currentRow()]);
    }
}

void Combat::on_deleteButton_clicked()
{
    int ennemySelected = ui->ennemyTable->currentRow();
    beforeRemovingEnnemy(m_mechants[ennemySelected]);
    m_mechants.erase(m_mechants.begin() + ennemySelected);
    ui->ennemyTable->removeRow(ennemySelected);
    ui->ennemyCount->setValue(ui->ennemyCount->value() - 1);
    this->updateGUI();

}

void Combat::beforeRemovingEnnemy(Personnage *toRemove)
{
    //test si cet ennemi existe dans la liste des attaquants :
    int loop = 0;
    while(loop != m_attaquants.count())
    {
        if (*m_attaquants[loop] == *toRemove)
        {
            ui->attaquesTableWidget->removeRow(loop);

            m_turnAttaques.erase(m_turnAttaques.begin() + loop);
            m_ciblesAttaque.erase(m_ciblesAttaque.begin() + loop);
            m_attaquants.erase(m_attaquants.begin() + loop);
        }
        loop++;
    }

    //vérification de présence en tant que cible dans une attaque :
    loop = 0;
    int loop2 = 0;
    while (loop != m_ciblesAttaque.count())
    {
        while (loop2 != m_ciblesAttaque[loop].count())
        {
            if (*m_ciblesAttaque[loop][loop2] == *toRemove)
            {
                m_ciblesAttaque[loop].erase(m_ciblesAttaque[loop].begin() + loop2);
            }
            loop2++;
        }
        loop2 = 0;
        loop++;
    }
}

void Combat::on_editButton_clicked()
{

}
