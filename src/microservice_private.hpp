#pragma once
#include "../include/request_handler.hpp"
#include <boost/asio.hpp>
#include <memory>

class Microservice::Impl {
  boost::asio::io_context io;
  boost::asio::ip::tcp::acceptor acceptor;
  RequestHandler* handler;
    
public:
  Impl(unsigned short port, RequestHandler* handler);
  void run();
  void stop();
  void start_accept();
  void handle_connection(boost::asio::ip::tcp::socket socket);
};
