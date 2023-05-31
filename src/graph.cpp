
#include "include/graph.hpp"

Graph::Graph(std::vector<Node*> nodes, std::vector<Edge*> edges) : nodes(nodes),edges(edges){};

Edge* Graph::getEdgeBetweenNodes(Node* from, Node* to){
    for(Edge* edge : from->edges){
        if(edge->to == to){
            return edge;
        }
    }
    return nullptr; //Niet mooi, werkt wel
}

int Graph::getCostOfPath(std::vector<Node*> nodesToVisit) {
    int totalCosts = 0;
    for(int i = 0; i < nodesToVisit.size() -1; i++){
        totalCosts  += getEdgeBetweenNodes(nodesToVisit[i], nodesToVisit[i+1])->cost ;
    }
    
    //Calculate total costs 
    return totalCosts;
}