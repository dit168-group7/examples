#include <chrono>
#include <iostream>

#include "cluon/UDPReceiver.hpp"
#include "cluon/FromProtoVisitor.hpp"

#include "messages.hpp"


int main(int /*argc*/, char** /*argv*/) {
    cluon::UDPReceiver receiver("0.0.0.0", 8000, []
        (std::string &&data, std::string &&/*from*/, std::chrono::system_clock::time_point &&/*timepoint*/) noexcept {
            std::stringstream sstr{data};
            
            cluon::FromProtoVisitor decoder;
            decoder.decodeFrom(sstr);
            
            Handshake msg;
            msg.accept(decoder);
            
            std::cout << "Received: " << msg.identity() << std::endl;
        }
    );
    
    using namespace std::literals::chrono_literals;
    while (receiver.isRunning()) {
        std::this_thread::sleep_for(1s);
    }
    
    return 0;
}
