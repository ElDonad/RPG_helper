#include "personnage.h"

int Personnage::id = 0;

int Personnage::setId()
{
    id++;
    m_id = id;
    return id;
}

Personnage::Personnage(QObject *parent) : QObject(parent)
{
    setId();
    m_vie = 100;
    m_vieMax = 100;
    m_mp = 50;
    m_mpMax = 50;
	m_vieBuffer = 0;
	m_mpBuffer = 0;
	

    //m_description = "Perso par défaut, pour les tests";
    m_nom = "Test";

    m_level = 1;
    
    m_isDeath = false;
	
	//combat stats
    m_defense = this->getTotalAbso() + (this->getTotalAbso() * 0.20);
	m_defenseBuffer = 0;
	m_critique = 1.20;
	m_critiqueBuffer = 0;
    m_critiqueHit = 95;
    m_critHitBuffer = 0;//valeur négative en général

    m_dodgeHit = 4;
    m_dodgeHitBuffer = 0;//valeur négative en général
	
	m_absorption = 0.15;
	m_absoptionBuffer = 0;
	
	//effects stats
	//m_isOnFire = false;
	m_fireTimer = 0;
	//m_isPoisoned = false;
	m_poisonTimer = 0;
	//m_isFrozen = false;
	m_frozenTimer = 0;
	//m_isStuned = false;
	m_stunTimer = 0;
	m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false; //ça marche ça ?
	m_isInDefenseState = false;

    QVector <int> effectsModifier;
    effectsModifier.push_back(0);
    effectsModifier.push_back(0);
    effectsModifier.push_back(0);
    effectsModifier.push_back(0);

    QVector <int> permanentEffectModifier;
    permanentEffectModifier.push_back(0);
    permanentEffectModifier.push_back(0);
    permanentEffectModifier.push_back(0);
    permanentEffectModifier.push_back(0);

    QVector <double> luckEffects;
    luckEffects.push_back(0);
    luckEffects.push_back(0);
    luckEffects.push_back(0);
    luckEffects.push_back(0);

    m_degats = 1;
	
	
}

Personnage::Personnage(const Personnage &toCopy) : m_vie(toCopy.m_vie),m_mp(toCopy.m_mp),m_vieBuffer(toCopy.m_vieBuffer),m_mpBuffer(toCopy.m_mpBuffer),m_vieMax(toCopy.m_vieMax),
                                                   m_mpMax(toCopy.m_mpMax),m_nom(toCopy.m_nom),m_degats(toCopy.m_degats),m_heal(toCopy.m_heal),m_degatsBuffer(toCopy.m_degatsBuffer),
                                                   m_defense(toCopy.m_defense),m_defenseBuffer(toCopy.m_defenseBuffer),m_critiqueHit(toCopy.m_critiqueHit),m_dodgeHit(toCopy.m_dodgeHit),
                                                   m_dodgeHitBuffer(toCopy.m_dodgeHitBuffer),m_critHitBuffer(toCopy.m_critHitBuffer),m_critique(toCopy.m_critique),m_critiqueBuffer(toCopy.m_critHitBuffer),
                                                   m_absorption(toCopy.m_absorption),m_absoptionBuffer(toCopy.m_absoptionBuffer),m_isOnFire(false),m_isPoisoned(false),m_isFrozen(false),m_isStuned(false),
                                                   m_fireTimer(0),m_frozenTimer(0),m_poisonTimer(0),m_stunTimer(0),m_level(toCopy.m_level),m_isInDefenseState(false),m_isDeath(false),m_attaques(*new QVector <Attaque *> (toCopy.m_attaques))
{
    setId();
}

