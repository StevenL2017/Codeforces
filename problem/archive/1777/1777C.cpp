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
    int n, m; cin >> n >> m;
    vi a(n); in(a);

    sorta(a);
    int ans = INT_MAX, c = 0, left = 0;
    vi cnt(m + 1, 0);
    for (int right = 0; right < n; right++) {
        for (int x = 1; x * x <= a[right]; x++) {
            if (a[right] % x == 0 && x <= m) {
                cnt[x]++;
                if (cnt[x] == 1) c++;
                if (x * x < a[right] && a[right] / x <= m) {
                    cnt[a[right] / x]++;
                    if (cnt[a[right] / x] == 1) c++;
                }
            }
        }
        if (c == m) ans = min(ans, a[right] - a[left]);
        while (left <= right && c == m) {
            for (int x = 1; x * x <= a[left]; x++) {
                if (a[left] % x == 0 && x <= m) {
                    cnt[x]--;
                    if (cnt[x] == 0) c--;
                    if (x * x < a[left] && a[left] / x <= m) {
                        cnt[a[left] / x]--;
                        if (cnt[a[left] / x] == 0) c--;
                    }
                }
            }
            left++;
            if (left <= right && c == m) ans = min(ans, a[right] - a[left]);
        }
    }

    cout << (ans < INT_MAX ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}