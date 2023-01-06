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
    int n; cin >> n;
    vi a(n); in(a);

    vector<vi> idx(n + 1);
    rep(i, n) {
        idx[a[i]].push_back(i);
        if (ssz(idx[a[i]]) > 2) {
            cout << "NO\n";
            return;
        }
    }

    vi a0;
    repd(i, n, 0) {
        if (ssz(idx[i]) == 0) a0.push_back(i);
    }

    vi p(n, 0), q(n, 0);
    for (int i = n, j = 0; i > 0; i--) {
        int m = ssz(idx[i]);
        if (m == 1) {
            p[idx[i][0]] = q[idx[i][0]] = i;
        }
        else if (m == 2) {
            p[idx[i][0]] = q[idx[i][1]] = i;
            if (a0[j] >= i) {
                cout << "NO\n";
                return;
            }
            p[idx[i][1]] = q[idx[i][0]] = a0[j++];
        }
    }

    cout << "YES\n";
    out(p); out(q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}