export module request_handler;

export class RequestHandler {
public:
  virtual ~RequestHandler();
  virtual const char *handle_request(const char *request) = 0;
  virtual const char *make_error_response(const char *error_msg);
};
