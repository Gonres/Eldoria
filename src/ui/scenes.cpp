//
// Created by Lukyn on 06.12.2024.
//

#include "scenes.h"
#include <iostream>
#include "../tools/color.h"
#include "../tools/global_settings.h"
#include "../tools/keyboard_key.h"

Scenes::Scenes() {
    m_currentScene = 0;
}

void Scenes::printEndGame() const {
    switch (m_currentScene) {
        case 0:
            sceneBossDefeat();
            break;
        case 1:
            sceneTheEnd();
            break;
        case 2:
            sceneCredits();
            break;
        default: break;
    }
}

void Scenes::printScenes() const {
    switch (m_currentScene) {
        case 0:
            sceneProlog1();
            break;
        case 1:
            sceneProlog2();
            break;
        case 2:
            sceneProlog3();
            break;
        case 3:
            sceneProlog4();
            break;
        default: break;
    }
}

void Scenes::setCurrentScene(const int currentScene) {
    m_currentScene = currentScene;
}

void Scenes::incrementCurrentScene() {
    if (isKeyDown(ENTER)) {
        m_currentScene++;
    }
}

int Scenes::getCurrentScene() const {
    return m_currentScene;
}

//
//MAIN MENU
//

void Scenes::sceneHeaderMenu() const {
    std::cout << " _____                                              __   ";
    setColor(Colors::red);
    std::cout << "______ _     _            _       \n";
    setColor(Colors::white);
    std::cout << "|  __ \\                                            / _| ";
    setColor(Colors::red);
    std::cout << "|  ____| |   | |          (_)      \n";
    setColor(Colors::white);
    std::cout << "| |  | |_   _ _ __   __ _  ___  ___  _ __     ___ | |_  ";
    setColor(Colors::red);
    std::cout << "| |__  | | __| | ___  _ __ _  __ _ \n";
    setColor(Colors::white);
    std::cout << "| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\   / _ \\|  _| ";
    setColor(Colors::red);
    std::cout << "|  __| | |/ _` |/ _ \\| '__| |/ _` |\n";
    setColor(Colors::white);
    std::cout << "| |__| | |_| | | | | (_| |  __/ (_) | | | | | (_) | |   ";
    setColor(Colors::red);
    std::cout << "| |____| | (_| | (_) | |  | | (_| |\n";
    setColor(Colors::white);
    std::cout << "|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\___/|_|   ";
    setColor(Colors::red);
    std::cout << "|______|_|\\__,_|\\___/|_|  |_|\\__,_|\n";
    setColor(Colors::white);
    std::cout << "                    __/ |                                                                 \n";
    std::cout << "                   |___/                                                                  \n";
}

void Scenes::sceneSmallHeaderMenu() const {
    std::cout << "|=====> Dungeon of ";
    setColor(Colors::red);
    std::cout << "ELDORIA";
    setColor(Colors::white);
    std::cout << " <=====|\n";
    std::cout << "\n";
}

void Scenes::sceneMainSelectedPlay() const {
    setColor(Colors::selected);
    std::cout << "- PLAY\n";
    setColor(Colors::white);
    std::cout << "  CREDITS\n";
    std::cout << "  HOW TO PLAY\n";
    std::cout << "  EXIT\n";
}

void Scenes::sceneMainSelectedCredits() const {
    std::cout << "  PLAY\n";
    setColor(Colors::selected);
    std::cout << "- CREDITS\n";
    setColor(Colors::white);
    std::cout << "  HOW TO PLAY\n";
    std::cout << "  EXIT\n";
}

void Scenes::sceneMainSelectedHTP() const {
    std::cout << "  PLAY\n";
    std::cout << "  CREDITS\n";
    setColor(Colors::selected);
    std::cout << "- HOW TO PLAY\n";
    setColor(Colors::white);
    std::cout << "  EXIT\n";
}

void Scenes::sceneMainSelectedExit() const {
    std::cout << "  PLAY\n";
    std::cout << "  CREDITS\n";
    std::cout << "  HOW TO PLAY\n";
    setColor(Colors::selected);
    std::cout << "- EXIT\n";
    setColor(Colors::white);
}

