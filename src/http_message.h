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
     * Http请求报文
     */
    struct HttpRequest
    {
        const char *method;
        const char *url;
        const char *version;
        std::list<std::pair<const char *, const char *>> headers;
        const char *body;

        HttpRequest(const char *m, const char *u, const char *v = "HTTP/1.1") : method(m), url(u), version(v),
                                                                                headers() { }
    };

    void Build(const HttpRequest &httpRequest, std::string &request);

    /*
     * HTTP响应报文
     */
    struct HttpResponse
    {
        const char *version;
        int code;
        const char *status;
        std::list<std::pair<const char *, const char *>> headers;
        const char *body;

        HttpResponse(int c, const char *s, const char *v = "HTTP/1.1") : version(v), code(c), status(s) { }
    };

    void Build(const HttpResponse &httpResponse, std::string &response);
}

#endif //UPNPCPP_HTTP_BUILDER_H
