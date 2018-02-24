#include <chrono>
#include <iostream>

#include "cluon/UDPSender.hpp"
#include "cluon/ToProtoVisitor.hpp"

#include "messages.hpp"


int main(int /*argc*/, char** /*argv*/) {
    cluon::UDPSender sender{"127.0.0.1", 8000};
    
    uint16_t value;
    
    while (true) {
        std::cout << "Enter a value: ";
        std::cin >> value;
        
        if (value == 1) {
            break;
        }
        std::cout << std::endl;
        
        // Assign input value
        Handshake msg;
        msg.identity(value);
        
        // Encode input
        cluon::ToProtoVisitor encoder;
        msg.accept(encoder);
        
        // String pack the data
        std::string data{encoder.encodedData()};
        sender.send(std::move(data));
    }
    
    return 0;
}    
