#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

enum {
    WHITE,
    GRAY,
    BLACK
};

std::vector<int> sorted;
std::vector<int> colours;
std::vector<std::vector<int>> list;

bool DFS(int peak) {
    colours[peak] = GRAY;
    for (auto el: list[peak]) {
        if (colours[el] == WHITE) {
            if (DFS(el)) {
                return true;
            }
        }
        if (colours[el] == GRAY)
            return true;
    }
    sorted.push_back(peak);
    colours[peak] = BLACK;
    return false;
}

int main() {
    std::ifstream in("topsort.in");
    std::ofstream out("topsort.out");
    unsigned int peaks = 0, edges = 0;
    in >> peaks >> edges;
    list.resize(peaks);
    colours.resize(peaks, WHITE);

    for (int i = 0; i < edges; i++) {
        unsigned int roadA = 0, roadB = 0;
        in >> roadA >> roadB;
        list[roadA - 1].push_back(roadB - 1);
    }

    for (int i = 0; i < peaks; i++) {
        if (colours[i] == WHITE)
            if (DFS(i)) {
                out << "-1\n";
                return 0;
            }
    }
    std::reverse(sorted.begin(), sorted.end());
    for (auto el: sorted)
        out << el + 1 << " ";

    return 0;
}