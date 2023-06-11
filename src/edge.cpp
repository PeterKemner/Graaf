#include "include/edge.hpp"

Edge::Edge(){
    this->cost = 0;
};

Edge::Edge(Node* from, Node* to, int cost): from(from), to(to), cost(cost){};

std::ostream &operator<<(std::ostream &os, Edge& edge) {

    os <<  "( " << edge.from->label << "->" << edge.to->label << ")" << "\n";
    return os;
}