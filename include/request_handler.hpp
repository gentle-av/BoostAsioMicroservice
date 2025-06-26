#pragma once

// Предварительное объявление для строки
struct RequestHandlerString;

class RequestHandler {
public:
    virtual ~RequestHandler() = 0;
    
    virtual RequestHandlerString* handle_request(const RequestHandlerString* request) = 0;
    virtual RequestHandlerString* make_error_response(const char* error_msg);
    
    // Методы для работы со строками
    static RequestHandlerString* create_string(const char* str);
    static void destroy_string(RequestHandlerString* str);
    static const char* get_cstring(const RequestHandlerString* str);
};
