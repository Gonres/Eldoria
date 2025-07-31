//
// Created by Lukyn on 06.12.2024.
//

#ifndef SCENES_H
#define SCENES_H
#include "../domain/entities/player.h"
#include "../domain/value_objects/items/armor.h"
#include "../domain/value_objects/items/potion.h"
#include "../domain/value_objects/items/weapon.h"

class Scenes {
    int m_currentScene;

public:
    Scenes();

    void printScenes() const;

    void printEndGame() const;

    void setCurrentScene(int currentScene);

    void incrementCurrentScene();

    int getCurrentScene() const;

    //Scene text
    void continueHint() const;

    void prologText1() const;

    void prologText2() const;

    void prologText3() const;

    void prologText4() const;

    //Scene arts
    void prologArt1() const;

    void prologArt2() const;

    void prologArt3() const;

    void prologArt4() const;

    //Whole cutscenes
    void sceneProlog1() const;

    void sceneProlog2() const;

    void sceneProlog3() const;

    void sceneProlog4() const;

    //END of GAME scenes
    void sceneDeathScreen() const;

    void sceneBossDefeat() const;

    void sceneTheEnd() const;

    void sceneCredits() const;

    //Menu scenes
    void sceneHeaderMenu() const;

    void sceneSmallHeaderMenu() const;

    void sceneMainSelectedPlay() const;

    void sceneMainSelectedCredits() const;

    void sceneMainSelectedHTP() const;

    void sceneMainSelectedExit() const;

    void sceneCreditsMenu() const;

    void sceneHTPMenu() const;

    void sceneRoleSelectedWarrior() const;

    void sceneRoleSelectedArcher() const;

    void sceneRoleSelectedMage() const;

    //Shop scenes
    void sceneShopHeader() const;

    void sceneShopWeaponHeader(Player *player) const;

    void sceneShopArmorHeader(Player *player) const;

    void sceneShopPotionHeader(Player *player) const;

    void sceneShopHint() const;

    void sceneShopOwnedWeapon(Player *player, Weapon *weapon) const;

    void sceneShopOwnedArmor(Player *player, Armor *armor) const;

    void sceneShopMainSelectedWeapons() const;

    void sceneShopMainSelectedArmor() const;

    void sceneShopMainSelectedPotions() const;

    void sceneShopMainSelectedExit() const;

    void sceneShopWeaponsSelectedWeapon1(Player *player, Weapon *weapon) const;

    void sceneShopWeaponsSelectedWeapon2(Player *player, Weapon *weapon) const;

    void sceneShopWeaponsSelectedWeapon3(Player *player, Weapon *weapon) const;

    void sceneShopArmorSelectedArmor1(Player *player, Armor *armor) const;

    void sceneShopArmorSelectedArmor2(Player *player, Armor *armor) const;

    void sceneShopArmorSelectedArmor3(Player *player, Armor *armor) const;

    void sceneShopPotionsSelectedPotion1(Potion *potion) const;
};

#endif //SCENES_H
