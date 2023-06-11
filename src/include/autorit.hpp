#pragma once
#include "Edge.hpp"
#include "Node.hpp"

class Autorit: public Edge{
    
    public:
        Autorit();
        Autorit(Node* from, Node* to, int cost);
        int getCost() override;
        Node* getFrom() override;
        Node* getTo() override;
};