#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


int main() {
    std::ifstream in ("negcycle.in");
    std::ofstream out ("negcycle.out");
    int amount, a, flag;
    std::vector<std::vector<std::pair<int, int>>> g;
    std::vector<int> length, answer, parent;
    in >> amount;
    g.resize(amount, std::vector<std::pair<int, int>>());
    length.resize(amount, 2500001);
    parent.resize(amount, -1);
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; ++j) {
            in >> a;
            if (a < 2500001)
                g[i].push_back(std::make_pair(j, a));
        }
    }
    for (int counter = 0; counter < amount; ++counter) {
        flag = -1;
        for (int i = 0; i < amount; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                if (length[i] + g[i][j].second < length[g[i][j].first]) {
                    length[g[i][j].first] = std::max(length[i] + g[i][j].second, -2500001);
                    parent[g[i][j].first] = i;
                    flag = g[i][j].first;
                }
            }
        }
    }
    if (flag == -1)
        out << "NO";
    else{
        for (int k = 0; k < amount; ++k)
            flag = parent[flag];
        int current_vertex = flag;
        while (true) {
            answer.push_back(current_vertex);
            if (answer.size() > 1 && current_vertex == flag)
                break;
            current_vertex = parent[current_vertex];
        }
        out << "YES" << std::endl << answer.size() << std::endl;
        reverse(answer.begin(), answer.end());
        for (int el : answer)
            out << el + 1 << " ";
    }
    return 0;
}