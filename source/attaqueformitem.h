#ifndef ATTAQUEFORMITEM_H
#define ATTAQUEFORMITEM_H

#include <QString>

#include <QWidget>
#include <QGridLayout>


class AttaqueFormItem
{
public:
    QString getLabel();
    virtual QWidget* getWidget(QGridLayout layout, int value)=0;


private:
    QString m_label;

};

#endif // ATTAQUEFORMITEM_H
