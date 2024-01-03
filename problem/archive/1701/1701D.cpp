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
    vi b(n); in(b);

    vector<pair<int, int>> left;
    for (int i = 0; i < n; i++) {
        left.emplace_back((i + 1) / (b[i] + 1) + 1, i);
    }
    sort(left.begin(), left.end());

    vi a(n);
    set<pair<int, int>> s;
    for (int x = 1, i = 0; x <= n; x++) {
        while (i < n && left[i].first == x) {
            auto idx = left[i].second;
            s.emplace(b[idx] ? (idx + 1) / b[idx] : n, idx);
            i++;
        }
        a[(*s.begin()).second] = x;
        s.erase(s.begin());
    }

    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}