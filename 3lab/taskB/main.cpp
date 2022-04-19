#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <climits>

int main() {
    std::ifstream in("spantree.in");
    std::ofstream out("spantree.out");
    out.precision(10);
    int n;
    in >> n;
    const int infiniteValue = INT_MAX;
    std::vector<int> minWeight(n, infiniteValue), x(n), y(n);
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    std::vector<bool> used(n);
    //algo prima
    double result = 0;
    for (int i = 0; i < n; i++)
        in >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (x[i] - x[j]) * (x[i] - x[j]) +
                          (y[i] - y[j]) * (y[i] - y[j]);
    minWeight[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || minWeight[j] < minWeight[v]))
                v = j;
        used[v] = true;
        for (int j = 0; j < n; j++)
            if (!used[j] && graph[v][j] < minWeight[j] && v != j)
                minWeight[j] = graph[v][j];
    }

    for (int i = 0; i < n; i++)
        result += sqrt(minWeight[i]);

    out << result;
}