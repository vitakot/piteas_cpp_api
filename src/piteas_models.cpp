/**
Piteas Data Models

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2024 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include "piteas_models.h"
#include "vk/tools/json_utils.h"
#include <boost/multiprecision/cpp_int.hpp>

namespace vk::piteas {
nlohmann::json Token::toJson() const {
    throw std::runtime_error("Unimplemented: Token::toJson()");
}

void Token::fromJson(const nlohmann::json& json) {
    readValue<std::string>(json, "address", m_address);
    readValue<std::string>(json, "symbol", m_symbol);
    readValue<int>(json, "chainId", m_chainId);
    readValue<int>(json, "decimals", m_decimals);
}

nlohmann::json Quote::toJson() const {
    throw std::runtime_error("Unimplemented: Quote::toJson()");
}

void Quote::fromJson(const nlohmann::json& json) {
    m_srcToken.fromJson(json["srcToken"]);
    m_destToken.fromJson(json["destToken"]);

    std::string srcAmountString;
    std::string destAmountString;

    readValue<std::string>(json, "srcAmount", srcAmountString);
    readValue<std::string>(json, "destAmount", destAmountString);

    const boost::multiprecision::int128_t srcAmount(srcAmountString);
    const boost::multiprecision::int128_t destAmount(destAmountString);

    m_srcAmount = EthereumDecimal(srcAmount) * EthereumWEI;
    m_destAmount = EthereumDecimal(destAmount) * EthereumWEI;

    readValue<std::int64_t>(json, "gasUseEstimate", m_gasUseEstimate);
    readValue<double>(json, "gasUseEstimateUSD", m_gasUseEstimateUSD);
}
}
