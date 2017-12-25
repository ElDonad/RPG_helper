#include "slacsheffectattaquedial.h"
#include "ui_slacsheffectattaquedial.h"

SlacshEffectAttaqueDial::SlacshEffectAttaqueDial(QVector<int> *effets, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SlacshEffectAttaqueDial)
{
    ui->setupUi(this);
    m_effects = effets;
}

SlacshEffectAttaqueDial::~SlacshEffectAttaqueDial()
{
    delete ui;
}

void SlacshEffectAttaqueDial::on_pushButton_clicked()
{
    if (ui->coldCheck->isChecked() == true)
    {
        m_effects->operator [](1) = 3;
    }

    if (ui->feuCheck->isChecked() == true)
    {
        m_effects->operator [] (0) = 5;
    }

    if (ui->poisonCheck->isChecked() == true)
    {
        m_effects->operator [](2) = 6;
    }

    if (ui->stunCheck->isChecked() == true)
    {
        m_effects->operator [](3) = 2;
    }

    this->close();
}
