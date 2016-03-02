//
// Created by qife on 16/3/1.
//

#ifndef UPNPCPP_NETTYPE_H
#define UPNPCPP_NETTYPE_H

#include <string>
#include <list>

namespace UPnP
{
    namespace Net
    {
        enum class ProtocolType : char
        {
            TCP,
            UDP
        };

        struct SocketAddr
        {
            // 两个值都必须是网络字节序
            unsigned long int IP;
            unsigned short int Port;
        };

        struct HostEnt
        {
            std::string Name;
            std::list<std::string> Aliases;
            int AddressType;
            std::list<std::string> AddressList; // 每个地址都是网络字节序
        };

        struct GroupRequest
        {
            // 两个值都必须是网络字节序
            unsigned long int MultiAddress;
            unsigned long int Interface;
        };
    }
}

#endif //UPNPCPP_NETTYPE_H
