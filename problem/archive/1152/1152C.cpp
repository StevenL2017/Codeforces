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
    int a, b; cin >> a >> b;

    vi cand;
    int x = 1, y = abs(a - b);
    while (x * x <= y) {
        if (y % x == 0) {
            cand.push_back(x);
            if (x * x != y) {
                cand.push_back(y / x);
            }
        }
        x++;
    }

    int ans = 0;
    ll mn = LLONG_MAX;
    for (auto c : cand) {
        if (a % c != b % c) continue;
        int k = 0;
        if (a % c != 0) {
            k = c - a % c;
        }
        ll tmp = lcm((ll)a + k, (ll)b + k);
        if (tmp < mn) {
            mn = tmp;
            ans = k;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}