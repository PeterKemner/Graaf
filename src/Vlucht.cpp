#include "../src/include/Vlucht.hpp"
#include "../src/include/Node.hpp"

Vlucht::Vlucht(Node* from, Node* to, int cost){
    this->from = from;
    this->to = to;
    this->cost = cost;
};

int Vlucht::getCost(){
    return this->cost;
};

Node* Vlucht::getFrom(){
    return this->from;
};

Node* Vlucht::getTo(){
    return this->to;
}