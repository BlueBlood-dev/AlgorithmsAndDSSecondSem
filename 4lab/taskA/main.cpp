#include <bits/stdc++.h>

std::vector<std::vector<std::pair<long long, long long> > > inputEdges;
const long long INF = (long long) 1e15;

int main() {
    std::ifstream in("pathmgep.in");
    std::ofstream out("pathmgep.out");
    int n, s, f;
    in >> n >> s >> f;
    inputEdges.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            in >> a;
            if (i != j)
                if (a != -1)
                    inputEdges[i].push_back(std::make_pair(j, a));
        }
    }
    long long distance[n];
    bool used[n];
    distance[s - 1] = 0;
    for (int i = 0; i < n; i++) {
        if (i != s - 1)
            distance[i] = INF;
        used[i] = false;
    }
    for (int i = 0; i < n; i++) {
        long long v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || distance[j] < distance[v]))
                v = j;
        if (distance[v] == INF)
            break;
        used[v] = true;
        for (int j = 0; j < inputEdges[v].size(); j++) {
            long long to = inputEdges[v][j].first;
            long long len = inputEdges[v][j].second;
            if (distance[v] + len < distance[to])
                distance[to] = distance[v] + len;
        }
    }
    if (distance[f - 1] != INF)
        out << distance[f - 1];
    else out << -1;
}
