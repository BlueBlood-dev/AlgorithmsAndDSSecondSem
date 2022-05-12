#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

std::vector<std::vector<std::pair<int, long long int>>> graph;
std::vector<bool> used;

void dfs(long long vertex) {
    used[vertex] = true;
    for (auto i: graph[vertex]) {
        if (!used[i.first])
            dfs(i.first);
    }
}

int main() {
    int m, a, b, s, n;
    long long int c;
    long long const int INF = 2*1e18    ;
    std::vector<long long int> length;
    std::ifstream in("path.in");
    std::ofstream out("path.out");
    in >> n >> m >> s;
    graph.resize(n, std::vector<std::pair<int, long long int>>());
    used.resize(n, false);
    length.resize(n, INF);
    for (int i = 0; i < m; i++) {
        in >> a >> b >> c;
        graph[a - 1].push_back(std::make_pair(b - 1, c));
    }
    length[s - 1] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if ((length[i] + graph[i][j].second < length[graph[i][j].first]) && length[i] < INF)
                    length[graph[i][j].first] =
                            length[i] + graph[i][j].second > -INF ? length[i] + graph[i][j].second : -INF;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            if ((length[i] + graph[i][j].second < length[graph[i][j].first]) && !used[graph[i][j].first] &&
                length[i] < INF)
                dfs(graph[i][j].first);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (length[i] == INF)
            out << "*" << std::endl;
        else if (used[i])
            out << "-" << std::endl;
        else
            out << length[i] << std::endl;
    }
    return 0;
}