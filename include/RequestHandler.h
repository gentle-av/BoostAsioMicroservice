#pragma once

#include <string>

class RequestHandler {
public:
  virtual ~RequestHandler() = default;
  virtual std::string handle_request(const std::string &request) = 0;
  virtual std::string make_error_response(const std::string &error_msg);
};
