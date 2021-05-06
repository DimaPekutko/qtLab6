#include "user.h"

User::User(QString name, long int number)
{
    this->name = name;
    this->number = number;
}

QString User::getName() {
    return name;
}

long int User::getNumber() {
    return number;
}
