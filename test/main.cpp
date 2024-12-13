/**
Piteas test

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2024 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include "piteas_client.h"
#include <boost/multiprecision/cpp_int.hpp>

int main() {
    const vk::piteas::Client client{};
    const vk::piteas::EthereumDecimal million{"1000000"};
    const auto result = client.getQuote("PLS", "0xefD766cCb38EaF1dfd701853BFCe31359239F305", million, 0.50, "");
    return getchar();
}
