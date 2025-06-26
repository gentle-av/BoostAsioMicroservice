#pragma once

class RequestHandler;

class Microservice {
public:
  Microservice(unsigned short port, RequestHandler* handler);
  ~Microservice();
  
  void run();
  void stop();

private:
  struct Impl;
  Impl* pimpl;
};
