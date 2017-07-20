#include "ennemiessetattaque.h"
#include "ui_ennemiessetattaque.h"

EnnemiesSetAttaque::EnnemiesSetAttaque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnnemiesSetAttaque)
{
    ui->setupUi(this);
}

EnnemiesSetAttaque::~EnnemiesSetAttaque()
{
    delete ui;
}
