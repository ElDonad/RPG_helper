#ifndef ATTAQUEFORM_H
#define ATTAQUEFORM_H

#include <QObject>
#include <QWidget>

#include <attaqueformitem.h>
#include <QVector>
#include <QString>
#include <QBoxLayout>

#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>

class AttaqueForm
{
public:
    AttaqueForm(QVector<AttaqueFormItem *> formItems, QString name="Formulaire Attaque");

private:
    QWidget m_form;
    QGridLayout m_mainLayout();
    QVector <QWidget> widgets;
    QVector <AttaqueFormItem*> m_formItems;
};

#endif // ATTAQUEFORM_H
