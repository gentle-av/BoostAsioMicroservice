module microservice;

import <boost/asio.hpp>;
import <memory>;

using namespace boost::asio;
using ip::tcp;

class Microservice::Impl {
public:
  Impl(unsigned short port, RequestHandler* handler)
    : acceptor(io, tcp::endpoint(tcp::v4(), port)),
      handler(handler) {}
  
  void run() { io.run(); }
  void stop() { io.stop(); }
  
  void start_accept() {
    acceptor.async_accept(
      [this](boost::system::error_code ec, tcp::socket socket) {
        if (!ec) handle_connection(std::move(socket));
        start_accept();
      });
  }

private:
    void handle_connection(tcp::socket socket) {
      char data[1024];
      auto length = socket.read_some(buffer(data));
      auto response = handler->handle_request(data);
      write(socket, buffer(response, strlen(response)));
    }

    io_context io;
    tcp::acceptor acceptor;
    RequestHandler* handler;
};

Microservice::Microservice(unsigned short port, RequestHandler* handler)
  : pimpl(new Impl(port, handler)) {
  pimpl->start_accept();
}

Microservice::~Microservice() { delete pimpl; }
void Microservice::run() { pimpl->run(); }
void Microservice::stop() { pimpl->stop(); }
