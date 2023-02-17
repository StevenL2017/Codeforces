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
    int n; string s;
    cin >> n >> s;

    int suf = 0;
    vi suf_cnt(26, 0);
    rep(i, n) {
        if (suf_cnt[s[i] - 'a'] == 0) {
            suf++;
        }
        suf_cnt[s[i] - 'a']++;
    }

    int ans = suf, pre = 0;
    vi pre_cnt(26, 0);
    rep(i, n) {
        if (pre_cnt[s[i] - 'a'] == 0) {
            pre++;
        }
        pre_cnt[s[i] - 'a']++;
        suf_cnt[s[i] - 'a']--;
        if (suf_cnt[s[i] - 'a'] == 0) {
            suf--;
        }
        ans = max(ans, pre + suf);
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