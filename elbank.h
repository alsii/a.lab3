#ifndef ELBANK_H
#define ELBANK_H

class elbank: public bank
{
private:
    bool electr;
public:
    elbank();
    ~elbank();

    //������������

    virtual void setelectr (bool a) {electr = a;}

    //���������

    virtual bool getelectr() {return electr;}

    //���������
    elbank* operator=( elbank &a);
};



#endif // ELBANK_H
