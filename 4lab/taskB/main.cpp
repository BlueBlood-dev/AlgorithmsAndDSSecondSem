#include <bits/stdc++.h>


const long long INF = (long long) 1e15;

int main() {
    std::ifstream in("pathsg.in");
    std::ofstream out("pathsg.out");
    int n, m;
    in >> n >> m;
    long long distance[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distance[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        in >> a >> b >> c;
        distance[a - 1][b - 1] = c;
    }

    for (int i = 0; i < n; i++)
        distance[i][i] = 0;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distance[i][j] != INF)
                out << distance[i][j];
            else
                out << -1;
            out << " ";
        }
        out << std::endl;
    }
}