#include "Inventory.h"

Inventory inventory;

void Inventory::upType(){
if(activType != typesObjects.size() - 1)
    activType++;
else
    activType = 0;
}

void Inventory::downType() {
    if(activType != 0)
        activType--;
    else
        activType = typesObjects.size() - 1;
}

Object Inventory::getBloc() {
    return Object(activType, rotation, сondition, std::array<uint8_t, 4>());
}

void Inventory::upRotation() {
    if (rotation == 3)
        rotation = 0;
    else
        rotation++;
}
