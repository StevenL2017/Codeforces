#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

bool check(vector<string>& a, char c) {
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == c && a[i][1] == c && a[i][2] == c) {
            return true;
        }
        if (a[0][i] == c && a[1][i] == c && a[2][i] == c) {
            return true;
        }
    }
    if (a[0][0] == c && a[1][1] == c && a[2][2] == c) {
        return true;
    }
    if (a[0][2] == c && a[1][1] == c && a[2][0] == c) {
        return true;
    }
    return false;
}

void solve() {
    vector<string> a(3);
    in(a);

    int cnt_x = 0, cnt_o = 0, draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 'X') cnt_x++;
            else if (a[i][j] == '0') cnt_o++;
            else draw = 0;
        }
    }
    bool win_x = check(a, 'X'), win_o = check(a, '0');

    if (cnt_x - cnt_o != 1 && cnt_x != cnt_o) {
        cout << "illegal" << endl;
        return;
    }
    if (win_x && (win_o || cnt_x == cnt_o)) {
        cout << "illegal" << endl;
        return;
    }
    if (win_o && (win_x || cnt_x - cnt_o == 1)) {
        cout << "illegal" << endl;
        return;
    }

    if (win_x) {
        cout << "the first player won" << endl;
    } else if (win_o) {
        cout << "the second player won" << endl;
    } else if (draw) {
        cout << "draw" << endl;
    } else if (cnt_x == cnt_o) {
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}