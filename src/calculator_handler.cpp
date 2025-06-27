#include "../include/calculator_handler.hpp"
#include "../include/request_handler.hpp"
#include <cstdio>

RequestHandlerString* CalculatorHandler::handle_request(const RequestHandlerString* request) {
    try {
        const char* req = RequestHandler::get_cstring(request);
        // ... реализация калькулятора ...
        char* result = new char[64];
        sprintf(result, "RESULT: %f", 42.0); // Упрощенный пример
        return RequestHandler::create_string(result);
    } catch (...) {
        return make_error_response("Calculation error");
    }
}
