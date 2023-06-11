#pragma once
#include "node.hpp"

class Edge{
    public:
    
    Node* from;
    Node* to;
    int cost;


    Edge();
    Edge(Node* from, Node* to, int cost);
    virtual int getCost();
    virtual Node* getFrom();
    virtual Node* getTo();

    friend std::ostream &operator<<(std::ostream& os, Edge& edge);
};