void Scenes::sceneCreditsMenu() const {
    std::cout << "               _   _                    \n";
    std::cout << "    /\\        | | | |                   \n";
    std::cout << "   /  \\  _   _| |_| |__   ___  _ __ ___ \n";
    std::cout << "  / /\\ \\| | | | __| '_ \\ / _ \\| '__/ __|\n";
    std::cout << " / ____ \\ |_| | |_| | | | (_) | |  \\__ \\\n";
    std::cout << "/_/    \\_\\__,_|\\__|_| |_|\\___/|_|  |___/\n\n\n";
    std::cout << "          Lukas ";
    setColor(Colors::red);
    std::cout << "\"Lukyn\" ";
    setColor(Colors::white);
    std::cout << "Kulhanek\n";
    std::cout << "          Ivo ";
    setColor(Colors::red);
    std::cout << "\"Gonres\" ";
    setColor(Colors::white);
    std::cout << "Dubsik\n";
    std::cout << "          Vit ";
    setColor(Colors::red);
    std::cout << "\"SquEEzy\" ";
    setColor(Colors::white);
    std::cout << "Benda\n";
    std::cout << "\n\n";
    setColor(Colors::selected);
    std::cout << "[ESC] Back\n";
    setColor(Colors::white);
}

void Scenes::sceneHTPMenu() const {
    std::cout << "  ---->  GAME MANUAL  <----\n";
    setColor(Colors::red);
    std::cout << "XP:\n";
    setColor(Colors::white);
    std::cout << "- You gain XP by either killing enemies from the darkness or rescuing prisoners of the dungeon.\n";
    std::cout << "- Leveling up will give you an extra amount of damage per each level depending on your class type.\n";
    setColor(Colors::red);
    std::cout << "Coins:\n";
    setColor(Colors::white);
    std::cout << "- In-game currency which you can obtain by killing enemies or rescuing prisoners.\n";
    std::cout << "- You can spend coins at Merchant.\n";
    setColor(Colors::red);
    std::cout << "Merchant:\n";
    setColor(Colors::white);
    std::cout << "- Civilian that is available each 3 stages of your journey through the dungeon.\n";
    std::cout << "- Use your coins at Merchant to buy certain type of items, depending on your class type.\n";
    setColor(Colors::red);
    std::cout << "Fights:\n";
    setColor(Colors::white);
    std::cout << "- You have an ability to fight with each enemy you might run into, and you will... a lot.\n";
    std::cout <<
            "- Your class type will be the key of each fight. Each class has a different range, that he can fight in.\n";
    std::cout << "- Use [F] to fight, if you are in your allowed range. Depending on your class and range, you will\n";
    std::cout << "  have an advantage of 1 or 2 attacks before the enemy will defend itself.\n";
    std::cout << "- Use your attacks wisely, because once they get too close, there is no going back.\n";
    setColor(Colors::red);
    std::cout << "Prisoners:\n";
    setColor(Colors::white);
    std::cout <<
            "- Civilians, which you can rescue from their cages. They will give you some coins and XP for exchange.\n";
    std::cout << "\n";
    setColor(Colors::selected);
    std::cout << "[ESC] Back\n";
    setColor(Colors::white);
}

void Scenes::sceneRoleSelectedWarrior() const {
    setColor(Colors::selected);
    std::cout << "- WARRIOR";
    setColor(Colors::white);
    std::cout << "                 /|   ________________\n";
    std::cout << "  ARCHER";
    std::cout << "              O|===|* >________________>\n";
    std::cout << "  MAGE";
    std::cout << "                    \\|\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "The Warrior has to face his enemies from close range.\n";
    std::cout << "Dungeon entities may damage you more often, but your armor is ready for that.\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "[ESC] Back\n";
}

void Scenes::sceneRoleSelectedArcher() const {
    std::cout << "  WARRIOR\n";
    setColor(Colors::selected);
    std::cout << "- ARCHER";
    setColor(Colors::white);
    std::cout << "          _.-\"/______________________/////\n";
    std::cout << "  MAGE";
    std::cout << "            `'-.\\~~~~~~~~~~~~~~~~~~~~~~\\\\\\\\\\\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "The Archer can attack his enemies from medium range.\n";
    std::cout << "You are able to fight first, but your health and armor are not the strongest.\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "[ESC] Back\n";
}

void Scenes::sceneRoleSelectedMage() const {
    std::cout << "  WARRIOR";
    std::cout << "           ___________________    . , ; .\n";
    std::cout << "  ARCHER";
    std::cout << "           (___________________|~~~~~X.;' .\n";
    setColor(Colors::selected);
    std::cout << "- MAGE";
    setColor(Colors::white);
    std::cout << "                                     ' `\" ' `\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "The Mage is able to stay in the shadows far away from its targets.\n";
    std::cout << "Unlocks potential to fight from high range, but once the entities gets too close...";
    std::cout << " it might ";
    setColor(Colors::red);
    std::cout << "HURT.\n";
    setColor(Colors::white);
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "[ESC] Back\n";
}

