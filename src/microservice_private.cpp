#include "./microservice_private.hpp"
#include <iostream>

Microservice::Impl::Impl(unsigned short port, RequestHandler* handler)
  : acceptor(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
    handler(handler) {
  start_accept();
}

Microservice::Impl::~Impl() {
  if (acceptor.is_open()) {
    boost::system::error_code ec;
    auto a = acceptor.close(ec);
    if (ec) {
      std::cerr << "Error closing acceptor: " << ec.message() << "\n";
    }
  }
}

void Microservice::Impl::run() {
  io.run();
}

void Microservice::Impl::stop() {
  io.stop();
}

void Microservice::Impl::start_accept() {
  acceptor.async_accept(
    [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
      if (!ec) {
        handle_connection(std::move(socket));
      } else {
        std::cerr << "Accept error: " << ec.message() << "\n";
      }
      start_accept(); // Продолжаем принимать новые соединения
    });
}

void Microservice::Impl::handle_connection(boost::asio::ip::tcp::socket socket) {
  try {
    char data[1024];
    boost::system::error_code ec;
    
    size_t length = socket.read_some(boost::asio::buffer(data), ec);
    if (ec) {
      throw boost::system::system_error(ec);
    }

    auto* request = RequestHandler::create_string(data);
    auto* response = handler->handle_request(request);
    const char* response_str = RequestHandler::get_cstring(response);

    boost::asio::write(socket, boost::asio::buffer(response_str, strlen(response_str)));

    RequestHandler::destroy_string(request);
    RequestHandler::destroy_string(response);
  } catch (const std::exception& e) {
    std::cerr << "Connection error: " << e.what() << "\n";
  }
}
