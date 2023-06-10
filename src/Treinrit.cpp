#include "../src/include/treinrit.hpp"
#include "../src/include/Node.hpp"

Treinrit::Treinrit(Station* from, Station* to, int cost){
    this->from = from;
    this->to = to;
    this->cost = cost;
}

int Treinrit::getCost(){
    return this->cost;
};

Station* Treinrit::getFrom(){
    return this->from;
};

Station* Treinrit::getTo(){
    return this->to;
};