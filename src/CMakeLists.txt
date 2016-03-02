cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(../include)
include_directories(../interface)

set(UPNPCPP_SOURCE UPnP.cpp http_message.cpp http_message.h upnp_service.cpp upnp_service.h)

add_library(UPnPCpp ${UPNPCPP_SOURCE})
