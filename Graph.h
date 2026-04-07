#pragma once
#include <map>
#include <vector>
using namespace std;

/**
 * @brief Reprezentace grafu, který je neorientovaný a není ohodnocený
 */
class Graph {
private:
    map<int, vector<int> > graph;
    int edges = 0;

public:
    void CreateEdge(int id_A, int id_B);
    void DeleteEdge(int id_A, int id_B);

    int GetEdges();
    int GetNodes();
    bool NodeExists(int id);

    vector<int> Neighbors(int id);
};
