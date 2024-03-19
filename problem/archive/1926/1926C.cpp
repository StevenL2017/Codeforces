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

const int N = 2e5 + 3;

ll ans[N];

ll calc(int x) {
    ll cur = 0;
    while (x) {
        cur += x % 10;
        x /= 10;
    }
    return cur;
}

void precompute() {
    for (int i = 1; i < N; i++) {
        ans[i] = calc(i) + ans[i - 1];
    }
}

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t;
    while (t--) solve();
}