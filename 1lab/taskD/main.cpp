#include <iostream>
#include <fstream>
#include <vector>
//global
bool used[100000];
int components[100000];
std::vector<int> list[100000];

void DFS(int peak){
    used[peak] = true;
    for (int i = 0; i < list[peak].size(); ++i) {
        int nextToBeReviewed = list[peak][i];
        if(!used[nextToBeReviewed]){
            components[nextToBeReviewed] = components[peak];
            DFS(nextToBeReviewed);
        }
    }
}

int main() {
    std::ifstream in("components.in");
    std::ofstream out("components.out");
    int n, m;
    int counter = 0;
    in >> n >> m;
    int roadA, roadB;
    for (int i = 0; i < m; ++i) {
        in >> roadA >> roadB;
        list[roadA - 1].push_back(roadB-1);
        list[roadB - 1].push_back(roadA-1);
    }
    for (int i = 0; i < n; ++i) {
        if(!used[i]){
            counter++;
            components[i] = counter;
            DFS(i);
        }
    }
    out << counter << std::endl;
    for (int component : components)
        if(component!=0)
        out<<component << " ";

    return 0;
}
