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

const int N = 39;

ll a[N];

void precompute() {
    a[0] = 1;
    for (int i = 1; i < N; i++) {
        a[i] = a[i - 1] + powl(3, i);
    }
}

ll dfs(ll x) {
    if (x <= 0) {
        return 0;
    }
    int idx = lower_bound(a, a + N, x) - a;
    ll ans = powl(3, idx);
    ans += dfs(x - ans);
    return ans;
}

void solve() {
    ll n; cin >> n;

    cout << dfs(n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t;
    while (t--) solve();
}