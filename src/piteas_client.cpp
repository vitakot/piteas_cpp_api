/**
Piteas Client

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2024 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#include "piteas_client.h"
#include "piteas_http_session.h"
#include <future>

namespace vk::piteas {
struct Client::P {
    Client* m_parent = nullptr;
    std::shared_ptr<HTTPSession> m_httpSession{};

    explicit P(Client* parent) {
        m_parent = parent;
    }
};

Client::Client() : m_p(std::make_unique<P>(this)) {
    m_p->m_httpSession = std::make_shared<HTTPSession>();
}

Client::~Client() = default;
}
