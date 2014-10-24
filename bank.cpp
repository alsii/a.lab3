#include <bank.h>
#include <QString>

//конструкторы

bank::bank()
{
    dd = 0;
    mm = 0;
    yy = 0;
    sum = 0.0;
    receiver = ' ';
    sender = ' ';
}

bank::bank(int date, int mounth, int year, int summa, QString send , QString rec)
{
    dd = date;
    mm = mounth;
    yy = year;
    sum = summa;
    receiver = rec;
    sender = send;
}

bank::~bank()
{

}

//модификаторы
void bank::setDD(int a)
{
       dd = a;
}

void bank::setMM(int a)
{
       mm = a;
}

void bank::setYY(int a)
{
       yy = a;
}

void bank::setSum(int a)
{
    if(a > 0.0)
        sum = a;
}


Arr::Arr()
{
    buf[0].setDD(0);
    size = 0;
}


void Arr::addNew(bank newElem)
{
    buf[size++] = newElem;
    sum += newElem.getSum();
}

void Arr::print ()
{

}

bank Arr::getCurrentElement()
{
    if(size > 0)
        return buf[size - 1];
}
