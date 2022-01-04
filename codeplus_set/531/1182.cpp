#include <iostream>
#include <vector>
using namespace std;

int n, s, ans;
int input[20];

void dfs(int idx, int sum, bool flag) {
    if (idx >= n) {
        if (sum == s && flag)
            ++ans;
        return ;
    }
    dfs(idx + 1, sum + input[idx], 1);
    dfs(idx + 1, sum, flag);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> input[i];
    dfs(0, 0, 0);
    cout << ans;
}
