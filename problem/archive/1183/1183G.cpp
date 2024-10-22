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
    int n;
    cin >> n;
    vi cnt(n), good(n);
    for (int i = 0; i < n; i++) {
        int x, f;
        cin >> x >> f;
        x--;
        cnt[x]++;
        if (f) good[x]++;
    }

    vector<vi> a(n + 1);
    for (int i = 0; i < n; i++) {
        a[cnt[i]].push_back(good[i]);
    }

    vi ans(2);
    multiset<int> s;
    for (int i = n; i > 0; i--) {
        for (auto x: a[i]) {
            s.insert(x);
        }
        if (!s.empty()) {
            int x = *s.rbegin();
            ans[0] += i;
            ans[1] += min(i, x);
            s.erase(s.find(x));
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