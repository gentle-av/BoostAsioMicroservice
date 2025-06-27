#pragma once
#include "request_handler.hpp"

class CalculatorHandler : public RequestHandler {
public:
    RequestHandlerString* handle_request(const RequestHandlerString* request) override;
};
