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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    pair<int, int> start, end;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    int n; cin >> n;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int c = a; c <= b; c++) {
            mp[make_pair(r, c)] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    mp[start] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto [dr, dc]: vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}}) {
            pair<int, int> v = {u.first + dr, u.second + dc};
            if (mp[v] == -1) {
                mp[v] = mp[u] + 1;
                q.push(v);
            }
        }
    }
    cout << mp[end] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}