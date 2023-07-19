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
    int n; cin >> n;
    vi a(n); in(a);

    vi f(3, 0); // 0 rest, 1 contest, 2 sport
    for (auto x : a) {
        vi g(3, n);
        g[0] = min({f[0], f[1], f[2]}) + 1;
        if (x == 1) {
            g[1] = min({f[0], f[2]});
        } else if (x == 2) {
            g[2] = min({f[0], f[1]});
        } else if (x == 3) {
            g[1] = min({f[0], f[2]});
            g[2] = min({f[0], f[1]});
        }
        f = g;
    }

    cout << *min_element(f.begin(), f.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}