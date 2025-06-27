#include "../include/microservice.hpp"
#include "echo_handler.hpp"
#include "calculator_handler.hpp"
#include <memory>

int main() {
  auto handler = std::make_unique<CalculatorHandler>();
  Microservice service(8080, handler.get());
  service.run();
  return 0;
}
