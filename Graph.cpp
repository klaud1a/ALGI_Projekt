#include "Graph.h"

void Graph::CreateEdge(int id_A, int id_B) {
    this->graph[id_A].push_back(id_B);
    this->graph[id_B].push_back(id_A);
    this->edges += 1;
}

void Graph::DeleteEdge(int id_A, int id_B) {
    auto v_a = this->graph[id_A];
    auto v_b = this->graph[id_B];
    v_a.erase(find(v_a.begin(), v_a.end(), id_B));
    v_b.erase(find(v_b.begin(), v_b.end(), id_A));

    if (v_a.empty()) {
        this->graph.erase(id_A);
    } if (v_b.empty()) {
        this->graph.erase(id_B);
    }

    this->edges -= 1;
}

vector<int> Graph::Neighbors(int id) {
    return this->graph[id];
}

int Graph::GetEdges() {
    return this->edges;
}
int Graph::GetNodes() {
    return graph.size();
}