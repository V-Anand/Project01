#include "Server.hpp"
#include <iostream>

using namespace data;

Server::Server(std::string const& host, int port)
    : host_(host)
    , port_(port)
{
}

Server::~Server()
{
}

void Server::start()
{
   std::cerr << "Server started @ " << host_ << ":" << port_ << std::endl;
}