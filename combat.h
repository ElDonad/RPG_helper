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


namespace Ui {
class Combat;
}

class Combat : public QWidget
{
    Q_OBJECT

public:
    explicit Combat(QVector <Heros*> &personnages, QWidget *parent = 0);
    ~Combat();
    void updateGUI();
    void updateEnnemisList();

private slots:
    void on_ennemyCount_valueChanged(int arg1);

    void on_ennemyTable_cellDoubleClicked(int row, int column);

    void setHerosAttaque(Heros* attaquant);

private:
    Ui::Combat *ui;
    QVector <Heros*> m_personnages;
    QVector <Personnage*> m_mechants;
    QVector <Attaque*> m_turnAttaques;
    QVector <QVector <Personnage*>> m_ciblesAttaque; //voir setattaque.cpp
};

#endif // COMBAT_H
