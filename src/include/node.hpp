#pragma once
#include <string>
#include <iostream>
#include <vector>

/*
Uitleg Edge-klasse:
Een Node heeft als attribuut een vector van Edges, terwijl een edge als attribuut een start en een eind node heeft.
Beide klassen zijn dus van elkaar afhankelijk, dit noemen we 'circular dependency'. 
We kunnen hiermee omgaan door middel van forward declaration, hiermee zorgen we dat de Node class wel al op de hoogte is 
van een Edge klasse, die we later pas implementeren.
We kunnen nu niet een Edge attribuut aanmaken in de Node-klasse, want die klasse weet niet hoe die eruit moet zien. 
Wel kunnen we een pointer naar edge (waarin een adres opgeslagen wordt) aanmaken. 
Omdat een Node meerdere Edges heeft, krijgt ie als attribuut een vector van Edge-pointers.
*/
class Edge; //forward declaration (we beloven dat we edge implementeren)

class Node
{
public:
    std::string label;
    std::vector<Edge*> edges;
    int afstandTotBron;

    Node(std::string label);
    Node(std::string label, int a):
        label(label),
        afstandTotBron(a)
        {}

    friend bool operator>(const Node& lhs, const Node& rhs){
        return lhs.afstandTotBron > rhs.afstandTotBron;
    }

    friend std::ostream &operator<<(std::ostream &os, Node& node);
};

