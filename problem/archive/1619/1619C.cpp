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
    ll a, s; cin >> a >> s;

    vi da, ds;
    while (a) {
        da.push_back(a % 10);
        a /= 10;
    }
    while (s) {
        ds.push_back(s % 10);
        s /= 10;
    }

    vi db;
    int j = 0;
    for (int i = 0; i < ssz(da); i++) {
        if (j >= ssz(ds)) {
            cout << -1 << endl;
            return;
        }
        if (da[i] <= ds[j]) {
            db.push_back(ds[j] - da[i]);
            j++;
        } else {
            if (j + 1 >= ssz(ds)) {
                cout << -1 << endl;
                return;
            }
            int cur = ds[j + 1] * 10 + ds[j] - da[i];
            if (cur < 0 || cur > 9) {
                cout << -1 << endl;
                return;
            }
            db.push_back(cur);
            j += 2;
        }
    }

    while (j < ssz(ds)) {
        db.push_back(ds[j++]);
    }

    ll b = 0;
    for (int i = ssz(db) - 1; i >= 0; i--) {
        b *= 10;
        b += db[i];
    }
    cout << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}