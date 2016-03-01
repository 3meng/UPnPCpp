cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(../include)

set(UPNPCPP_SOURCE UPnP.cpp http_builder.cpp http_builder.h)

add_library(UPnPCpp ${UPNPCPP_SOURCE})
