#ifndef LIGHT_H
#define LIGHT_H

enum ind {green, yellow, red, flashyel};

class TrLight{
    ind curr;
    public:
        TrLight();
        void flash();
        void curColor();
        void work();
        void changeColor(char);
};

#endif //LIGHT_H
