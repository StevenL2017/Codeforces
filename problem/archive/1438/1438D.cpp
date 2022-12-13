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
    vi a(n); in(a);

    map<int, vi> mp;
    rep(i, n) {
        mp[a[i]].push_back(i);
    }

    vector<vi> ans;
    int i = -1, j = -1;
    for (auto& [k, v]: mp) {
        if (ssz(v) % 2 == 0) continue;
        if (i == -1) {
            i = v.back();
            mp[k].pop_back();
        }
        else if (j == -1) {
            j = v.back();
            mp[k].pop_back();
        }
        else {
            auto z = v.back();
            mp[k].pop_back();
            auto xor_ = a[i] ^ a[j] ^ a[z];
            a[i] = a[j] = a[z] = xor_;
            mp[xor_].push_back(i);
            mp[xor_].push_back(j);
            ans.push_back({i + 1, j + 1, z + 1});
            i = z;
            j = -1;
        }
    }
    if (i != -1) mp[a[i]].push_back(i);
    if (j != -1) mp[a[j]].push_back(j);

    int cnt = 0, z = 0;
    for (auto& [k, v]: mp) {
        if (ssz(v) & 1) {
            cnt++;
            z = v.back();
        }
    }
    if (cnt == 2) {
        cout << "NO\n";
        return;
    }

    for (auto& [k, v]: mp) {
        if (k == a[z]) continue;
        for (int i = 0; i < ssz(v); i += 2) {
            ans.push_back({v[i] + 1, v[i + 1] + 1, z + 1});
        }
    }

    cout << "YES\n";
    cout << ssz(ans) << endl;
    for (auto& v: ans) out(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}