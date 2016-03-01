//
// Created by qife on 16/2/29.
//
// Socket抽象接口
//

#ifndef UPNPCPP_SOCKET_H
#define UPNPCPP_SOCKET_H

#include "nettype.h"

namespace UPnP
{
    namespace Net
    {
        template<typename T>
        class BasicSocket
        {
            T t;

            BasicSocket(T var) : t(var) { }

        public:
            BasicSocket(ProtocolType type) : t(type) { }

            // 将socket绑定到指定的地址上
            int Bind(SocketAddr &address) { return t.Bind(address); }

            // 连接到远程地址
            int Connect(SocketAddr &address) { return t.Connect(address); }

            // 开始监听.参数指示请求连接队列中最大等待连接个数
            int Listen(int backlog) { return t.Listen(backlog); }

            // 接受一个远程连接请求,参数中存储远程计算机的地址信息,返回一个新的套接字
            BasicSocket<T> Accept(SocketAddr &address) { return BasicSocket(t.Accept(address)); }

            // 发送数据
            int Send(const void *msg, int len, int flags = 0) { return t.Send(msg, len, flags); }

            // 接收数据
            int Recv(void *buff, int len, unsigned int flags = 0) { return t.Recv(buff, len, flags); }

            // 关闭套接字
            void Close() { t.Close(); }

            // 停用套接字指定功能
            int Shutdown(int how) { return t.Shutdown(how); }

            // 获取Socket选项
            int GetSocketOption(int level, int name, char *value, int *len)
            {
                return t.GetSocketOption(level, name, value, len);
            }

            // 设置Socket选项
            int SetSocketOption(int level, int name, char *value, int *len)
            {
                return t.SetSocketOption(level, name, value, len);
            }

            // 获取远程连接的套接字地址信息
            int GetPeerName(SocketAddr &address) { return t.GetPeerName(address); }

            // 获取错误代码(可能平台相关)
            int GetErrorCode() { return t.GetErrorCode(); }
        };

        template<typename T>
        struct BasicSocketUtils
        {
        public:
            // 将参数指定的unsigned long正数转换为网络字符顺序
            unsigned long int HtoNl(unsigned long int hostLong) { return T.HtoNl(hostLong); }

            // 获取本地主机名称
            int GetHostName(std::string &hostname) { return T.GetHostName(hostname); }

            // 根据主机名获取主机地址及相关信息
            bool GetHostByName(const std::string &name, HostEnt &hostEnt) { return T.GetHostByName(name, hostEnt); }
        };
    }
}

#endif //UPNPCPP_SOCKET_H
