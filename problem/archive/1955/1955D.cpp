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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    in(a);
    in(b);

    int ans = 0, cnt = 0;
    map<int, int> ca, cb;
    for (auto x: b) {
        cb[x]++;
    }
    for (int i = 0; i < m; i++) {
        if (ca[a[i]] < cb[a[i]]) {
            cnt++;
        }
        ca[a[i]]++;
    }
    if (cnt >= k) ans++;
    for (int i = m; i < n; i++) {
        if (ca[a[i - m]] > 0 && ca[a[i - m]] <= cb[a[i - m]]) {
            cnt--;
        }
        ca[a[i - m]]--;
        if (ca[a[i]] < cb[a[i]]) {
            cnt++;
        }
        ca[a[i]]++;
        if (cnt >= k) ans++;
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