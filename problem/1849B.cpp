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
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) s.emplace(-k, i + 1);
        else s.emplace(-(a[i] % k), i + 1);
    }

    vi ans;
    while (!s.empty()) {
        auto [x, i] = *s.begin();
        s.erase(s.begin());
        x = -x;
        x -= k;
        if (x <= 0) {
            ans.push_back(i);
        } else {
            s.emplace(-x, i);
        }
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}