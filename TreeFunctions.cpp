#include "TreeFunctions.h"
#include <iostream>
#include <fstream>


/** @brief spracuváva .txt soubor, z kterého delá graf
 *  @param g graf, který vytváříme ze souboru
 *  @param source string s názvem .txt souboru, kde jsou vypsané dvojice nodes, mezi kterýma je edge
 *  @return 0 ak je vše ok, 1 ak se neco stalo při otevíraní file
 */
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


/** @brief odstraňuje listy, a checkuje jestli návazný node taky není list a rovou ho dá taky pryč
 *  @param g graf, ze kterého odstraňujeme listy
 *  @param id ID node, který odstraňujeme
 */
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

/** @brief funkce, která zisťuje, jestli je graf strom
 *  @param g graf, který zkoumáme
 *  @param nodes počet všech nodes
 *  @return true ak je strom, false ak není
 */
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
    } else {
        return isItTree(g, nodes);
    }
}