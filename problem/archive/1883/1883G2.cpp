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
    int n, m;
    cin >> n >> m;
    vi a(n - 1), b(n);
    in(a);
    in(b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cnt = 0, mx = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (j < n - 1 && b[i] > a[j]) {
            cnt++;
            j++;
            continue;
        }
        mx = max(mx, b[i]);
    }
    cnt = n - 1 - cnt;

    cout << (m < mx ? cnt * 1ll * m : (cnt * 1ll * (mx - 1) + (cnt + 1) * 1ll * (m - mx + 1))) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}