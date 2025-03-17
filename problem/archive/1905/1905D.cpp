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
    vi a(n);
    in(a);

    deque<pair<int, int>> q;
    vi cnt(n + 1);
    ll mex = 0, tot = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        while (cnt[mex]) {
            mex++;
        }
        q.push_back({mex, 1});
        tot += mex;
    }

    ll ans = tot;
    for (int i = 0; i < n; i++) {
        pair<int, int> cur(a[i], 0);
        q.front().second--;
        tot -= q.front().first;
        if (q.front().second == 0) {
            q.pop_front();
        }
        while (!q.empty() && q.back().first >= a[i]) {
            cur.second += q.back().second;
            tot -= q.back().first * 1ll * q.back().second;
            q.pop_back();
        }
        q.push_back(cur);
        tot += cur.first * 1ll * cur.second;
        q.push_back({n, 1});
        tot += n;
        ans = max(ans, tot);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}