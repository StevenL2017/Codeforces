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
    int n, m; cin >> n >> m;
    vi k(n); in(k);

    sorta(k);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c < 0) {
            cout << "NO\n";
            continue;
        }

        auto idx = lower_bound(k.begin(), k.end(), b) - k.begin();
        if (idx - 1 >= 0) {
            if ((b - k[idx - 1]) * 1ll * (b - k[idx - 1]) < 4ll * a * c) {
                cout << "YES\n";
                cout << k[idx - 1] << endl;
                continue;
            }
        }
        if (idx + 1 < n) {
            if ((b - k[idx + 1]) * 1ll * (b - k[idx + 1]) < 4ll * a * c) {
                cout << "YES\n";
                cout << k[idx + 1] << endl;
                continue;
            }
        }
        if (idx < n) {
            if ((b - k[idx]) * 1ll * (b - k[idx]) < 4ll * a * c) {
                cout << "YES\n";
                cout << k[idx] << endl;
                continue;
            }
        }
        cout << "NO\n";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}