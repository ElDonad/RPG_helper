#include "briefing.h"
#include "ui_briefing.h"

Briefing::Briefing(QVector<QVector<Personnage *> > &ciblesAttaque, QVector<Attaque *> &attaquesSelected, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Briefing)
{
    ui->setupUi(this);
    m_cibles = ciblesAttaque;
    m_attaques = attaquesSelected;
    bakeTurn();
}

Briefing::~Briefing()
{
    delete ui;
}

void Briefing::bakeTurn()
{
    int attaquesLoop = 0;
    int ciblesLoop = 0;

    while (attaquesLoop != m_attaques.count())
    {
        while (ciblesLoop != m_cibles[attaquesLoop].count())
        {
            newEvent("<strong><span style=\"text-decoration: underline;\"><span style=\"font-size: medium;\">Nouveau combat : <font color=\"#228b22\">" + m_attaques[attaquesLoop]->m_parent->getName() + "</font> contre <font color=\"#ff0000\">" + m_cibles[attaquesLoop][ciblesLoop]->getName() + " !</span></span></strong>");
            //QVector <QString> retour = m_attaquants[attaquesLoop].combat(*m_cibles[attaquesLoop][ciblesLoop],m_attaques[attaquesLoop]);
            QVector<QString> retour = m_attaques[attaquesLoop]->attaque(m_cibles[attaquesLoop][ciblesLoop]);
            qDebug()<<retour.size();
            qDebug()<<retour[0];
            int loop = 0;
            while (loop != retour.count())//affichage des events
            {
                newEvent(retour[loop]);
                loop++;
            }
            ciblesLoop++;
        }
        ciblesLoop = 0;
        attaquesLoop++;
    }
    newEvent("<strong><span style=\"text-decoration: underline;\"><span style=\"color: #ff9900;\">FIN DU COMBAT</span></span></strong>");
}

void Briefing::newEvent(QString event)
{
    ui->briefZone->insertHtml(event + "<br />");
}
