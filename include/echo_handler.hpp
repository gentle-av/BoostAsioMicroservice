#pragma once
#include "request_handler.hpp"

class EchoHandler : public RequestHandler {
public:
    RequestHandlerString* handle_request(const RequestHandlerString* request) override;
};
