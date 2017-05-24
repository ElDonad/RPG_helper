#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_gold = 5000;


    QString gold = QString::number(m_gold);
    QString textGold = "Gold total : " + gold;

    ui->goldCount->setText(textGold);





}

MainWindow::MainWindow(QString path, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Personnages
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
    Combat* combatWindows = new Combat();
    combatWindows->show();

}


void MainWindow::on_save_clicked()
{
    saveMain("C:\\Users\\Elie\\Documents\\build-RPG_Marin-Desktop_Qt_5_8_0_MinGW_32bit-Debug\\debug\\save\\main.txt");
}

void MainWindow::saveMain(QString path)
{
    QVector <QString> saveVector;

    QString saveGold = QString::number(m_gold);
    saveVector.push_back(saveGold);
    saveFile(saveVector, path);

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
