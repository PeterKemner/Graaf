# Graaf
Toelichting Dijkstra algoritme implementatie:


Als eerst maak de de vectors "dist" en "prev" zoals in de pseudocode staat en maak ik de priority queue aan.

Dan zet ik de afstandTotBron van de start node op 0 en met een for loop de rest op infinity (INT_MAX in deze context). Ik zet alle vorigeNode van de nodes op unidentified (Nullptr in deze context).

Dan zet ik de start in de priority queue en start ik de main while loop.

De loop start pas als de priority queue niet leeg is.

Dan wordt de eerste node gepakt uit de priority queue, en dat ik start want de afstandTotBron bij start is 0 en bij de rest is het INT_MAX (infinity).

Dan wordt de node geevalueerd in de evalueerBuren functie, in de functie wordt een for loop gestart die door de vector edges kijkt, en als de node waar de edge naartoegaat afstandTotBron kleiner is dan die van de node die is meegegeven + de weight van de edge, dan wordt de node waar de edge naartoegaat afstandTotBron, de afstandTotBron van de node die is meegegeven + de weight van de edge. De node waar de edge naartoegaat vorigeNode wordt de node die was meegegeven en die wordt toegevoegt aan de priority queue.

Nadat het evalueren van de node klaar is wordt die uit de priority queue gehaald en begint een nieuwe for loop.

de for loop loopt zolang als de functie getNeighbour() <-- geeft een vector met de buren van een node.

Daarna wordt de vaiable alt gemaakt en dat is de afstandTotBron van de huidigestation + de weight van edge

Als alt kleiner is dan afstand tot de bron van de huidigenode dan wordt de afstandTotBron van de huidigenode naar alt en de vorigeNode wordt de neighbour

Op het eind wordt de snelste pad gereturned