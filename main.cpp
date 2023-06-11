#include <iostream>
#include "src\include\node.hpp"
#include "src\include\edge.hpp"
#include "src\include\graph.hpp" 
#include "src\include\vlucht.hpp"
#include "src\include\autorit.hpp" 
#include "src\include\treinrit.hpp"  

int main(){

    //Hier maken we de Nodes van de voorbeeld graaf aan. Deze graaf lijkt op die in de slides, maar is directed.

    Node a = Node("a",5); Node b = Node("b", 1); Node c = Node("c", 130); Node d = Node("d", 1); Node e = Node("e", 100); Node f = Node("f", 10);
    
    //Nadat we de Nodes hebben, kunnen we de edges tussen de nodes aanmaken
    Autorit a1 = Autorit(&a, &b, 1); Autorit a2 = Autorit(&a, &c, 300);    
    Autorit b1 = Autorit(&b, &c, 500); Autorit b2 = Autorit(&b, &d, 1);
    Autorit c1 = Autorit(&c, &d, 300); Autorit c2 = Autorit(&c, &e, 100);    
    Autorit d1 = Autorit(&d, &f, 1); 
    Autorit e1 = Autorit(&e, &d, 001); Autorit e2 = Autorit(&e, &f, 300);   

    //Dan voegen de we edges weer toe aan het vector<Edge*> edges attribuut van de nodes.
    a.edges.push_back(&a1); 
    a.edges.push_back(&a2);
    b.edges.push_back(&b1);
    b.edges.push_back(&b2);
    c.edges.push_back(&c1);
    c.edges.push_back(&c2);
    d.edges.push_back(&d1);
    e.edges.push_back(&e1);
    e.edges.push_back(&e1);

    //We verzamelen de nodes en edges in een graph object.
    Graph g = Graph(
        {&a, &b, &c, &d, &e, &f},
        {&a1, &a2, &b1, &b2, &c1, &c2, &d1, &e1, &e2}
    );

    for(auto& i : g.nodes){
        g.nogTeEvaluerenStations.push(i);
    }

    while(!g.nogTeEvaluerenStations.empty()){
        std::cout << g.nogTeEvaluerenStations.top()->label << " : " << g.nogTeEvaluerenStations.top()->afstandTotBron << std::endl;
        g.nogTeEvaluerenStations.pop();
    }

    Edge* edgebetweennodes= g.getEdgeBetweenNodes(&a, &b);

    std::vector<Node*> nodesInPath = {&a, &b, &c, &d, &f};

    std::cout << "Cost of path " << g.getCostOfPath(nodesInPath) << "\n";

    for(Node* x: g.dijkstra(&a, &f)){
        std::cout << x->label << "\n";
    }
}
