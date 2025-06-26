#include "echo_handler.hpp"
#include "request_handler.hpp"

RequestHandlerString* EchoHandler::handle_request(const RequestHandlerString* request) {
  const char* req_str = RequestHandler::get_cstring(request);
  char* response = new char[strlen(req_str) + 7];
  sprintf(response, "ECHO: %s", req_str);
  return RequestHandler::create_string(response);
}
