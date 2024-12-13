/**
Piteas Client

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2024 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include "piteas_client.h"
#include "piteas_http_session.h"
#include <future>
#include <nlohmann/json.hpp>

namespace vk::piteas {
struct Client::P {
    Client* m_parent = nullptr;
    std::shared_ptr<HTTPSession> m_httpSession{};

    explicit P(Client* parent) {
        m_parent = parent;
    }
};

http::response<http::string_body> checkResponse(const http::response<http::string_body>& response) {
    if (response.result() != http::status::ok) {
        const std::string msg = std::string("Bad HTTP response: ") + std::to_string(response.result_int());
        throw std::runtime_error(msg.c_str());
    }
    return response;
}

Client::Client() : m_p(std::make_unique<P>(this)) {
    m_p->m_httpSession = std::make_shared<HTTPSession>();
}

Client::~Client() = default;

Quote Client::getQuote(const std::string& tokenInAddress, const std::string& tokenOutAddress, const EthereumDecimal& amount,
                       const float allowedSlippage, const std::string& account) const {

    std::string path = "/quote?";

    path.append("tokenInAddress=");
    path.append(tokenInAddress);

    path.append("&tokenOutAddress=");
    path.append(tokenOutAddress);

    auto amountWithDecimals = amount/EthereumWEI;
    path.append("&amount=");
    path.append(amountWithDecimals.convert_to<std::string>());

    path.append("&allowedSlippage=");
    path.append(std::to_string(allowedSlippage));

    if (!account.empty()) {
        path.append("&account=");
        path.append(account);
    }

    const auto response = checkResponse(m_p->m_httpSession->get(path));

    Quote quote;
    quote.fromJson(nlohmann::json::parse(response.body()));
    return quote;
}
}
