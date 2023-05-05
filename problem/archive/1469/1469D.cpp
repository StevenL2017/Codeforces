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

    vi a;
    set<int> s;
    int x = n;
    while (x > 2) {
        a.push_back(x);
        s.insert(x);
        x = ceil(sqrt(x));
    }
    a.push_back(2);

    vector<pair<int, int>> ans;
    repa(i, 3, n) {
        if (!s.count(i)) {
            ans.emplace_back(i, n);
        }
    }
    rep(i, ssz(a) - 1) {
        ans.emplace_back(a[i], a[i + 1]);
        ans.emplace_back(a[i], a[i + 1]);
    }

    cout << ssz(ans) << endl;
    for (auto& v: ans) {
        cout << v.first << " " << v.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}