
#include <iostream>
#include <cstdlib>
using namespace std;

int input[20][20];
int n, ans = 987654321;
int startTeam[20];

void calPoint() {
	int startTeamVal = 0;
	int linkTeamVal = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (startTeam[i] && startTeam[j])
				startTeamVal += input[i][j] + input[j][i];
			else if (!startTeam[i] && !startTeam[j])
				linkTeamVal += input[i][j] + input[j][i];
	ans = min(ans, abs(startTeamVal - linkTeamVal));
}

void dfs(int idx, int cnt) {
	if (idx == n)
		return; 
	if (cnt == n / 2) {
		calPoint();
		return ;
	}
	startTeam[idx] = 1;
	dfs(idx + 1, cnt + 1);
	startTeam[idx] = 0;
	dfs(idx + 1, cnt);
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