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
    int n, r; cin >> n >> r;
    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vi pos, neg;
    rep(i, n) {
        if (b[i] >= 0) pos.push_back(i);
        else neg.push_back(i);
    }

    sort(pos.begin(), pos.end(), [&] (int i, int j) { return a[i] < a[j]; });
    for (auto& i: pos) {
        if (a[i] > r) {
            cout << "NO\n";
            return;
        }
        r += b[i];
    }

    sort(neg.begin(), neg.end(), [&] (int i, int j) { return max(a[i], -b[i]) + b[i] > max(a[j], -b[j]) + b[j]; });
    for (auto& i: neg) {
        if (a[i] > r) {
            cout << "NO\n";
            return;
        }
        r += b[i];
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}