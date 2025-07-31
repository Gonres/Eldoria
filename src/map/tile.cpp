#include "tile.h"

Tile::Tile(const char symbol) {
    this->symbol = symbol;
}

Tile *Tile::createTile(const char symbol) {
    return new Tile(symbol);
}

char Tile::getTile() const {
    return symbol;
}
