#include <chrono>
#include <iostream>
#include <cstdint>

#include "cluon/OD4Session.hpp"
#include "cluon/Envelope.hpp"
#include "messages.hpp"


int main(int /*argc*/, char** /*argv*/) {
    cluon::OD4Session *receiver = new cluon::OD4Session(111, 
        [](cluon::data::Envelope &&envelope) noexcept {
            std::cout << envelope.dataType() << std::endl;
    });
    
    using namespace std::literals::chrono_literals;
    while (receiver->isRunning()) {
        std::this_thread::sleep_for(1s);
    }
    
    return 0;
}
