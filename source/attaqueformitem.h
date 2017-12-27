#ifndef ATTAQUEFORMITEM_H
#define ATTAQUEFORMITEM_H

//#include <attaqueform.h>
#include <QString>

class AttaqueForm;
class AttaqueFormItem
{
public:
    enum itemType {CheckBoxItem, IntSpinBoxItem, DoubleSpinBoxItem, RadioBoxItem, Label, LineEdit};
    virtual void registerFormItem()=0;
    //virtual void returnValues()=0;
    virtual itemType getType();
    virtual void resetCible(AttaqueForm* cible);


protected:
    itemType m_itemType;
    AttaqueForm *m_cible;
};

#endif // ATTAQUEFORMITEM_H
