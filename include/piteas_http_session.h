/**
Piteas HTTPS Session

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2024 Vitezslav Kot <vitezslav.kot@gmail.com>.
*/

#ifndef INCLUDE_PITEAS_HTTP_SESSION_H
#define INCLUDE_PITEAS_HTTP_SESSION_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <string>

namespace vk::piteas {
namespace beast = boost::beast;
namespace http = beast::http;

class HTTPSession {
    struct P;
    std::unique_ptr<P> m_p{};

public:
    HTTPSession();
    ~HTTPSession();
    http::response<http::string_body> get(const std::string& target) const;
};
}
#endif // INCLUDE_PITEAS_HTTP_SESSION_H
