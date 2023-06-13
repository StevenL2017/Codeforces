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

const vi p = {1, 10, 100, 1000, 10000};

void solve() {
    string s; cin >> s;

    auto calc = [&] (string t) -> int {
        int ans = 0, mx = 0;
        for (int i = ssz(t) - 1; i >= 0; i--) {
            int cur = t[i] - 'A';
            if (cur < mx) {
                ans -= p[cur];
            } else {
                ans += p[cur];
                mx = cur;
            }
        }
        return ans;
    };

    int ans = INT_MIN;
    for (int i = 0; i < 5; i++) {
        char cur = 'A' + i;
        int p = s.find_first_of(cur);
        if (p != -1) {
            for (int j = 0; j < 5; j++) {
                char alt = 'A' + j;
                s[p] = alt;
                ans = max(ans, calc(s));
                s[p] = cur;
            }
        }
        p = s.find_last_of(cur);
        if (p != -1) {
            for (int j = 0; j < 5; j++) {
                char alt = 'A' + j;
                s[p] = alt;
                ans = max(ans, calc(s));
                s[p] = cur;
            }
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