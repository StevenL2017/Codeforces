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
    string s; cin >> s;

    int ans = 0, first = -1, last = -1;
    rep(i, n - 1) {
        if (s[i] == '0' && s[i + 1] == '1') {
            ans += 1;
            if (first == -1) first = i + 1;
            last = i + 1;
        }
        else if (s[i] == '1' && s[i + 1] == '0') {
            ans += 10;
            if (first == -1) first = i;
            last = i;
        }
        else if (s[i] == '1' && s[i + 1] == '1') {
            ans += 11;
            if (first == -1) first = i;
            last = i + 1;
        }
    }

    if (last != -1 && n - 1 - last > 0 && n - 1 - last <= k) {
        ans -= (last == 0 ? 9 : 10);
        k -= n - 1 - last;
        if (first > 0 && first != last && first <= k) {
            ans--;
        }
    }
    else if (first > 0 && first < n - 1 && first <= k) {
        ans--;
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