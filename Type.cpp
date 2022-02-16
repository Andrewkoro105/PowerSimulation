#include <iostream>
#include "Type.h"

TypeObject typesObjects[]{
    {//air
        {sf::IntRect(0, 0, 100, 100)},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1}
    }
};

TypeObject::TypeObject(std::vector<sf::IntRect> rectTexture, TypeObject::Power powerIN, TypeObject::Power powerOut,TypeObject::Static _static) {

    textures.resize(-_static.active + 2);

    if(rectTexture.size() == -_static.active + 2)
        for (int i = 0; i < rectTexture.size(); ++i)
            textures[i].loadFromFile(pathMiltiTexture, rectTexture[i]);
    else if(rectTexture.size() > -_static.active + 2)
    {
        textures[0].loadFromFile(pathMiltiTexture, rectTexture[0]);
        std::cout << "you can't use more than one textures as you have active - static\n";
    }
    else if (rectTexture.size() < -_static.active + 2)
    {
        textures[0].loadFromFile(pathMiltiTexture, rectTexture[0]);
        textures[1].loadFromFile(pathMiltiTexture, rectTexture[0]);
        std::cout << "you did not set a textures for one of the states\n";
    }
}