Personnage::Personnage(int vie, int vieMax, int mp, int mpMax, QString& nom,
                       int level, double defense, double critique,
                       double absorption, int critHit, int dodgeHit, QVector<Attaque*>& attaques, QObject *parent) : QObject(parent)
{
    setId();
    m_vie = vie;
    m_vieMax = vieMax;
    m_vieBuffer = 0;
    m_mp = mp;
    m_mpMax = mpMax;
    m_mpBuffer = 0;

    m_nom = nom;
    //m_description = description;
    m_level = level;
    m_defense = defense;
    m_critique = critique;
    m_absorption = absorption;
    m_absoptionBuffer = 0;
    m_isDeath = false;
    m_defenseBuffer = 0;
    m_critiqueBuffer = 0;
    m_dodgeHit = dodgeHit;
    m_critiqueHit = critHit;


    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false;
    m_isDeath = false;
    //effects stats
    //m_isOnFire = false;
    m_fireTimer = 0;
    //m_isPoisoned = false;
    m_poisonTimer = 0;
    //m_isFrozen = false;
    m_frozenTimer = 0;
    //m_isStuned = false;
    m_stunTimer = 0;
    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false; //ça marche ça ?
    m_isInDefenseState = false;

    m_attaques = attaques;
    m_degats = 1;

    QVector <int> blankEffect;
    blankEffect.push_back(0);
    blankEffect.push_back(0);
    blankEffect.push_back(0);
    blankEffect.push_back(0);

    QVector <double> blankEffectDouble;
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);

    m_attaques.push_back(new Attaque (0,"Passer son tour",0,0,1,0,0,0,0,0,0,0,0,blankEffect,blankEffectDouble,blankEffect,9999,0,"Passer son tour"));

}

bool Personnage::equal(Personnage const& b) const
{
    if(m_nom == b.m_nom && m_vie == b.m_vie && m_level == b.m_level && m_id == b.m_id)
        return true;
    else
        return false;
}

void Personnage::setVie(int newVie){
    if (newVie <= m_vieMax && newVie>= 0)
    {
        m_vie = newVie;
    }
    else
    {
        m_vie = 0;
    }
}

Personnage::Personnage(QString path, QVector <Attaque*> attaques, QObject *parent) : QObject(parent) //constructeur à partir de fichier
{
    setId();
    //pas de buffer d'HP ou de MP, donc initialisation normale
    QVector <QString> donnees = getFile(path);

    int newVie = donnees[0].toInt();
    m_vie = newVie;

    int newMp = donnees[1].toInt();
    m_mp = newMp;

    int newVieMax = donnees[2].toInt();
    m_vieMax = newVieMax;

    int newMpMax = donnees[3].toInt();
    m_mpMax = newMpMax;

    m_nom = donnees[4];

    int newDefense = donnees[5].toInt();
    m_defense = newDefense;

    int newCritique = donnees[6].toInt();
    m_critiqueHit = newCritique;

    int newDodgeHit = donnees[7].toInt();
    m_dodgeHit = newDodgeHit;

    int newAbsorption = donnees[8].toInt();
    m_absorption = newAbsorption;

    int newCritHit = donnees[9].toInt();
    m_critiqueHit = newCritHit;

    m_dodgeHitBuffer = 0;

    m_critHitBuffer = 0;

    int newLevel = donnees[10].toInt();
    m_level = newLevel;

    int degatsBuffer = donnees[11].toInt();
    m_degats = degatsBuffer;

    int healBuffer = donnees[12].toInt();
    m_heal = healBuffer;

    m_attaques = attaques;


   //inchangé
    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false;
    m_isDeath = false;
    //effects stats
    //m_isOnFire = false;
    m_fireTimer = 0;
    //m_isPoisoned = false;
    m_poisonTimer = 0;
    //m_isFrozen = false;
    m_frozenTimer = 0;
    //m_isStuned = false;
    m_stunTimer = 0;
    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false; //ça marche ça ?
    m_isInDefenseState = false;




    
    //init des buffers classique
    m_vieBuffer = 0;
    m_mpBuffer = 0;
    m_defenseBuffer = 0;
    m_critiqueBuffer = 0;


}

