#include "attaqueform.h"

AttaqueForm::AttaqueForm(QVector<AttaqueFormItem*> formItems, QString name,QWidget *parent): m_form()
{

    m_mainLayout = new QGridLayout();
    m_form.setWindowTitle(name);
    m_formItems = formItems;
    m_itemNumber = 0;

    //processUi();

}

void AttaqueForm::addCheckBoxItem(QString label, CheckBoxAttaqueFormItem* retour, bool defaultValue)
{
    QCheckBox* checkBox = new QCheckBox (label);
    checkBox->setChecked(defaultValue);
    m_formItems.push_back(retour);
    m_widgets.push_back(checkBox);
    m_mainLayout->addWidget(m_widgets[m_itemNumber],m_itemNumber,1,1,2);
    m_itemNumber++;


}

void AttaqueForm::addDoubleSpinBoxItem(QString label, DoubleSpinBoxAttaqueFormItem *retour, double min, double max, double defaultValue)
{
    QDoubleSpinBox* doubleSpinBox = new QDoubleSpinBox();
    doubleSpinBox->setValue(defaultValue);
    QLabel *qlabel = new QLabel(label);
    m_widgets.push_back(doubleSpinBox);
    m_formItems.push_back(retour);
    m_mainLayout->addWidget(m_widgets[m_itemNumber],m_itemNumber,2);
    m_mainLayout->addWidget(qlabel,m_itemNumber,1);
    m_itemNumber++;
}

void AttaqueForm::addIntSpinBoxItem(QString label, IntSpinBoxAttaqueFormItem *retour, int min, int max, int defaultValue)
{
    QSpinBox* intSpinBox = new QSpinBox;
    intSpinBox->setValue(defaultValue);
    QLabel *qlabel = new QLabel(label);
    m_widgets.push_back(intSpinBox);
    m_formItems.push_back(retour);
    m_mainLayout->addWidget(m_widgets[m_itemNumber],m_itemNumber,2);
    m_mainLayout->addWidget(qlabel,m_itemNumber,1);
    m_itemNumber++;

}

void AttaqueForm::addLabel(QString label)
{
    QLabel *qlabel = new QLabel(label);
    m_mainLayout->addWidget(dynamic_cast<QWidget*>(qlabel),m_itemNumber,1,1,2);
    m_itemNumber++;

}

void AttaqueForm::addLineEdit(QString label, LineEditAttaqueFormItem *retour, QString defaultValue)
{
    QLabel *qlabel = new QLabel(label);
    QLineEdit *lineEdit = new QLineEdit(defaultValue);
    m_widgets.push_back(lineEdit);
    m_formItems.push_back(retour);
    m_mainLayout->addWidget(m_widgets[m_itemNumber],m_itemNumber,1);
    m_mainLayout->addWidget(qlabel,m_itemNumber + 1,2);
    m_itemNumber++;
}

//void AttaqueForm::addRadioBoxItem(QString label, RadioBoxAttaqueFormItem *retour,QVector<QString>radio, int defaultValue)
//{
//    QGroupBox *group = new QGroupBox(label);
//    QVBoxLayout *box = new QVBoxLayout();
//    group->setLayout(box);
//    box

//}

void AttaqueForm::processUi()
{
    for (int i=0; i==m_widgets.count(); i++)
    {
        switch (m_formItems[i]->getType()) {
        case AttaqueFormItem::CheckBoxItem:
        {
            CheckBoxAttaqueFormItem *process = dynamic_cast <CheckBoxAttaqueFormItem*>(m_formItems[i]);
            QCheckBox *finalWidget = dynamic_cast <QCheckBox*> (m_widgets[i]);
            process->returnValues(finalWidget->isChecked());
            break;
        }

        case AttaqueFormItem::DoubleSpinBoxItem:
        {
            DoubleSpinBoxAttaqueFormItem *process = dynamic_cast <DoubleSpinBoxAttaqueFormItem*> (m_formItems[i]);
            QDoubleSpinBox *finalWidget = dynamic_cast <QDoubleSpinBox*> (m_widgets[i]);
            process->returnValues(finalWidget->value());
            break;
        }
        case AttaqueFormItem::IntSpinBoxItem:
        {
            IntSpinBoxAttaqueFormItem *process = dynamic_cast <IntSpinBoxAttaqueFormItem*> (m_formItems[i]);
            QSpinBox *finalWidget = dynamic_cast <QSpinBox*> (m_widgets[i]);
            process->returnValues(finalWidget->value());
            break;
        }
        case AttaqueFormItem::LineEdit:
        {
            LineEditAttaqueFormItem *process = dynamic_cast <LineEditAttaqueFormItem*> (m_formItems[i]);
            QLineEdit *finalWidget = dynamic_cast <QLineEdit*> (m_widgets[i]);
            process->returnValues(finalWidget->text());
        }
        default:
            break;
        }
    }
}

void AttaqueForm::execute()
{
    QPushButton *button = new QPushButton("Valider");
    m_pushButton = button;
    m_mainLayout->addWidget(button, m_itemNumber,1,1,2);
    m_form.setLayout(m_mainLayout);
    connect(m_pushButton,SIGNAL(pressed()),this,SLOT(onOkPressed()));
    m_form.exec();
}

void AttaqueForm::onOkPressed()
{
    qDebug()<<"onOkPressed";
    processUi();
    m_form.close();
}


