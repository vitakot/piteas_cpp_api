cmake_minimum_required(VERSION 3.16)
project(piteas_ccapi)

set(CMAKE_CXX_STANDARD 20)
find_package(Boost 1.78 REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(include SYSTEM ${Boost_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR})

set(HEADERS include/piteas_client.h
        include/piteas_http_session.h
        include/piteas_models.h)

set(SOURCES src/piteas_client.cpp
        src/piteas_http_session.cpp
        src/piteas_models.cpp)

add_library(piteas_ccapi OBJECT ${SOURCES} ${HEADERS})
target_link_libraries(piteas_ccapi PRIVATE OpenSSL::Crypto OpenSSL::SSL)

add_executable(test test/main.cpp)
target_link_libraries(test PRIVATE piteas_ccapi)