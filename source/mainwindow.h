#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <heros.h>
#include <QWidget>
#include <savetools.h>
#include <combat.h>
#include <attaque.h>
#include <QFileDialog>
#include <statsmodifier.h>

//attaques spéciales :
#include <attaquefeuglace.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setWidgetUi(int idPerso, int widget, QString newValue);
    void saveMain();
    void updateGui();
    

private:
    Ui::MainWindow *ui;
    //Heros pierrot();



private :
    //groupes de widget par perso
    Heros m_bourrin;
    Heros m_mage;
    Heros m_assassin;
    Heros m_healer;
    Heros m_shaman;
    Heros m_archer;
    QVector <Personnage> m_presets;
    QVector <QColor> m_presetsColor;


    //Path principal (au besoin, je cherche pourquoi les path relatifs ne marchent pas
    QString m_mainPath;

    int m_gold;




private slots:
    void on_testButton_clicked();
    void on_pushButton_2_clicked();
    void on_save_clicked();
    void on_pushValidateGold_clicked();
    void onClose();
    void on_statsButton_2_clicked();
    void on_combatButton_clicked();
};

#endif // MAINWINDOW_H
