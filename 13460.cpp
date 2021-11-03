#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[10][10];
int r_x, r_y, b_x, b_y, o_x, o_y, flag;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct pos {
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};
queue<pos> q;

bool is_equal(pos a, pos b) {
	return (a.rx == b.rx && a.ry == b.ry && a.bx == b.bx && a.by == b.by);
}

bool is_b_ok(pos src, const int dir) {
	int nx = src.bx + dx[dir];
	int ny = src.by + dy[dir];
	while (map[nx][ny] != '#') {
		if (map[nx][ny] == 'O')
			return false;
		nx += dx[dir];
		ny += dy[dir];
	}
	return true;
}

pos move(pos cur, const int &dir) {
	pos next;
	next.rx = cur.rx + dx[dir];
	next.ry = cur.ry + dy[dir];
	next.bx = cur.bx + dx[dir];
	next.by = cur.by + dy[dir];
	if (map[next.rx][next.ry] == 'O') {
		flag = 1;
		return cur;
	}
	if (map[next.rx][next.ry] == '#' || (next.rx == cur.bx && next.ry == cur.by)) {
		next.rx -= dx[dir];
		next.ry -= dy[dir];
	}
	if (map[next.bx][next.by] == '#' || (next.bx == cur.rx && next.by == cur.ry)) {
		next.bx -= dx[dir];
		next.by -= dy[dir];
	}
	if (is_equal(cur, next))
		return cur;
	return (move(next, dir));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				r_x = i;
				r_y = j;
				map[i][j] = '.';
			} else if (map[i][j] == 'B') {
				b_x = i;
				b_y = j;
				map[i][j] = '.';
			} else if (map[i][j] == 'O') {
				o_x = i;
				o_y = j;
			}
		}
	}

	q.push({r_x, r_y, b_x, b_y, 0});
	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (!is_b_ok(tmp, i))
				continue ;
			pos next_pos = move(tmp, i);
			if (is_equal(tmp, next_pos) && !flag)
				continue ;
			next_pos.cnt = tmp.cnt;
			++next_pos.cnt;
			if (next_pos.cnt > 10) {
				cout << "-1";
				flag = 1;
				break ;
			}
			if (flag) {
				cout << next_pos.cnt;
				break ;
			}
			q.push(next_pos);
		}
		if (flag)
			break ;
	}
	if (q.empty() && !flag)
		cout << "-1";
}
