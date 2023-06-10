#pragma once
#include "Edge.hpp"
#include "Node.hpp"

class Treinrit: public Edge{

    public:
        Treinrit(Node* from, Node* to, int cost);
        int getCost() override;
        Node* getFrom() override;
        Node* getTo() override;
};
