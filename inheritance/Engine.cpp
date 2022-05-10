#include "Engine.h"

Engine::Engine() {
    horsePower = 0;
}

Engine::Engine(const string& id, const string& manifacturer, const string& comment, unsigned short horsePower) : CarPart(id, manifacturer, comment) {
    this->horsePower = horsePower;
}



const unsigned short Engine::getHorsePower() const {
    return horsePower;
}
