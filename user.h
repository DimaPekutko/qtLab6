#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(QString name, long int number);
    QString getName();
    long int getNumber();
private:
    QString name;
    long int number;
};

#endif // USER_H
