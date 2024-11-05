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

const int MOD = 998244353;

void solve() {
    int l, r;
    cin >> l >> r;

    int ans1 = 0, x = l;
    while (x <= r) {
        x <<= 1;
        ans1++;
    }

    int ans21 = r / (1 << (ans1 - 1)) - l + 1;
    int ans22 = max(0, r / (1 << (ans1 - 2)) / 3 - l + 1) * (ans1 - 1) % MOD;
    int ans2 = (ans21 + ans22) % MOD;

    cout << ans1 << " " << ans2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}