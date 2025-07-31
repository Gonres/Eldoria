#include "loot_enemy.h"
#include "../../tools/global_settings.h"

LootEnemy::LootEnemy(Player *player, Enemy *enemy) {
    this->player = player;
    this->enemy = enemy;
}

void LootEnemy::execute() {
    player->addXp(enemy->getXpReward());
    player->addCoins(enemy->getCoinReward());
    dropPotion();
}

void LootEnemy::dropPotion() const {
    if (GlobalSettings::getRandomNumber(100) <= enemy->getPotionDropChance()) {
        player->addPotion(new Potion());
    }
}


