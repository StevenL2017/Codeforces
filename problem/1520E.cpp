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
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;

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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vi sheeps;
    rep(i, n) {
        if (s[i] == '*') {
            sheeps.push_back(i);
        }
    }

    int m = sheeps.size();
    if (m == 0) {
        cout << 0 << endl;
        return;
    }

    int mid1 = sheeps[m / 2];
    ll ans1 = 0LL;
    int cnt = 1;
    repD(i, m / 2 - 1, -1) {
        ans1 += max(0, mid1 - sheeps[i] - cnt);
        cnt++;
    }
    cnt = 1;
    repA(i, m / 2 + 1, m) {
        ans1 += max(0, sheeps[i] - mid1 - cnt);
        cnt++;
    }

    int mid2 = sheeps[(m + 1) / 2];
    ll ans2 = 0LL;
    cnt = 1;
    repD(i, (m + 1) / 2 - 1, -1) {
        ans2 += max(0, mid2 - sheeps[i] - cnt);
        cnt++;
    }
    cnt = 1;
    repA(i, (m + 1) / 2 + 1, m) {
        ans2 += max(0, sheeps[i] - mid2 - cnt);
        cnt++;
    }

    cout << min(ans1, ans2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}