#include "add_merchant.h"

AddMerchant::AddMerchant(
    Map *map,
    const Position position
) : position(position) {
    this->map = map;
}

Merchant *AddMerchant::getMerchant() {
    return merchant;
}

void AddMerchant::setMerchantToNull() {
    merchant = nullptr;
}

void AddMerchant::execute() {
    merchant = new Merchant(position);
    map->putCharacterInPosition(position, '$');
}
