#include "../src/include/autorit.hpp"
#include "../src/include/Node.hpp"

Autorit::Autorit(Node* from, Node* to, int cost){
    this->from = from;
    this->to = to;
    this->cost = cost;
};

int Autorit::getCost(){
    return this->cost;
};

Node* Autorit::getFrom(){
    return this->from;
};

Node* Autorit::getTo(){
    return this->to;
};