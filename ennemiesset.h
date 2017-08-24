#ifndef ENNEMIESSET_H
#define ENNEMIESSET_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <personnage.h>
#include <QColorDialog>

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
    explicit EnnemiesSet(Personnage &toSet,QColor &toSetColor,QVector <Personnage> presets,QWidget *parent = 0);
    //~EnnemiesSet();

private slots:
    void on_addAttaqueCommandLinkButton_clicked();

    void on_pushButton_2_clicked();

    void on_setColorPushButton_clicked();

    void on_pushButton_clicked();

    void on_attaquesList_currentRowChanged(int currentRow);

private:
    Ui::EnnemiesSet *ui;
    Personnage *m_toSet;
    QVector <Personnage> m_presets;
    QColor *m_toSetColor;
    void updateGUI();
    void updateAttaquesList();

};

#endif // ENNEMIESSET_H
