#include "type_changes.h"

Container toInt(Container container){
    if (container.label == 1)
    {
        container.label = 2;
        container.type.numI = container.type.numD;
    }
    else if (container.label == 3)
    {
        container.label = 2;
        container.type.numI = container.type.car;
    }
    return container;
}

Container toDouble(Container container){
    if (container.label == 2)
    {
        container.label = 1;
        container.type.numD = container.type.numI;
    }
    if (container.label == 3)
    {
        container.label = 1;
        container.type.numD = container.type.car;
    }
    return container;
}

Container toChar(Container container){
    if (container.label == 1)
    {
        int x = container.type.numD;
        container.label = 3;
        container.type.car = x;
    }
    if (container.label == 2)
    {
        container.label = 3;
        container.type.car = container.type.numI;
    }
    return container;
}

void fill(Container *vars){
    vars[0].label = 2;
    vars[0].type.numI = 10;
    vars[1].label = 2;
    vars[1].type.numI = 11;
    vars[2].label = 2;
    vars[2].type.numI = 12;
    vars[3].label = 2;
    vars[3].type.numI = 13;
    vars[4].label = 2;
    vars[4].type.numI = 14;
    vars[5].label = 2;
    vars[5].type.numI = 15;
    vars[13].label = 3;
    vars[13].type.car = '\n';
    vars[18].label = 3;
    vars[18].type.car = ' ';
    vars[23].label = 2;
    vars[23].type.numI = 0;
    vars[24].label = 2;
    vars[24].type.numI = 1;
    vars[25].label = 2;
    vars[25].type.numI = 2;
}

int comparaCont(Container x, Container y){
    if(x.label != 3 && y.label != 3)
    {
        x = toDouble(x);
        y = toDouble(y);
        if (x.type.numD == y.type.numD) return 1;
        else if (x.type.numD > y.type.numD) return 2;
        else return 3;
    }
    else
    {
        x = toChar(x);
        y = toChar(y);
        if (x.type.car == y.type.car) return 1;
        else return 0;
    }
}

int isZero(Container container){
    if (container.label == 1) return (container.type.numD != 0);
    else if (container.label == 2) return (container.type.numI != 0);
    return 0;
}