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
    int q, a0, c0;
    cin >> q >> a0 >> c0;

    map<int, vi> amount, cost;
    map<int, vector<ll>> money;
    amount[0] = {a0};
    cost[0] = {c0};
    money[0] = {a0 * 1ll * c0};
    
    vector<vi> graph(q + 1);
    vi start(q + 1, 0);

    auto update = [&] (int u) {
        for (auto& v: graph[u]) {
            start[v]++;
        }
    };

    rep(i, q) {
        int op; cin >> op;
        if (op == 1) {
            int p, a, c;
            cin >> p >> a >> c;

            graph[p].push_back(i + 1);
            start[i + 1] = start[p];
            
        } else {

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