void Personnage::rewrite(int vie, int vieMax, int mp, int mpMax, QString nom, int level, double defense, double critique, double absorption, int critHit, int dodgeHit, QVector<Attaque*> &attaques)
{
    m_vie = vie;
    m_vieMax = vieMax;
    m_vieBuffer = 0;
    m_mp = mp;
    m_mpMax = mpMax;
    m_mpBuffer = 0;

    m_nom = nom;
    //m_description = description;
    m_level = level;
    m_defense = defense;
    m_critique = critique;
    m_absorption = absorption;
    m_absoptionBuffer = 0;
    m_isDeath = false;
    m_defenseBuffer = 0;
    m_critiqueBuffer = 0;
    m_dodgeHit = dodgeHit;
    m_critiqueHit = critHit;


    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false;
    m_isDeath = false;
    //effects stats
    //m_isOnFire = false;
    m_fireTimer = 0;
    //m_isPoisoned = false;
    m_poisonTimer = 0;
    //m_isFrozen = false;
    m_frozenTimer = 0;
    //m_isStuned = false;
    m_stunTimer = 0;
    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false; //ça marche ça ?
    m_isInDefenseState = false;

    QVector <int> blankEffect;
    blankEffect.push_back(0);
    blankEffect.push_back(0);
    blankEffect.push_back(0);
    blankEffect.push_back(0);

    QVector <double> blankEffectDouble;
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);

    m_attaques.push_back(new Attaque (0,"Passer son tour",0,0,1,0,0,0,0,0,0,0,0,blankEffect,blankEffectDouble,blankEffect,9999,0,"Passer son tour"));

    int loop = 0;
    while (loop != attaques.count())
    {
        m_attaques.push_back(attaques[loop]);
        loop++;
    }

}

void Personnage::rewrite(QString path, QVector <Attaque*> attaques)
{
    //pas de buffer d'HP ou de MP, donc initialisation normale
    QVector <QString> donnees = getFile(path);

    int newVie = donnees[0].toInt();
    m_vie = newVie;

    int newMp = donnees[1].toInt();
    m_mp = newMp;

    int newVieMax = donnees[2].toInt();
    m_vieMax = newVieMax;

    int newMpMax = donnees[3].toInt();
    m_mpMax = newMpMax;

    m_nom = donnees[4];

    int newDefense = donnees[5].toInt();
    m_defense = newDefense;

    int newCritique = donnees[6].toInt();
    m_critiqueHit = newCritique;

    int newDodgeHit = donnees[7].toInt();
    m_dodgeHit = newDodgeHit;

    int newAbsorption = donnees[8].toInt();
    m_absorption = newAbsorption;

    int newCritHit = donnees[9].toInt();
    m_critiqueHit = newCritHit;

    m_dodgeHitBuffer = 0;

    m_critHitBuffer = 0;

    int newLevel = donnees[10].toInt();
    m_level = newLevel;

    int degatsBuffer = donnees[11].toInt();
    m_degats = degatsBuffer;

    int healBuffer = donnees[12].toInt();
    m_heal = healBuffer;

    QVector <int> blankEffect;
    blankEffect.push_back(0);
    blankEffect.push_back(0);
    blankEffect.push_back(0);
    blankEffect.push_back(0);

    QVector <double> blankEffectDouble;
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);
    blankEffectDouble.push_back(0);

    m_attaques.push_back(new Attaque (0,"Passer son tour",0,0,1,0,0,0,0,0,0,0,0,blankEffect,blankEffectDouble,blankEffect,9999,0,"Passer son tour"));

    int loop = 0;
    while (loop != attaques.count())
    {
        m_attaques.push_back(attaques[loop]);
        loop++;
    }

    //inchangé
    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false;
    m_isDeath = false;
    //effects stats
    //m_isOnFire = false;
    m_fireTimer = 0;
    //m_isPoisoned = false;
    m_poisonTimer = 0;
    //m_isFrozen = false;
    m_frozenTimer = 0;
    //m_isStuned = false;
    m_stunTimer = 0;
    m_isOnFire = m_isFrozen = m_isPoisoned = m_isStuned = false; //ça marche ça ?
    m_isInDefenseState = false;





    //init des buffers classique
    m_vieBuffer = 0;
    m_mpBuffer = 0;
    m_defenseBuffer = 0;
    m_critiqueBuffer = 0;
}



