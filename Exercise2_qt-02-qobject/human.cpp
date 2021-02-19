#include "human.h"
#include <QDebug>

Human::Human(quint32 age, char sex, QObject *parent)
    :QObject(parent)
    , m_age(age)
    , m_sex(sex)
{
}

Human::~Human()
{
   qDebug() << objectName() << " destroyed";
}
