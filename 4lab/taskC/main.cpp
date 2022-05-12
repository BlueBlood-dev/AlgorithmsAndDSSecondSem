#include <iostream>
#include <fstream>
#include <vector>
#include <set>

const int INF = (int)1e15;

int main() {
    std::ifstream in("pathbgep.in");
    std::ofstream out("pathbgep.out");
    int n, m;
    in >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    for (int i = 0; i < m; ++i) {
        int roadA, roadB, weight;
        in >> roadA >> roadB >> weight;
        --roadA;
        --roadB;
        graph[roadA].push_back(std::make_pair(roadB, weight));
        graph[roadB].push_back(std::make_pair(roadA, weight));
    }

    std::vector<int> distance(n, INF);
    distance[0] = 0;
    std::set<std::pair<int, int>> cmnSet;
    cmnSet.insert(std::make_pair(distance[0], 0));

    while (!cmnSet.empty()) {
        int v = cmnSet.begin()->second;
        cmnSet.erase(cmnSet.begin());

        for (int j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first;
            int length = graph[v][j].second;
            if (distance[v] + length < distance[to]) {
                cmnSet.erase(std::make_pair(distance[to], to));
                distance[to] = distance[v] + length;
                cmnSet.insert(std::make_pair(distance[to], to));
            }
        }
    }

    for (int i = 0; i < n; ++i)
        out << distance[i] << "\n";
}