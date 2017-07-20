#include "ennemiesset.h"
#include "ui_ennemiesset.h"

EnnemiesSet::EnnemiesSet(Personnage &toSet, QVector<Personnage> presets, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnnemiesSet)
{
    ui->setupUi(this);
    m_toSet = &toSet;
    m_presets = presets;
    this->updateGUI();
}

void EnnemiesSet::updateGUI()
{

}

