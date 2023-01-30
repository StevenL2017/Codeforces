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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, k; cin >> n >> k;
    vi x(n), y(n); in(x); in(y);

    sorta(x);
    vi suf(n + 1, 0);
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
        while (j >= 0 && x[j] - x[i] > k) {
            j--;
        }
        suf[i] = max(suf[i + 1], j - i + 1);
    }

    int ans = 0, pre = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && x[i] - x[j] > k) {
            j++;
        }
        pre = max(pre, i - j + 1);
        ans = max(ans, pre + suf[i + 1]);
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