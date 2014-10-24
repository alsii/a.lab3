#ifndef BANK_H
#define BANK_H

#include <QString>

class bank
{
private:
    int dd, mm, yy;
    int sum;
    QString receiver, sender;
public:
    //������������
    bank();
    bank(int date, int mounth, int year, int summa, QString send, QString rec);
    ~bank();

    //������������
    void setDD(int a);
    void setMM(int a);
    void setYY(int a);
    void setSum(int a);
    void setReceiver(QString a) {receiver = a;}
    void setSender(QString a) {sender = a;}

    //���������
    int getDD() {return dd;}
    int getMM() {return mm;}
    int getYY() {return yy;}
    int getSum() {return sum;}
    QString getReceiver() {return receiver;}
    QString getSender() {return sender;}
 };


class Arr
    {
    private:
        int size;
        bank buf[30];
        float sum;
    public:
            Arr();

            void addNew(bank newElem);
            float total();
            void print();

            float   getSum () { return sum; };

            void setSum (int sum_in) { sum = sum_in; };

            // ��� ������� � ��������� ������� - ���������� ��������� ����������� �������
            bank getCurrentElement();
    };

#endif // BANK_H
