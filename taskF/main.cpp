#include <fstream>
#include <vector>
#include <string>
#include <queue>


class Handler {
public:
    int up;
    int right_;
    int down;
    int left_;
    std::string path;

    Handler() {
        up = -1;
        right_ = -1;
        down = -1;
        left_ = -1;
        path = "";
    }
};

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    int height, width;
    in >> height >> width;
    std::vector<std::vector<char>> maze(height, std::vector<char>(width, 0));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            in >> maze[i][j];
        }
    }
    auto *list = new Handler[height * width];
    int startPoint = 0;
    int finishPoint = 0;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (maze[i][j] != '#') {
                if (i > 0) {
                    if (maze[i - 1][j] != '#') {
                        list[i * width + j].up = (i - 1) * width + j;
                    }
                }
                if (j < width - 1) {
                    if (maze[i][j + 1] != '#') {
                        list[i * width + j].right_ = i * width + j + 1;
                    }
                }
                if (i < height - 1) {
                    if (maze[i + 1][j] != '#') {
                        list[i * width + j].down = (i + 1) * width + j;
                    }
                }
                if (j > 0) {
                    if (maze[i][j - 1] != '#') {
                        list[i * width + j].left_ = i * width + j - 1;
                    }
                }
            }
            if (maze[i][j] == 'S') {
                startPoint = i * width + j;
            }
            if (maze[i][j] == 'T') {
                finishPoint = i * width + j;
            }
        }
    }
    std::vector<bool> visited(height * width, false);
    std::queue<int> connectedNodes;
    connectedNodes.push(startPoint);
    while (!connectedNodes.empty()) {
        if (list[connectedNodes.front()].right_ != -1 &&
            !visited[list[connectedNodes.front()].right_]) {
            visited[list[connectedNodes.front()].right_] = true;
            list[list[connectedNodes.front()].right_].path =
                    list[connectedNodes.front()].path + 'R';
            connectedNodes.push(list[connectedNodes.front()].right_);
        }
        if (list[connectedNodes.front()].up != -1 &&
            !visited[list[connectedNodes.front()].up]) {
            visited[list[connectedNodes.front()].up] = true;
            list[list[connectedNodes.front()].up].path =
                    list[connectedNodes.front()].path + 'U';
            connectedNodes.push(list[connectedNodes.front()].up);
        }
        if (list[connectedNodes.front()].left_ != -1 &&
            !visited[list[connectedNodes.front()].left_]) {
            visited[list[connectedNodes.front()].left_] = true;
            list[list[connectedNodes.front()].left_].path =
                    list[connectedNodes.front()].path + 'L';
            connectedNodes.push(list[connectedNodes.front()].left_);
        }
        if (list[connectedNodes.front()].down != -1 &&
            !visited[list[connectedNodes.front()].down]) {
            visited[list[connectedNodes.front()].down] = true;
            list[list[connectedNodes.front()].down].path =
                    list[connectedNodes.front()].path + 'D';
            connectedNodes.push(list[connectedNodes.front()].down);
        }
        connectedNodes.pop();
    }

    if (!list[finishPoint].path.empty())
        out << list[finishPoint].path.size() << '\n' << list[finishPoint].path;
    else
        out << -1;

}