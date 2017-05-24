#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <heros.h>
#include <QWidget>
#include <savetools.h>
#include <combat.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QString path,QWidget *parent = 0);
    ~MainWindow();
    void setWidgetUi(int idPerso, int widget, QString newValue);
    void saveMain(QString path);

private:
    Ui::MainWindow *ui;
    //Heros pierrot();



private :
    //groupes de widget par perso
    Heros Bourrin;
    Heros Mage;


    //Path principal (au besoin, je cherche pourquoi les path relatifs ne marchent pas
    QString m_mainPath;

    int m_gold;




private slots:
    void on_testButton_clicked();
    void on_pushButton_2_clicked();
    void on_save_clicked();
    void on_pushValidateGold_clicked();
};

#endif // MAINWINDOW_H
