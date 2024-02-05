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

const int N = 1e5 + 3;

int a[N], ss[N];

ll calc(int k, int n) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ss[i] = a[i] + (i + 1) * k;
    }
    sort(ss, ss + n);
    for (int i = 0; i < k; i++) {
        ans += ss[i];
    }
    return ans;
}

void solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    ll tot = 0;
    for (int i = 0; i <= n; i++) {
        auto cur = calc(i, n);
        if (cur <= s) {
            ans = i;
            tot = cur;
        } else {
            break;
        }
    }
    cout << ans << " " << tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}