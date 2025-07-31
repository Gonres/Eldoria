//
// Created by ivo on 11/16/2024.
//

#include "map.h"
#include <cassert>
#include <iostream>

Map::Map(const unsigned int mapHeight, const unsigned int mapWidth, const DoorPosition doorPosition)
    : fullMap(mapHeight * mapWidth, Tile::createTile('.')) {
    this->mapHeight = mapHeight;
    this->mapWidth = mapWidth;
    this->doorPosition = doorPosition;
}

void Map::putCharacterInPosition(const Position position, const char character) {
    // Ensure the position is within the bounds of the map
    assert(("Character is not within the bounds of the map",
        position.y > 0 && position.y < mapHeight && position.x > 0 && position.x < mapWidth));
    fullMap[position.y * mapWidth + position.x] = Tile::createTile(character);
}

// Get position of a single tile
char Map::assignTilePosition(const Position position) const {
    return fullMap[position.y * mapWidth + position.x]->getTile();
}

void Map::printMap() {
    for (unsigned int y = 0; y < mapHeight; y++) {
        for (unsigned int x = 0; x < mapWidth; x++) {
            if (y == 0 || y == mapHeight - 1 || x == 0 || x == mapWidth - 1) {
                fullMap[y * mapWidth + x] = Tile::createTile('#'); // Border character
                putDoor(x, y);
            }
            std::cout << assignTilePosition(Position(x, y));
        }
        std::cout << '\n';
    }
}

std::vector<Tile *> Map::getFullMap() {
    return fullMap;
}

void Map::putDoor(const unsigned int x, const unsigned int y) {
    // Middle of the vertical borders
    const unsigned int middleRow = mapHeight / 2;
    // Middle of the horizontal borders
    const unsigned int middleCol = mapWidth / 2;

    switch (doorPosition) {
        case DoorPosition::leftDoor:
            if (y == middleRow) {
                fullMap[y * mapWidth] = Tile::createTile('|');
            }
            break;
        case DoorPosition::rightDoor:
            if (y == middleRow) {
                fullMap[y * mapWidth + (mapWidth - 1)] = Tile::createTile('|');
            }
            break;
        case DoorPosition::topDoor:
            if (x == middleCol) {
                fullMap[x] = Tile::createTile('|');
            }
            break;
        case DoorPosition::bottomDoor:
            if (x == middleCol) {
                fullMap[(mapHeight - 1) * mapWidth + x] = Tile::createTile('|');
            }
            break;
    }
}

Position Map::getStartingPosition(const DoorPosition doorPosition) const {
    switch (doorPosition) {
        case DoorPosition::bottomDoor:
            assert(("Door should not be placed on the same side which player walked from",
                doorPosition != DoorPosition::topDoor));
        // Enter on the top of the new map
            return Position{mapWidth / 2, 1};
        case DoorPosition::topDoor:
            assert(("Door should not be placed on the same side which player walked from",
                doorPosition != DoorPosition::bottomDoor));
        // Enter on the bottom
            return Position{mapWidth / 2, mapHeight - 2};
        case DoorPosition::rightDoor:
            assert(("Door should not be placed on the same side which player walked from",
                doorPosition != DoorPosition::leftDoor));
        // Enter on the left side
            return Position{1, mapHeight / 2};
        case DoorPosition::leftDoor:
            assert(("Door should not be placed on the same side which player walked from",
                doorPosition != DoorPosition::rightDoor));
        // Enter on the right side
            return Position{mapWidth - 2, mapHeight / 2};
        default:
            return Position{1, 1};
    }
}

DoorPosition Map::getDoorPosition() const {
    return doorPosition;
}

void Map::clearCharacterFromPosition(const Position position) {
    // Ensure the position is within the bounds of the map
    if (position.y > 0 && position.y < mapHeight &&
        position.x > 0 && position.x < mapWidth) {
        // Replace with empty character
        fullMap[position.y * mapWidth + position.x] = Tile::createTile('.');
    }
}
