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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    vi cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    vi ans(n + 1);
    for (int i = 0; i <= n; i++) {
        ans[cnt[i]]++;
        if (n - i + 1 <= n) {
            ans[n - i + 1]--;
        }
        if (!cnt[i]) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i + 1] += ans[i];
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}