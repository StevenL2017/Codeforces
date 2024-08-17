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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi color(n);
    int pos = 0, neg = 0, tot = 0;
    for (int i = 0; i < n; i++) {
        auto c = s[i];
        if (c == '(') {
            tot++;
        } else {
            tot--;
        }
        if (tot > 0) {
            pos = 1;
            color[i] = 1;
        } else if (tot < 0) {
            neg = 1;
            color[i] = 2;
        } else {
            color[i] = color[i - 1];
        }
    }

    if (tot != 0) {
        cout << -1 << endl;
        return;
    }

    if (pos == 0 || neg == 0) {
        vi ans(n, 1);
        cout << 1 << endl;
        out(ans);
        return;
    }

    cout << 2 << endl;
    out(color);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}