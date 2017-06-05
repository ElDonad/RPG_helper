#include "combat.h"
#include "ui_combat.h"


Combat::Combat(QVector<Heros *> &personnages, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Combat)
{
    ui->setupUi(this);
    m_personnages = personnages;
    Heros *machin = new Heros();
    m_personnages.push_back(machin);


    //ui->ennemisCount->setText("0");
    this->updateGUI();

    ;
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

}

void Combat::updateEnnemisList()
{
    while (ui->ennemyCount->value() != ui->ennemyTable->rowCount())
    {
        if (ui->ennemyCount->value() > ui->ennemyTable->rowCount())
        {
            m_mechants.push_back(new Personnage ());
            ui->ennemyTable->setRowCount(ui->ennemyTable->rowCount() + 1);
            ui->ennemyTable->setItem(ui->ennemyTable->rowCount() - 1, 0, new QTableWidgetItem(m_mechants[ui->ennemyTable->rowCount() - 1]->getName()));
        }

        if (ui->ennemyCount->value() < ui->ennemyTable->rowCount())
        {
            delete m_mechants[m_mechants.size() - 1];
            m_mechants.pop_back();
            ui->ennemyTable->setRowCount(ui->ennemyTable->rowCount() - 2);
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

void Combat::setHerosAttaque(Heros *attaquant)
{
    setAttaque *fenetreSetAttaque = new setAttaque(attaquant, m_mechants, m_personnages, m_turnAttaques, m_ciblesAttaque);
    fenetreSetAttaque->exec();
}
