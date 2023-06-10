#pragma once
#include "node.hpp"
#include "edge.hpp"
#include "comparable.hpp"
#include <queue>

class Graph{
    private:
    std::vector<Edge*> edges;

    public:
    std::vector<Node*> nodes;
    std::priority_queue<Node*, std::vector<Node*>, NodeComparable> nogTeEvaluerenStations;
    Graph(std::vector<Node*> nodes, std::vector<Edge*> edges);
    Edge* getEdgeBetweenNodes(Node* from, Node* to);
    int getCostOfPath(std::vector<Node*> nodesToVisit);
    void evalueerBuren(Node* huidigstation);
    std::vector<Node*>dijkstra(Node* start, Node* end);
};