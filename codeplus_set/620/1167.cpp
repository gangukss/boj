#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct connectedNode {
    int idx;
    int len;
};
const int M = 1e5 + 1;
int n;
vector<vector<connectedNode>> input(M);
int ans, root;
bool visit[M];

void dfs(int node, int len) {
    visit[node] = 1;
    if (len > ans) {
        root = node;
        ans = len;
    }
    for (auto nextNodeInfo : input[node]) {
        if (!visit[nextNodeInfo.idx]) {
            visit[nextNodeInfo.idx] = 1;
            dfs(nextNodeInfo.idx, len + nextNodeInfo.len);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int node, node2, len;
        cin >> node;
        while (1) {
            cin >> node2;
            if (node2 == -1)
                break ;
            cin >> len;
            input[node].push_back({node2, len});
        }
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    dfs(root, 0);
    cout << ans;
}


