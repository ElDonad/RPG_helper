#ifndef ATTAQUEFORM_H
#define ATTAQUEFORM_H

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <attaqueformitem.h>
#include <checkboxattaqueformitem.h>
#include <doublespinboxattaqueformitem.h>
#include <intspinboxattaqueformitem.h>
#include <lineeditattaqueformitem.h>
#include <radioboxattaqueformitem.h>

#include <QVector>
#include <QString>
#include <QBoxLayout>
#include <QDebug>

#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVector>

class AttaqueFormItem;
class CheckBoxAttaqueFormItem;
class DoubleSpinBoxAttaqueFormItem;
class IntSpinBoxAttaqueFormItem;
class LineEditAttaqueFormItem;
class RadioBoxAttaqueFormItem;


class AttaqueForm : public QWidget
{
    Q_OBJECT

public:
    explicit AttaqueForm(QVector<AttaqueFormItem *> formItems, QString name="Formulaire Attaque",QWidget *parent = 0);

/* Comment doit marcher le système de génération procédrale :
 * - un vector de QWidget qu'on peut caster avec dynamic_cast contient l'ensemble des widgets affichés
 * - Les informations sont retournées et données par un formitem. à chaque qidget correspond une fonction ici.
 * */
    void addCheckBoxItem(QString label, CheckBoxAttaqueFormItem * retour, bool defaultValue = false);
    //void addRadioBoxItem(QString label, RadioBoxAttaqueFormItem *retour, QVector<QString> radio, int defaultValue = 0);
    void addIntSpinBoxItem(QString label, IntSpinBoxAttaqueFormItem *retour,int min = 0, int max = 100, int defaultValue = 0);
    void addDoubleSpinBoxItem(QString label, DoubleSpinBoxAttaqueFormItem *retour, double min = 0, double max = 100, double defaultValue = 0);
    void addLabel(QString label);
    void addLineEdit(QString label, LineEditAttaqueFormItem* retour, QString defaultValue = "");
    void processUi();
    void execute();

public slots:
    void onOkPressed();

private:
    QDialog m_form;
    QGridLayout* m_mainLayout;
    QVector <QWidget*> m_widgets;
    QVector <AttaqueFormItem*> m_formItems;
    int m_itemNumber;
    QPushButton* m_pushButton;
};

#endif // ATTAQUEFORM_H
