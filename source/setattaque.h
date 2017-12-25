#ifndef SETATTAQUE_H
#define SETATTAQUE_H

#include <QDialog>
#include <attaque.h>
#include <heros.h>
#include <personnage.h>
#include <QVector>
#include <QDebug>

namespace Ui {
class setAttaque;
}

class setAttaque : public QDialog
{
    Q_OBJECT

public:
    explicit setAttaque(Personnage *attaquant,
                        QVector <Personnage*> &ennemis,
                        QVector <Heros*> &personnages,
                        QVector <Attaque*> &attaquesBuffer,
                        QVector <QVector <Personnage*>> &ciblesAttaque,
                        QWidget *parent = 0);
    ~setAttaque();

private slots:
    void on_pushButton_clicked();

    void on_attaquesTableWidget_cellActivated(int row, int column);

    void on_herosTableWidget_cellDoubleClicked(int row, int column);

    void on_pushButton_2_clicked();

    void on_ennemisTableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::setAttaque *ui;
    Personnage *m_attaquant;
    QVector <Heros*> m_personnages;
    QVector <Personnage*> m_ennemis;
    QVector <Attaque*> *m_attaquesBuffer;
    QVector <int> m_rowSelectedHeros;
    QVector <int> m_rowSelectedMechants;
    QVector<QVector<Personnage*>> *m_ciblesAttaque;

    QVector <Attaque*> m_attaqueAffichee;

    //variables des tableaux
    int m_currentAttaqueTableCellRow;

    /* à propos du tableau ciblesAttaque :
     * une colonne : une attaque
     * une ligne : une cible
     *
     * ex :
     *
     * Attaque1         Attaque2
     * *Personnage1     *Personnage1 */

};

#endif // SETATTAQUE_H
