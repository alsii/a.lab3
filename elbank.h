#ifndef ELBANK_H
#define ELBANK_H

class elbank: public bank
{
private:
    bool electr;
public:
    elbank();
    ~elbank();

    //модификаторы

    virtual void setelectr (bool a) {electr = a;}

    //селекторы

    virtual bool getelectr() {return electr;}

    //операторы
    elbank* operator=( elbank &a);
};



#endif // ELBANK_H
