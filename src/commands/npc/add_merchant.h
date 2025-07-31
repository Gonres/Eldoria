#ifndef ADD_MERCHANT_H
#define ADD_MERCHANT_H
#include <vector>

#include "../../domain/value_objects/merchant.h"
#include "../../map/map.h"

class AddMerchant {
public:
    explicit AddMerchant(const std::vector<Map *> &maps);

    ~AddMerchant();

    void addMerchant(int currentLevel, Position position);

    Merchant *getMerchant() const;

    void setMerchantToNull();

private:
    Merchant *merchant;
    std::vector<Map *> maps;
};

#endif //ADD_MERCHANT_H
