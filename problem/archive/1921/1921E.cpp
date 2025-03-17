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

void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;

    if (xa >= xb) {
        cout << "Draw" << endl;
        return;
    }

    string winner;
    bool win;
    if ((xb - xa) & 1) {
        winner = "Alice";
        xa++;
        if (ya < yb) ya++;
        else if (ya > yb) ya--;
        if (ya == yb) {
            win = true;
        } else if (ya < yb) {
            int t = w - ya;
            win = xb - xa >= 2 * t;
        } else {
            int t = ya - 1;
            win = xb - xa >= 2 * t;
        }
    } else {
        winner = "Bob";
        if (ya == yb) {
            win = true;
        } else if (ya < yb) {
            int t = yb - 1;
            win = xb - xa >= 2 * t;
        } else {
            int t = w - yb;
            win = xb - xa >= 2 * t;
        }
    }
    cout << (win ? winner : "Draw") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}