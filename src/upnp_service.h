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
    typedef void (*OnHttpRequest)(const Net::Socket &, const HttpRequest &);

    // 当一个HTTP响应信息到来时调用
    typedef void (*OnHttpResponse)(const Net::Socket &, const HttpResponse &);

    class UpnpService
    {
        unsigned short int udpPort, tcpPort;
        std::map<int, OnHttpRequest> events;

    public:
        UpnpService(unsigned short int u = 0, unsigned short int t = 0) : udpPort(u), tcpPort(t), events() { }

        OnHttpRequest RegisterCallback(int id, OnHttpRequest event)
        {
            auto ret = events.insert(std::pair(id, event));
            return ret.second ? ret.first : nullptr;
        }

        // 通过UDP发送请求消息
        int SendUdpMsg(const HttpRequest &request);

        // 通过TCP发送请求消息
        int SendTcpMsg(const HttpRequest &request, OnHttpResponse);
    };
}

#endif //UPNPCPP_UPNP_SERVICE_H
