#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human: public QObject
{
    Q_OBJECT
public:
    Human(quint32 age, char sex, QObject *parent = Q_NULLPTR);
    ~Human();

    quint32 age() const { return m_age; }
    char sex() const { return m_sex; }

private:
    quint32 m_age = 0u;
    char m_sex = 'm';
};

#endif // HUMAN_H
