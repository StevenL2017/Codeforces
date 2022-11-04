#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); in(a);

    vector<ll> pre_sum(n + 1, 0), pre_xor(n + 1, 0);
    map<int, int> odd, even, mp;
    odd[0] = -1;
    even[0] = 0;
    rep(i, n) {
        pre_sum[i + 1] = pre_sum[i] + a[i];
        pre_xor[i + 1] = pre_xor[i] ^ a[i];
        if (i & 1) {
            if (odd.find(pre_xor[i + 1]) != odd.end()) mp[i + 1] = odd[pre_xor[i + 1]];
            else mp[i + 1] = -1;
            even[pre_xor[i + 1]] = i + 1;
        } else {
            if (even.find(pre_xor[i + 1]) != even.end()) mp[i + 1] = even[pre_xor[i + 1]];
            else mp[i + 1] = -1;
            odd[pre_xor[i + 1]] = i + 1;
        }
    }

    while (q--) {
        ll l, r; cin >> l >> r;
        if (pre_sum[r] - pre_sum[l - 1] == 0) {
            cout << 0 << endl;
            continue;
        }
        if ((r - l + 1) & 1) {
            if ((pre_xor[r] ^ pre_xor[l - 1]) == 0) {
                cout << 1 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            if ((pre_xor[r] ^ pre_xor[l - 1]) != 0) {
                cout << -1 << endl;
            } else {
                if (a[l - 1] == 0 && ((pre_xor[r] ^ pre_xor[l]) == 0)) {
                    cout << 1 << endl;
                }
                else if (a[r - 1] == 0 && ((pre_xor[r - 1] ^ pre_xor[l - 1]) == 0)) {
                    cout << 1 << endl;
                }
                else if (mp[r] > l) {
                    cout << 2 << endl;
                }
                else {
                    cout << -1 << endl;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}