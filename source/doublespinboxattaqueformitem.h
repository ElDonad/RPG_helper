#ifndef DOUBLESPINBOXATTAQUEFORMITEM_H
#define DOUBLESPINBOXATTAQUEFORMITEM_H

#include <attaqueformitem.h>

//class AttaqueForm;
class DoubleSpinBoxAttaqueFormItem : public AttaqueFormItem
{
public:
    DoubleSpinBoxAttaqueFormItem(AttaqueForm *cible, QString label, double *toReturn, double defaultValue = 0, double min = 0, double max = 100);
    virtual void registerFormItem();
    virtual void returnValues(double value);

private:
    double m_defaultValue;
    double *m_toReturn;
    QString m_label;
    double m_min;
    double m_max;

};

#endif // DOUBLESPINBOXATTAQUEFORMITEM_H