int Personnage::getVie()
{
    return m_vie;
}

void Personnage::setMp(int newMp)
{
    if (newMp <= m_mpMax && newMp>= 0)
    {
        m_mp = newMp;
    }
    else
    {
        m_mp = 0;
    }
}

int Personnage::getMp()
{
    return m_mp;
}

void Personnage::setVieBuffer(double newVieBuffer)
{
    m_vieBuffer = newVieBuffer;
}

double Personnage::getVieBuffer()
{
    return m_vieBuffer;
}

void Personnage::setMpBuffer(double newMpBuffer)
{
    m_mpBuffer = newMpBuffer;
}

double Personnage::getMpBuffer()
{
    return m_mpBuffer;
}

void Personnage::setCritique(double newCritique)
{
    if(newCritique >= 0)
    {
        m_critique = newCritique;
    }
}

double Personnage::getCritique()
{
    return m_critique;
}

void Personnage::setDodge(int newDodge)
{
    if (newDodge >= 0)
    {
        m_dodgeHit = newDodge;
    }
}

int Personnage::getDodge()
{
    return m_dodgeHit;
}

void Personnage::setDodgeHitBuffer(double newDodgeBuffer)
{
    if (m_dodgeHitBuffer + newDodgeBuffer >= 0 && m_dodgeHitBuffer + newDodgeBuffer <= 100)
    {
        m_dodgeHitBuffer = newDodgeBuffer;
    }
    else
    {
        m_dodgeHitBuffer = 0;
    }
}

double Personnage::getDodgeHitBuffer()
{
    return m_dodgeHitBuffer;
}

void Personnage::setCritiqueBuffer(double newCritiqueBuffer)
{
    if (m_critiqueBuffer + newCritiqueBuffer >= 0 && m_critiqueBuffer + newCritiqueBuffer <= 100)
    {
        m_critiqueBuffer = newCritiqueBuffer;
    }
    else
    {
        m_critiqueBuffer = 0;
    }
}

double Personnage::getCritiqueBuffer()
{
    return m_critiqueBuffer;
}



void Personnage::setDefense(double newDefense)
{
    m_defense = newDefense;
}

double Personnage::getDefense()
{
    return m_defense;
}

void Personnage::setDefenseBuffer(double newDefenseBuffer)
{
    m_defenseBuffer = newDefenseBuffer;
}

double Personnage::getDefenseBuffer()
{
    return m_defenseBuffer;
}

void Personnage::setVieMax(int newVieMax)
{
    if(newVieMax > 0)
    {
        m_vieMax = newVieMax;
    }
}

int Personnage::getVieMax()
{
    return m_vieMax;
}

void Personnage::setMpMax(int newMpMax)
{
    if (newMpMax > 0)
    {
        m_mpMax = newMpMax;
    }
}

int Personnage::getMpMax()
{
    return m_mpMax;
}

void Personnage::setName(QString newName)
{
    m_nom = newName;
}

QString Personnage::getName()
{
    return m_nom;
}


bool* Personnage::returnEffect(int effect) //private, en pointeur car cela permet à une métode d'influer directement sur la variable membre
{
    bool *cible;
    switch (effect) {
    case 1:
        cible = &m_isOnFire;
        break;

    case 2:
        cible = &m_isFrozen;
        break;

    case 3:
        cible = &m_isPoisoned;
        break;

    case 4:
        cible = &m_isStuned;
        break;
    default:
        break;
    }
    return cible;
}

