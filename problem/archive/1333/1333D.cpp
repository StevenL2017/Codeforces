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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int mn = 0, mx = 0, cnt = 0, pre = -1;
    repd(i, n - 1, -1) {
        if (s[i] == 'R') {
            if (cnt == 0) continue;
            mx += cnt;
            mn = max(cnt, pre + 1);
            pre = mn;
        } else {
            cnt++;
        }
    }

    if (k < mn || mx < k) {
        cout << -1 << endl;
        return;
    }

    auto get_step = [&] (string s) -> vi {
        vi steps;
        rep(i, n - 1) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                steps.push_back(i);
            }
        }
        return steps;
    };

    bool single = false;
    vi remain;
    rep(i, k) {
        if (!single) {
            auto steps = get_step(s);
            int m = ssz(steps), j = 0;
            cout << min(m, mx - (k - 1 - i)) << " ";
            while (j < m && mx > k - 1 - i) {
                cout << steps[j] + 1 << " ";
                swap(s[steps[j]], s[steps[j] + 1]);
                j++;
                mx--;
            }
            if (mx == k - 1 - i) {
                single = true;
                remain = get_step(s);
            }
        } else {
            int v = remain.back();
            remain.pop_back();
            cout << 1 << " " << v + 1;
            swap(s[v], s[v + 1]);
            if (v - 1 >= 0 && s[v - 1] == 'R') {
                remain.push_back(v - 1);
            }
            if (v + 2 < n && s[v + 2] == 'L') {
                remain.push_back(v + 1);
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}