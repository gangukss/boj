#include <iostream>
using namespace std;

int n;
char a, b, c;
char input[26][2];

void preorder(int i) {
    cout << (char)('A' + i);
    if (input[i][0] != '.')
        preorder(input[i][0] - 'A');
    if (input[i][1] != '.')
        preorder(input[i][1] - 'A');
}

void inorder(int i) {
    if (input[i][0] != '.')
        inorder(input[i][0] - 'A');
    cout << (char)('A' + i);
    if (input[i][1] != '.')
        inorder(input[i][1] - 'A');
}

void postorder(int i) {
    if (input[i][0] != '.')
        postorder(input[i][0] - 'A');
    if (input[i][1] != '.')
        postorder(input[i][1] - 'A');
    cout << (char)('A' + i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        input[a - 'A'][0] = b;
        input[a - 'A'][1] = c;
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
}

