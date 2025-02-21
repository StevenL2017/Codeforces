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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    set<ll> s;
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        ll tot = 0;
        for (int j = 0; j < m; j++) {
            tot += a[i][j] * j;
        }
        s.insert(tot);
        mp[tot] = i + 1;
    }
    cout << mp[*s.rbegin()] << " " << (*s.rbegin() - *s.begin()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}