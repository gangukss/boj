#include <iostream>
#include <vector>
using namespace std;

int k, s[49];
bool visit[49];
vector<int> ans;

void dfs(int idx) {
    if ((int)ans.size() >= 6) {
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
        return ;
    }
    for (int i = idx; i < k; ++i) {
        if (!visit[i]) {
            visit[i] = 1;
            ans.emplace_back(s[i]);
            dfs(i);
            visit[i] = 0;
            ans.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        cin >> k;
        if (k == 0)
            break ;
        for (int i = 0; i < k; ++i)
            cin >> s[i];
        dfs(0);
        cout << "\n";
    }
}
