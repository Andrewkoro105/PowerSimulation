#include "Copying.h"

Copying::Copying(sf::Vector2i startPosition, sf::Vector2i endPosition, World& world) : world(world) {
    if (startPosition.x > endPosition.x){
        cornerH = CornerHorizon::Right;
    } else{
        cornerH = CornerHorizon::Left;
    }
    if (startPosition.y > endPosition.y) {
        cornerV = CornerVertical::Top;
    } else{
        cornerV = CornerVertical::Down;
    }
    for (int x = startPosition.x, x1 = 0; cornerH? (x <= endPosition.x) : (x >= endPosition.x); ( cornerH ? ++x : --x), ++x1) {
        cells.push_back({});
        for (int y = startPosition.y; cornerV? (y <= endPosition.y) : (y >= endPosition.y); cornerV ? ++y : --y) {
            cells[x1].push_back(world.getObject({x, y}));
        }
    }
}

void Copying::paste(sf::Vector2i position) {
    for (int x = 0 ; x < cells.size(); ++x) {
        for (int y = 0; y < cells[0].size(); ++y) {
            world.setObject(cells[x][y], {cornerH ? (position.x + x) : (position.x - x), cornerV ? (position.y + y) : (position.y - y)});
        }
    }
}