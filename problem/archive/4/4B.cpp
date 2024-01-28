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
    int n, s;
    cin >> n >> s;
    vi ans, d;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tot += x;
        d.push_back(y - x);
        ans.push_back(x);
    }

    if (tot > s) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        auto inc = min(d[i], s - tot);
        tot += inc;
        ans[i] += inc;
    }

    if (tot < s) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}