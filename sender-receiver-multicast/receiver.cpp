#include <chrono>
#include <iostream>

#include "cluon/UDPReceiver.hpp"
#include "cluon/FromProtoVisitor.hpp"

#include "messages.hpp"
using namespace std;


int main(int /*argc*/, char** /*argv*/) {
    cluon::UDPReceiver receiver("225.0.0.111", 8080, []
        (string &&data, string &&/*from*/, chrono::system_clock::time_point &&/*timepoint*/) noexcept {
            stringstream sstr{data};
            
            cluon::FromProtoVisitor decoder;
            decoder.decodeFrom(sstr);
            
            Handshake msg;
            msg.accept(decoder);
            
            cout << "Received multicast message: " << msg.identity() << endl;
        }
    );
    
    using namespace literals::chrono_literals;
    while (receiver.isRunning()) {
        this_thread::sleep_for(1s);
    }
    
    return 0;
}