int *Personnage::returnEffectTimer(int effect)
{
    int *cible;
    switch (effect) {
    case 1:
        cible = &m_fireTimer;
        break;

    case 2:
        cible = &m_frozenTimer;
        break;

    case 3:
        cible = &m_poisonTimer;
        break;

    case 4:
        cible = &m_stunTimer;
        break;
    default:
        break;
    }
    return cible;
}

void Personnage::toggleEffect(int effectNumber)
{
    bool *cible = returnEffect(effectNumber);
    int *cibleTimer = returnEffectTimer(effectNumber);
    if (*cible == true)
    {
        *cible = false;
        *cibleTimer = 0;

    }
    else if (*cible == false)
    {
        *cible = true;
    }
}

void Personnage::toggleEffect(int effectNumber, bool newState)
{
    bool *cible = returnEffect(effectNumber);
    *cible = newState;
}

bool Personnage::getEffect(int effect)
{
    bool *cible = returnEffect(effect);
    return *cible;
}

void Personnage::setLevel(int newLevel)
{
    if (newLevel<= 1 && newLevel >= 10)
    {
        m_level = newLevel;
    }
}

int Personnage::getLevel()
{
    return m_level;
}

void Personnage::save(QString filePath) //a finir...
{
    QVector <QString> merd;

    QString vie = QString::number(m_vie);
    merd.push_back(vie);

    QString mp = QString::number(m_mp);
    merd.push_back(mp);

    QString vieMax = QString::number(m_vieMax);
    merd.push_back(vieMax);

    QString mpMax = QString::number(m_mpMax);
    merd.push_back(mpMax);

    merd.push_back(m_nom);

    QString defense = QString::number(m_defense);
    merd.push_back(defense);

    QString critique = QString::number(m_critique);
    merd.push_back(critique);

    QString dodgeHit = QString::number(m_dodgeHit);
    merd.push_back(dodgeHit);

    QString abso = QString::number(m_absorption);
    merd.push_back(abso);

    QString critHit = QString::number(m_critiqueHit);
    merd.push_back(critHit);

    //relatif au niveau
    QString degatsBuffer = QString::number(m_degats);
    merd.push_back(degatsBuffer);

    QString healBuffer = QString::number(m_heal);
    merd.push_back(healBuffer);


    int loopAttaques = 0;
    while (loopAttaques < m_attaques.size())
    {
        int degats = m_attaques[loopAttaques]->getDegats();
        merd.push_back(QString::number(degats));

        QString nom = m_attaques[loopAttaques]->getName();
        merd.push_back(nom);

        int heal = m_attaques[loopAttaques]->getHeal();
        merd.push_back(QString::number(heal));

        int mpCost = m_attaques[loopAttaques]->getMpCost();
        merd.push_back(QString::number(mpCost));

        int persistence = m_attaques[loopAttaques]->getPersistence();
        merd.push_back(QString::number(persistence));

        double degatsModifier = m_attaques[loopAttaques]->getDegatsModifier();
        merd.push_back(QString::number(degatsModifier));

        double armureModifier = m_attaques[loopAttaques]->getArmureModifier();
        merd.push_back(QString::number(armureModifier));

        double mpCostModifier = m_attaques[loopAttaques]->getMpCostModifier();
        merd.push_back(QString::number(mpCostModifier));

        double absoModifier = m_attaques[loopAttaques]->getAbsoModifier();
        merd.push_back(QString::number(absoModifier));

        int dodgeHitModifier = m_attaques[loopAttaques]->getDodgeModifier();
        merd.push_back(QString::number(dodgeHitModifier));

        int critHitModifier = m_attaques[loopAttaques]->getCriticalModifier();
        merd.push_back(QString::number(critHitModifier));

        double critModifier = m_attaques[loopAttaques]->getAttaqueCritModifier();
        merd.push_back(QString::number(critModifier));

        int loop2 = 0;
        QVector <int> effets = m_attaques[loopAttaques]->getEffectsModifier();
        while (loop2 < 4)
        {
            merd.push_back(QString::number(effets[loop2]));

            loop2++;
        }

        int charge = m_attaques[loopAttaques]->getCharge();
        merd.push_back(QString::number(charge));

        loop2 = 0;
        QVector <int> permanentEffets = m_attaques[loopAttaques]->getPermanentEffectsModifier();
        while (loop2 < 4)
        {
            merd.push_back(QString::number(permanentEffets[loop2]));
            loop2++;
        }

        int attaqueId = m_attaques[loopAttaques]->getId();
        merd.push_back(QString::number(attaqueId));


        loopAttaques++;
    }

    saveFile(merd, filePath);
}

