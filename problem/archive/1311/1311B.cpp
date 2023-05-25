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
    int n, m; cin >> n >> m;
    vi a(n); in(a);
    vi p(m); in(p);

    sort(p.begin(), p.end());

    int pre = 0;
    auto check = [&] (int s, int e) -> bool {
        for (int i = s; i < e; i++) {
            if (a[i] < pre) {
                return false;
            }
            pre = a[i];
        }
        return true;
    };

    if (!check(0, p[0] - 1)) {
        cout << "NO\n";
        return; 
    }

    for (int i = 0; i < m; ) {
        int mn = min(a[p[i] - 1], a[p[i]]);
        int mx = max(a[p[i] - 1], a[p[i]]);
        while (i + 1 < m && p[i + 1] - p[i] == 1) {
            i++;
            mn = min({mn, a[p[i] - 1], a[p[i]]});
            mx = max({mx, a[p[i] - 1], a[p[i]]});
        }
        if (mn < pre) {
            cout << "NO\n";
            return;
        }
        pre = mx;

        if (i + 1 < m && !check(p[i] + 1, p[i + 1] - 1)) {
            cout << "NO\n";
            return; 
        }

        i++;
    }

    if (!check(p[m - 1] + 1, n)) {
        cout << "NO\n";
        return; 
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}