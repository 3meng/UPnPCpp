//
// Created by qife on 16/3/1.
//

#ifndef UPNPCPP_PLACEHOLDER_H
#define UPNPCPP_PLACEHOLDER_H

#include "nettype.h"

namespace UPnP
{
    namespace Net
    {
        class SocketPlaceHolder
        {
        public:
            SocketPlaceHolder(ProtocolType type) { }

            // 将socket绑定到指定的地址上
            int Bind(SocketAddr &address) { return -1; }

            // 连接到远程地址
            int Connect(SocketAddr &address) { return -1; }

            // 开始监听.参数指示请求连接队列中最大等待连接个数
            int Listen(int backlog) { return -1; }

            // 接受一个远程连接请求,参数中存储远程计算机的地址信息,返回一个新的套接字
            SocketPlaceHolder Accept(SocketAddr &address) { return SocketPlaceHolder(ProtocolType::TCP); }

            // 发送数据
            int Send(const void *msg, int len, int flags = 0) { return -1; }

            // 接收数据
            int Receive(void *buff, int len, unsigned int flags = 0) { return -1; }

            // 发送到指定地址
            int SendTo(const char *msg, int len, int flags, const SocketAddr &address, int toLen) { return -1; }

            // 接收一个数据报数据
            int ReceiveFrom(char *buff, int len, int flags, SocketAddr &address, int &fromLen) { return -1; }

            // 关闭套接字
            void Close() {  }

            // 停用套接字指定功能
            int Shutdown(int how) { return -1; }

            // 加入一个组播
            int AddMembership(const GroupRequest &req) { return -1; }

            // 离开一个组播
            int DropMembership(const GroupRequest &req) { return -1; }

            // 获取Socket选项
            int GetSocketOption(int level, int name, char *value, int *len) { return -1; }

            // 设置Socket选项
            int SetSocketOption(int level, int name, char *value, int *len) { return -1; }

            // 获取远程连接的套接字地址信息
            int GetPeerName(SocketAddr &address) { return -1; }

            // 获取错误代码(可能平台相关)
            int GetErrorCode() { return 0; }
        };

        struct SocketUtilsPlaceHolder
        {
            // 将参数指定的unsigned long正数转换为网络字符顺序
            unsigned long int HtoNl(unsigned long int hostLong) { return hostLong; }

            // 获取本地主机名称
            int GetHostName(std::string &hostname) { return 0; }

            // 根据主机名获取主机地址及相关信息
            bool GetHostByName(const std::string &name, HostEnt &hostEnt) { return false; }
        };
    }
}

#endif //UPNPCPP_PLACEHOLDER_H
