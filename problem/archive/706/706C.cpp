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
    vi c(n); in(c);
    vector<string> a(n); in(a);

    vector<string> ra(n);
    for (int i = 0; i < n; i++) {
        ra[i] = a[i];
        reverse(ra[i].begin(), ra[i].end());
    }

    ll f = 0, g = c[0];
    for (int i = 1; i < n; i++) {
        ll nf = LLONG_MAX, ng = LLONG_MAX;
        if (a[i] >= a[i - 1]) {
            nf = min(nf, f);
        }
        if (a[i] >= ra[i - 1]) {
            nf = min(nf, g);
        }
        if (ra[i] >= a[i - 1] && f < LLONG_MAX) {
            ng = min(ng, f + c[i]);
        }
        if (ra[i] >= ra[i - 1] && g < LLONG_MAX) {
            ng = min(ng, g + c[i]);
        }
        f = nf;
        g = ng;
    }

    ll ans = min(f, g);
    cout << (ans < LLONG_MAX ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}