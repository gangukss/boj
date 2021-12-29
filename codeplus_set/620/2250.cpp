#include <iostream>
using namespace std;

#define SUBLEFT 0
#define SUBRIGHT 1
#define MINCOLNUM 0
#define MAXCOLNUM 1

int n, a, b, c, col, maxRow, ansLevel, ansWidth;
const int M = 1e4 + 1;
int input[M][2], parent[M], minMaxColNum[M][2];

int getRootNode(int node) {
    if(parent[node] == 0)
        return node;
    return getRootNode(parent[node]);
}

void setColumnNumber(int node, int level) {
    maxRow = max(maxRow, level);
    if (input[node][SUBLEFT] != -1)
        setColumnNumber(input[node][SUBLEFT], level + 1);
    ++col;
    if (minMaxColNum[level][MINCOLNUM] == 0)
        minMaxColNum[level][MINCOLNUM] = col;
    minMaxColNum[level][MAXCOLNUM] = col;
    if (input[node][SUBRIGHT] != -1)
        setColumnNumber(input[node][SUBRIGHT], level + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        input[a][SUBLEFT] = b;
        input[a][SUBRIGHT] = c;
        parent[b] = parent[c] = a;
    }
    int root = getRootNode(1);
    setColumnNumber(root, 1);
    for (int level = 1; level <= maxRow; ++level) {
        int width = minMaxColNum[level][MAXCOLNUM] - minMaxColNum[level][MINCOLNUM] + 1;
        if (ansWidth < width) {
            ansLevel = level;
            ansWidth = width;
        }
    }
    cout << ansLevel << " " << ansWidth;
}

