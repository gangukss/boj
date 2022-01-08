#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

struct pos {
    int x, y;
};
int r, c, k, chocolateCnt = 0;
int temperature[20][20];
int controledTemperature[20][20];
int wall[20][20]; // -1 none 0 up 1 right 2 up right
bool visit[20][20];
vector<pos> rightFan;
vector<pos> leftFan;
vector<pos> upFan;
vector<pos> downFan;
vector<pos> checkPoint;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

void operateRightFan(int x, int y, int cnt) {
    if (cnt < 1)
        return ;
    if (!isValid(x, y) || visit[x][y])
        return ;
    visit[x][y] = 1;
    temperature[x][y] += cnt;
    if (x - 1 >= 0 && wall[x][y] != 0 && wall[x][y] != 2 && wall[x - 1][y] < 1)
        operateRightFan(x - 1, y + 1, cnt - 1);
    if (wall[x][y] < 1)
        operateRightFan(x, y + 1, cnt - 1);
    if (x + 1 < r && wall[x + 1][y] < 0)
        operateRightFan(x + 1, y + 1, cnt - 1);
}

void operateLeftFan(int x, int y, int cnt) {
    if (cnt < 1)
        return ;
    if (!isValid(x, y) || visit[x][y])
        return ;
    visit[x][y] = 1;
    temperature[x][y] += cnt;
    if (x - 1 >= 0 && y - 1 >= 0 && wall[x][y] != 0 && wall[x][y] != 2 && wall[x - 1][y - 1] < 1)
        operateLeftFan(x - 1, y - 1, cnt - 1);
    if (y - 1 >= 0 && wall[x][y - 1] < 1)
        operateLeftFan(x, y - 1, cnt - 1);
    if (x + 1 < r && y - 1 >= 0 && wall[x + 1][y - 1] < 1 && wall[x + 1][y] != 0 && wall[x + 1][y] != 2)
        operateLeftFan(x + 1, y - 1, cnt - 1);
}

void operateUpFan(int x, int y, int cnt) {
    if (cnt < 1)
        return ;
    if (!isValid(x, y) || visit[x][y])
        return ;
    visit[x][y] = 1;
    temperature[x][y] += cnt;
    if (y - 1 >= 0 && wall[x][y - 1] < 0)
        operateUpFan(x - 1, y - 1, cnt - 1);
    if (wall[x][y] != 0 && wall[x][y] != 2)
        operateUpFan(x - 1, y, cnt - 1);
    if (y + 1 < c && wall[x][y] < 1 && wall[x][y + 1] != 0 && wall[x][y + 1] != 2)
        operateUpFan(x - 1, y + 1, cnt - 1);
}

void operateDownFan(int x, int y, int cnt) {
    if (cnt < 1)
        return ;
    if (!isValid(x, y) || visit[x][y])
        return ;
    visit[x][y] = 1;
    temperature[x][y] += cnt;
    if (x + 1 < r && y - 1 >= 0 && wall[x][y - 1] < 1 && wall[x + 1][y - 1] != 0 && wall[x + 1][y - 1] != 2)
        operateDownFan(x + 1, y - 1, cnt - 1);
    if (x + 1 < r && wall[x + 1][y] != 0 && wall[x + 1][y] != 2)
        operateDownFan(x + 1, y, cnt - 1);
    if (x + 1 < r && y + 1 < c && wall[x][y] < 1 && wall[x + 1][y + 1] != 0 && wall[x + 1][y + 1] != 2)
        operateDownFan(x + 1, y + 1, cnt - 1);
}

void operateFan() {
    for (auto point : rightFan) {
        memset(visit, 0, sizeof(visit));
        operateRightFan(point.x, point.y + 1, 5);
    }
    for (auto point : leftFan) {
        memset(visit, 0, sizeof(visit));
        operateLeftFan(point.x, point.y - 1, 5);
    }
    for (auto point : upFan) {
        memset(visit, 0, sizeof(visit));
        operateUpFan(point.x - 1, point.y, 5);
    }
    for (auto point : downFan) {
        memset(visit, 0, sizeof(visit));
        operateDownFan(point.x + 1, point.y, 5);
    }
}

void regulatedTemperature() {
    memcpy (controledTemperature, temperature, sizeof(temperature));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int u = 0; u < 4; ++u) {
                int compareX = i + dx[u];
                int compareY = j + dy[u];
                if (isValid(compareX, compareY)) {
                    // lrud
                    if (u == 0 && wall[compareX][compareY] > 0)
                        continue ;
                    if (u == 1 && wall[i][j] > 0)
                        continue ;
                    if (u == 2 && (wall[i][j] == 0 || wall [i][j] == 2))
                        continue ;
                    if (u == 3 && (wall[compareX][compareY] == 0 || wall[compareX][compareY] == 2))
                        continue ;
                    int dif = temperature[i][j] - temperature[compareX][compareY];
                    if (dif > 0)
                        controledTemperature[i][j] -= abs(dif) / 4;
                    else if (dif < 0)
                        controledTemperature[i][j] += abs(dif) / 4;
                }
            }
        }
    }
    memcpy (temperature, controledTemperature, sizeof(temperature));
}

void decreaseTemperature() {
    for (int i = 0; i < c; ++i) {
        if (temperature[0][i] > 0)
            --temperature[0][i];
        if (temperature[r - 1][i] > 0)
            --temperature[r - 1][i];
    }
    for (int i = 1; i < r - 1; ++i) {
        if (temperature[i][0] > 0)
            --temperature[i][0];
        if (temperature[i][c - 1] > 0)
            --temperature[i][c - 1];
    }
}

bool checkK() {
    for (auto point : checkPoint)
        if (temperature[point.x][point.y] < k)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> k;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                rightFan.push_back({i, j});
            } else if (tmp == 2) {
                leftFan.push_back({i, j});
            } else if (tmp == 3) {
                upFan.push_back({i, j});
            } else if (tmp == 4) {
                downFan.push_back({i, j});
            } else if (tmp == 5) {
                checkPoint.push_back({i, j});
            }
        }
    }
    memset(wall, -1, sizeof(wall));
    int w, x, y, t;
    cin >> w;
    for (int i = 0; i < w; ++i) {
        cin >> x >> y >> t;
        if (wall[x - 1][y - 1] == -1)
            wall[x - 1][y - 1] = t;
        else if (wall[x - 1][y - 1] != t)
            wall[x - 1][y - 1] = 2;
    }
    while (!checkK()) {
        if (chocolateCnt > 100)
            break ;
        operateFan();
        regulatedTemperature();
        decreaseTemperature();
        ++chocolateCnt;
    }
    cout << chocolateCnt;
}