//
//SHOP MENU // AKA MERCHANT
//

void Scenes::sceneShopHeader() const {
    std::cout << "     __  __ ______ _____   _____ _    _          _   _ _______ \n";
    std::cout << "    |  \\/  |  ____|  __ \\ / ____| |  | |   /\\   | \\ | |__   __|\n";
    std::cout << "    | \\  / | |__  | |__) | |    | |__| |  /  \\  |  \\| |  | |   \n";
    std::cout << "    | |\\/| |  __| |  _  /| |    |  __  | / /\\ \\ | . ` |  | |   \n";
    std::cout << "    | |  | | |____| | \\ \\| |____| |  | |/ ____ \\| |\\  |  | |   \n";
    std::cout << "    |_|  |_|______|_|  \\_\\\\_____|_|  |_/_/    \\_\\_| \\_|  |_| \n\n";
    std::cout << " Welcome adventurer!\n"
            " Looking for something to save your life, or perhaps a weapon to end your enemies'?\n"
            " Take a look around -- I've got what you need!\n\n";
}

void Scenes::sceneShopWeaponHeader(Player *player) const {
    std::cout << "    __          __                              \n";
    std::cout << "    \\ \\        / /                              \n";
    std::cout << "     \\ \\  /\\  / /__  __ _ _ __   ___  _ __  ___ \n";
    std::cout << "      \\ \\/  \\/ / _ \\/ _` | '_ \\ / _ \\| '_ \\/ __|\n";
    std::cout << "       \\  /\\  /  __/ (_| | |_) | (_) | | | \\__ \\\n";
    std::cout << "        \\/  \\/ \\___|\\__,_| .__/ \\___/|_| |_|___/\n";
    std::cout << "                         | |                    \n";
    std::cout << "                         |_|     \n";
    std::cout << "  COINS: ";
    setColor(Colors::yellow);
    std::cout << player->getCoins() << "\n\n";
    setColor(Colors::white);
}

void Scenes::sceneShopArmorHeader(Player *player) const {
    std::cout << "        /\\                              \n";
    std::cout << "       /  \\   _ __ _ __ ___   ___  _ __ \n";
    std::cout << "      / /\\ \\ | '__| '_ ` _ \\ / _ \\| '__|\n";
    std::cout << "     / ____ \\| |  | | | | | | (_) | |   \n";
    std::cout << "    /_/    \\_\\_|  |_| |_| |_|\\___/|_|   \n\n";
    std::cout << "  COINS: ";
    setColor(Colors::yellow);
    std::cout << player->getCoins() << "\n\n";
    setColor(Colors::white);
}

void Scenes::sceneShopPotionHeader(Player *player) const {
    std::cout << "     _____      _   _                 \n";
    std::cout << "    |  __ \\    | | (_)                \n";
    std::cout << "    | |__) |__ | |_ _  ___  _ __  ___ \n";
    std::cout << "    |  ___/ _ \\| __| |/ _ \\| '_ \\/ __|\n";
    std::cout << "    | |  | (_) | |_| | (_) | | | \\__ \\\n";
    std::cout << "    |_|   \\___/ \\__|_|\\___/|_| |_|___/\n\n";
    std::cout << "  COINS: ";
    setColor(Colors::yellow);
    std::cout << player->getCoins() << "\n\n";
    setColor(Colors::white);
}

void Scenes::sceneShopHint() const {
    std::cout << "\n Press [ENTER] to make a choice\n";
    setColor(Colors::red);
    std::cout << "\n THE WEAPON & ARMOR POOL DEPENDS ON YOUR ROLE TYPE";
    setColor(Colors::white);
}

void Scenes::sceneShopOwnedWeapon(Player *player, Weapon *weapon) const {
    switch (player->weaponOwned(weapon)) {
        case 0:
            break;
        case 1:
            std::cout << "[OWNED]\n";
            break;
    }
}

void Scenes::sceneShopOwnedArmor(Player *player, Armor *armor) const {
    switch (player->armorOwned(armor)) {
        case 0:
            break;
        case 1:
            std::cout << "[OWNED]\n";
            break;
    }
}

void Scenes::sceneShopMainSelectedWeapons() const {
    setColor(Colors::selected);
    std::cout << "- WEAPONS\n";
    setColor(Colors::white);
    std::cout << "  ARMOR\n";
    std::cout << "  POTION\n";
    std::cout << "  EXIT\n";
}

