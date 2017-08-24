#include "infospersos.h"
#include "ui_infospersos.h"

InfosPersos::InfosPersos(Personnage *info, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfosPersos)
{
    ui->setupUi(this);
    ui->nameLabel->setText(info->getName() + " :");
    ui->label_3->setText("Niveau : " + QString::number(info->getLevel()));

    if (info->getDefenseState() == true)
        ui->checkBox->setChecked(true);

    if (info->getMpMax() != 0)
    {
        ui->manaProgressBar->setValue((info->getMp() * 100) / info->getMpMax());
    }
    else if (info->getMpMax() == 0)
        ui->manaProgressBar->setValue(0);
    if (info->getVieMax() != 0)
        ui->vieProgressBar->setValue((info->getVie() * 100) / info->getVieMax());
    else if (info->getVieMax() == 0)
          ui->vieProgressBar->setValue(0);
    ui->manaLabel->setText(QString::number(info->getMp()) + "/" + QString::number(info->getMpMax()));
    ui->vieLabel->setText(QString::number(info->getVie()) + "/" + QString::number(info->getVieMax()));

    if (info->getEffect(1) == true)
    {
        ui->fire->setPalette(*new QPalette (QPalette::WindowText,QColor(qRgb(255,153,51))));
        ui->fireTimer->display(info->getTimer(1));
    }

    if (info->getEffect(2) == true)
    {
        ui->freeze->setPalette(*new QPalette (QPalette::WindowText,QColor(qRgb(51,153,255))));
        ui->iceTimer->display(info->getTimer(2));
    }

    if (info->getEffect(3) == true)
    {
        //ui->poison->setPalette(*new QPalette (QPalette::WindowText,QColor(qRgb(178,102,255))));
        ui->poisonTimer->display(info->getTimer(3));
        ui->poison->setText("<span style:\"color=#b266ff\">P</span>");
    }
    else if (info->getEffect(3) == true)
    {
        ui->poison->setText("P");
    }

    if (info->getEffect(4) == true)
    {
        ui->stun->setPalette(*new QPalette (QPalette::WindowText,QColor(qRgb(255,255,51))));
        ui->stunTimer->display(info->getTimer(4));
    }
    m_info = info;

}

InfosPersos::~InfosPersos()
{
    delete ui;
}

void InfosPersos::on_checkBox_clicked(bool checked)
{
    if (checked == true)
    {
        m_info->setDefenseState(true);
    }
    if (checked == false)
    {
        m_info->setDefenseState(false);
    }
}

void InfosPersos::on_pushButton_clicked()
{
    this->close();
}
