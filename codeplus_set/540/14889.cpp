#include <iostream>
#include <cstdlib>
using namespace std;

int n, s[20][20], ans = 987654321;
bool startTeam[20];

void dfs(int idx, int cnt) {
	if (idx >= n)
		return ;
	if (cnt == n / 2) {
		int sumStartTeamScore = 0;
		int sumLinkTeamScore = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (startTeam[i] && startTeam[j])
					sumStartTeamScore += s[i][j] + s[j][i];
				else if (!startTeam[i] && !startTeam[j])
					sumLinkTeamScore += s[i][j] + s[j][i];
		ans = min(ans, abs(sumStartTeamScore - sumLinkTeamScore));
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
			cin >> s[i][j];
	dfs(0, 0);
	cout << ans;
}
