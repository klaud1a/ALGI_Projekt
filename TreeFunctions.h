#pragma once
#include <string>
#include "Graph.h"

using namespace std;

int GetInput(Graph* g, string source);
void RemoveVine(Graph* g, int id);
bool isItTree(Graph* g);