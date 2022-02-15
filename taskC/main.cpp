#include <iostream>
#include <fstream>
#include<vector>

bool checkIfPar(const std::vector<std::vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            if (matrix[i][j] == matrix[j][i] && matrix[i][j] == 1)
                return true;
        }
    }
    return false;
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    std::vector<std::vector<int>> matrix;
    std::vector<int> points;

    for (int i = 0; i < n; ++i)
        points.push_back(0);

    for (int i = 0; i < n; ++i)
        matrix.push_back(points);

    int roadA, roadB;
    for (int i = 0; i < m; ++i) {
        in >> roadA >> roadB;
        if (matrix[roadA - 1][roadB - 1] == 1) {
            out << "YES";
            return 0;
        }
        matrix[roadA - 1][roadB - 1] = 1;
    }

    if (checkIfPar(matrix)) out << "YES"; else out << "NO";

    return 0;
}