void Scenes::sceneShopMainSelectedArmor() const {
    std::cout << "  WEAPONS\n";
    setColor(Colors::selected);
    std::cout << "- ARMOR\n";
    setColor(Colors::white);
    std::cout << "  POTION\n";
    std::cout << "  EXIT\n";
}

void Scenes::sceneShopMainSelectedPotions() const {
    std::cout << "  WEAPONS\n";
    std::cout << "  ARMOR\n";
    setColor(Colors::selected);
    std::cout << "- POTION\n";
    setColor(Colors::white);
    std::cout << "  EXIT\n";
}

void Scenes::sceneShopMainSelectedExit() const {
    std::cout << "  WEAPONS\n";
    std::cout << "  ARMOR\n";
    std::cout << "  POTION\n";
    setColor(Colors::selected);
    std::cout << "- EXIT\n";
    setColor(Colors::white);
}

void Scenes::sceneShopWeaponsSelectedWeapon1(Player *player, Weapon *weapon) const {
    switch (player->getRole()) {
        case Role::warrior:
            setColor(Colors::selected);
            std::cout << "- Stone cleaver\n";
            setColor(Colors::white);
            std::cout << "  Blade of Rushing Fury\n";
            std::cout << "  Axe of Eternal Flame\n";
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
        case Role::archer:
            setColor(Colors::selected);
            std::cout << "- Flame Arrows\n";
            setColor(Colors::white);
            std::cout << "  Arrow of Hidden Shadow\n";
            std::cout << "  Crossbow of the Night's Mark\n";
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
        case Role::mage:
            setColor(Colors::selected);
            std::cout << "- Staff of Fate\n";
            setColor(Colors::white);
            std::cout << "  Ring of Hidden Flames\n";
            std::cout << "  Orb of Destructive Energy\n";
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
    }
}

void Scenes::sceneShopWeaponsSelectedWeapon2(Player *player, Weapon *weapon) const {
    switch (player->getRole()) {
        case Role::warrior:
            std::cout << "  Stone cleaver\n";
            setColor(Colors::selected);
            std::cout << "- Blade of Rushing Fury\n";
            setColor(Colors::white);
            std::cout << "  Axe of Eternal Flame\n";
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
        case Role::archer:
            std::cout << "  Flame Arrows\n";
            setColor(Colors::selected);
            std::cout << "- Arrow of Hidden Shadow\n";
            setColor(Colors::white);
            std::cout << "  Crossbow of the Night's Mark\n";
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
        case Role::mage:
            std::cout << "  Staff of Fate\n";
            setColor(Colors::selected);
            std::cout << "- Ring of Hidden Flames\n";
            setColor(Colors::white);
            std::cout << "  Orb of Destructive Energy\n";
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
    }
}

void Scenes::sceneShopWeaponsSelectedWeapon3(Player *player, Weapon *weapon) const {
    switch (player->getRole()) {
        case Role::warrior:
            std::cout << "  Stone cleaver\n";
            std::cout << "  Blade of Rushing Fury\n";
            setColor(Colors::selected);
            std::cout << "- Axe of Eternal Flame\n";
            setColor(Colors::white);
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
        case Role::archer:
            std::cout << "  Flame Arrows\n";
            std::cout << "  Arrow of Hidden Shadow\n";
            setColor(Colors::selected);
            std::cout << "- Crossbow of the Night's Mark\n";
            setColor(Colors::white);
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
        case Role::mage:
            std::cout << "  Staff of Fate\n";
            std::cout << "  Ring of Hidden Flames\n";
            setColor(Colors::selected);
            std::cout << "- Orb of Destructive Energy\n";
            setColor(Colors::white);
            std::cout << "\n PRICE: " << weapon->getPrice() << " coins\n";
            std::cout << " Adds " << weapon->getDamage() << " damage points to attacks\n";
            sceneShopOwnedWeapon(player, weapon);
            break;
    }
}

void Scenes::sceneShopArmorSelectedArmor1(Player *player, Armor *armor) const {
    switch (player->getRole()) {
        case Role::warrior:
            setColor(Colors::selected);
            std::cout << "- Old Steel Chestplate\n";
            setColor(Colors::white);
            std::cout << "  The Eldorian Thunderhelm\n";
            std::cout << "  Tombkeeper's Shield\n";
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
        case Role::archer:
            setColor(Colors::selected);
            std::cout << "- Cloak of Whispering Wind\n";
            setColor(Colors::white);
            std::cout << "  Marksman's Chestplate\n";
            std::cout << "  Forest Warden's Helm\n";
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
        case Role::mage:
            setColor(Colors::selected);
            std::cout << "- Robe of Fiery Circle\n";
            setColor(Colors::white);
            std::cout << "  Hood of Misty Guardian\n";
            std::cout << "  Aura of Arcane Spell\n";
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
    }
}

