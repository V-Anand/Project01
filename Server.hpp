#pragma once
#include <string>

namespace data {

    class Server {
          std::string host_;
          int port_;

      public:
          Server(std::string const& host, int port);
          ~Server();

          Server(Server const&) = delete;
          Server& operator=(Server const&) = delete;

          Server(Server &&) = delete;
          Server& operator=(Server &&) = delete;
          
          void start();
    };
}