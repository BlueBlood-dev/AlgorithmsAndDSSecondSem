#include <fstream>
#include <queue>

std::vector <int> list[30000];
int roads[400000];

void BFS(int peak) {
    int used[400000];
    for (int i = 0; i < 40000; ++i)
        used[i] = 0;
    std::queue<int> queue;
    queue.push(peak);
    while (!queue.empty()) {
        int temp = queue.front();
        queue.pop();
        for (auto i : list[temp]) {
            if (i != peak && (roads[i] == 0 || roads[i] > roads[temp] + 1)) {
                roads[i] = roads[temp] + 1;
                queue.push(i);
            }
        }
        used[temp] = true;
    }
}

int main() {
    std::ifstream in("pathbge1.in");
    std::ofstream out("pathbge1.out");
    int n,m;
    in >> n >> m;
    for (int i = 0; i < m; ++i) {
        int roadA,roadB;
        in >> roadA >> roadB;
        list[roadA - 1].push_back(roadB - 1);
        list[roadB - 1].push_back(roadA - 1);
    }
    BFS(0);// 0 == start peak
    for (int i = 0; i < n; ++i) {
        out << roads[i] << " ";
    }

}