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
};
}
#endif // INCLUDE_PITEAS_CLIENT_H
