#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    g.CreateEdge(4, 1);
    g.CreateEdge(4, 2);
    g.CreateEdge(3, 4);
    g.CreateEdge(5, 4);
    g.CreateEdge(6, 5);

    cout << g.GetEdges() << endl;
    cout << g.GetNodes() << endl;

    auto v = g.Neighbors(4);

    for (auto i : v)
        cout << i << " ";
}