QString Personnage::returnVieSurVieMax()
{
    QString vieQString = QString::number(m_vie);
    QString vieMaxQString = QString::number(m_vieMax);
    QString returnQString = vieQString + "/" + vieMaxQString;
    return returnQString;
}

double Personnage::returnPurcentVie()
{
    int purcent = m_vie * m_vieMax;
    purcent = purcent / 100;
    return purcent;
}



//Partie spécifique combat (général à tous les mobs)


void Personnage::setCritiqueHit(int newCriticalHit)
{
    if (newCriticalHit >= 0)
    {
        m_critiqueHit = newCriticalHit;
    }
}

int Personnage::getCritiqueHit()
{
    return m_critiqueHit;
}

void Personnage::setCritiqueHitBuffer(int newCritiqueHitBuffer)
{
    m_critHitBuffer = newCritiqueHitBuffer;
}

int Personnage::getCritiqueHitBuffer()
{
    return m_critHitBuffer;
}

double Personnage::getTotalCritique()
{
    int returnValue = m_critique + m_critHitBuffer;
    return returnValue;
}

double Personnage::getTotalDefense()
{
    return m_defense + m_defenseBuffer;
}

int Personnage::getTotalVie()
{
    return m_vie + m_vieBuffer;
}

int Personnage::getTotalMp()
{
    return m_mp + m_mpBuffer;
}

double Personnage::getTotalAbso()
{
    return m_absorption + m_absoptionBuffer;
}

void Personnage::degat(int degatCount)
{
    /* TODO :
    -gestion de l'abso, de la défense
    -Mort si vie < 0
    */
    int absoTotale = this->getTotalAbso();
    degatCount = degatCount / absoTotale;

    if (m_isInDefenseState == true)
    {
        int defenseTotale = this->getTotalDefense();
        degatCount = degatCount / defenseTotale;
    }
    if (degatCount <= m_vie)
    {
        m_vie = m_vie - degatCount;
    }
    if (degatCount > m_vie)
    {
        m_vie = 0;
    }
    if (m_vie == 0)
    {
        m_isDeath = true;
    }


    

}

void Personnage::levelUp() //doit être fait en fonction du level, vérifizer les données avec Marin
{
    if (m_isDeath == false)
    {
        if (m_level != 4 && m_level < 9)
        {
            m_degats = m_degats * (1.013);
        }

        if (m_level == 4 || m_level == 9)
        {
            m_degats = m_degats * (1.5);
        }
    }
}

void Personnage::setTimer(int effectTimer, int value)
{
    int *cible = returnEffectTimer(effectTimer);
    *cible = value;
}

int Personnage::getTimer(int effectTimer)
{
    int *cible = returnEffectTimer(effectTimer);
    return *cible;
}

void Personnage::putOnEffect(int effect, int turnCount) // version finale de la fonction de set des effets
{
    bool* effectToggle = this->returnEffect(effect);
    int* effectTimer = this->returnEffectTimer(effect);

    if (*effectTimer > 0)
    {
        *effectToggle = true;
        if (*effectTimer < turnCount)
        {
           *effectTimer = turnCount;
        }
    }
}

void Personnage::newTurn()
{
    for (int loop = 1; loop == 4; loop++) //gestion des effets
    {
        bool *effectToggle = this->returnEffect(loop);
        int *effectTimer = this->returnEffectTimer(loop);

        if (*effectTimer > 0)
        {
            *effectTimer =- *effectTimer;
        }
        if (*effectTimer == 0)
        {
            *effectToggle = false;
        }

        if (*effectTimer > 0)
        {
            *effectToggle = true;
        }
    }
}

