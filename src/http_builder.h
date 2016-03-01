//
// Created by qife on 16/3/2.
//

#ifndef UPNPCPP_HTTP_BUILDER_H
#define UPNPCPP_HTTP_BUILDER_H

#include <string>
#include <list>
#include <utility>

namespace UPnP
{
    /*
     * 使用Http报文格式生成字符串
     */
    struct HttpRequestBuilder
    {
        const char *method;
        const char *url;
        const char *version;
        std::list<std::pair<const char *, const char *>> headers;
        const char *body;

        HttpRequestBuilder(const char *m, const char *u, const char *v = "HTTP/1.1") : method(m), url(u), version(v),
                                                                                       headers() { }

        void Build(char *request);

        void Build(std::string &request);
    };
}

#endif //UPNPCPP_HTTP_BUILDER_H
