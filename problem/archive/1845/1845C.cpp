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
    string s, l, r;
    int m;
    cin >> s >> m >> l >> r;

    int mx = 0;
    for (int i = 0; i < m; i++) {
        int nmx = mx;
        for (char j = l[i]; j <= r[i]; j++) {
            int cur = mx;
            while (cur < ssz(s) && s[cur] != j) {
                cur++;
            }
            nmx = max(nmx, cur);
        }
        mx = nmx + 1;
    }
    cout << (mx > ssz(s) ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}