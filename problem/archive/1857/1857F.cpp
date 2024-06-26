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
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int q;
    cin >> q;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll s = x * x - 4 * y;
        if (s < 0) {
            cout << 0 << " ";
            continue;
        }
        auto t = (ll)sqrt(s);
        if (t * t != s && (t + 1) * (t + 1) != s) {
            cout << 0 << " ";
            continue;
        }
        if ((t + 1) * (t + 1) == s) {
            t++;
        }
        if ((x + t) & 1) {
            cout << 0 << " ";
            continue;
        }
        auto a1 = (x - t) / 2, a2 = (x + t) / 2;
        cout << (a1 != a2 ? cnt[a1] * 1ll * cnt[a2] : (cnt[a1] - 1) * 1ll * cnt[a1] / 2) << " ";
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