void Scenes::sceneShopArmorSelectedArmor2(Player *player, Armor *armor) const {
    switch (player->getRole()) {
        case Role::warrior:
            std::cout << "  Old Steel Chestplate\n";
            setColor(Colors::selected);
            std::cout << "- The Eldorian Thunderhelm\n";
            setColor(Colors::white);
            std::cout << "  Tombkeeper's Shield\n";
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
        case Role::archer:
            std::cout << "  Cloak of Whispering Wind\n";
            setColor(Colors::selected);
            std::cout << "- Marksman's Chestplate\n";
            setColor(Colors::white);
            std::cout << "  Forest Warden's Helm\n";
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
        case Role::mage:
            std::cout << "  Robe of Fiery Circle\n";
            setColor(Colors::selected);
            std::cout << "- Hood of Misty Guardian\n";
            setColor(Colors::white);
            std::cout << "  Aura of Arcane Spell\n";
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
    }
}

void Scenes::sceneShopArmorSelectedArmor3(Player *player, Armor *armor) const {
    switch (player->getRole()) {
        case Role::warrior:
            std::cout << "  Old Steel Chestplate\n";
            std::cout << "  The Eldorian Thunderhelm\n";
            setColor(Colors::selected);
            std::cout << "- Tombkeeper's Shield\n";
            setColor(Colors::white);
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
        case Role::archer:
            std::cout << "  Cloak of Whispering Wind\n";
            std::cout << "  Marksman's Chestplate\n";
            setColor(Colors::selected);
            std::cout << "- Forest Warden's Helm\n";
            setColor(Colors::white);
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
        case Role::mage:
            std::cout << "  Robe of Fiery Circle\n";
            std::cout << "  Hood of Misty Guardian\n";
            setColor(Colors::selected);
            std::cout << "- Aura of Arcane Spell\n";
            setColor(Colors::white);
            std::cout << "\n PRICE: " << armor->getPrice() << " coins\n";
            std::cout << " Adds " << armor->getArmor() << " defense points against enemy attacks\n";
            sceneShopOwnedArmor(player, armor);
            break;
    }
}

void Scenes::sceneShopPotionsSelectedPotion1(Potion *potion) const {
    setColor(Colors::selected);
    std::cout << "- Elixir of Vitality \n";
    setColor(Colors::white);
    std::cout << "\n PRICE: " << potion->getPrice() << " coins\n";
    std::cout << " On use, adds " << potion->getHpGain() << " health points\n";
}

//
//CUTSCENES
//

void Scenes::continueHint() const {
    std::cout << "\n   Press [ENTER] to continue...";
}

void Scenes::prologText1() const {
    std::cout <<
            "\n   Switzerland, Arosa Valley, Kingdom of Eldoria, year 1638. Local scientists are attempting to gain power\n";
    std::cout <<
            "   and secure a strategic advantage over other kingdoms by summoning the demon Necromancer.\n\n";
}

void Scenes::prologArt1() const {
    std::cout << "                                  |>>>\n";
    std::cout << "                                  |\n";
    std::cout << "                    |>>>      _  _|_  _         |>>>\n";
    std::cout << "                    |        |;| |;| |;|        |\n";
    std::cout << "                _  _|_  _    \\\\.    .  /    _  _|_  _\n";
    std::cout << "               |;|_|;|_|;|    \\\\:. ,  /    |;|_|;|_|;|\n";
    std::cout << "               \\\\..      /    ||;   . |    \\\\.    .  /\n";
    std::cout << "                \\\\.  ,  /     ||:  .  |     \\\\:  .  /\n";
    std::cout << "                 ||:   |_   _ ||_ . _ | _   _||:   |\n";
    std::cout << "                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |\n";
    std::cout << "                 ||:   ||.    .     .      . ||:  .|\n";
    std::cout << "                 ||: . || .     . .   .  ,   ||:   |       \\,/\n";
    std::cout << "                 ||:   ||:  ,  _______   .   ||: , |            /`\\\n";
    std::cout << "                 ||:   || .   /+++++++\\    . ||:   |\n";
    std::cout << "                 ||:   ||.    |+++++++| .    ||: . |\n";
    std::cout << "              __ ||: . ||: ,  |+++++++|.  . _||_   |\n";
    std::cout << "     ____--`~    '--~~__|.    |+++++__|----~    ~`---,              ___\n";
    std::cout << "-~--~                   ~---__|,--~'                  ~~----_____-~'   `~----~~\n";
}

