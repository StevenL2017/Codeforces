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
    string s;
    cin >> s;

    int n = ssz(s);
    vector<ll> f(26);
    vector<vector<ll>> g(26, vector<ll>(26));
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            g[j][c] += f[j];
        }
        f[c]++;
    }

    ll ans = *max_element(begin(f), end(f));
    for (int i = 0; i < 26; i++) {
        ans = max(ans, *max_element(begin(g[i]), end(g[i])));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}