#ifndef ENNEMIESSET_H
#define ENNEMIESSET_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <personnage.h>
#include <QColorDialog>
#include <QListWidgetItem>

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
    typedef enum
    {
        PlainSelection,
        PresetSelection
    }RenderType;
    explicit EnnemiesSet(Personnage &toSet, QColor &toSetColor, RenderType render, QVector <Personnage>* presets=new QVector <Personnage>(), QVector <QColor>* presetsColor = new QVector<QColor>(),QWidget *parent = 0);
    //~EnnemiesSet();


private slots:
    void on_addAttaqueCommandLinkButton_clicked();

    void on_pushButton_2_clicked();

    void on_setColorPushButton_clicked();

    void on_pushButton_clicked();

    void on_attaquesList_currentRowChanged(int currentRow);

    void on_presetsListWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::EnnemiesSet *ui;
    Personnage *m_toSet;
    QVector <Personnage> *m_presets;
    QVector <QColor> *m_presetsColor;
    QColor *m_toSetColor;
    RenderType m_renderType;
    void updateGUI();
    void updateAttaquesList();
    void updateColor();

};

#endif // ENNEMIESSET_H
