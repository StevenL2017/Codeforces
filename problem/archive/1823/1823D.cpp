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
    vector<pair<int, int>> a(k);
    rep(i, k) cin >> a[i].first;
    rep(i, k) cin >> a[i].second;

    if (a[0].first < a[0].second) {
        cout << "NO\n";
        return;
    }

    string ans = "abc", temp = "abc";
    rep(_, a[0].second - 3) {
        ans = 'a' + ans;
    }
    int j = 0;
    rep(_, a[0].first - a[0].second) {
        ans += temp[j];
        j = (j + 1) % 3;
    }
    repa(i, 1, k) {
        int px = a[i - 1].first, pc = a[i - 1].second;
        int x = a[i].first, c = a[i].second;
        if (x - c < px - pc) {
            cout << "NO\n";
            return;
        }
        string cur(c - pc, (char)(i + 2 + 'a'));
        ans += cur;
        rep(_, (x - px) - (c - pc)) {
            ans += temp[j];
            j = (j + 1) % 3;
        }
    }

    cout << "YES\n";
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}