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