void Scenes::sceneProlog1() const {
    prologText1();
    prologArt1();
    continueHint();
}

void Scenes::prologText2() const {
    std::cout <<
            "\n   However, the evil they have summoned has gotten out of the scientist's hands and chaos has broken out in the kingdom.\n";
    std::cout <<
            "   Every night, evil entities descend upon the kingdom, and people begin to vanish without a trace.\n\n";
}

void Scenes::prologArt2() const {
    std::cout << "                 .7\n";
    std::cout << "               .'/\n";
    std::cout << "              / /\n";
    std::cout << "             / /\n";
    std::cout << "            / /\n";
    std::cout << "           / /\n";
    std::cout << "          / /\n";
    std::cout << "         / /\n";
    std::cout << "        / /\n";
    std::cout << "      __|/\n";
    std::cout << "    ,-\\__\\\n";
    std::cout << "    |f-\"Y\\|\n";
    std::cout << "    \\()7L/\n";
    std::cout << "     cgD                            __ _\n";
    std::cout << "     |\\(                          .'  Y '>,\n";
    std::cout << "      \\ \\                        / _   _   \\\n";
    std::cout << "       \\\\\\                       )(_) (_)(|}\n";
    std::cout << "        \\\\\\                      {  4A   } /\n";
    std::cout << "         \\\\\\                      \\uLuJJ/\\l\n";
    std::cout << "          \\\\\\                     |3    p)/\n";
    std::cout << "           \\\\\\___ __________      /nnm_n//\n";
    std::cout << "           c7___-__,__-)\\,__)(\".  \\\\_>-<_/D\n";
    std::cout << "                      //V     \\_\"-._.__G G_c__.-__<\"/ ( \\\n";
    std::cout << "                             <\"-._>__-,G_.___)\\   \\7\\\n";
    std::cout << "                            (\"-.__.| \\\"<.__.-\" )   \\ \\\n";
    std::cout << "                            |\"-.__\"\\  |\"-.__.-\".\\   \\ \\\n";
    std::cout << "                            (\"-.__\"\". \\\"-.__.-\".|    \\_\\\n";
    std::cout << "                            \\\"-.__\"\"|!|\"-.__.-\".)     \\ \\\n";
    std::cout << "                             \"-.__\"\"\\_|\"-.__.-\"./      \\ l\n";
    std::cout << "                              \".__\"\"\">G>-.__.-\">       .--,_\n";
    std::cout << "                                  \"\"  G,\n";
}

void Scenes::sceneProlog2() const {
    prologText2();
    prologArt2();
    continueHint();
}

void Scenes::prologText3() const {
    std::cout << "\n   One night, ";
    setColor(Colors::red);
    std::cout << "EVIL";
    setColor(Colors::white);
    std::cout << " had come for the princess herself.\n";
    std::cout <<
            "   You, Prince Kaelan, have noticed this and decided to pursue the evil with the helpless princess.\n\n";
}

void Scenes::prologArt3() const {
    std::cout << "                 __                                            |                     \n";
    std::cout << "                /__`.                                          |                     \n";
    std::cout <<
            "               / \\ `\\\\                                         |                     \n";
    std::cout <<
            "              /   \\  `\\                                        |                     \n";
    std::cout <<
            "             /     \\   \\                                       |                           _,.         '``oH NOoo, they have captured\n";
    std::cout <<
            "            /_______\\  /\\                                      |                         ,` -.)            the princess Laurien``'\n";
    std::cout <<
            "            (((( ))))                                          |                        ( _/-\\\\-._\n";
    std::cout <<
            "           (((' . ')))                                         |                       /,|`--._,-^|            ,\n";
    std::cout <<
            "           (((\\_O_/)))                                         |                       \\_| |`-._/||          ,'|\n";
    std::cout <<
            "           (((_) (_)))                                         |                         |  `-, / |         /  /\n";
    std::cout <<
            "          /((( \\ / )))\\                                        |                         |     || |        /  /\n";
    std::cout <<
            "         / (((  ^  ))) \\                                       |                          `r-._||/   __   /  /\n";
    std::cout <<
            "        / / ((  ^  )) \\ \\                                      |                      __,-<_     )`-/  `./  /\n";
    std::cout <<
            "       ( (   \\  ^  /   ) )                                     |                     /  \\   `---'   \\   /  /\n";
    std::cout <<
            "        \\ \\   )www(   / /                                      |                    |    |           |./  /\n";
    std::cout <<
            "         `\\\\ /     \\ //'                                       |                    \\    /           //  /\n";
    std::cout <<
            "           /'       `\\                                         |                     \\_/' \\         |/  /\n";
    std::cout <<
            "          /           \\                                        |                      |    |   _,^-'/  /\n";
    std::cout <<
            "         /             \\                                       |                      |    , ``  (\\/  /_\n";
    std::cout <<
            "        /               \\                                      |                       \\,.->._    \\X-=/^\n";
    std::cout <<
            "       /                 \\                                     |                       (  /   `-._//^`\n";
    std::cout <<
            "      /                   \\                                    |                        `Y-.____(__}\n";
    std::cout <<
            "     /                     \\                                   |                         |     {__)\n";
    std::cout <<
            "    /                       \\                                  |                               ()\n";
    std::cout << "   /                         \\                                 |\n";
    std::cout << "  /                           \\                                |\n";
    std::cout << " |                             |                               |\n";
    std::cout << "  `-----......_____......-----'                                |\n";
}

