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
    QString truc31Path;
    QVector <QString> mainSave = getFile (path + "/saveMain.txt"); //le fichier principal doit contenir la première ligne 1 (0   au début)
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
        bourrinAttaques.push_back(new Attaque(75,bourrinName,0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects, 101,1));//SPECIAL : désactive l'état défense du bourrin pendant le reste du tour
        bourrinAttaques.push_back(new Attaque(50,"Smash",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,102,1));
        bourrinAttaques.push_back(new Attaque(60,"Bonk",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,103,1));//10% chance de faire du stun
        bourrinAttaques.push_back(new Attaque(0,"Heal",0.1,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,104,1));//!! vérifier heal en pourcentages
        bourrinAttaques.push_back(new Attaque(0,"Proteccio",0,0,1,0,0,0,0,0.4,0,0,0,blankEffects,blankEffects,blankEffects,105,1));//voir suites.txt
        bourrinAttaques.push_back(new Attaque(70,"Pirouette",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,106,2));
        bourrinAttaques.push_back(new Attaque(30,"Tremblement De Terre",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,107,3));
        bourrinAttaques.push_back(new Attaque(0, "Shield",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,108,4));
        bourrinAttaques.push_back(new Attaque(100,"Bourrin 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,109,5));//10% chance de stun
        bourrinAttaques.push_back(new Attaque(0,"Proteccio 2",0,0,1,0,0,0,0,0.6,0,0,0,blankEffects,blankEffects,blankEffects,110,5));//comme proteccio 1
        bourrinAttaques.push_back(new Attaque(80,"Smash 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,111,6));
        bourrinAttaques.push_back(new Attaque(85,"Bonk 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,112,7));//20% de stun
        bourrinAttaques.push_back(new Attaque(110,"Pirouette 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,113,8));
        bourrinAttaques.push_back(new Attaque(0,"Shield 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,114,9));//4* les PV du bourrin
        bourrinAttaques.push_back(new Attaque(130,"Bourrin 3",0,0,2,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,115,10));//30% stun
        
        m_bourrin.rewrite(200,200,0,0,"Bourrin",1,(0.4),(1.5),0,45,(-45),bourrinAttaques);

        //assassin
        QVector <Attaque*> assassinAttaques;

        assassinAttaques.push_back(new Attaque(70,"Traître",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,201,1));
        assassinAttaques.push_back(new Attaque(60,"Dash",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,202,1));
        assassinAttaques.push_back(new Attaque(50,"Double lame",0,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,203,1));
        assassinAttaques.push_back(new Attaque(0,"Invisi",0,20,1,0,0,0,0,0,0,35,0,blankEffects,blankEffects,blankEffects,204,1));
        assassinAttaques.push_back(new Attaque(0,"Mana Heal",0,10,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,205,1));//régen 50 mana pour toute l'équipe, marin devra cibler tout le monde
        assassinAttaques.push_back(new Attaque(45,"Tir",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,206,2));
        assassinAttaques.push_back(new Attaque(0,"Empoisonnement",0,20,4,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,207,4));//voir suites.txt pour les particularités
        assassinAttaques.push_back(new Attaque(90,"Dash 2",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,208,5));
        assassinAttaques.push_back(new Attaque(70,"Tir 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,209,6));
        assassinAttaques.push_back(new Attaque(0,"Mana heal 2",0,20,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,210,7));//même chose que mana heal 1 : 100 MP heal
        assassinAttaques.push_back(new Attaque(80,"Double lame 2",0,50,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,211,8));
        assassinAttaques.push_back(new Attaque(105,"Traître 2",0,35,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,212,9));
        assassinAttaques.push_back(new Attaque(0,"Invisi 2",0,35,3,0,0,0,0,0,0,55,0,blankEffects,blankEffects,blankEffects,213,10));

        m_assassin.rewrite(140,140,70,70,"Assassin",1,0.2,1.5,0,45,(-45),assassinAttaques);

        //mage
        QVector <Attaque*> mageAttaques;

        mageAttaques.push_back(new Attaque(35,"Entouré",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,301,1));
        mageAttaques.push_back(new Attaque(45,"Cercle divin",0,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,302,1));
        mageAttaques.push_back(new Attaque(40,"Foudre",0,25,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,303,1));//baisse de 5pts de mana pendant trois tours


        QVector <int> mageAttaqueSDF;
        mageAttaqueSDF.push_back(2);
        mageAttaqueSDF.push_back(0);
        mageAttaqueSDF.push_back(0);
        mageAttaqueSDF.push_back(0);

        QVector <int> mageLuckSDF;
        mageLuckSDF.push_back(100);
        mageLuckSDF.push_back(0);
        mageLuckSDF.push_back(0);
        mageLuckSDF.push_back(0);

        QVector <int> fullLuck;
        fullLuck.push_back(100);
        fullLuck.push_back(100);
        fullLuck.push_back(100);
        fullLuck.push_back(100);

        mageAttaques.push_back(new Attaque(50,"SDF",0,20,2,0,0,0,0,0,0,0,0,mageAttaqueSDF,mageLuckSDF,blankEffects,304,1));
        mageAttaques.push_back(new Attaque(0,"Heal",0.1,15,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,305,1));
        mageAttaques.push_back(new Attaque(0,"/effect",0,15,6,0,0,0,0,0,0,0,0,blankEffects,mageLuckSDF,blankEffects,306,2));
        mageAttaques.push_back(new Attaque(0,"Mana Power",0,20,3,0,1.3,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,307,3));

        QVector <int> mageEffectSDF2;
        mageEffectSDF2.push_back(4);
        mageEffectSDF2.push_back(0);
        mageEffectSDF2.push_back(0);
        mageEffectSDF2.push_back(0);

        mageAttaques.push_back(new Attaque(65,"SDF 2",0,50,4,1,0,0,0,0,0,0,0,mageEffectSDF2,mageLuckSDF,blankEffects,308,4));
        mageAttaques.push_back(new Attaque(60,"Entouré 2",0,0,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,309,5));
        mageAttaques.push_back(new Attaque(0,"Heal 2",0.35,30,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,310,6));
        mageAttaques.push_back(new Attaque(65,"Foudre 2",0,50,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,311,7));
        mageAttaques.push_back(new Attaque(0,"Mana power 2,",0,30,5,0,1.5,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,312,8));
        mageAttaques.push_back(new Attaque(60,"Cercle divin 2",0,60,1,0,0,0,0,0,0,0,0,blankEffects,blankEffects,blankEffects,313,9));

        QVector <int> mageEffectSDF3;
        mageEffectSDF3.push_back(7);
        mageEffectSDF3.push_back(0);
        mageEffectSDF3.push_back(0);
        mageEffectSDF3.push_back(0);

        mageAttaques.push_back(new Attaque(110,"SDF 3",0,100,7,2,0,0,0,0,0,0,0,mageEffectSDF3,mageLuckSDF,blankEffects,314,10));

        m_mage.rewrite(100,100,100,100,"Mage",1,0.2,1.5,0,45,(-45),mageAttaques);




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
    Combat* combatWindows = new Combat(personnages);
    combatWindows->show();

}


void MainWindow::on_save_clicked()
{
    saveMain(m_mainPath);
}

void MainWindow::saveMain(QString path)
{
    QVector <QString> saveVector;

    QString saveGold = QString::number(m_gold);
    saveVector.push_back(saveGold);
    saveFile(saveVector, path);

    m_bourrin.save(m_mainPath + "/test31.txt");//changer quand il y aura le tableau


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
    this->saveMain(m_mainPath);

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

    Combat* combatWindows = new Combat(personnages);
    combatWindows->show();
}
