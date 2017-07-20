#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QTextStream>
#include <QFile>
#include <iostream>
#include <stdlib.h>

#include <savetools.h>
#include <attaque.h>
#include <slacsheffectattaquedial.h>

#include <QDialog>


class Personnage : public QObject
{
    Q_OBJECT
public:
    explicit Personnage(QObject *parent = 0); //fait
    explicit Personnage(int vie, int vieMax, int mp, int mpMax, QString &nom,
                        int level, double defense, double critique, double absorption, int critHit, int dodgeHit, QVector<Attaque*>& attaques, QObject *parent); //fait
    explicit Personnage(QString path,  QVector<Attaque*> attaques, QObject *parent = 0);//fait
    explicit Personnage(Personnage const& toCopy);

    void rewrite(int vie, int vieMax, int mp, int mpMax, QString nom,
                 int level, double defense, double critique, double absorption, int critHit, int dodgeHit, QVector<Attaque *> &attaques);
    void rewrite(QString path, QVector<Attaque*> attaques);

    ~Personnage();

    bool equal(Personnage const& b) const;
    void combat(Personnage &cible, Attaque *bonneAttaque);//fait

    void setVie(int newVie); //fait
    int getVie(); //fait

    void setMp(int newMp); //fait
    int getMp(); //fait

    void setVieBuffer(double newVieBuffer); //fait
    double getVieBuffer(); //fait

    void setMpBuffer(double newMpBuffer);//fait
    double getMpBuffer(); //fait

    void setVieMax(int newVieMax); //fait
    int getVieMax(); //fait

    void setMpMax(int newMpMax); //fait
    int getMpMax();//fait

    void setName(QString newName); //fait
    QString getName(); //fait

    void setDefense(double newDefense);//fait
    double getDefense();//fait

    void setCritique(double newCritique);//fait
    double getCritique();//fait

    void setCritiqueBuffer(double newCritiqueBuffer);//fait
    double getCritiqueBuffer();//fait

    void setDodge(int newDodge);//fait
    int getDodge();//fait

    void setDodgeHitBuffer(double newDodgeBuffer);//fait
    double getDodgeHitBuffer();//fait

    void setDefenseBuffer(double newDefenseBuffer);//fait
    double getDefenseBuffer();//fait

    void setDefenseStateBuffer(double newDefensetateBuffer);//fait
    double getDefenseStateBuffer();//fait

    void setCritiqueHit(int newCriticalHit);//fait
    int getCritiqueHit();//fait

    void setCritiqueHitBuffer(int newCritiqueHitBuffer);//fait
    int getCritiqueHitBuffer();//fait

    int getTotalCriticalHit();
    int getTotalDodgeHit();

    double getDegats();
    void setDegats();

    double getHeal();
    void setHeal();

    void setAbso(double newAbso);
    double getAbso();

    QVector<Attaque *> getAttaques();
    void setAttaque (QVector <Attaque *> newAttaques);




    //Partie spécifique combat (générale à tous les mobs)
    double getTotalCritique();//fait
    double getTotalDefense();//fait
    int getTotalVie();//fait
    int getTotalMp();//fait
    double getTotalAbso();

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
    double returnPurcentVie();

    Attaque returnAttaque(int attaqueId);


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
    static int id;
    int m_id;
    int setId();

    int m_vie;
    int m_mp;
    int m_vieBuffer;
    int m_mpBuffer;
    int m_vieMax;
    int m_mpMax;
    QString m_nom;
    //QString m_description;

    //combat stats
    double m_degats;//pour les sauts de level, en pourcentage
    double m_heal;//même chose
    
    int m_degatsBuffer;
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
    QVector <Attaque*> m_attaques;

};

#endif // PERSONNAGE_H
