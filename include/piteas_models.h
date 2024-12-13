/**
Piteas Data Models

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2024 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef INCLUDE_PITEAS_MODELS_H
#define INCLUDE_PITEAS_MODELS_H

#include "vk/tools/i_json.h"
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace vk::piteas {
using EthereumDecimal = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<18>>;
static const auto EthereumWEI = EthereumDecimal{"0.000000000000000001"};

struct Token final : IJson {
    std::string m_address;
    std::string m_symbol;
    int m_chainId;
    int m_decimals;

    [[nodiscard]] nlohmann::json toJson() const override;

    void fromJson(const nlohmann::json& json) override;
};

struct Quote final : IJson {
    Token m_srcToken;
    Token m_destToken;
    EthereumDecimal m_srcAmount;
    EthereumDecimal m_destAmount;
    std::int64_t m_gasUseEstimate;
    double m_gasUseEstimateUSD;

    [[nodiscard]] nlohmann::json toJson() const override;

    void fromJson(const nlohmann::json& json) override;
};
}
#endif // INCLUDE_PITEAS_MODELS_H
