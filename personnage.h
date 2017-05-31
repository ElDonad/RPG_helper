#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QTextStream>
#include <QFile>
#include <iostream>

#include <savetools.h>
#include <attaque.h>


class Personnage : public QObject
{
    Q_OBJECT
public:
    explicit Personnage(QObject *parent = 0); //fait
    explicit Personnage(int vie, int vieMax, int mp, int mpMax, QString nom,
                        int level, float defense, float critique, float absorption, int critHit, int dodgeHit, QVector<Attaque> attaques, QObject *parent); //fait
    explicit Personnage(QString path, QObject *parent = 0);

    void setVie(int newVie); //fait
    int getVie(); //fait

    void setMp(int newMp); //fait
    int getMp(); //fait

    void setVieBuffer(int newVieBuffer); //fait
    int getVieBuffer(); //fait

    void setMpBuffer(int newMpBuffer);//fait
    int getMpBuffer(); //fait

    void setVieMax(int newVieMax); //fait
    int getVieMax(); //fait

    void setMpMax(int newMpMax); //fait
    int getMpMax();//fait

    void setName(QString newName); //fait
    QString getName(); //fait

    void setDefense(int newDefense);//fait
    int getDefense();//fait

    void setCritique(int newCritique);//fait
    int getCritique();//fait

    void setCritiqueBuffer(int newCritiqueBuffer);//fait
    int getCritiqueBuffer();//fait

    void setDodge(int newDodge);//fait
    int getDodge();//fait

    void setDodgeHitBuffer(int newDodgeBuffer);//fait
    int getDodgeHitBuffer();//fait

    void setDefenseBuffer(int newDefenseBuffer);//fait
    int getDefenseBuffer();//fait

    void setDefenseStateBuffer(int newDefensetateBuffer);//fait
    int getDefenseStateBuffer();//fait

    void setCritiqueHit(int newCriticalHit);//fait
    int getCritiqueHit();//fait

    void setCritiqueHitBuffer(int newCritiqueHitBuffer);//fait
    int getCritiqueHitBuffer();//fait

    int getTotalCriticalHit();
    int getTotalDodgeHit();


    //Partie spécifique combat (générale à tous les mobs)
    int getTotalCritique();//fait
    int getTotalDefense();//fait
    int getTotalVie();//fait
    int getTotalMp();//fait
    int getTotalAbso();

    void degat(int degatCount); //comprend la gestion de l'absorption et de la vie supplémentaire fait
    void levelUp(); //différentes augmentations de stats, défini à +20% pour l'instant, à redéfinir par la suite, fait

    void setDefenseState(bool defenseState);
    bool getDefenseState();

    /* Au sujet des tours :
     * -La gestion du feu ou autre est gérée par le personnage
     * -Un timer de tour est incrémenté à chaque appel de la fonction newTurn()
     * -Lors de l'appel de la fonction endFight(), tous les compteurs sont remis à zéro
     * - !! Voir avec Marin si les effets sont cumulés ou écrasés
     * putOnEffect() permet de set une valeur de tour.
     * */

    void putOnEffect (int effect, int turnCount = 1);
    void newTurn();
    void endFight();

    void setTimer (int effectTimer, int value);
    int getTimer (int effectTimer);


    void save(QString filePath);

    //pour les textes affichés
    QString returnVieSurVieMax();
    int returnPurcentVie();


private : bool* returnEffect(int effect); //fait
          int *returnEffectTimer(int effect);
public :
    void toggleEffect(int effectNumber); //fait
    void toggleEffect(int effectNumber, bool newState); //fait
    bool getEffect(int effect); //fait
    /*
     * fire = 1
     * glace = 2
     * poison = 3
     * stun = 4
     */
    void setLevel(int newLevel); //fait
    int getLevel(); //fait

private :
    //general stats
    int m_vie;
    int m_mp;
    int m_vieBuffer;
    int m_mpBuffer;
    int m_vieMax;
    int m_mpMax;
    QString m_nom;
    //QString m_description;

    //combat stats
    int degatsBuffer;
    int m_defense;
    int m_defenseBuffer;
    int m_critiqueHit;
    int m_dodgeHit;
    int m_dodgeHitBuffer;
    int m_critHitBuffer;
    double m_critique; //Le critique supplémentaire (ex : 1.20 pour +20%) est utilisé lors des attaques. Ne doit pas être changé normalement
    double m_critiqueBuffer; //(ex : 0.10) pour un bonus de 10%
    //le dodge ANNULE TOUT !!! Penser à modifier ça
    double m_absorption; //pourcentage
    double m_absoptionBuffer;


    //effect stats
    bool m_isOnFire;
    int m_fireTimer;
    bool m_isPoisoned;
    int m_poisonTimer;
    bool m_isFrozen;
    int m_frozenTimer;
    bool m_isStuned;
    int m_stunTimer;

    //spacific stats
    int m_level;

    //defense state :
    bool m_isInDefenseState;
    //int m_defenseStateBuffer;
    bool m_isDeath;
    QVector <Attaque> m_attaques;

};

#endif // PERSONNAGE_H
