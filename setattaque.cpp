#include "setattaque.h"
#include "ui_setattaque.h"



setAttaque::~setAttaque()
{
    delete ui;
}

setAttaque::setAttaque(Personnage *attaquant, QVector<Personnage *> ennemis, QVector<Heros *> personnages, QVector<Attaque *> &attaquesBuffer, QVector<QVector<Personnage *> > &ciblesAttaque, QWidget *parent) :     QDialog(parent),
    ui(new Ui::setAttaque)
{
    ui->setupUi(this);
}
