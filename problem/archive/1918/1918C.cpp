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

ll calc(ll a, ll b, ll r) {
    ll x;
    int i = 60, larger = -1;
    bool is_limit = true;
    while (i >= 0) {
        if ((a >> i & 1ll) == (b >> i & 1ll)) {
            i--;
            continue;
        }
        if (a >> i & 1ll) {
            larger = 0;
        } else {
            larger = 1;
        }
        i--;
        break;
    }
    while (i >= 0) {
        if ((a >> i & 1ll) == (b >> i & 1ll)) {
            i--;
            continue;
        }
        if (a >> i & 1) {

        }
    }
}

void solve() {
    ll a, b, r;
    cin >> a >> b >> r;

    if (a < b) {
        swap(a, b);
    }

    ll x = 0;
    bool first = false;
    for (int i = 60; i >= 0; i--) {
        if ((a >> i & 1ll) == (b >> i & 1ll)) {
            continue;
        }
        if (a >> i & 1ll) {
            if (!first) {
                first = true;
            } else {
                if ((x | (1ll << i)) <= r) {
                    x |= 1ll << i;
                    a ^= 1ll << i;
                    b ^= 1ll << i;
                }
            }
        }
    }

    cout << a - b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}