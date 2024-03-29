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
    vector<vi> a(n);
    rep(i, n) {
        int k; cin >> k;
        a[i].resize(k);
        in(a[i]);
    }

    set<int> s;
    repa(i, 1, n + 1) s.insert(i);

    int p = 0;
    rep(i, n) {
        bool ok = false;
        for (auto& v: a[i]) {
            if (s.count(v)) {
                ok = true;
                s.erase(v);
                break;
            }
        }
        if (ok) continue;
        if (!p) p = i + 1;
    }

    if (p) {
        cout << "IMPROVE" << endl;
        cout << p << " " << *s.begin() << endl;
    } else {
        cout << "OPTIMAL" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}