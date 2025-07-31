#include "player_movement.h"

#include "../tools/keyboard_key.h"

PlayerMovement::PlayerMovement(Player *player) {
    this->player = player;
}

void PlayerMovement::movePlayer(Map *map, const std::function<void()> &nextLevel,
                                const std::vector<Enemy *> &enemies) const {
    if (isBlockedByEnemy(enemies)) {
        return;
    }
    const Position nextPosition = calculateNextPosition();

    if (nextPosition.x == player->getPosition().x && nextPosition.y == player->getPosition().y) {
        return;
    }

    const char nextTile = map->assignTilePosition(nextPosition);
    handleMovement(map, nextTile, nextPosition, nextLevel);
}

bool PlayerMovement::isBlockedByEnemy(const std::vector<Enemy *> &enemies) const {
    for (const Enemy *enemy: enemies) {
        if (enemy->isAggroed() &&
            Position::isInRangeOfOne(player->getPosition().x, player->getPosition().y,
                                     enemy->getPosition().x, enemy->getPosition().y)) {
            return true;
        }
    }
    return false;
}

Position PlayerMovement::calculateNextPosition() const {
    Position nextPosition = player->getPosition();

    if (isKeyDown(KEY_W)) {
        nextPosition.y -= 1;
    } else if (isKeyDown(KEY_S)) {
        nextPosition.y += 1;
    } else if (isKeyDown(KEY_A)) {
        nextPosition.x -= 1;
    } else if (isKeyDown(KEY_D)) {
        nextPosition.x += 1;
    }
    return nextPosition;
}

void PlayerMovement::handleMovement(Map *map, const char nextTile, const Position nextPosition,
                                    const std::function<void()> &nextLevel) const {
    if (nextTile == '.') {
        moveToPosition(map, nextPosition);
    } else if (nextTile == '|') {
        advanceToNextLevel(map, nextLevel);
    }
}

void PlayerMovement::moveToPosition(Map *map, const Position nextPosition) const {
    map->clearCharacterFromPosition(player->getPosition());
    player->setPosition(nextPosition);
    map->putCharacterInPosition(player->getPosition(), '@');
}

void PlayerMovement::advanceToNextLevel(Map *map, const std::function<void()> &nextLevel) const {
    nextLevel();
    map->clearCharacterFromPosition(player->getPosition());
}

