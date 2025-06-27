#include "../include/microservice.hpp"
#include "./microservice_private.hpp"

Microservice::Microservice(unsigned short port, RequestHandler* handler)
  : pimpl(new Impl(port, handler)) {}

Microservice::~Microservice() {
  delete pimpl;
}

void Microservice::run() {
  pimpl->run();
}

void Microservice::stop() {
  pimpl->stop();
}
