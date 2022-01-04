#include <iostream>
using namespace std;

int n, ansMax = -1987654321, ansMin = 1987654321;
int input[11];
int operatorCnt[4]; // plus minus multiplication division

int calculate(int ret, int val, int operatorIdx) {
    if (operatorIdx == 0)
        ret += val;
    else if (operatorIdx == 1)
        ret -= val;
    else if (operatorIdx == 2)
        ret *= val;
    else if (operatorIdx == 3)
        ret /= val;
    return ret;
}

void dfs(int idx, int result) {
    if (idx >= n) {
        ansMax = max(ansMax, result);
        ansMin = min(ansMin, result);
        return ;
    }
    for (int i = 0; i < 4; ++i) {
        if (operatorCnt[i]) {
            --operatorCnt[i];
            dfs(idx + 1, calculate(result, input[idx], i));
            ++operatorCnt[i];
        }
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
        cin >> operatorCnt[i];
    dfs(1, input[0]);
    cout << ansMax << "\n" << ansMin;
}

