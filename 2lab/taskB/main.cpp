#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

enum {
    WHITE,
    GRAY,
    BLACK
};
int noCycle = -1;

std::vector<int> parents;
std::vector<int> colours;
std::vector<std::vector<int>> list;

int dfs(int peak) {
    colours[peak] = GRAY;
    for (int el: list[peak]) {
        if (colours[el] == GRAY) {
            parents[el] = peak;
            return peak;
        }
        if (colours[el] == WHITE) {
            parents[el] = peak;
            int temp = dfs(el);
            if (temp != noCycle)
                return temp;
        }
    }
    colours[peak] = BLACK;
    return noCycle;
}

int main() {
    std::ifstream in("cycle.in");
    std::ofstream out("cycle.out");

     int peaks = 0;
     int edges = 0;
    in >> peaks >> edges;
    list.resize(peaks);
    colours.resize(peaks, WHITE);
    parents.resize(peaks, -1);

    for (int i = 0; i < edges; i++) {
        int roadA = 0, roadB = 0;
        in >> roadA >> roadB;
        list[roadA - 1].push_back(roadB - 1);
    }

    for (int i = 0; i < peaks; i++) {
        if (colours[i] == WHITE) {
            int cycleStart = dfs(i);
            if (cycleStart != noCycle) {
                out << "YES\n";
                out << cycleStart + 1 << " ";
                std::vector<int> cycle;
                for (int j = parents[cycleStart]; j != cycleStart; j = parents[j])
                    cycle.push_back(j + 1);
                std::reverse(cycle.begin(), cycle.end());
                for (int elements: cycle)
                    out << elements << " ";
                return 0;
            }
        }
    }
    out << "NO\n";
    return 0;
}