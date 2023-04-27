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

int query(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;

    vi valid = {1, 2};
    for (int i = 3; i < n; i += 2) {
        vi cur = {valid[0], valid[1], i, i + 1};
        vector<pair<int, int>> res;
        for (int j = 0; j < 4; j++) {
            vi temp;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                temp.push_back(cur[k]);
            }
            auto x = query(temp[0], temp[1], temp[2]);
            res.emplace_back(x, cur[j]);
        }
        sorta(res);
        valid = {res[0].second, res[1].second};
    }
    if (n & 1) {
        int last = 1;
        while (last == valid[0] || last == valid[1]) {
            last++;
        }
        vi cur = {valid[0], valid[1], n, last};
        vector<pair<int, int>> res;
        for (int j = 0; j < 4; j++) {
            vi temp;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                temp.push_back(cur[k]);
            }
            auto x = query(temp[0], temp[1], temp[2]);
            res.emplace_back(x, cur[j]);
        }
        sorta(res);
        valid = {res[0].second, res[1].second};
    }

    cout << "! " << valid[0] << " " << valid[1] << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}