void Scenes::sceneProlog3() const {
    prologText3();
    prologArt3();
    continueHint();
}

void Scenes::prologText4() const {
    std::cout <<
            "\n   Trail led you to a nearby tomb known as the Tomb of Oblivion - feared by all, for no one who entered ever returned. \n";
    std::cout <<
            "   Kaelan wasted no time and, armed only with his solitary weapon, ventured into the tomb, ";
    setColor(Colors::red);
    std::cout << "ALONE.\n\n";
    setColor(Colors::white);
}

void Scenes::prologArt4() const {
    std::cout << "                                    .' '.\n";
    std::cout << "                                  .'  |  `.\n";
    std::cout << "                                .'    |    `.\n";
    std::cout << "                              .`---.._|_..---'.\n";
    std::cout << "                               ||    |=|    ||\n";
    std::cout << "                               ||`-._|=|_.-'||\n";
    std::cout << "                          _____||    |=|    ||__\n";
    std::cout << "            ____________.'     `-.   |=|  .'_.'\\/`.\n";
    std::cout << "        .'     _   _.'      _   _        .'\\.' `._`./`.\n";
    std::cout << "      .' _       _.' __          __    .'\\.'  ___`._`./`.\n";
    std::cout << "    .'        _ .'   _____           .'\\.'         `._`./`.\n";
    std::cout << "  .'  _  _    .'       ______      .'\\.'  __         `._`./`.\n";
    std::cout << ".'`--...__ _.'            ______ .'\\.'           __    `._`./`.\n";
    std::cout << " `--...__ .'   ____            .'\\.'           _         `._`./`.\n";
    std::cout << " |      .`--...__            .'\\.'     _               ____`._`./`.\n";
    std::cout << " | /`-._ `--...__`--...___ .'\\.'              _______       _`._`./`.\n";
    std::cout << " | | ) ( |       `--...____\\.'     _     _  .'      .`.        `._`./\n";
    std::cout << " | |)   (| /`-._             |            .'      .'   `.     _ |\n";
    std::cout << " | |(--| | | )( |  /`-._`--._|____       /      .'       `.     |\n";
    std::cout << " | | ) `.| |(  )|  | )( |    | _      _ /      /   .---.  `\\    |\n";
    std::cout << " | `--._ | |/  \\|  |(  )|`-  |         /`--.._/   /     \\  ' _  |\n";
    std::cout << " | `-.   | |)-.(|  |/  \\|    |       __|      |_  |`-   |  |  _ |\n";
    std::cout << " |    `-.| |) |(|  |)-.(|    |  ___  _ |  __  | __| \\`- |  |    |\n";
    std::cout << " '-._    | `--._/  |) |(|    |      __ |      |   | |`- |  | _  |\n";
    std::cout << "     `-._| `--.    `--._/    |  ___    | _    |   | |`- |  |   '|\n";
    std::cout << "         |      `--._        |       _ |    ' |   |O|`- | _| _  |\n";
    std::cout << "         '--. ._. _    `--._ |         | _    |_ \"| |`- |. |  __|\n";
    std::cout << "                   `--._     |__       |   _  |\"  | |`- |  |___ |\n";
    std::cout << "                        `--._|_________|_     | _ |  `- |_ |____|\n";
    std::cout << "                                         '--._|___|     |__|\n";
}

void Scenes::sceneProlog4() const {
    prologText4();
    prologArt4();
    continueHint();
}

