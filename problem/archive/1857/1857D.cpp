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
    int n; cin >> n;
    vi a(n), b(n);
    in(a); in(b);

    vector<pair<int, int>> d;
    for (int i = 0; i < n; i++) {
        d.emplace_back(a[i] - b[i], i + 1);
    }
    sort(d.begin(), d.end(), [&] (pair<int, int> x, pair<int, int> y) { return x.first > y.first || x.first == y.first && x.second < y.second; });

    vi ans;
    for (auto [diff, node]: d) {
        if (diff == d[0].first) {
            ans.push_back(node);
        }
    }

    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}