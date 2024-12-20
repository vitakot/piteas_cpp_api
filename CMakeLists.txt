cmake_minimum_required(VERSION 3.16)
project(piteas_api)

set(CMAKE_CXX_STANDARD 20)

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

find_package(OpenSSL REQUIRED)

if (NOT TARGET vk_tools)
    add_subdirectory(vk_cpp_tools)
endif()

include_directories(include vk_cpp_tools/include SYSTEM ${OPENSSL_INCLUDE_DIR})

set(HEADERS include/piteas_client.h
        include/piteas_http_session.h
        include/piteas_models.h)

set(SOURCES src/piteas_client.cpp
        src/piteas_http_session.cpp
        src/piteas_models.cpp)

add_library(piteas_api OBJECT ${SOURCES} ${HEADERS})
target_link_libraries(piteas_api PRIVATE OpenSSL::Crypto OpenSSL::SSL vk_tools)

add_executable(test_piteas_api test/main.cpp)
target_link_libraries(test_piteas_api PRIVATE piteas_api)