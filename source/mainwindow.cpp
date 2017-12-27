#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow),
    m_bourrin(),
    m_mage(),
    m_assassin(),
    m_healer(),
    m_shaman(),
    m_archer()
    
    {
    ui->setupUi(this);


    QString path = QFileDialog::getExistingDirectory(this);
    m_mainPath = path;
    //QString correctPath = convertNormalPathIntoProtected(path);
    /*m_gold = 5000;

    Personnage *jeanMarc = new Personnage();
    QString gold = QString::number(m_gold);
    QString textGold = "Gold total : " + gold;
    
    ui->goldCount->setText(textGold);
    */
    
    //si besoin (faire des tests) demander le chemin vers le dossier save
    
    //une fois ceci fait, on récupère le chemin et on crée tous les personnages. Puis on continue.
    QVector <QString> mainSave = getFile (path + "/mainSave.txt"); //le fichier principal doit contenir la première ligne 1 (0   au début)
    int truc = mainSave[0].toInt();
    if (truc == 0)//non initialisé
    {   
        QVector <int> blankEffects;
        blankEffects.push_back(0);
        blankEffects.push_back(0);
        blankEffects.push_back(0);
        blankEffects.push_back(0);

        QVector <double> blankEffectsDouble;
        blankEffectsDouble.push_back(0);
        blankEffectsDouble.push_back(0);
        blankEffectsDouble.push_back(0);
        blankEffectsDouble.push_back(0);

        //bourrin : fait
        QVector <Attaque*> bourrinAttaques;
        QString bourrinName("Bourrin");
//        bourrinAttaques.push_back(new Attaque(*m_bourrin,75,bourrinName,0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects, 101,1));//SPECIAL : désactive l'état défense du bourrin pendant le reste du tour
        bourrinAttaques.push_back(new Attaque(&m_bourrin,50,"Smash",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,102,1));
//        bourrinAttaques.push_back(new Attaque(60,"Bonk",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,103,1));//10% chance de faire du stun
//        bourrinAttaques.push_back(new Attaque(0,"Heal",0.1,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,104,1));// !! vérifier heal en pourcentages
//        bourrinAttaques.push_back(new Attaque(0,"Proteccio",0,0,1,0,0,0,0,0.4,0,0,0,blankEffects,blankEffects,blankEffects,105,1));//voir suites.txt
        bourrinAttaques.push_back(new Attaque(&m_bourrin,70,"Pirouette",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,106,2));
//        bourrinAttaques.push_back(new Attaque(30,"Tremblement De Terre",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,107,3));
//        bourrinAttaques.push_back(new Attaque(0, "Shield",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,108,4));
//        bourrinAttaques.push_back(new Attaque(100,"Bourrin 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,109,5));//10% chance de stun
//        bourrinAttaques.push_back(new Attaque(0,"Proteccio 2",0,0,1,0,0,0,0,0.6,0,0,0,blankEffects,blankEffects,blankEffects,110,5));//comme proteccio 1
//        bourrinAttaques.push_back(new Attaque(80,"Smash 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,111,6));
//        bourrinAttaques.push_back(new Attaque(85,"Bonk 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,112,7));//20% de stun
//        bourrinAttaques.push_back(new Attaque(110,"Pirouette 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,113,8));
//        bourrinAttaques.push_back(new Attaque(0,"Shield 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,114,9));//4* les PV du bourrin
//        bourrinAttaques.push_back(new Attaque(130,"Bourrin 3",0,0,2,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,115,10));//30% stun
        bourrinAttaques.push_back(new AttaqueFeuGlace(&m_bourrin,0,"Attaque Feu/Glace",0,30,3,0,1.1,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,180,1,""));
//        archerAttaques.push_back(new Attaque(0,"Feu/glace",0,30,3,0,1.1,0,0,0,0,0,blankEffects,blankEffects,blankEffects,404,1));//feu : 3t, glace : 1t (choix)
        
        m_bourrin.rewrite(1000,1000,0,0,"Bourrin",1,(0.4),(1.5),0,45,(-45),bourrinAttaques);

//        //assassin
//        QVector <Attaque*> assassinAttaques;

//        assassinAttaques.push_back(new Attaque(70,"Traître",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,201,1));
//        assassinAttaques.push_back(new Attaque(60,"Dash",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,202,1));
//        assassinAttaques.push_back(new Attaque(50,"Double lame",0,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,203,1));
//        assassinAttaques.push_back(new Attaque(0,"Invisi",0,20,1,0,0,0,0,0,0,35,0,blankEffects,blankEffects,blankEffects,204,1));
//        assassinAttaques.push_back(new Attaque(0,"Mana Heal",0,10,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,205,1));//régen 50 mana pour toute l'équipe, marin devra cibler tout le monde
//        assassinAttaques.push_back(new Attaque(45,"Tir",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,206,2));
//        assassinAttaques.push_back(new Attaque(0,"Empoisonnement",0,20,4,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,207,4));//voir suites.txt pour les particularités
//        assassinAttaques.push_back(new Attaque(90,"Dash 2",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,208,5));
//        assassinAttaques.push_back(new Attaque(70,"Tir 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,209,6));
//        assassinAttaques.push_back(new Attaque(0,"Mana heal 2",0,20,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,210,7));//même chose que mana heal 1 : 100 MP heal
//        assassinAttaques.push_back(new Attaque(80,"Double lame 2",0,50,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,211,8));
//        assassinAttaques.push_back(new Attaque(105,"Traître 2",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,212,9));
//        assassinAttaques.push_back(new Attaque(0,"Invisi 2",0,35,3,0,0,0,0,0,0,55,0,blankEffects,blankEffects,blankEffects,213,10));

//        m_assassin.rewrite(860,860,70,70,"Assassin",1,0.2,1.5,0,45,(-45),assassinAttaques);

//        //mage
//        QVector <Attaque*> mageAttaques;

//        mageAttaques.push_back(new Attaque(35,"Entouré",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,301,1));
//        mageAttaques.push_back(new Attaque(45,"Cercle divin",0,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,302,1));
//        mageAttaques.push_back(new Attaque(40,"Foudre",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,303,1));//baisse de 5pts de mana pendant trois tours


//        QVector <int> mageAttaqueSDF;
//        mageAttaqueSDF.push_back(2);
//        mageAttaqueSDF.push_back(0);
//        mageAttaqueSDF.push_back(0);
//        mageAttaqueSDF.push_back(0);

//        QVector <int> mageLuckSDF;
//        mageLuckSDF.push_back(100);
//        mageLuckSDF.push_back(0);
//        mageLuckSDF.push_back(0);
//        mageLuckSDF.push_back(0);

//        QVector <int> fullLuck;
//        fullLuck.push_back(100);
//        fullLuck.push_back(100);
//        fullLuck.push_back(100);
//        fullLuck.push_back(100);

//        mageAttaques.push_back(new Attaque(50,"SDF",0,20,2,0,0,0,0,0,0,0,0,mageAttaqueSDF,mageLuckSDF,blankEffects,304,1));
//        mageAttaques.push_back(new Attaque(0,"Heal",0.1,15,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,305,1));
//        mageAttaques.push_back(new Attaque(0,"/effect",0,15,6,0,0,0,0,0,0,0,0,blankEffects,mageLuckSDF,blankEffects,306,2));
//        mageAttaques.push_back(new Attaque(0,"Mana Power",0,20,3,0,1.3,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,307,3));

//        QVector <int> mageEffectSDF2;
//        mageEffectSDF2.push_back(4);
//        mageEffectSDF2.push_back(0);
//        mageEffectSDF2.push_back(0);
//        mageEffectSDF2.push_back(0);

//        mageAttaques.push_back(new Attaque(65,"SDF 2",0,50,4,1,0,0,0,0,0,0,0,mageEffectSDF2,mageLuckSDF,blankEffects,308,4));
//        mageAttaques.push_back(new Attaque(60,"Entouré 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,309,5));
//        mageAttaques.push_back(new Attaque(0,"Heal 2",0.35,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,310,6));
//        mageAttaques.push_back(new Attaque(65,"Foudre 2",0,50,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,311,7));
//        mageAttaques.push_back(new Attaque(0,"Mana power 2,",0,30,5,0,1.5,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,312,8));
//        mageAttaques.push_back(new Attaque(60,"Cercle divin 2",0,60,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,313,9));

//        QVector <int> mageEffectSDF3;
//        mageEffectSDF3.push_back(7);
//        mageEffectSDF3.push_back(0);
//        mageEffectSDF3.push_back(0);
//        mageEffectSDF3.push_back(0);

//        mageAttaques.push_back(new Attaque(110,"SDF 3",0,100,7,2,0,0,0,0,0,0,0,mageEffectSDF3,mageLuckSDF,blankEffects,314,10));

//        m_mage.rewrite(620,620,100,100,"Mage",1,(0.2),(1.5),0,45,(-45),mageAttaques);

//        QVector <Attaque*> archerAttaques;
//        archerAttaques.push_back(new Attaque(65,"Pan !",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,401,1));
//        archerAttaques.push_back(new Attaque(55,"Explosion",0,20,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,402,1));
//        archerAttaques.push_back(new Attaque(0,"Heal",0.1,10,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,403,1));
//        archerAttaques.push_back(new Attaque(0,"Feu/glace",0,30,3,0,1.1,0,0,0,0,0,blankEffects,blankEffects,blankEffects,404,1));//feu : 3t, glace : 1t (choix)
//        archerAttaques.push_back(new Attaque(0,"Arborescence",0,50,3,0,0,0,0,2000,0,0,0,blankEffects,blankEffects,blankEffects,405,1));//mettre l'abso en buffer d'int

//        QVector <int> embrancheEffects;
//        embrancheEffects.push_back(0);
//        embrancheEffects.push_back(0);
//        embrancheEffects.push_back(0);
//        embrancheEffects.push_back(2);

//        archerAttaques.push_back(new Attaque(0,"Embranché",0,20,1,0,0,0,0,0,0,0,0,embrancheEffects,fullLuck,blankEffects,406,2));
//        archerAttaques.push_back(new Attaque(65,"Triflèche",0,25,1,0,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,407,3));
//        archerAttaques.push_back(new Attaque(0,"Heal 2",0.35,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,408,4));
//        archerAttaques.push_back(new Attaque(0,"Motivation",0,60,1,0,1.1,0,0,0,0,15,0,blankEffects,blankEffects,blankEffects,409,5));
//        archerAttaques.push_back(new Attaque(75,"Pan ! 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,410,6));
//        archerAttaques.push_back(new Attaque(80,"Explosion 2",0,45,1,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,411,7));
//        archerAttaques.push_back(new Attaque(0,"Arborescence 2",0,100,5,0,0,0,0,20000,0,0,0,blankEffects,blankEffects,blankEffects,412,8));
//        archerAttaques.push_back(new Attaque(0,"Feu/glace 2",0,40,3,0,1.2,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,413,9));//même chose, feu :5/glace:2
//        archerAttaques.push_back(new Attaque(105,"Pan ! 3",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,414,10));
//        archerAttaques.push_back(new Attaque(90,"Triflèche 2",0,55,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,415,10));
//        m_archer.rewrite(680,680,75,75,"Archer",1,(0.2),(1.5),0,45,(-45),archerAttaques);


//        QVector <Attaque*> healerAttaques;
//        healerAttaques.push_back(new Attaque(70,"Bombe",0,0,2,1,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,501,1));
//        healerAttaques.push_back(new Attaque(20,"Ying/Yang",0.1,30,2,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,502,1));//inflige dégâts et heal pendant 2 tours
//        healerAttaques.push_back(new Attaque(0,"Speedy",0,30,3,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,503,1,"Augmente la vitesse de 2"));
//        healerAttaques.push_back(new Attaque(0,"Heal",0.1,10,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,504,1));
//        healerAttaques.push_back(new Attaque(0,"Fiole de vie",0,35,10,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,505,1,"Heal de HP : 40%"));
//        healerAttaques.push_back(new Attaque(0,"/effect",0,15,6,0,0,0,0,0,0,0,0,blankEffects,mageLuckSDF,blankEffects,506,2));
//        healerAttaques.push_back(new Attaque(70,"Smash",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,507,3));
//        healerAttaques.push_back(new Attaque(0,"Heal 2",0.35,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,508,4));
//        healerAttaques.push_back(new Attaque(0,"Fiole mixte",0,50,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,509,5,));//heal de MP : ?
//        healerAttaques.push_back(new Attaque(90,"Bombe 2",0,0,2,1,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,510,5));
//        QVector<int> trappeEffects;

//        trappeEffects.push_back(0);
//        trappeEffects.push_back(0);
//        trappeEffects.push_back(5);
//        trappeEffects.push_back(0);
//        healerAttaques.push_back(new Attaque(0,"Trappe",0,0,1,0,0,0,0,0,0,0,0,trappeEffects,fullLuck,blankEffects,511,6));
//        healerAttaques.push_back(new Attaque(0,"Fiole de vie 2",0,60,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,512,7,"Heal de 50% trois fois"));
//        healerAttaques.push_back(new Attaque(0,"Heal 3",0.45,100,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,513,8));
//        healerAttaques.push_back(new Attaque(45,"Ying/Yang 2",0.3,45,4,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,514,8));//dégâts et heal sur 4 tours (comme YY 1)
//        healerAttaques.push_back(new Attaque(0,"Speedy 2",0,40,5,0,0,0,0,0,30,0,0,blankEffects,blankEffects,blankEffects,515,9));
//        healerAttaques.push_back(new Attaque(0,"Moivation",0.15,180,4,1,1.2,0,0,1.2,0,0,15,blankEffects,blankEffects,blankEffects,516,10,"Le kahos"));//+100 MP
//        healerAttaques.push_back(new Attaque(0,"Heal 4",0,200,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,517,10));//heal à 100% des HP et MP (sauf pour le bourrin) + m_isDeath = false

//        m_healer.rewrite(800,800,80,80,"Healer",1,(0.2),1.5,0,45,(-45),healerAttaques);

//        QVector<int> shamanAttaques;
//        shamanAttaques.push_back(new Attaque(50,"Smash",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,601,1));
//        shamanAttaques.push_back(new Attaque(0,"Dispenser",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,602,1));//totem : 40%HP de tous les héros,tape 30
//        shamanAttaques.push_back(new Attaque(0,"Prison",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,603,1,"Le totem immobilise les cibles"));//totem : 50%HP # , 50DMG
//        shamanAttaques.push_back(new Attaque(0,"Totem de l'amort(adelle)",0,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,604,1));//totem : 45%HP # , 25DMG
//        shamanAttaques.push_back(new Attaque(0,"Symétra",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,605,1,"5% heal par attaque"));//totem : 45%HP # 25DMG
//        shamanAttaques.push_back(new Attaque(50,"Tremblement de terre",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,606,2));
//        shamanAttaques.push_back(new Attaque(0,"Totem du désert",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,607,3));//demander plus tard
//        shamanAttaques.push_back(new Attaque(0,"Dispenser 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,607,4));//50%HP # 40DMG
//        shamanAttaques.push_back(new Attaque(0,"Totem de l'amort(omate)",0,40,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,608,5));//55%HP # 40DMG
//        shamanAttaques.push_back(new Attaque(0,"Symétra 2",0,40,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,609,5));//55%HP, 35DMG
//        shamanAttaques.push_back(new Attaque(0,"Prison 2",0,45,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,610,6));//65%HP, 70DMG
//        shamanAttaques.push_back(new Attaque(80,"Smash 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,613,7));
//        shamanAttaques.push_back(new Attaque(0,"Dispenser 3",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,611,8));//60%HP, 60DMG
//        shamanAttaques.push_back(new Attaque(0,"Totem du désert 2",0,55,1,0,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,612,8));//85%HP, désactive état défense (-100% armure modifier)
//        shamanAttaques.push_back(new Attaque(85,"Tremblement de terre²", 0,45,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,613,9));
//        shamanAttaques.push_back(new Attaque(0,"Symétroy",0,55,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,614,9));//65%HP, 45DMG
//        shamanAttaques.push_back(new Attaque(0,"Prison 3",0,60,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,615,10));//80HP, 100DMG
//        shamanAttaques.push_back(new Attaque(0,"Totem de l'amor(ora) 3",0,55,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,616,10));//70%HP, 50DMG

//        m_shaman.rewrite(640,640,80,80,"Shaman",1,0.2,1.5,0,45,(-45),shamanAttaques);




        m_gold = 5000;


    }
    else if (truc == 1)
    {
        m_gold = (getFile(m_mainPath + "/mainSave.txt"))[1].toInt();
        //int nbFichiersSD = Directory.GetFiles(path, "*.*", SearchOption.TopDirectory).Length - 1; : pour avoir le nombre de fichiers

        //1. on set les personnages
        QVector <int> blankEffects;
        blankEffects.push_back(0);
        blankEffects.push_back(0);
        blankEffects.push_back(0);
        blankEffects.push_back(0);


        QVector <Attaque*> bourrinAttaques;
        QString bourrinName("Bourrin");
//        bourrinAttaques.push_back(new Attaque(*m_bourrin,75,bourrinName,0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects, 101,1));//SPECIAL : désactive l'état défense du bourrin pendant le reste du tour
        bourrinAttaques.push_back(new Attaque(&m_bourrin,50,"Smash",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,102,1));
//        bourrinAttaques.push_back(new Attaque(60,"Bonk",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,103,1));//10% chance de faire du stun
//        bourrinAttaques.push_back(new Attaque(0,"Heal",0.1,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,104,1));// !! vérifier heal en pourcentages
//        bourrinAttaques.push_back(new Attaque(0,"Proteccio",0,0,1,0,0,0,0,0.4,0,0,0,blankEffects,blankEffects,blankEffects,105,1));//voir suites.txt
        bourrinAttaques.push_back(new Attaque(&m_bourrin,70,"Pirouette",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,106,2));
//        bourrinAttaques.push_back(new Attaque(30,"Tremblement De Terre",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,107,3));
//        bourrinAttaques.push_back(new Attaque(0, "Shield",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,108,4));
//        bourrinAttaques.push_back(new Attaque(100,"Bourrin 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,109,5));//10% chance de stun
//        bourrinAttaques.push_back(new Attaque(0,"Proteccio 2",0,0,1,0,0,0,0,0.6,0,0,0,blankEffects,blankEffects,blankEffects,110,5));//comme proteccio 1
//        bourrinAttaques.push_back(new Attaque(80,"Smash 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,111,6));
//        bourrinAttaques.push_back(new Attaque(85,"Bonk 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,112,7));//20% de stun
//        bourrinAttaques.push_back(new Attaque(110,"Pirouette 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,113,8));
//        bourrinAttaques.push_back(new Attaque(0,"Shield 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,114,9));//4* les PV du bourrin
//        bourrinAttaques.push_back(new Attaque(130,"Bourrin 3",0,0,2,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,115,10));//30% stun
        bourrinAttaques.push_back(new AttaqueFeuGlace(&m_bourrin,0,"Attaque Feu/Glace",0,30,3,0,1.1,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,180,1,""));
//        archerAttaques.push_back(new Attaque(0,"Feu/glace",0,30,3,0,1.1,0,0,0,0,0,blankEffects,blankEffects,blankEffects,404,1));//feu : 3t, glace : 1t (choix)

        m_bourrin.rewrite(1000,1000,0,0,"Bourrin",1,(0.4),(1.5),0,45,(-45),bourrinAttaques);

//        QVector <Attaque*> assassinAttaques;

//        assassinAttaques.push_back(new Attaque(70,"Traître",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,201,1));
//        assassinAttaques.push_back(new Attaque(60,"Dash",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,202,1));
//        assassinAttaques.push_back(new Attaque(50,"Double lame",0,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,203,1));
//        assassinAttaques.push_back(new Attaque(0,"Invisi",0,20,1,0,0,0,0,0,0,35,0,blankEffects,blankEffects,blankEffects,204,1));
//        assassinAttaques.push_back(new Attaque(0,"Mana Heal",0,10,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,205,1));//régen 50 mana pour toute l'équipe, marin devra cibler tout le monde
//        assassinAttaques.push_back(new Attaque(45,"Tir",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,206,2));
//        assassinAttaques.push_back(new Attaque(0,"Empoisonnement",0,20,4,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,207,4));//voir suites.txt pour les particularités
//        assassinAttaques.push_back(new Attaque(90,"Dash 2",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,208,5));
//        assassinAttaques.push_back(new Attaque(70,"Tir 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,209,6));
//        assassinAttaques.push_back(new Attaque(0,"Mana heal 2",0,20,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,210,7));//même chose que mana heal 1 : 100 MP heal
//        assassinAttaques.push_back(new Attaque(80,"Double lame 2",0,50,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,211,8));
//        assassinAttaques.push_back(new Attaque(105,"Traître 2",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,212,9));
//        assassinAttaques.push_back(new Attaque(0,"Invisi 2",0,35,3,0,0,0,0,0,0,55,0,blankEffects,blankEffects,blankEffects,213,10));

//        m_assassin.rewrite(getFile(m_mainPath + "/assassin.txt"),assassinAttaques);

//        QVector <Attaque*> mageAttaques;

//        mageAttaques.push_back(new Attaque(35,"Entouré",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,301,1));
//        mageAttaques.push_back(new Attaque(45,"Cercle divin",0,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,302,1));
//        mageAttaques.push_back(new Attaque(40,"Foudre",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,303,1));//baisse de 5pts de mana pendant trois tours


//        QVector <int> mageAttaqueSDF;
//        mageAttaqueSDF.push_back(2);
//        mageAttaqueSDF.push_back(0);
//        mageAttaqueSDF.push_back(0);
//        mageAttaqueSDF.push_back(0);

//        QVector <int> mageLuckSDF;
//        mageLuckSDF.push_back(100);
//        mageLuckSDF.push_back(0);
//        mageLuckSDF.push_back(0);
//        mageLuckSDF.push_back(0);

//        QVector <int> fullLuck;
//        fullLuck.push_back(100);
//        fullLuck.push_back(100);
//        fullLuck.push_back(100);
//        fullLuck.push_back(100);

//        mageAttaques.push_back(new Attaque(50,"SDF",0,20,2,0,0,0,0,0,0,0,0,mageAttaqueSDF,mageLuckSDF,blankEffects,304,1));
//        mageAttaques.push_back(new Attaque(0,"Heal",0.1,15,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,305,1));
//        mageAttaques.push_back(new Attaque(0,"/effect",0,15,6,0,0,0,0,0,0,0,0,blankEffects,mageLuckSDF,blankEffects,306,2));
//        mageAttaques.push_back(new Attaque(0,"Mana Power",0,20,3,0,1.3,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,307,3));

//        QVector <int> mageEffectSDF2;
//        mageEffectSDF2.push_back(4);
//        mageEffectSDF2.push_back(0);
//        mageEffectSDF2.push_back(0);
//        mageEffectSDF2.push_back(0);

//        mageAttaques.push_back(new Attaque(65,"SDF 2",0,50,4,1,0,0,0,0,0,0,0,mageEffectSDF2,mageLuckSDF,blankEffects,308,4));
//        mageAttaques.push_back(new Attaque(60,"Entouré 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,309,5));
//        mageAttaques.push_back(new Attaque(0,"Heal 2",0.35,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,310,6));
//        mageAttaques.push_back(new Attaque(65,"Foudre 2",0,50,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,311,7));
//        mageAttaques.push_back(new Attaque(0,"Mana power 2,",0,30,5,0,1.5,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,312,8));
//        mageAttaques.push_back(new Attaque(60,"Cercle divin 2",0,60,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,313,9));

//        QVector <int> mageEffectSDF3;
//        mageEffectSDF3.push_back(7);
//        mageEffectSDF3.push_back(0);
//        mageEffectSDF3.push_back(0);
//        mageEffectSDF3.push_back(0);

//        mageAttaques.push_back(new Attaque(110,"SDF 3",0,100,7,2,0,0,0,0,0,0,0,mageEffectSDF3,mageLuckSDF,blankEffects,314,10));

//        m_mage.rewrite(getFile(m_mainPath + "/mage.txt"), mageAttaques);

//        QVector <Attaque*> archerAttaques;
//        archerAttaques.push_back(new Attaque(65,"Pan !",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,401,1));
//        archerAttaques.push_back(new Attaque(55,"Explosion",0,20,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,402,1));
//        archerAttaques.push_back(new Attaque(0,"Heal",0.1,10,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,403,1));
//        archerAttaques.push_back(new Attaque(0,"Feu/glace",0,30,3,0,1.1,0,0,0,0,0,blankEffects,blankEffects,blankEffects,404,1));//feu : 3t, glace : 1t (choix)
//        archerAttaques.push_back(new Attaque(0,"Arborescence",0,50,3,0,0,0,0,2000,0,0,0,blankEffects,blankEffects,blankEffects,405,1));//mettre l'abso en buffer d'int

//        QVector <int> embrancheEffects;
//        embrancheEffects.push_back(0);
//        embrancheEffects.push_back(0);
//        embrancheEffects.push_back(0);
//        embrancheEffects.push_back(2);

//        archerAttaques.push_back(new Attaque(0,"Embranché",0,20,1,0,0,0,0,0,0,0,0,embrancheEffects,fullLuck,blankEffects,406,2));
//        archerAttaques.push_back(new Attaque(65,"Triflèche",0,25,1,0,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,407,3));
//        archerAttaques.push_back(new Attaque(0,"Heal 2",0.35,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,408,4));
//        archerAttaques.push_back(new Attaque(0,"Motivation",0,60,1,0,1.1,0,0,0,0,15,0,blankEffects,blankEffects,blankEffects,409,5));
//        archerAttaques.push_back(new Attaque(75,"Pan ! 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,410,6));
//        archerAttaques.push_back(new Attaque(80,"Explosion 2",0,45,1,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,411,7));
//        archerAttaques.push_back(new Attaque(0,"Arborescence 2",0,100,5,0,0,0,0,20000,0,0,0,blankEffects,blankEffects,blankEffects,412,8));
//        archerAttaques.push_back(new Attaque(0,"Feu/glace 2",0,40,3,0,1.2,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,413,9));//même chose, feu :5/glace:2
//        archerAttaques.push_back(new Attaque(105,"Pan ! 3",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,414,10));
//        archerAttaques.push_back(new Attaque(90,"Triflèche 2",0,55,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,415,10));
//        m_archer.rewrite(getFile(m_mainPath + "/archer.txt"),archerAttaques);

        int loop = 0;
        QVector <QString> file;
        while (getFile(m_mainPath + "/presets/" + QString::number(loop) + ".txt").empty() == false)
        {
            file = getFile(m_mainPath + "/presets/" + QString::number(loop) + ".txt");
            m_presets.push_back(Personnage(file));
            loop++;
        }
    }
    //on est donc après avoir trouvé le chemin. Pour l'instant je garde les chemins relatifs.



    //connexions
    connect(this, SIGNAL(destroyed(this)), this, SLOT(onClose()));
    this->updateGui();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setWidgetUi(int idPerso, int widget, QString newValue)
{
    /*QWidget *tableauWidgets[8];

    switch (idPerso) :
    case 1 :
        *tableauWidgets =*/


}

void MainWindow::on_testButton_clicked()
{
    QVector <Heros*> personnages;
    personnages.push_back(&m_bourrin);
    Combat* combatWindows = new Combat(personnages,&m_presets,&m_presetsColor);
    combatWindows->show();

}


void MainWindow::on_save_clicked()
{
    saveMain();
}

void MainWindow::saveMain()
{
    //1. On commence par l'argent dans le mainSave
    QVector <QString> aSauver;
    aSauver.push_back("1");
    aSauver.push_back(QString::number(m_gold));
    saveFile(aSauver,m_mainPath + "/mainSave.txt");

    //2. les héros, dans des fichiers séparés
    saveFile(m_bourrin.save(Personnage::ClassicSave), m_mainPath + "/bourrin.txt");
    saveFile(m_shaman.save(Personnage::ClassicSave), m_mainPath + "/shaman.txt");
    saveFile(m_archer.save(Personnage::ClassicSave), m_mainPath + "/archer.txt");
    saveFile(m_assassin.save(Personnage::ClassicSave), m_mainPath + "/assassin.txt");
    saveFile(m_healer.save(Personnage::ClassicSave), m_mainPath + "/healer.txt");
    saveFile(m_mage.save(Personnage::ClassicSave), m_mainPath + "/mage.txt");

    //3. les presets, dans des fichiers séparés aussi
    int loop = 0;
    while (m_presets.count() != loop)
    {
        QVector <QString> savePresets = m_presets[loop].save(Personnage::CompleteSave);
        saveFile (savePresets, m_mainPath + "/presets/" + QString::number(loop) + ".txt");
        loop++;
    }
}

void MainWindow::on_pushValidateGold_clicked()
{
    QString newGoldString = ui->editGold->text();
    ui->editGold->clear();
    if (newGoldString[0] == '+')
    {
        int cut = newGoldString.size() - 1;
        newGoldString = newGoldString.right(cut);
        int newGold = newGoldString.toInt();
        m_gold = m_gold + newGold;
    }

    else if (newGoldString[0] == '-')
    {
        int cut = newGoldString.size() - 1;
        newGoldString = newGoldString.right(cut);
        int newGold = newGoldString.toInt();
        m_gold  =m_gold - newGold;
    }
    else
    {
        int newGold = newGoldString.toInt();
        m_gold = newGold;
    }
    QString gold = QString::number(m_gold);
    QString textGold = "Gold total : " + gold;

    ui->goldCount->setText(textGold);
}

void MainWindow::on_pushButton_2_clicked()//mea culpa, pas toucher...
{

}

void MainWindow::onClose()//à finir après avoir créé les persos
{
    this->saveMain();

}

void MainWindow::updateGui()
{
    ui->vieProgressBar_2->setMaximum(m_bourrin.getVieMax());
    ui->vieProgressBar_2->setValue(m_bourrin.getVie());
    ui->vieIndicator_2->setText(m_bourrin.returnVieSurVieMax());
}

void MainWindow::on_statsButton_2_clicked()//bourrin
{
    StatsModifier *stats = new StatsModifier (m_bourrin, this);
    connect(stats, SIGNAL(truc()), this, SLOT(update()));
    stats->exec();
    this->updateGui();
}

void MainWindow::on_combatButton_clicked()
{
    QVector <Heros*> personnages;
    personnages.push_back(&m_bourrin);
    personnages.push_back(&m_healer);
    personnages.push_back(&m_archer);
    personnages.push_back(&m_assassin);
    personnages.push_back(&m_mage);
    personnages.push_back(&m_shaman);

    Combat* combatWindows = new Combat(personnages,&m_presets,&m_presetsColor);
    combatWindows->show();
}
