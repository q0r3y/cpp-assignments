#ifndef DIE_H
#define DIE_H

class Die {
private:
    int dieType;
    int dieValue;
public:
    Die(int dieType);
    void setDieType(int dieType);
    int getDieType();
    void setDieValue(int dieValue);
    int getDieValue();
    int rollDie();
};

#endif
