#ifndef INTSPINBOXATTAQUEFORMITEM_H
#define INTSPINBOXATTAQUEFORMITEM_H

#include <attaqueformitem.h>

class AttaqueForm;
class IntSpinBoxAttaqueFormItem : public AttaqueFormItem
{
public:
    IntSpinBoxAttaqueFormItem(AttaqueForm *cible, QString label, int *toReturn, int defaultValue = 0, int min = 0, int max = 100);
    virtual void registerFormItem();
    virtual void returnValues(int values);

private:
    int m_defaultValue;
    int *m_toReturn;
    QString m_label;
    int m_min;
    int m_max;


};

#endif // INTSPINBOXATTAQUEFORMITEM_H
