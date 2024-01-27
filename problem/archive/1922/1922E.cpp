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

vi dfs(ll x) {
    vi res;
    if (x == 2) {
        res.push_back(0);
    } else if (x & 1) {
        res = dfs(x - 1);
        res.push_back(*min_element(res.begin(), res.end()) - 1);
    } else {
        res = dfs(x / 2);
        res.push_back(*max_element(res.begin(), res.end()) + 1);
    }
    return res;
}

void solve() {
    ll x;
    cin >> x;

    auto ans = dfs(x);
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