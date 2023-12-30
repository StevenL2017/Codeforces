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
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;

    set<pair<int, int>> sk;
    sk.emplace(xk - a, yk - b);
    sk.emplace(xk - a, yk + b);
    sk.emplace(xk + a, yk - b);
    sk.emplace(xk + a, yk + b);
    sk.emplace(xk - b, yk - a);
    sk.emplace(xk - b, yk + a);
    sk.emplace(xk + b, yk - a);
    sk.emplace(xk + b, yk + a);

    set<pair<int, int>> sq;
    sq.emplace(xq - a, yq - b);
    sq.emplace(xq - a, yq + b);
    sq.emplace(xq + a, yq - b);
    sq.emplace(xq + a, yq + b);
    sq.emplace(xq - b, yq - a);
    sq.emplace(xq - b, yq + a);
    sq.emplace(xq + b, yq - a);
    sq.emplace(xq + b, yq + a);

    int ans = 0;
    for (auto item: sk) {
        if (sq.count(item)) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}