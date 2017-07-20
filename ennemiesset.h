#ifndef ENNEMIESSET_H
#define ENNEMIESSET_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <personnage.h>

namespace Ui {
class EnnemiesSet;
}

class EnnemiesSet : public QDialog
{
    Q_OBJECT
    /*
     * Les attaques de tous les ennemis générés de cette fenêtre auront un id commençant par 12...
     */

public:
    explicit EnnemiesSet(Personnage &toSet,QVector <Personnage> presets,QWidget *parent = 0);
    //~EnnemiesSet();

private:
    Ui::EnnemiesSet *ui;
    Personnage *m_toSet;
    QVector <Personnage> m_presets;
    void updateGUI();
};

#endif // ENNEMIESSET_H