void Scenes::sceneDeathScreen() const {
    setColor(Colors::red);
    std::cout <<
            "\n\n\n\n                                      __     ______  _    _           _____ _____ ______ _____  \n";
    std::cout <<
            "                                      \\ \\   / / __ \\| |  | |         |  __ \\_   _|  ____|  __ \\ \n";
    std::cout << "                                       \\ \\_/ / |  | | |  | |         | |  | || | | |__  | |  | |\n";
    std::cout << "                                        \\   /| |  | | |  | |         | |  | || | |  __| | |  | |\n";
    std::cout << "                                         | | | |__| | |__| |         | |__| || |_| |____| |__| |\n";
    std::cout <<
            "                                         |_|  \\____/ \\____/          |_____/_____|______|_____/ \n\n\n\n";
    setColor(Colors::white);
    std::cout <<
            "                       You failed saving princess, including yourself. Your legacy and courage will be remembered\n";
    std::cout << "                                                    among the Kingdom of ";
    setColor(Colors::red);
    std::cout << "ELDORIA.\n";
    setColor(Colors::white);
}

void Scenes::sceneTheEnd() const {
    setColor(Colors::green);
    std::cout <<
            "\n\n\n\n                                                     _______ _    _ ______         ______ _   _ _____  \n";
    std::cout <<
            "                                                    |__   __| |  | |  ____|       |  ____| \\ | |  __ \\ \n";
    std::cout <<
            "                                                       | |  | |__| | |__          | |__  |  \\| | |  | |\n";
    std::cout <<
            "                                                       | |  |  __  |  __|         |  __| | . ` | |  | |\n";
    std::cout <<
            "                                                       | |  | |  | | |____        | |____| |\\  | |__| |\n";
    std::cout <<
            "                                                       |_|  |_|  |_|______|       |______|_| \\_|_____/ \n\n\n";
    setColor(Colors::white);
    std::cout << "                                                                    Thank you for playing.\n\n\n";
}

void Scenes::sceneBossDefeat() const {
    std::cout << "\n\n\n\n                          (,);    /\\                        \n";
    std::cout << "                         (( ^_    ||            ...         \n";
    std::cout << "                          ' /  \\  ||           (()))        \n";
    std::cout << "                            L {=) ||           {' ())       \n";
    std::cout << "                             ) -  ||            )_ (()      \n";
    std::cout << "                           (_   \\====       @  (   (_)      \n";
    std::cout << "                           | (___/{ }        \\7 \\ _) |      \n";
    std::cout << "                            \\____\\/)          {)=== /\\      \n";
    std::cout << "                            |    |             \\ |    |     \n";
    std::cout << "                            |_/\\_|               |    |     \n";
    std::cout << "                             |  |                |    |     \n";
    std::cout << "                              ) )\\               |    |     \n";
    std::cout << "                            _/| |/               |    |     \n";
    std::cout << "                           ( ,\\ |_               '~~~~'     \n";
    std::cout << "                            \\_(___)               _/Y \n\n\n";
    setColor(Colors::white);
    std::cout <<
            "          You managed to save princess and defeated the king of EVIL, The Necromancer, for eternity.\n\n";
    setColor(Colors::red);
    std::cout << "   oR DiD YoU?\n";
    setColor(Colors::white);
}

void Scenes::sceneCredits() const {
    std::cout << "                                                     _   _                    \n";
    std::cout << "                                          /\\        | | | |                   \n";
    std::cout << "                                         /  \\  _   _| |_| |__   ___  _ __ ___ \n";
    std::cout << "                                        / /\\ \\| | | | __| '_ \\ / _ \\| '__/ __|\n";
    std::cout << "                                       / ____ \\ |_| | |_| | | | (_) | |  \\__ \\\n";
    std::cout << "                                      /_/    \\_\\__,_|\\__|_| |_|\\___/|_|  |___/\n\n\n";
    std::cout << "                                                Lukas ";
    setColor(Colors::red);
    std::cout << " \"Lukyn\" ";
    setColor(Colors::white);
    std::cout << "Kulhanek\n";
    std::cout << "                                                Ivo ";
    setColor(Colors::red);
    std::cout << " \"Gonres\" ";
    setColor(Colors::white);
    std::cout << "Dubsik\n";
    std::cout << "                                                Vit ";
    setColor(Colors::red);
    std::cout << " \"SquEEzy\" ";
    setColor(Colors::white);
    std::cout << "Benda\n";
    std::cout << "                                      \n\n";
    setColor(Colors::selected);
    std::cout << "[ENTER] Return to the kingdom as a HERO\n";
    setColor(Colors::white);
}

