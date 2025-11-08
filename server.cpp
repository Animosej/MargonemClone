// server.cpp
#include <SFML/Network.hpp>
#include <string>
#include <iostream>

int main() {
    sf::TcpListener listener;
    if (listener.listen(53000) != sf::Socket::Done) {
        std::cerr << "Error: Cannot bind to port 53000" << std::endl;
        return -1;
    }
    
    std::cout << "Server listening on port 53000..." << std::endl;
    
    sf::TcpSocket client;
    if (listener.accept(client) == sf::Socket::Done) {
        std::cout << "Client connected!" << std::endl;
        std::string msg = "Witaj w Margonem Clone!";
        client.send(msg.c_str(), msg.size() + 1);
    }
    
    return 0;
}