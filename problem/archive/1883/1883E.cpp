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
    vector<ll> a(n);
    in(a);

    ll ans = 0, pre = 0;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            ll x = a[i];
            while (x < a[i - 1]) {
                x <<= 1ll;
                pre++;
            }
            ans += pre;
        } else {
            ll x = a[i - 1];
            while (pre > 0 && (x << 1ll) <= a[i]) {
                x <<= 1ll;
                pre--;
            }
            ans += pre;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}