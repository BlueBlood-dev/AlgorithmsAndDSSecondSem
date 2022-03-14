#include <iostream>
#include <fstream>
#include <vector>

bool checkIfOriented(const std::vector<std::vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            if ((matrix[i][j] != matrix[j][i]) || (i==j && matrix[i][j] == 1))
                return false;
        }
    }
    return true;
}


int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n;
    in >> n;
    std::vector<int> points;
    std::vector<std::vector<int>> matrix;
    int value = 0;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> value;
            points[j] = value;
        }
        matrix.push_back(points);
    }
    if (checkIfOriented(matrix)) out << "YES"; else out << "NO";
    return 0;
}
