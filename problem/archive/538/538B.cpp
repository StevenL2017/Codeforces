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
    int n; cin >> n;

    vi d;
    int k = 0;
    while (n) {
        d.push_back(n % 10);
        k = max(k, d.back());
        n /= 10;
    }

    vi ten(10, 1);
    for (int i = 1; i < 10; i++) {
        ten[i] = ten[i - 1] * 10;
    }

    vi ans(k, 0);
    for (int j = 0; j < ssz(d); j++) {
        for (int i = 0; i < d[j]; i++) {
            ans[i] += ten[j];
        }
    }

    cout << k << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}