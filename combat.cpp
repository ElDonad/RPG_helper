#include "combat.h"
#include "ui_combat.h"
#include <QTableView>

Combat::Combat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Combat)
{
    ui->setupUi(this);

    //ui->ennemisCount->setText("0");

    ;
}

Combat::~Combat()
{
    delete ui;
}
