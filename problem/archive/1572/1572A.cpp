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
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n;
    cin >> n;

    vi ans(n);
    queue<int> q;
    vector<vi> graph(n);
    vi indeg(n, 0);
    rep(i, n) {
        int k;
        cin >> k;
        if (k == 0) {
            ans[i] = 1;
            q.push(i);
        }
        rep(j, k) {
            int req;
            cin >> req;
            graph[req - 1].push_back(i);
            indeg[i]++;
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        for (auto& nxt: graph[cur]) {
            if (--indeg[nxt] == 0) {
                q.push(nxt);
            }
            ans[nxt] = max(ans[nxt], nxt < cur ? ans[cur] + 1 : ans[cur]);
        }
    }

    if (cnt != n) cout << -1 << endl;
    else cout << *max_element(ans.begin(), ans.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}