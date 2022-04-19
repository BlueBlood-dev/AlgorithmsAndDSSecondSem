#include <fstream>
#include <vector>
#include <algorithm>
int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n, m;
    in >> n >> m;
    std::vector<int> graph(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        in >> a >> b;
        graph[a - 1]++;
        graph[b - 1]++;
    }
    for (auto item : graph)
        out << item << ' ';
    return 0;
}

