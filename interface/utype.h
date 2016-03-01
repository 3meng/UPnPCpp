//
// Created by qife on 16/1/18.
//

#ifndef UPNPCPP_UTYPE_H
#define UPNPCPP_UTYPE_H

#include "socket.h"

#if defined(__WINDOWS)

#elif defined(__LINUX)

#elif defined(__OS_X)

#else

#include "placeholder.h"

#endif

namespace UPnP
{
    namespace Net
    {
#if defined(__WINDOWS)
        //
#elif defined(__LINUX)
        // typedef BasicSocket<something> Socket;
        // typedef BasicSocketUtils<something> SocketUtils;
#elif defined(__OS_X)
        //
#else
        typedef BasicSocket<SocketPlaceHolder> Socket;
        typedef BasicSocketUtils<SocketUtilsPlaceHolder> SocketUtils;
#endif
    }
}

#endif //UPNPCPP_UTYPE_H
