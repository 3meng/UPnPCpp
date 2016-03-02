//
// Created by qife on 16/3/2.
//

#ifndef UPNPCPP_UPNP_SERVICE_H
#define UPNPCPP_UPNP_SERVICE_H

#include <map>

#include "utype.h"
#include "http_message.h"

namespace UPnP
{
    // 使用回调响应客户端请求.对于HTTP请求,同时在回调中返回响应消息
    typedef void (*UpnpCallback)(const Net::Socket &, const HttpRequest &);

    class UpnpService
    {
        unsigned short int udpPort, tcpPort;
        std::map<int, UpnpCallback> events;

    public:
        UpnpService(unsigned short int u = 0, unsigned short int t = 0) : udpPort(u), tcpPort(t) { }

        UpnpCallback RegisterCallback(int id, UpnpCallback event)
        {
            auto ret = events.insert(std::pair(id, event));
            return ret.second ? ret.first : nullptr;
        }

        // 通过UDP发送请求消息
        int SendUdpMsg(const HttpRequest &request);

        // 通过TCP发送请求消息
        int SendTcpMsg(const HttpRequest &request, HttpResponse &response);
    };
}

#endif //UPNPCPP_UPNP_SERVICE_H
