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
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n) {
        cin >> p[i].first >> p[i].second;
        p[i].first += 1e6;
        p[i].second += 1e6;
    }

    while (true) {
        vector<vi> cnt(2, vi(2, 0));
        rep(i, n) {
            cnt[p[i].first & 1][p[i].second & 1]++;
        }
        if (cnt[0][0] + cnt[1][1] > 0 && cnt[0][1] + cnt[1][0] > 0) {
            vi ans;
            rep(i, n) {
                if ((p[i].first + p[i].second) & 1) {
                    ans.push_back(i + 1);
                }
            }
            cout << ssz(ans) << endl;
            out(ans);
            return;
        }
        if (cnt[0][0] + cnt[0][1] > 0 && cnt[1][1] + cnt[1][0] > 0) {
            vi ans;
            rep(i, n) {
                if ((p[i].first) & 1) {
                    ans.push_back(i + 1);
                }
            }
            cout << ssz(ans) << endl;
            out(ans);
            return;
        }

        int x, y;
        rep(i, 2) {
            rep(j, 2) {
                if (cnt[i][j]) {
                    x = i;
                    y = j;
                }
            }
        }
        rep(i, n) {
            p[i].first = (p[i].first - x) / 2;
            p[i].second = (p[i].second - y) / 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}