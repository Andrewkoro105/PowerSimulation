#pragma  once
#include "bloks/Type.h"
#include "bloks/Object.h"

extern class Inventory {
    int activType = 1;
    uint8_t rotation = 0;
    uint8_t сondition = 0;
public:
    Object getBloc();
    void upType();
    void downType();
    void upRotation();
}inventory;