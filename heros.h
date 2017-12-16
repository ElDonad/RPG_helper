#ifndef HEROS_H
#define HEROS_H

#include <QObject>
#include <QWidget>
#include "personnage.h"
#include <QLabel>





class Heros : public Personnage
{
    Q_OBJECT

public:
    Heros();
    Heros(QVector<QString> path, QVector<Attaque *> attaques);

private :
    int pvTableau[];
    int mpTableau[];




    //void genererTableau(QVector <QString> &tableau, QString name, QString widget);


};

#endif // HEROS_H
