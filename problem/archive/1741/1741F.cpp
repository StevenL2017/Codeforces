#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 1; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

vi calc(vector<vi> a) {
    int n = a.size();
    vector<pair<int, int>> l, r;
    rep(i, n) {
        l.emplace_back(a[i][0], i);
        r.emplace_back(a[i][1], i);
    }
    sortA(l);
    sortA(r);

    vector<pair<int, int>> cur;
    vector<vector<pair<int, int>>> suf(n);
    repD(i, n - 1, -1) {
        int j = r[i].second;
        int xl = a[j][0], xr = r[i].first, c = a[j][2];
        if (cur.empty()) {
            cur.emplace_back(xl, c);
        }
        else if (cur.size() == 1) {
            if (cur[0].second == c) {
                cur[0].first = min(cur[0].first, xl);
            } else {
                cur.emplace_back(xl, c);
            }
        }
        else {
            if (cur[0].second == c) {
                cur[0].first = min(cur[0].first, xl);
            }
            else if (cur[1].second == c) {
                cur[1].first = min(cur[1].first, xl);
            } else {
                cur.emplace_back(xl, c);
            }
        }
        sortA(cur);
        if (cur.size() == 3) {
            cur.pop_back();
        }
        suf[i] = cur;
    }

    vi ans(n, INF);
    int k = 0;
    rep(i, n) {
        int j = l[i].second;
        int xl = l[i].first, xr = a[j][1], c = a[j][2];
        while (k < n && r[k].first < xl) k++;
        if (k < n) {
            auto s = suf[k];
            if (s[0].second != c) {
                ans[j] = min(ans[j], max(0, s[0].first - xr));
            }
            else if (s.size() == 2) {
                ans[j] = min(ans[j], max(0, s[1].first - xr));
            }
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vi> a(n, vi(3)), b(n, vi(3));
    rep(i, n) {
        cin >> a[i][0];
        cin >> a[i][1];
        cin >> a[i][2];
        b[i][0] = INF - a[i][1];
        b[i][1] = INF - a[i][0];
        b[i][2] = a[i][2];
    }

    vi ans1 = calc(a), ans2 = calc(b);
    rep(i, n) {
        cout << min(ans1[i], ans2[i]) << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}