#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
vector<char> v;
vector<char> ans;

size_t findOppositeBraket(size_t i) {
	if (input[i] == ')') {
		while (input[--i] != '(')
			if (input[i] == ')')
				i = findOppositeBraket(i);
	} else if (input[i] == '(') {
		while (input[++i] != ')')
			if (input[i] == '(')
				i = findOppositeBraket(i);
	}
	return i;
}
size_t findLeftBracketPosition(size_t i) {
	while (i > 0 && input[i] >= 'A' && input[i] <= 'Z')
		--i;
	if (input[i] == '(')
		return i;
	if (input[i] == ')') {
		i = findOppositeBraket(i);
		if (i != 0)
			--i;
	}
	return i;
}
size_t findRightBracketPosition(size_t i) {
	while (i < input.size() - 1 && input[i] >= 'A' && input[i] <= 'Z')
		++i;
	if (input[i] == ')')
		return i;
	if (input[i] == '(') {
		i = findOppositeBraket(i);
		if (i != input.size() - 1)
			++i;
	}
	return i;
}
void insertBraket(size_t &i) {
	size_t lbp = findLeftBracketPosition(i - 1);
	size_t rbp = findRightBracketPosition(i + 1);
	if (input[lbp] == '(' && input[rbp] == ')')
		return ;
	if (input[lbp] == '(' || lbp == 0)
		input.insert(lbp, "(");
	else
		input.insert(lbp + 1, "(");
	++i;
	if (++rbp == input.size() - 1)
		input.push_back(')');
	else
		input.insert(rbp, ")");
}

int main() {
	cin >> input;
	for (size_t i = 0; i < input.size(); ++i)
		if (input[i] == '*' || input[i] == '/')
			insertBraket(i);
	for (size_t i = 0; i < input.size(); ++i)
		if (input[i] == '+' || input[i] == '-')
			insertBraket(i);
	for (size_t i = 0; i < input.size(); ++i) {
		if (input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-' || input[i] == '(') {
			v.emplace_back(input[i]);
		} else if (input[i] >= 'A' && input[i] <= 'Z') {
			ans.emplace_back(input[i]);
		} else if (input[i] == ')') {
			if (v.back() == '(')
				v.pop_back();
			else {
				ans.emplace_back(v.back());
				v.pop_back();
				v.pop_back();
			}
		}
	}
	if (!v.empty())
		ans.emplace_back(v.back());
	for (size_t i = 0; i < ans.size(); ++i)
		cout << ans[i];
}
