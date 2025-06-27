#include "../include/request_handler.hpp"
#include <cstdlib>
#include <cstring>

struct RequestHandlerString {
  char* data;
};

RequestHandler::~RequestHandler() = default;

RequestHandlerString* RequestHandler::create_string(const char* str) {
  auto* s = new RequestHandlerString;
  s->data = strdup(str);
  return s;
}

void RequestHandler::destroy_string(RequestHandlerString* str) {
  free(str->data);
  delete str;
}

const char* RequestHandler::get_cstring(const RequestHandlerString* str) {
  return str ? str->data : "";
}

RequestHandlerString* RequestHandler::make_error_response(const char* error_msg) {
  return create_string(error_msg);
}
