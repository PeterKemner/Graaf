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

std::vector<Node*> Graph::dijkstra(Node* start, Node* end){
    std::vector<Node*> dist{nodes};
    std::vector<Node*> prev{nodes};

    start->afstandTotBron = 0;
    std::priority_queue<Node*, std::vector<Node*>, NodeComparable> nogTeEvaluerenStations;

    for(Node* v: this->nodes){
        if(v != start){
            dist[v->afstandTotBron] = INT_MAX;
            // prev[] = "Unidentified";
        }
        nogTeEvaluerenStations.push(v, dist[v]);
    }

	nogTeEvaluerenStations.push(start);
	while(nogTeEvaluerenStations.size() != 0) {
		Node* huidigstation = nogTeEvaluerenStations.top();
		evalueerBuren(huidigstation);
		nogTeEvaluerenStations.pop();
        for (){
            int alt = dist[huidigstation->afstandTotBron] + getEdgeBetweenNodes(u, v);
            if (alt < dist[v]){
                dist[v->afstandTotBron] = alt;
                prev[v] = u; 
                nogTeEvaluerenStations.decrease_priority(v, alt);
            }
        }
    }
}