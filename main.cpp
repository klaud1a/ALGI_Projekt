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

int main() {
    Graph g;
    string s = "TestData/MediumGraph2.txt";

    if (GetInput(&g, s) == 1) {
        return 1;
    }

    cout << g.GetEdges() << endl;
    cout << g.GetNodes() << endl;

    if (g.GetNodes() - g.GetEdges() != 1) {
        cout << "not a tree" << endl;
        return 0;
    }

    auto v = g.Neighbors(3);

    for (auto i : v)
        cout << i << " ";

    //odoberanie "listov"
    
    return 0;
}