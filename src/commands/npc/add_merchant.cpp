#include "add_merchant.h"

AddMerchant::AddMerchant(const std::vector<Map *> &maps) {
    this->merchant = nullptr;
    this->maps = maps;
}

AddMerchant::~AddMerchant() {
    delete merchant;
}

void AddMerchant::addMerchant(const int currentLevel, const Position position) {
    merchant = new Merchant(position);
    maps[currentLevel]->putCharacterInPosition(position, '$');
}

Merchant *AddMerchant::getMerchant() const {
    return merchant;
}

void AddMerchant::setMerchantToNull() {
    merchant = nullptr;
}
