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
    vi a(n); in(a);

    auto calc1 = [&] (vi a) -> vector<pair<int, int>> {
        vector<pair<int, int>> ans;
        int mx = *max_element(a.begin(), a.end());
        if (mx <= 0) {
            for (int i = n - 1; i > 0; i--) {
                ans.emplace_back(i, i + 1);
            }
            return ans;
        }
        int mxi = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx) {
                mxi = i + 1;
                break;
            }
        }
        int mn = *min_element(a.begin(), a.end());
        while (mx < abs(mn)) {
            ans.emplace_back(mxi, mxi);
            mx *= 2;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                ans.emplace_back(i + 1, mxi);
            }
        }
        for (int i = 1; i < n; i++) {
            ans.emplace_back(i + 1, i);
        }
        return ans;
    };

    auto calc2 = [&] (vi a) -> vector<pair<int, int>> {
        vector<pair<int, int>> ans;
        int mn = *min_element(a.begin(), a.end());
        if (mn >= 0) {
            for (int i = 1; i < n; i++) {
                ans.emplace_back(i + 1, i);
            }
            return ans;
        }
        int mni = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == mn) {
                mni = i + 1;
                break;
            }
        }
        int mx = *max_element(a.begin(), a.end());
        while (abs(mn) < mx) {
            ans.emplace_back(mni, mni);
            mn *= 2;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                ans.emplace_back(i + 1, mni);
            }
        }
        for (int i = n - 1; i > 0; i--) {
            ans.emplace_back(i, i + 1);
        }
        return ans;
    };

    auto ans = calc1(a);
    if (ssz(ans) <= 31) {
        cout << ssz(ans) << endl;
        for (auto [i, j] : ans) {
            cout << i << " " << j << endl;
        }
        return;
    }
    ans = calc2(a);
    cout << ssz(ans) << endl;
    for (auto [i, j] : ans) {
        cout << i << " " << j << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}