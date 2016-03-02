//
// Created by qife on 16/3/2.
//

#include "http_message.h"

using namespace UPnP;

void UPnP::Build(const HttpRequest &httpRequest, std::string &request)
{
    request.append(httpRequest.method).push_back(' ');
    request.append(httpRequest.url).push_back(' ');
    request.append(httpRequest.version).append("\r\n");

    for (const auto &item : httpRequest.headers)
    {
        request.append(item.first).push_back(':');
        request.append(item.second).append("\r\n");
    }
    request.append("\r\n");

    request.append(httpRequest.body);
}

void UPnP::Build(const HttpResponse &httpResponse, std::string &response)
{
    response.append(httpResponse.version).push_back(' ');
    response.append(std::to_string(httpResponse.code)).push_back(' ');
    response.append(httpResponse.status).append("\r\n");

    for (const auto &item : httpResponse.headers)
    {
        response.append(item.first).push_back(':');
        response.append(item.second).append("\r\n");
    }
    response.append("\r\n");

    response.append(httpResponse.body);
}
