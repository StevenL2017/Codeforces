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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vi d(n + 2, -k);
    rep(i, n) cin >> d[i + 1];

    set<tuple<int, int, bool>> vis;
    function<bool(int, int, bool)> dfs = [&] (int pos, int tide, bool down) -> bool {
        if (pos > n) return true;
        if (vis.count({pos, tide, down})) return false;
        vis.insert({pos, tide, down});
        tide += down ? -1 : 1;
        if (tide == 0) down = false;
        if (tide == k) down = true;
        if (d[pos] + tide <= l && dfs(pos, tide, down)) return true;
        if (d[pos + 1] + tide <= l && dfs(pos + 1, tide, down)) return true;
        return false;
    };

    if (dfs(0, 0, false)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}