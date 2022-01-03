#include <iostream>
#include <cstdlib>
using namespace std;

int n, ans = 987654321;
int input[20][20];
bool isStartTeam[20];

void updateAns() {
    int startTeamSum = 0;
    int linkTeamSum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isStartTeam[i] && isStartTeam[j]) {
                startTeamSum += input[i][j] + input[j][i];
            } else if (!isStartTeam[i] && !isStartTeam[j]) {
                linkTeamSum += input[i][j] + input[j][i];
            }
        }
    }
    ans = min(ans, abs(startTeamSum - linkTeamSum));
}

void dfs(int startTeamCnt, int idx) {
    if (startTeamCnt >= n / 2) {
        updateAns();
        return ;
    }
    if (idx > n / 2 && startTeamCnt + n - idx < n / 2 )
        return ;
    isStartTeam[idx] = 1;
    dfs(startTeamCnt + 1, idx + 1);
    isStartTeam[idx] = 0;
    dfs(startTeamCnt, idx + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> input[i][j];
    dfs(0, 0);
    cout << ans;
}
