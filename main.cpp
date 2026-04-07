#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

int GetInput(Graph* g, string source) {
    ifstream G_source(source);
    if (!G_source.is_open()) {
        cerr << "Error opening the file!";
        G_source.close();
        return 1;
    }
    string a;
    string b;

    while (getline(G_source, a, ' ')) {
        getline(G_source, b);
        g->CreateEdge(stoi(a), stoi(b));
    }

    G_source.close();
    return 0;
}

void RemoveVine(Graph* g,int id) {
    auto neighbors = g->Neighbors(id);
    if (neighbors.size() == 1) {
        int neighbor = neighbors[0];
        g->DeleteEdge(id, neighbor);
        if (g->NodeExists(neighbor)) { //skontrolovat či to nebyla jeho posledna konekcie
            RemoveVine(g, neighbor);
        }
        
    }
}

bool isItTree(Graph* g, int nodes) {
    bool LeafExists = false;
    for (int i = 0; i < nodes; i++) {
        if (g->NodeExists(i)) {
            auto v = g->Neighbors(i);
            if (v.size() == 1) {
                LeafExists = true;
                RemoveVine(g, i);
            }
        }
    }
    if (g->GetNodes() == 0) {
        return true;
    } else if(LeafExists == false) {
        return false;
    }
    else {
        isItTree(g, nodes);
    }
}

int main() {
    Graph g;
    string s = "TestData/MediumGraph4.txt";

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

    if (isItTree(&g, nodes)) {
        cout << "Tree" << endl;
    }
    else {
        cout << "Not a tree" << endl;
    }
    
    return 0;
}