#include "enemy_movement.h"

#include "../tools/keyboard_key.h"

EnemyMovement::EnemyMovement(Enemy *enemy) {
    this->enemy = enemy;
}

void EnemyMovement::moveEnemy(Map *map, const Player *player) const {
    if (!enemy->isAlive()) {
        return;
    }

    if (!enemy->isAggroed() || (!movementKeys() && !isKeyDown(KEY_F))) {
        return;
    }

    Position nextPosition = calculateNextPosition(player);

    if (map->assignTilePosition(nextPosition) == '.') {
        updatePosition(map, nextPosition);
    }
}

Position EnemyMovement::calculateNextPosition(const Player *player) const {
    Position nextPosition = enemy->getPosition();

    if (Position::getDistanceX(player->getPosition().x, nextPosition.x) >
        Position::getDistanceX(player->getPosition().y, nextPosition.y)) {
        nextPosition.x += player->getPosition().x > nextPosition.x ? 1 : -1;
    } else {
        nextPosition.y += player->getPosition().y > nextPosition.y ? 1 : -1;
    }

    return nextPosition;
}

void EnemyMovement::updatePosition(Map *map, const Position nextPosition) const {
    map->clearCharacterFromPosition(enemy->getPosition());
    enemy->setPosition(nextPosition);
    map->putCharacterInPosition(enemy->getPosition(), '!');
}
