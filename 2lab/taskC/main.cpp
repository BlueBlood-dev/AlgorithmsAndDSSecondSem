#include <iostream>
#include <fstream>
#include <vector>
#include <list>

enum colours {
    WHITE,
    GREY,
    BLACK
};

colours getInverseColor(colours c) {
    if (c == GREY)
        return BLACK;
    else if (c == BLACK)
        return GREY;
    else
        return WHITE;
}

bool colorNodesDFS(const std::vector<std::list<int>>& G, std::vector<colours>& coloursArray, colours colour, int v) {
    coloursArray[v] = colour;
    for (int u : G[v]) {
        if (coloursArray[u] == WHITE) {
            if (!colorNodesDFS(G, coloursArray, getInverseColor(colour), u))
                return false;
        }
        else if (coloursArray[u] == colour)
            return false;
    }
    return true;
}

bool checkBipartite(const std::vector<std::list<int>>& graph) {
    std::vector<colours> colors(graph.size(), WHITE);
    for (int i = 0; i < graph.size(); i++) {
        if (colors[i] == WHITE) {
            if (!colorNodesDFS(graph, colors, GREY, i))
                return false;
        }
    }
    return true;
}

int main() {
    std::ifstream in("bipartite.in");
    std::ofstream out("bipartite.out");
    int peaks, edges;
    in >> peaks >> edges;
    std::vector<std::list<int>> graph(peaks, std::list<int>(0));
    int roadA, roadB;
    for (int i = 0; i < edges; i++) {
        in >> roadA >> roadB;
        graph[roadA - 1].push_back(roadB - 1);
        graph[roadB - 1].push_back(roadA - 1);
    }
    if (checkBipartite(graph))
        out << "YES" << std::endl;
    else
        out << "NO" << std::endl;
}