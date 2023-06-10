#pragma once
#include "Edge.hpp"
#include "Node.hpp"

class Vlucht: public Edge{

    public:
        Vlucht(Node* from, Node* to, int cost);
        int getCost() override;
        Node* getFrom() override;
        Node* getTo() override;
};