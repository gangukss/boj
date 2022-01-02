#include <iostream>
using namespace std;

int n, ansMax = -1987654321, ansMin = 1987654321;
int input[11];
int fourOperator[4];
int visit[4];

void dfs(int idx, int result) {
    if (idx >= n) {
        ansMax = max(ansMax, result);
        ansMin = min(ansMin, result);
        return ;
    }
    if (visit[0] < fourOperator[0]) {
        ++visit[0];
        dfs(idx + 1, result + input[idx]);
        --visit[0];
    }
    if (visit[1] < fourOperator[1]) {
        ++visit[1];
        dfs(idx + 1, result - input[idx]);
        --visit[1];
    }
    if (visit[2] < fourOperator[2]) {
        ++visit[2];
        dfs(idx + 1, result * input[idx]);
        --visit[2];
    }
    if (visit[3] < fourOperator[3]) {
        ++visit[3];
        dfs(idx + 1, result / input[idx]);
        --visit[3];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> input[i];
    for (int i = 0; i < 4; ++i)
        cin >> fourOperator[i];
    dfs(1, input[0]);
    cout << ansMax << "\n" << ansMin;
}
