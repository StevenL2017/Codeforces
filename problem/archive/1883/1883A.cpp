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
    string s; cin >> s;

    char c = '1';
    auto calc = [&] (char a, char b) -> int {
        if (a == b) return 0;
        if (a == '0') {
            return 10 - (b - '0');
        }
        if (b == '0') {
            return 10 - (a - '0');
        }
        return max(a, b) - min(a, b);
    };

    int ans = 0;
    for (auto x: s) {
        ans += calc(c, x);
        c = x;
    }
    cout << ans + 4 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}