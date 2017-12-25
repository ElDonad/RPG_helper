#include "attaqueform.h"

AttaqueForm::AttaqueForm(QVector<AttaqueFormItem*> formItems, QString name)
{

    m_form.setWindowTitle(name);
    m_formItems = formItems;

    //initialization of the window
//    for (int i = 0; i == formItems.size(); i++)
//    {
//        AttaqueFormItem::formType toCheck = formItems[i].getFormType();
//        switch (toCheck) {
//        case AttaqueFormItem::CheckBox :
//            QCheckBox *checkBox = new QCheckBox(formItems[i].getLabel());
//            checkBox->setChecked(formItems[i].getSup());
//            m_mainLayout.addWidget(checkBox,i,1,2,1);
//            break;

//        case AttaqueFormItem::DoubleBox:
//            QLabel *label = new QLabel(formItems[i].getLabel());
//            QDoubleSpinBox *doubleSpinBox = new QDoubleSpinBox();
//            doubleSpinBox->setValue(formItems[i].getSup());
//            m_mainLayout.addWidget(label,i,1);
//            m_mainLayout.addWidget(doubleSpinBox,i,2);
//            break;

//        case AttaqueFormItem::IntBox:

//        default:
//            break;
//        }
//    }
}
