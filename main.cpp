#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>

#include "Graph.h"
#include "TreeFunctions.h"

using namespace std;

int main() {
    Graph g;
    string s = "TestData/MediumGraph5.txt";

    if (GetInput(&g, s) == 1) { //create graph from .txt file
        return 1;
    }

    int edges = g.GetEdges();
    int nodes = g.GetNodes();

    if (nodes - edges != 1) {
        cout << "Not a tree" << endl;
        return 0;
    }

    //odoberanie "listov"

    if (isItTree(&g)) {
        cout << "Tree" << endl;
    } else {
        cout << "Not a tree" << endl;
    }
    
    return 0;
}