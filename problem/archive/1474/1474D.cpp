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

    auto check = [&] (vi x) -> bool {
        repa(i, 1, ssz(x)) {
            if (x[i] < x[i - 1]) {
                return false;
            } else {
                x[i] -= x[i - 1];
            }
        }
        if (x.back() == 0) return true;
        else return false;
    };

    if (check(a)) {
        cout << "YES\n";
        return;
    }
    swap(a[0], a[1]);
    if (check(a)) {
        cout << "YES\n";
        return;
    }
    swap(a[0], a[1]);
    swap(a[n - 2], a[n - 1]);
    if (check(a)) {
        cout << "YES\n";
        return;
    }
    swap(a[n - 2], a[n - 1]);

    vi b = a, p(n), s(n);
    p[0] = a[0];
    repa(i, 1, n) {
        if (p[i - 1] == -1 || b[i - 1] > b[i]) {
            p[i] = -1;
        } else {
            b[i] -= b[i - 1];
            p[i] = b[i];
        }
    }
    b = a;
    s[n - 1] = a[n - 1];
    repd(i, n - 2, -1) {
        if (s[i + 1] == -1 || b[i + 1] > b[i]) {
            s[i] = -1;
        } else {
            b[i] -= b[i + 1];
            s[i] = b[i];
        }
    }

    repa(i, 1, n - 2) {
        if (p[i - 1] == -1 || s[i + 2] == -1) continue;
        if (check({p[i - 1], a[i + 1], a[i], s[i + 2]})) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}