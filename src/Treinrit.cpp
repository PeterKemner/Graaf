#include "../src/include/treinrit.hpp"
#include "../src/include/Node.hpp"

Treinrit::Treinrit(Node* from, Node* to, int cost){
    this->from = from;
    this->to = to;
    this->cost = cost;
}

int Treinrit::getCost(){
    return this->cost;
};

Node* Treinrit::getFrom(){
    return this->from;
};

Node* Treinrit::getTo(){
    return this->to;
};