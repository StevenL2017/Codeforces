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
    vi p(n); in(p);

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vi odd, even;
    int co = (n + 1) / 2, ce = n / 2;
    int ans = 0, c = 0, pre = -1;
    rep(i, n) {
        if (p[i] == 0) {
            c++;
        } else {
            if (p[i] & 1) {
                co--;
                if (pre == -1 || pre & 1) {
                    if (pre != -1 && c > 0) odd.push_back(c);
                } else {
                    ans++;
                }
            } else {
                ce--;
                if (pre == -1 || !(pre & 1)) {
                    if (pre != -1 && c > 0) even.push_back(c);
                } else {
                    ans++;
                }
            }
            c = 0;
            pre = p[i] & 1;
        }
    }

    if (pre == -1) {
        cout << 1 << endl;
        return;
    }

    sorta(odd);
    sorta(even);
    rep(i, ssz(odd)) {
        if (co >= odd[i]) {
            co -= odd[i];
        } else {
            ans += (ssz(odd) - i) * 2;
            break;
        }
    }
    rep(i, ssz(even)) {
        if (ce >= even[i]) {
            ce -= even[i];
        } else {
            ans += (ssz(even) - i) * 2;
            break;
        }
    }

    int i = 0;
    c = 0;
    while (i < n && p[i] == 0) {
        i++;
        c++;
    }
    if (p[i] & 1) {
        if (co >= c) co -= c;
        else ans++;
    } else {
        if (ce >= c) ce -= c;
        else ans++;
    }

    i = n - 1;
    c = 0;
    while (i >= 0 && p[i] == 0) {
        i--;
        c++;
    }
    if (p[i] & 1 && co < c) ans++;
    else if (!(p[i] & 1) && ce < c) ans++;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}