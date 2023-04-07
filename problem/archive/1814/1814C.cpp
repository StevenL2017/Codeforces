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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vi r(n); in(r);

    vi a, b, idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return r[i] > r[j]; });
    
    rep(i, n) {
        ll t1 = 1ll * (ssz(a) + 1) * s1 * r[idx[i]];
        ll t2 = 1ll * (ssz(b) + 1) * s2 * r[idx[i]];
        if (t1 <= t2) {
            a.push_back(idx[i] + 1);
        } else {
            b.push_back(idx[i] + 1);
        }
    }

    cout << ssz(a) << " ";
    rep(i, ssz(a)) cout << a[i] << " ";
    cout << endl;
    cout << ssz(b) << " ";
    rep(i, ssz(b)) cout << b[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}