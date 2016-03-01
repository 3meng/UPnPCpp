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
            unsigned long int IP;
            unsigned short int Port;
        };

        struct HostEnt
        {
            std::string Name;
            std::list<std::string> Aliases;
            int AddressType;
            std::list<std::string> AddressList;
        };
    }
}

#endif //UPNPCPP_NETTYPE_H
