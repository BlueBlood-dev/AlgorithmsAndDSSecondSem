#include <iostream>
#include <fstream>
#include <vector>
//declare global vectors

void DFS(int peak){

}



int main() {
    std::ifstream in("components.in");
    std::ofstream out("components.out");
    int n, m;
    in >> n >> m;
    std::vector<std::vector<int>> list;
    std::vector<int>  points;
    list.resize(n);
    for (int i = 0; i < n; ++i) {
        list.push_back(points);
    }
    int roadA, roadB;
    for (int i = 0; i < m; ++i) {
        in >> roadA >> roadB;
        list[roadA - 1].push_back(roadB);
        list[roadB - 1].push_back(roadA);
    }
////test output
//    for (int i = 0; i < list.size(); ++i) {
//        for (int j = 0; j < list[i].size(); ++j) {
//            std::cout << list[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }

    return 0;
}
