/**
Piteas Client

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2024 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef INCLUDE_PITEAS_CLIENT_H
#define INCLUDE_PITEAS_CLIENT_H

#include <memory>
#include "piteas_models.h"

namespace vk::piteas {

class Client {
    struct P;
    std::unique_ptr<P> m_p{};

public:
    Client();
    ~Client();

    /**
     * Get swap quote on Piteas SDK on Pulsechain
     *
     * @param tokenInAddress Example: 0x2A06a971fE6ffa002fd242d437E3db2b5cC5B433 Use PLS for native token
     * @param tokenOutAddress Example: 0x2A06a971fE6ffa002fd242d437E3db2b5cC5B433 Use PLS for native token
     * @param amount Amount with decimals
     * @param allowedSlippage Default: 0.5
     * @param account Receiver address. Not required and default account is msg.sender.
     * @return 
     */
    [[nodiscard]] Quote getQuote(const std::string& tokenInAddress, const std::string& tokenOutAddress,
                                 const EthereumDecimal& amount, float allowedSlippage,
                                 const std::string& account) const;
};
}
#endif // INCLUDE_PITEAS_CLIENT_H
