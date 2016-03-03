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

            // 获取套接字所使用传输协议
            ProtocolType GetProtocolType() const { return t.GetProtocolType(); }

            // 将socket绑定到指定的地址上
            int Bind(SocketAddr &address) const { return t.Bind(address); }

            // 连接到远程地址
            int Connect(SocketAddr &address) const { return t.Connect(address); }

            // 开始监听.参数指示请求连接队列中最大等待连接个数
            int Listen(int backlog) const { return t.Listen(backlog); }

            // 接受一个远程连接请求,参数中存储远程计算机的地址信息,返回一个新的套接字
            BasicSocket<T> Accept(SocketAddr &address) const { return BasicSocket(t.Accept(address)); }

            // 发送数据
            int Send(const void *msg, int len, int flags = 0) const { return t.Send(msg, len, flags); }

            // 接收数据
            int Receive(void *buff, int len, unsigned int flags = 0) const { return t.Receive(buff, len, flags); }

            // 发送到指定地址
            int SendTo(const char *msg, int len, int flags, const SocketAddr &address, int toLen) const
            {
                return t.SendTo(msg, len, flags, address, toLen);
            }

            // 接收一个数据报数据
            int ReceiveFrom(char *buff, int len, int flags, SocketAddr &address, int &fromLen) const
            {
                return t.ReceiveFrom(buff, len, flags, address, fromLen);
            }

            // 关闭套接字
            void Close() const { t.Close(); }

            // 停用套接字指定功能
            int Shutdown(int how) const { return t.Shutdown(how); }

            // 加入一个组播
            int AddMembership(const GroupRequest &req) const { return t.AddMembership(req); }

            // 离开一个组播
            int DropMembership(const GroupRequest &req) const { return t.DropMembership(req); }

            // 获取Socket选项
            int GetSocketOption(int level, int name, char *value, int len) const
            {
                return t.GetSocketOption(level, name, value, len);
            }

            // 设置Socket选项
            int SetSocketOption(int level, int name, char *value, int len) const
            {
                return t.SetSocketOption(level, name, value, len);
            }

            // 获取远程连接的套接字地址信息
            int GetPeerName(SocketAddr &address) const { return t.GetPeerName(address); }

            // 获取错误代码(可能平台相关)
            int GetErrorCode() const { return t.GetErrorCode(); }
        };

        template<typename T>
        struct BasicSocketUtils
        {
        public:
            // 将long参数从本机序转换为网络字符顺序
            static unsigned long int HtoNl(unsigned long int x) { return T::HtoNl(x); }

            // 将long参数从网络字节序转换为本机序
            static unsigned long int NtoHl(unsigned long int x) { return T::NtoHl(x); }

            // 将short参数从本机序转换为网络字节序
            static unsigned short int HtoNs(unsigned short int x) { return T::HtoNs(x); }

            // 将short参数从网络序转换为本机序
            static unsigned short int NtoHs(unsigned short int x) { return T::NtoHs(x); }

            // 从点分十进制表示的IP地址转换为一个对应的长整数(使用网络字节序)
            static unsigned long int InetAddr(const char *addr) { return T::InetAddr(addr); }

            // 从点分十进制表示的IP地址转换为一个对应的长整数(使用本机字节序)
            static unsigned long int InetNetwork(const char *addr) { return T::InetNetwork(addr); }

            // 将点分十进制表示的IP地址转换为一个对应长整数,转换成功返回非零,否则返回0
            static int InetAton(const char *addr, unsigned long int &ip) { return T::InetAton(addr, ip); }

            // 将一个长整数表示的IP地址转换为点分十进制表示
            static const char *InetNtoa(unsigned long int x) { return T::InetNtoa(x); }

            // 获取本地主机名称
            static int GetHostName(std::string &hostname) { return T::GetHostName(hostname); }

            // 根据主机名获取主机地址及相关信息
            static bool GetHostByName(const std::string &name, HostEnt &hostEnt)
            {
                return T::GetHostByName(name, hostEnt);
            }
        };
    }
}

#endif //UPNPCPP_SOCKET_H