void Personnage::endFight()
{
    for (int loop = 1; loop == 4; loop++)
    {
        bool *effectToggle = this->returnEffect(loop);
        int *effectTimer = this->returnEffectTimer(loop);

        *effectTimer = 0;
        *effectToggle = false;
    }
}

void Personnage::combat(Personnage &cible, Attaque *bonneAttaque)
{
    if (m_isDeath == false)
    {



        int de = rand()% 50 + (-50);
        int totalDodge = m_dodgeHit + m_dodgeHitBuffer;
        if (de > totalDodge && m_mp >= bonneAttaque->getMpCost())//si pas dodge, MP suffisants,
        {
            double degats = (0.0);
            int degatAttaque = 0;
            degatAttaque = (bonneAttaque->getDegats());
            degats = static_cast <double> (degatAttaque);
            degats = degats * (m_level * 1.031);
            degats = degats * (de/1000);
            degats = degats * m_degats;
            int totalCritique = m_critiqueHit;
            totalCritique =- bonneAttaque->getCriticalModifier();
            totalCritique =- m_critHitBuffer;
            if (de > totalCritique)
            {
                int degatsFinaux = static_cast <int> (degats);
                degats = degats * bonneAttaque->getAttaqueCritModifier();
                cible.degat(degatsFinaux);
            }
            m_mp = m_mp - bonneAttaque->getMpCost();

            QVector <int> effects = bonneAttaque->getEffectsModifier();
            QVector <double> effectsLuck = bonneAttaque->getEffectsLuck();

            int deEffects = rand() % 100 + 1;
            if (effects[0] > 0 && effectsLuck[0] * 100 >= deEffects)
            {
                cible.putOnEffect(1, effects[0]);
            }
            if (effects[1] > 0 && effectsLuck[1] * 100 >= deEffects)
            {
                cible.putOnEffect(2, effects[1]);
            }
            if (effects[2] > 0 && effectsLuck[2] * 100 >= deEffects)
            {
                cible.putOnEffect(3, effects[2]);
            }
            if (effects[3] > 0 && effectsLuck[3] * 100 >= deEffects)
            {
                cible.putOnEffect(4, effects[3]);
            }

        }

        if (bonneAttaque->getId() == 306)
        {
            QVector <int> effetsChanges;
            effetsChanges.push_back(0);
            effetsChanges.push_back(0);
            effetsChanges.push_back(0);
            effetsChanges.push_back(0);

            SlacshEffectAttaqueDial *effets = new SlacshEffectAttaqueDial(&effetsChanges);
            effets->exec();

            int loop = 0;
            while (loop != 3)
            {
                if (effetsChanges[loop] > 0)
                {
                    putOnEffect(loop + 1,effetsChanges[loop]);
                }
                loop++;
            }
        }
    }
}

void Personnage::setAbso(double newAbso)
{
    m_absorption = newAbso;
}

double Personnage::getAbso()
{
    return m_absorption;
}

Attaque Personnage::returnAttaque(int attaqueId)
{
    Attaque *bonneAttaque = NULL;
    int counter = 0;
    while (bonneAttaque = NULL)
    {
        int idAttaqueAnalysee = m_attaques[counter]->getId();
        if (idAttaqueAnalysee == attaqueId)
        {
            bonneAttaque = m_attaques[counter];
        }
        counter++;
    }

    return *bonneAttaque;

}

QVector <Attaque*> Personnage::getAttaques()
{
    return m_attaques;
}

Personnage::~Personnage()
{
    while (m_attaques.count() != 0)
    {
        delete m_attaques[m_attaques.count() - 1];
        m_attaques.pop_back();
    }
}

void Personnage::setAttaque(QVector<Attaque *> newAttaques)
{
    m_attaques = newAttaques;
}
