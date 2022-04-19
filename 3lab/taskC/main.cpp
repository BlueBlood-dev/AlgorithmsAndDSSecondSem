#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> par;

int makeSet(int v) {
    if (v == par[v])
        return v;
    else
        par[v] = makeSet(par[v]);
}

void uniteSet(int first, int second) {
    first = makeSet(first);
    second = makeSet(second);
    if (first != second)
        par[first] = second;
}

int main() {
    std::ifstream in("spantree3.in");
    std::ofstream out("spantree3.out");
    int n, m;
    long long answer = 0;
    in >> n >> m;
    std::vector<std::pair<long long, std::pair<long long, long long>>> graph;
    par.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        in >> a >> b >> c;
        graph.emplace_back(c, std::make_pair(a - 1, b - 1));
    }
    sort(graph.begin(), graph.end());
    for (int i = 0; i < n; ++i)
        par[i] = i;
    for (int i = 0; i < m; ++i) {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int c = graph[i].first;

        if (makeSet(a) != makeSet(b)) {
            answer += c;
            uniteSet(a, b);
        }
    }
    out << answer;
}