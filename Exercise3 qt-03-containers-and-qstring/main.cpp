#include <QCoreApplication>
#include <QDebug>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    QListIterator<QString> i(names);
    QString longestName = "";
    while (i.hasNext())
    {
        auto cur = i.next();
        if(cur.length() > longestName.length())
           longestName = cur;
    }
    QString output("Longest name: %1");
    qDebug() << output.arg(longestName);

    QList<QString>::const_iterator iterator = names.cbegin();
    QString shortestName = *(iterator++);
    for(; iterator != names.cend(); ++iterator )
    {
        auto cur = *iterator;
        if(cur.length() < shortestName.length())
           shortestName = cur;
    }
    qDebug() << shortestName.prepend("Shortest name: ");

    QString strFinal;
    foreach (const QString& str, names)
    {
        if(str.endsWith("lynn"))
            strFinal += str + ",";
    }
    qDebug() << strFinal;

    foreach (const QString& str, names)
    {
        if(str.endsWith("lynn"))
            strFinal += str + ",";
    }

    QStack<QString> stack;
    for(const auto& item: names)
        stack.push(item);
    while(stack.size())
        qDebug() << stack.pop();



    return a.exec();
}
