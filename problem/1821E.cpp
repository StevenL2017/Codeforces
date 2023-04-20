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
    int k; string s;
    cin >> k >> s;

    int n = ssz(s);
    ll ans = LLONG_MAX;
    while (k >= 0) {
        vi cnt(n, 0), mp(n, -1);
        vector<int> st;
        ll cur = 0;
        repd(i, n - 1, -1) {
            if (s[i] == ')') {
                st.push_back(i);
            } else {
                auto j = st.back();
                st.pop_back();
                mp[j] = i;
                if (!st.empty()) {
                    cur += ssz(st);
                    cnt[st[0]]++;
                }
            }
        }
        ans = min(ans, cur);

        int mx = 0, right = -1;
        rep(i, n) {
            if (cnt[i] && cnt[i] >= mx && mp[i] != -1) {
                mx = cnt[i];
                right = i;
            }
        }
        if (right == -1) break;
        auto left = mp[right];
        string t = s.substr(0, left + 1) + ')' + s.substr(left + 1, right - left - 1) + s.substr(right + 1, n - right - 1);
        s = t;
        k--;
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