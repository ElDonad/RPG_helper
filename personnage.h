#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QTextStream>
#include <QFile>

#include <savetools.h>


class Personnage : public QObject
{
    Q_OBJECT
public:
    explicit Personnage(QObject *parent = 0); //fait
    explicit Personnage(int vie, int mp, QString nom, QString description, int level, QObject *parent = 0); //fait
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

    void setDodgeBuffer(int newDodgeBuffer);//fait
    int getDodgeBuffer();//fait

    void setDefenseBuffer(int newDefenseBuffer);//fait
    int getDefenseBuffer();//fait

    void setDefenseStateBuffer(int newDefensetateBuffer);//fait
    int getDefenseStateBuffer();//fait


    //Partie spécifique combat (générale à tous les mobs)
    int getTotalCritique();//fait
    int getTotalDodge();//fait
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
    int m_defense;
    int m_defenseBuffer;
    int m_critique;
    int m_critiqueBuffer;
    int m_dodge;
    int m_dodgeBuffer;
    int m_absorption; //pourcentage
    int m_absoptionBuffer;


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

};

#endif // PERSONNAGE_H
