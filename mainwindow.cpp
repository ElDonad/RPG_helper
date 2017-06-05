#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_bourrin(),
    Mage()
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
    int truc = 1;
    if (truc == 1)
     {   
        QVector <Attaque> test31Attaques;
        test31Attaques.push_back(Attaque());
        QString truc311Name = "truc31";
        QObject *parent = 0;
        Personnage truc31 (119,120,0,0,truc311Name, 1,0.2,0.15,0.12,95,5,test31Attaques, parent);
        truc31Path = path + "/test31.txt";
        truc31.save(truc31Path);
    }
    //on est donc après avoir trouvé le chemin. Pour l'instant je garde les chemins relatifs.

    Personnage test31(truc31Path);
    m_bourrin.rewrite(m_mainPath + "/test31.txt");


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
    Combat* combatWindows = new Combat(personnages);
    combatWindows->show();
}
