#ifndef ADD_MERCHANT_H
#define ADD_MERCHANT_H
#include <vector>

#include "../command.h"
#include "../../domain/value_objects/merchant.h"
#include "../../map/map.h"

class AddMerchant final : public Command {
public:
    AddMerchant(Map *map, Position position);

    static Merchant *getMerchant();

    static void setMerchantToNull();

private:
    inline static Merchant *merchant = nullptr;
    Map *map;
    Position position;

    void execute() override;
};

#endif //ADD_MERCHANT_H
