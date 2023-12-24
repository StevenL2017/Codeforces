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
    ll n, p, l, t;
    cin >> n >> p >> l >> t;

    ll task = (n + 6) / 7;
    ll cnt = (p + l + 2 * t - 1) / (l + 2 * t);
    if (task / 2 >= cnt) {
        cout << n - cnt << endl;
        return;
    }

    ll ans = task / 2;
    p -= (l + 2 * t) * ans;
    if (task & 1) {
        ans++;
        p -= l + t;
    }
    if (p <= 0) {
        cout << n - ans << endl;
        return;
    }

    ans += (p + l - 1) / l;
    cout << n - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}