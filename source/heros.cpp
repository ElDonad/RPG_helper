#include "heros.h"

Heros::Heros() : Personnage()
{
    //m_vie = 100;

    //connect(this, SIGNAL(setWidgetUi(Heros,int,QString)), MainWindow, SLOT(setPersoWidgets(Heros,int,QString)))
}

Heros::Heros(QVector<QString> path, QVector <Attaque*> attaques) : Personnage(path, attaques)
{

}

