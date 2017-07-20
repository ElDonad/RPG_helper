#include "setattaque.h"
#include "ui_setattaque.h"



setAttaque::~setAttaque()
{
    delete ui;
}

setAttaque::setAttaque(Personnage *attaquant, QVector<Personnage *> &ennemis, QVector<Heros *> &personnages, QVector<Attaque *> &attaquesBuffer, QVector<QVector<Personnage *> > &ciblesAttaque, QWidget *parent) :     QDialog(parent),
    ui(new Ui::setAttaque)
{
    ui->setupUi(this);
    m_attaquant = attaquant;
    m_ennemis = ennemis;
    m_personnages = personnages;
    m_attaquesBuffer = &attaquesBuffer;
    m_ciblesAttaque = &ciblesAttaque;

    //set le tableau des attaques
    int loopAttaques = 0;
    while (m_attaquant->getAttaques().count() != loopAttaques)
    {
        qDebug()<<"getAttaques.count : "<<m_attaquant->getAttaques().count();
        qDebug()<<"nombre cellules : "<< ui->attaquesTableWidget->rowCount() - 1;
        qDebug()<<"Nom première attaque : "<<m_attaquant->getAttaques()[0]->getName();
        if (m_attaquant->getAttaques().count() > ui->attaquesTableWidget->rowCount())
        {
            QVector <Attaque*> attaqueBuffer2 = m_attaquant->getAttaques();

            qDebug()<<QString::number(ui->attaquesTableWidget->rowCount());
            Attaque *bufferAttaque = attaqueBuffer2[ui->attaquesTableWidget->rowCount()];
            qDebug()<<bufferAttaque->getName();

            if (bufferAttaque->getLevel() <= m_attaquant->getLevel())
            {
                m_attaqueAffichee.push_back(bufferAttaque);
                ui->attaquesTableWidget->setRowCount(ui->attaquesTableWidget->rowCount() + 1);
                int nombre = ui->attaquesTableWidget->rowCount() - 1;
                Attaque buffer = *m_attaqueAffichee[nombre];
                ui->attaquesTableWidget->setItem(ui->attaquesTableWidget->rowCount() - 1, 0, new QTableWidgetItem(buffer.getName()));
            }
        }

        loopAttaques++;

    }

    ui->nameAttaque->setText(m_attaquant->getName() + " lvl " + QString::number(m_attaquant->getLevel()) + " : ");
    this->setWindowTitle(m_attaquant->getName() + " lvl " + QString::number(m_attaquant->getLevel()));


    //set le tableau des Heros
    while (m_personnages.count() != ui->herosTableWidget->rowCount())
    {
        ui->herosTableWidget->setRowCount(ui->herosTableWidget->rowCount() + 1);
        ui->herosTableWidget->setItem(ui->herosTableWidget->rowCount() - 1,0,new QTableWidgetItem(m_personnages[ui->herosTableWidget->rowCount() - 1]->getName()));
    }

    //set le tableau des Méchants
    while (m_ennemis.count() != ui->ennemisTableWidget->rowCount())
    {
        ui->ennemisTableWidget->setRowCount(ui->ennemisTableWidget->rowCount() + 1);
        ui->ennemisTableWidget->setItem(ui->ennemisTableWidget->rowCount() - 1,0,new QTableWidgetItem(m_ennemis[ui->ennemisTableWidget->rowCount() - 1]->getName()));
    }

}



void setAttaque::on_pushButton_clicked()
{
    m_attaquesBuffer->push_back(m_attaquant->getAttaques()[m_currentAttaqueTableCellRow]);

    //récupération des cibles dans le tableau des ennemis
    QVector <Personnage*> ciblesAttaque;

    int loop = 0;
    while (loop != m_rowSelectedMechants.count())
    {
        ciblesAttaque.push_back(m_ennemis[m_rowSelectedMechants[loop]]);
        loop++;
    }


    //récupération des cibles dans le tableau des héros
    loop = 0;
    while (loop != m_rowSelectedHeros.count())
    {
       ciblesAttaque.push_back(m_personnages[m_rowSelectedHeros[loop]]);
       loop++;
    }
    m_ciblesAttaque->push_back(ciblesAttaque);

    this->setVisible(false);
}

void setAttaque::on_attaquesTableWidget_cellActivated(int row, int column)
{
    m_currentAttaqueTableCellRow = row;
    QVector <Attaque*> attaquesTableau = m_attaquant->getAttaques();
    Attaque *selected = attaquesTableau[row];
    ui->nameAttaque->setText(selected->getName() + " :");
    ui->degatsDesc->setText(QString::number(selected->getDegats()));
    ui->chargeDesc->setText(QString::number(selected->getCharge()));
    ui->mpDesc->setText(QString::number(selected->getCharge()));
    ui->DescAttaque->setText(selected->getDescription());
    ui->healDesc->setText(QString::number(selected->getHeal()));
}



void setAttaque::on_herosTableWidget_cellDoubleClicked(int row, int column)
{
    int loopVerif1 = 0;

    bool alreadySelected = false;
    int selectPos = 0;
    while (loopVerif1 != m_rowSelectedHeros.count())
    {
        if (row == m_rowSelectedHeros[loopVerif1])
        {
            alreadySelected = true;
            selectPos = loopVerif1;
        }
        loopVerif1++;
    }

    if (alreadySelected == false)
    {
        ui->herosTableWidget->item(row, column)->setBackgroundColor(QColor("#C7FFCD"));
        m_rowSelectedHeros.push_back(row);

    }

    if (alreadySelected == true)
    {
        ui->herosTableWidget->item(row, column)->setBackgroundColor(QColor("#FFFFFF"));
        m_rowSelectedHeros.remove(selectPos);
    }
}

void setAttaque::on_pushButton_2_clicked()
{
    this->close();
}

void setAttaque::on_ennemisTableWidget_cellDoubleClicked(int row, int column)
{
    int loopVerif1 = 0;

    bool alreadySelected = false;
    int selectPos = 0;
    while (loopVerif1 != m_rowSelectedMechants.count())
    {
        if (row == m_rowSelectedMechants[loopVerif1])
        {
            alreadySelected = true;
            selectPos = loopVerif1;
        }
        loopVerif1++;
    }

    if (alreadySelected == false)
    {
        ui->ennemisTableWidget->item(row, column)->setBackgroundColor(QColor("#FF9999"));
        m_rowSelectedMechants.push_back(row);

    }

    if (alreadySelected == true)
    {
        ui->ennemisTableWidget->item(row, column)->setBackgroundColor(QColor("#FFFFFF"));
        m_rowSelectedMechants.remove(selectPos);
    }
}
