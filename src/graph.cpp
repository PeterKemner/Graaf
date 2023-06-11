#include <map>
#include "include/graph.hpp"
#include <queue>

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

void Graph::evalueerBuren(Node* huidigstation) {
	for (Edge* stap : huidigstation->edges){
		if (stap->to->afstandTotBron > 
			huidigstation->afstandTotBron + stap->cost) {
			stap->to->afstandTotBron = huidigstation-> afstandTotBron + stap->cost;
			stap->to->vorigeNode = huidigstation;
			nogTeEvaluerenStations.push(stap->to);
		}
	}
}

std::vector<Node*> Graph::getNeighbour(Node* huidigstation){
    std::vector<Node*> neighbours;
    for(Node* i: this->nodes){
            for(Edge* y: this->edges){
                if(getEdgeBetweenNodes(huidigstation, i) == y){
                    neighbours.push_back(y->getTo()); 
                };
            }
        }
    return neighbours;
    }

std::vector<Node*> Graph::dijkstra(Node* start, Node* end){
    std::vector<Node*> dist;
    std::vector<Node*> prev;

    start->afstandTotBron = 0;
    std::priority_queue<Node*, std::vector<Node*>, NodeComparable> nogTeEvaluerenStations;

    for(Node* v: this->nodes){
        if(v != start){
            v->afstandTotBron = INT_MAX;
            dist.push_back(v);
            v->vorigeNode = nullptr;
            prev.push_back(v);
        }
    }

	nogTeEvaluerenStations.push(start);
	while(nogTeEvaluerenStations.size() != 0) {
		Node* huidigstation = nogTeEvaluerenStations.top();
		evalueerBuren(huidigstation);
		nogTeEvaluerenStations.pop();
        for (int h = 0; h < getNeighbour(huidigstation).size() + 1, h++;){
            int alt = huidigstation->afstandTotBron + getEdgeBetweenNodes(huidigstation, getNeighbour(huidigstation)[h])->getCost();
            if (alt < huidigstation->afstandTotBron){
                for(int j = 0; j < prev.size() + 1; j++){
                    if (prev[j]->label == huidigstation->label){
                        prev.erase(prev.begin()+(j-1));
                    }
                }
                huidigstation->afstandTotBron = alt;
                huidigstation->vorigeNode = getNeighbour(huidigstation)[h];
                // nogTeEvaluerenStations.pop(huidigstation->vorigeNode);
            }
        }
    }
    return dist, prev;
}
