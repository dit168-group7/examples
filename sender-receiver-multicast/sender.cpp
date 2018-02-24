#include <chrono>
#include <iostream>

#include "cluon/UDPSender.hpp"
#include "cluon/ToProtoVisitor.hpp"

#include "messages.hpp"
using namespace std;

int main(int /*argc*/, char** /*argv*/) {
    cluon::UDPSender sender{"225.0.0.111", 8080};
    
    uint16_t value;
    
    while (true) {
        cout << "Enter a value: ";
        cin >> value;
        
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
        string data{encoder.encodedData()};
        sender.send(std::move(data));
    }
    
    return 0;
}    
