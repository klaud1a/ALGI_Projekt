#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    ifstream G_source("TestData/SmallGraph1.txt");

    if (!G_source.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }
    string a;
    string b;

    while (getline(G_source, a, ' ')) {
        getline(G_source, b);
        g.CreateEdge(stoi(a), stoi(b));
    }
    
    G_source.close();

    cout << g.GetEdges() << endl;
    cout << g.GetNodes() << endl;

    auto v = g.Neighbors(3);

    for (auto i : v)
        cout << i << " ";

    return 0;
}