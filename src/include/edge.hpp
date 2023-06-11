#pragma once
#include "node.hpp"

class Edge{
    public:
    
    Node* from;
    Node* to;
    int cost;


    Edge();
    Edge(Node* from, Node* to, int cost);
    virtual int getCost() = 0;
    virtual Node* getFrom() = 0;
    virtual Node* getTo() = 0;

    friend std::ostream &operator<<(std::ostream& os, Edge& edge);
};