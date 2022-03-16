#include <bits/stdc++.h>

using namespace std;


bool used[(int)1e5];
vector<int> sorted;
set<pair<int, int> > temp;
vector<int> graph[(int)1e5];

void dfs(int v) {
    used[v] = true;
    for (int i : graph[v])
        if (!used[i])
            dfs(i);

    sorted.push_back(v);
}

void topSort(int peaks) {
    for (int i = 0; i < peaks; ++i)
        used[i] = false;
    sorted.clear();
    for (int i = 0; i < peaks; ++i)
        if (!used[i])
            dfs(i);
    reverse(sorted.begin(), sorted.end());
}

int main() {
    ifstream in("hamiltonian.in");
    ofstream out("hamiltonian.out");
    int edges;
    int peaks;
    in >> peaks >> edges;
    int roadA, roadB;
    for (int i = 0; i < edges; i++) {
        in >> roadA >> roadB;
        graph[roadA - 1].push_back(roadB - 1);
        temp.insert(make_pair(roadA - 1, roadB - 1));
    }
    bool x = true;
    topSort(peaks);

    for (int i = 0; i < sorted.size() - 1; i++) {
        if (temp.count(make_pair(sorted[i], sorted[i + 1])) == 0) {
            x = false;
            break;
        }
    }
    x?out << "YES":out << "NO";
}