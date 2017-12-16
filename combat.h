#ifndef COMBAT_H
#define COMBAT_H

#include <QWidget>
#include <QVector>
#include <personnage.h>
#include <attaque.h>
#include <heros.h>
#include <setattaque.h>
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <savetools.h>
#include <operatorequal.h>
#include <ennemiesset.h>
#include <briefing.h>
#include <infospersos.h>



namespace Ui {
class Combat;
}

class Combat : public QWidget
{
    Q_OBJECT

public:
    explicit Combat(QVector <Heros*> &personnages,QVector <Personnage> *presets, QVector <QColor> *presetsColor,QWidget *parent = 0);
    ~Combat();
    void updateGUI();
    void updateEnnemisList();

private slots:
    void on_ennemyCount_valueChanged(int arg1);

    void on_ennemyTable_cellDoubleClicked(int row, int column);

    void on_bourrinAttaque_clicked();

    void on_eraseAttaqueButton_clicked();

    void on_copieButton_clicked();

    void on_ennemyTable_doubleClicked(const QModelIndex &index);

    void on_deleteButton_clicked();


    void on_editButton_clicked();

    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_bourrinInfos_clicked();

    void on_mageInfos_clicked();

    void on_chamanInfos_clicked();

    void on_assassinInfos_clicked();

    void on_ArcherInfos_clicked();

    void on_healerInfos_clicked();

    void on_infos_clicked();

    void on_clearButton_clicked();

    void on_PresetsButton_clicked();

private:
    Ui::Combat *ui;
    QVector <Heros*> m_personnages;
    QVector <Personnage*> m_mechants;
    QVector <Attaque*> m_turnAttaques; //les attaques sélectionnées
    QVector <QVector <Personnage*>> m_ciblesAttaque; //voir setattaque.h
    QVector <QColor> m_ennemiesColor;
    QVector <Personnage> *m_presets;
    QVector <QColor> *m_presetsColor;

    void clicked (Personnage *traite);
    void beforeRemovingEnnemy(Personnage *toRemove);
    //pour l'affichage des fins de tour
    QVector <QString> addQVector (QVector<QString>base,QVector <QString> aAjouter);
    void splash(QVector<QString> toDisplay);

    /*Petite précision :
     * m_turnAttaques : les attaques à réaliser, dans l'ordre
     * m_ciblesAttaques : les cibles de l'attaque, à réaliser
     * m_attaquants : les attaquants, dans l'ordre, qui vont éxecuter les attaques du tableau */
};

#endif // COMBAT_H
