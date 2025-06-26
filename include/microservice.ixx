export module microservice;

import request_handler;

export class Microservice {
public:
  Microservice(unsigned short port, RequestHandler *handler);
  ~Microservice();

  void run();
  void stop();

private:
  class Impl;
  Impl *pimpl;
};
