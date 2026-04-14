#include "Graph.h"

/** @brief Vytvorí neorientovaný edge mezi dvěma nodes
 *  @param id_A ID prvního node
 *  @param id_B ID druhýho node
 */
void Graph::CreateEdge(int id_A, int id_B) {
    this->graph[id_A].push_back(id_B);
    this->graph[id_B].push_back(id_A);
    this->edges += 1;
}

/** @brief Odstraní edge mezi nodes
 *  @param id_A ID prvního node
 *  @param id_B ID druhýho node
 */
void Graph::DeleteEdge(int id_A, int id_B) {
    auto &v_a = this->graph.at(id_A);
    auto &v_b = this->graph.at(id_B);
    v_a.erase(find(v_a.begin(), v_a.end(), id_B));
    v_b.erase(find(v_b.begin(), v_b.end(), id_A));

    if (v_a.empty()) {
        this->graph.erase(id_A);
    } if (v_b.empty()) {
        this->graph.erase(id_B);
    }

    this->edges -= 1;
}

/** @brief Sousedy daného node
 *  @param id ID nodu, kterého sousedy chceme
 *  @return vektor s ID všech sousedných nodes
 */
vector<int> Graph::Neighbors(int id) {
    return this->graph.at(id);
}

/** @brief funkce, která vrací počet edges grafu
 *  @return počet edges grafu
 */
int Graph::GetEdges() {
    return this->edges;
}

/** @brief Vráti počet nodes
 *  @return počet nodes grafu
 */
int Graph::GetNodes() {
    return graph.size();
}

/** @brief Zisťuje existencii node na základe ID
 *  @param id ID nodu, kterého existenci skoumáme
 *  @return true/false jestli daný node existuje
 */
bool Graph::NodeExists(int id) {
    return graph.contains(id);
}

/** @brief IDs všetkých node v strome
 *  @return vektor s ID nodes (aka keys v map)
 */
vector<int> Graph::NodeKeys(){
    vector<int> map_keys;
    for (auto node : this->graph){
        map_keys.push_back(node.first);
    }
    return map_keys;
}