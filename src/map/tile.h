#ifndef TILE_H
#define TILE_H

class Tile {
public:
    static Tile *createTile(char symbol);

    char getTile() const;

private:
    char symbol;

    explicit Tile(char symbol);
};

#endif //TILE_H
