#include <bits/stdc++.h>
using namespace std;

vector<int> graph[(int)1e5];
vector<int> temp[(int)1e5];
bool used[(int)1e5];
vector<int> sorted;
bool winHandler[(int)1e5];

void dfs (int peak) {
    used[peak] = true;
    for (int to : graph[peak])
        if (!used[to])
            dfs (to);

    sorted.push_back (peak);
}

void topological_sort(int peaks) {
    for (int i=0; i<peaks; ++i)
        used[i] = false;
    sorted.clear();
    for (int i=0; i<peaks; ++i)
        if (!used[i])
            dfs (i);
}

void search(int peak){
    if(!winHandler[peak]){
        for(int i : temp[peak]){
            winHandler[i] = true;
        }
    }

}

int main(){
    ifstream in("game.in");
    ofstream out("game.out");
    int edges, peaks, s;
    in >> peaks >> edges >> s;
    for(int i = 0; i < edges; i++){
        int roadA, roadB;
        in >> roadA >> roadB;
        graph[roadA - 1].push_back(roadB - 1);
        temp[roadB - 1].push_back(roadA - 1);
    }

    topological_sort(peaks);
    for(int i = 0; i < peaks; i++)
        winHandler[i] = false;
    for(int el : sorted)
        search(el);

    if(winHandler[s - 1]) out << "First player wins";
    else out << "Second player wins";
}