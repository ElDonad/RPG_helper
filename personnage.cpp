#include "personnage.h"

Personnage::Personnage(QObject *parent) : QObject(parent)
{
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

    m_attaques.push_back(Attaque(20, "attaque test", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, effectsModifier, permanentEffectModifier));
	
	
}

Personnage::Personnage(int vie, int vieMax, int mp, int mpMax, QString nom,
                       int level, float defense, float critique,
                       float absorption, int critHit, int dodgeHit, QVector<Attaque> attaques, QObject *parent) : QObject(parent)
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

    m_attaques = attaques;
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

Personnage::Personnage(QString path, QObject *parent) : QObject(parent) //constructeur à partir de fichier
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

    int newDodgeHitBuffer = donnees[10].toInt();
    m_dodgeHitBuffer = newDodgeHitBuffer;

    int newCritBuffer = donnees[11].toInt();
    m_critHitBuffer = newCritBuffer;

    int nombreLignesFait = 11;
    while(donnees.size() - 10 >= 10)
    {
        QVector <QString> nouvelleAttaqueSave;
        for (int loop = 1; loop == 10; ++loop)
        {
            nouvelleAttaqueSave.push_back(donnees[nombreLignesFait + loop]);
            ++nombreLignesFait;
        }
        Attaque truc(nouvelleAttaqueSave);
        m_attaques.push_back(truc);
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

    int newLevel = donnees[13].toInt();
    m_level = newLevel;

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

void Personnage::setVieBuffer(int newVieBuffer)
{
    m_vieBuffer = newVieBuffer;
}

int Personnage::getVieBuffer()
{
    return m_vieBuffer;
}

void Personnage::setMpBuffer(int newMpBuffer)
{
    m_mpBuffer = newMpBuffer;
}

int Personnage::getMpBuffer()
{
    return m_mpBuffer;
}

void Personnage::setCritique(int newCritique)
{
    if(newCritique >= 0)
    {
        m_critique = newCritique;
    }
}

int Personnage::getCritique()
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

void Personnage::setDodgeHitBuffer(int newDodgeBuffer)
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

int Personnage::getDodgeHitBuffer()
{
    return m_dodgeHitBuffer;
}

void Personnage::setCritiqueBuffer(int newCritiqueBuffer)
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

int Personnage::getCritiqueBuffer()
{
    return m_critiqueBuffer;
}



void Personnage::setDefense(int newDefense)
{
    m_defense = newDefense;
}

int Personnage::getDefense()
{
    return m_defense;
}

void Personnage::setDefenseBuffer(int newDefenseBuffer)
{
    m_defenseBuffer = newDefenseBuffer;
}

int Personnage::getDefenseBuffer()
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

    QString dodge = QString::number(m_dodgeHit);
    merd.push_back(dodge);

    QString abso = QString::number(m_absorption);
    merd.push_back(abso);

    saveFile(merd, filePath);
}

QString Personnage::returnVieSurVieMax()
{
    QString vieQString = QString::number(m_vie);
    QString vieMaxQString = QString::number(m_vieMax);
    QString returnQString = vieQString + "/" + vieMaxQString;
    return returnQString;
}

int Personnage::returnPurcentVie()
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

int Personnage::getTotalCritique()
{
    int returnValue = m_critique + m_critHitBuffer;
    return returnValue;
}

int Personnage::getTotalDefense()
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

int Personnage::getTotalAbso()
{
    return m_absorption + m_absoptionBuffer;
}

void Personnage::degat(int degatCount)
{
    // à prendre en compte : vie totale, défense, abso
    /*int vie = this->getTotalVie();
    int absoTotale = this->getTotalAbso();
    vie =+ (absoTotale * vie) / 100;
    vie =+ this->getTotalDefense();*/

    int degatsFinaux = degatCount;
    int defense = this->getTotalDefense();
    degatsFinaux = degatsFinaux - defense;
    if (degatsFinaux > 0)
    {
        //abso
        int abso = this->getTotalAbso();
        while (abso > 0)
        {
            degatsFinaux --;
            abso--;
        }
    }
    if (degatsFinaux > 0)
    {
        m_vie =- degatsFinaux;
    }

    if (m_vie <= 0)
    {
        m_isDeath = true;
    }

}

void Personnage::levelUp() //variables à définir exactement avec Marin
{
    if (m_level < 10 && m_isDeath == false)
    {
        m_vieMax =+ (m_vieMax * 15)/100;
        m_mpMax =+ (m_vieMax * 10)/100;
        m_dodgeHit =+ 2;
        m_critique =- 2;

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

