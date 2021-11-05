#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string expression;
int alpha[26];
vector<double> v;

int main() {
	cin >> n >> expression;
	for (int i = 0; i < n; ++i)
		cin >> alpha[i];
	for (size_t i = 0; i < expression.size(); ++i) {
		if (expression[i] >= 'A' && expression[i] <= 'Z') {
			v.emplace_back(alpha[expression[i] - 'A']);
		} else {
			double b = v.back();
			v.pop_back();
			double a = v.back();
			v.pop_back();
			if (expression[i] == '*') {
				v.emplace_back(a * b);
			} else if (expression[i] == '/') {
				v.emplace_back(a / b);
			} else if (expression[i] == '+') {
				v.emplace_back(a + b);
			} else if (expression[i] == '-') {
				v.emplace_back(a - b);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << v.back();
}
