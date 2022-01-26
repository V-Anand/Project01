#include <iostream>
#include "Server.hpp"

int main() {
  int rc = 0;
  try {
    data::Server s("localhost", 8080);
    s.start();
  } catch (...) {
    std::cerr << "Unknown Error" << std::endl;
    rc = 1;
  }
  return rc;
}