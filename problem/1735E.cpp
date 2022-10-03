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
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

bool check(int diff, vi& d1, vi& d2) {
    int n = d1.size();
    int p1 = 0, p2 = diff;
    multiset<int, greater<int>> s1, s2;
    rep(i, n) {
        s1.insert(d1[i]);
        s2.insert(d2[i]);
    }

    auto farthest = [&] (multiset<int, greater<int>>& s) -> int {
        return s.empty() ? -1 : *s.begin();
    };
    auto far_both = [&] () -> int {
        return max(farthest(s1), farthest(s2));
    };

    vi ans;
    while (far_both() > diff) {
        bool choose_s1 = farthest(s1) > farthest(s2);
        auto& s_far = choose_s1 ? s1 : s2;
        auto& s_near = choose_s1 ? s2 : s1;
        int value = *s_far.begin();
        int complem = value - diff;
        if (!s_near.count(complem)) {
            return false;
        }
        s_far.erase(s_far.find(value));
        s_near.erase(s_near.find(complem));
        if (choose_s1) {
            ans.push_back(p1 + value);
        } else {
            ans.push_back(p2 - value);
        }
    }

    vi mid1, mid2;
    for (auto x : s1) {
        mid1.push_back(x);
    }
    for (auto x : s2) {
        mid2.push_back(x);
    }
    sortA(mid1);
    sortD(mid2);
    rep(i, mid1.size()) {
        if (mid1[i] + mid2[i] != diff) {
            return false;
        }
    }

    rep(i, mid1.size()) {
        ans.push_back(mid1[i]);
    }
    sortA(ans);
    if (ans[0] < 0) {
        int delta = -ans[0];
        p1 += delta;
        p2 += delta;
        rep(i, ans.size()) {
            ans[i] += delta;
        }
    }

    cout << "YES" << endl;
    rep(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << p1 << " " << p2 << endl;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vi d1(n), d2(n);
    rep(i, n) {
        cin >> d1[i];
    }
    rep(i, n) {
        cin >> d2[i];
    }

    int dist1 = d1[0];
    for (auto dist2 : d2) {
        if (check(dist1 + dist2, d1, d2)) {
            return;
        }
        if (check(abs(dist1 - dist2), d1, d2)) {
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}