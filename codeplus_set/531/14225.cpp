#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int s[20];
vector<int> v;

void dfs(int idx, int sum) {
    if (idx >= n) {
        v.emplace_back(sum);
        return ;
    }
    dfs(idx + 1, sum);
    dfs(idx + 1, sum + s[idx]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    dfs(0, 0);
    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 1; i < (int)v.size(); ++i) {
        if (v[i - 1] == v[i] || ans++ == v[i])
            continue ;
        cout << ans - 1;
        return 0;
    }
    cout << ans;
}

