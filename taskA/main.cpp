#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int m, n;
    in >> n >> m;
    std::vector<int> points;
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < n; ++i)
        points.push_back(0);

    for (int i = 0; i < n; ++i)
        matrix.push_back(points);

    int roadA, roadB;
    for (int i = 0; i < m; ++i) {
        in >> roadA >> roadB;
        matrix[roadA - 1][roadB - 1] = 1;
    }

    for (auto &i: matrix) {
        for (int j = 0; j < points.size(); ++j) {
            out << i[j] << " ";
        }
        out << std::endl;
    }

    return 0;
}
