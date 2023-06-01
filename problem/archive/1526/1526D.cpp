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
    string s; cin >> s;

    int n = ssz(s);
    vi a(n), p{0, 1, 2, 3};
    for (int i = 0; i < n; i++) {
        a[i] = string("ANOT").find(s[i]);
    }

    vector<vi> suf(4, vi(n + 1, 0));
    for (int j = 0; j < 4; j++) {
        for (int i = n - 1; i >= 0; i--) {
            suf[j][i] = suf[j][i + 1] + (a[i] == j);
        }
    }

    string ans;
    ll mx = -1;
    do {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; p[j] != a[i]; j++) {
                cnt += suf[p[j]][i];
            }
        }
        if (cnt > mx) {
            mx = cnt;
            ans.clear();
            for (int j = 0; j < 4; j++) {
                ans += string(suf[p[j]][0], "ANOT"[p[j]]);
            }
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}