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
    vector<vi> a(n, vi(n));
    rep(i, n) in(a[i]);

    vi salary(n * 2), parent(n * 2);
    rep(i, n) {
        salary[i] = a[i][i];
    }

    vi leaf(n);
    iota(leaf.begin(), leaf.end(), 0);
    function<int(vi)> dfs = [&] (vi leaves) -> int {
        int m = ssz(leaves);
        if (m == 1) {
            return leaves[0];
        }

        int mx = -1;
        rep(i, m) {
            mx = max(mx, a[leaves[0]][leaves[i]]);
        }

        vector<vi> cand;
        cand.push_back({leaves[0]});
        repa(i, 1, m) {
            int idx = -1;
            rep(j, ssz(cand)) {
                if (a[leaves[i]][cand[j][0]] != mx) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) {
                idx = ssz(cand);
                cand.push_back({});
            }
            cand[idx].push_back(leaves[i]);
        }

        int cur = n++;
        salary[cur] = mx;
        rep(i, ssz(cand)) {
            int nxt = dfs(cand[i]);
            parent[nxt] = cur;
        }
        return cur;
    };
    int root = dfs(leaf);

    cout << n << endl;
    rep(i, n) cout << salary[i] << " ";
    cout << endl << root + 1 << endl;
    rep(i, n) {
        if (i == root) continue;
        cout << i + 1 << " " << parent[i] + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}