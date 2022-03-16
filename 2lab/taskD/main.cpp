#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<int>> list, listTrsp;
vector<int> res;
vector<char> used;
vector<int> components;
//top sort
void DFS1(int v) {
    used[v] = true;
    for (int i : list[v]) {
        if (!used[i])
            DFS1(i);
    }
    res.push_back(v);
}
// маркируем компоненты сильной связности
void DFS2(int v, int k) {
    components[v] = k;
    for (int i : listTrsp[v]) {
        if (components[i] == -1)
            DFS2(i, k);
    }
}

int main() {
    int peaks, edges;
    ifstream in("cond.in");
    ofstream out("cond.out");

    in >> peaks >> edges;
    list.resize(peaks, vector<int>(0));
    listTrsp.resize(peaks, vector<int>(0));
    components.resize(peaks, -1);
    used.resize(peaks, false);
    int roadA, roadB;
    for (int i = 0; i < edges; i++) {
        in >> roadA >> roadB;
        list[roadA - 1].push_back(roadB - 1);
        listTrsp[roadB - 1].push_back(roadA - 1);
    }
// top sort
    for (int i = 0; i < peaks; i++)
        if (!used[i])
            DFS1(i);

    int counter = 0;
    reverse(res.begin(),res.end());
    //выделяем компоненты.
    for (int element : res) {
        if (components[element] == -1) {
            DFS2(element, counter);
            counter++;
        }
    }

    out << counter << "\n";
    for (int i = 0; i < peaks; i++)
        out << components[i] + 1 << " ";
}