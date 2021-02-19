#include <QCoreApplication>
#include <QHash>


class CIpAddr
{
public:
        inline explicit CIpAddr(QString ip):
            m_ip(ip)
        {}

        bool operator==(const CIpAddr &key) const
        {
            return m_ip == key.m_ip;
        }

        inline const QString& getIp() const {return m_ip;}

private:
        QString m_ip;
};

inline size_t qHash(const CIpAddr &key, uint seed = 0)
{
    if (key.getIp().isEmpty())
        return seed;
    else
        return qHash(key.getIp(), seed);
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<CIpAddr, QString> hash;
    hash.insert(CIpAddr("127.0.0.1"), "localhost");
    hash.insert(CIpAddr("234.0.0.1"), "host1");
    hash.insert(CIpAddr("168.0.0.1"), "host2");
    hash.insert(CIpAddr("167.0.0.1"), "host3");
    hash.insert(CIpAddr("146.0.0.1"), "host4");


    qDebug() << hash[CIpAddr("127.0.0.1")];

    return a.exec();
}
