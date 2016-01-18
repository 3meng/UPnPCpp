//
// Created by qife on 16/1/18.
//

#ifndef UPNPCPP_UTYPE_H
#define UPNPCPP_UTYPE_H

namespace UPnPCpp
{
    template<typename B, typename D>
    struct UType
    {
        using type = D;

    private:
        // 添加约束, 限制B类型为D类型基类.
        void constraint()
        {
            D *pd;
            B *pb = static_cast<B *>(pd);
        }
    };

    // 头文件以同样方式引入...
#if defined(__WINDOWS)
    // using HttpService = UType<HttpBase, WindowsHttpService>::type;
#elif defined(__LINUX)
    // using HttpService = UType<HttpBase, LinuxHttpService>::type;
#elif defined(__OS_X)
    // using HttpService = UType<HttpBase, OSXHttpService>::type;
#else
    // using HttpService = UType<HttpBase, HttpBase>::type;
#endif
}

#endif //UPNPCPP_UTYPE_H
