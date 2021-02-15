#include <QCoreApplication>
#include <QDebug>
#include "human.h"

void printTreeInfo(QObject *parent)
{
    Human* pHuman = qobject_cast<Human*>(parent);
    qDebug() << parent->objectName() << pHuman->age() << pHuman->sex();

    const QObjectList children = parent->children();
    for(qsizetype i = 0; i < children.size(); ++i)
    {
        qDebug() << " has the following children: ";
        printTreeInfo(children.at(i));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* parent = new Human(54, 'm');
    parent->setObjectName("Lucas Grey");

    Human* child1 = new Human(28, 'f', parent);
    child1->setObjectName("Mary Grey");

    Human* child12 = new Human(2, 'm', child1);
    child12->setObjectName("Fred Smith");
    Human* child11 = new Human(2, 'f', child1);
    child11->setObjectName("Jane Smith");


    Human* child2 = new Human(32, 'm', parent);
    child2->setObjectName("Jason Grey");

    Human* child21 = new Human(5, 'm', child2);
    child21->setObjectName("Sean Grey");
    Human* child22 = new Human(1, 'f', child2);
    child22->setObjectName("Jessica Grey");
    Human* child23 = new Human(1, 'f', child2);
    child23->setObjectName("Hannah Grey");

	
    printTreeInfo(parent);

    qDebug() << " via dump method :";
    parent->dumpObjectTree();

    delete parent;

    return a.exec();
}
