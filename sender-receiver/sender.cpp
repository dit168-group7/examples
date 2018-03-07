#include <chrono>
#include <iostream>
#include <cstdint>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "messages.hpp"


int main(int /*argc*/, char** /*argv*/) {
    cluon::OD4Session *sender = new cluon::OD4Session(111, 
        [](cluon::data::Envelope /*&&envelope*/) noexcept {});
    
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
     
        sender->send(msg);
    }
    
    return 0;
}    
