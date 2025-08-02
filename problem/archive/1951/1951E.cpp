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
    string s;
    cin >> s;

    auto check = [&] (string t) -> bool {
        int l = 0, r = ssz(t) - 1;
        while (l <= r) {
            if (t[l] != t[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    };

    if (!check(s)) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << s << endl;
        return;
    }

    int n = ssz(s), first_diff = -1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[0]) {
            first_diff = i;
            break;
        }
    }

    if (first_diff == -1) {
        cout << "NO" << endl;
        return;
    }

    if (!check(s.substr(0, first_diff + 1)) && !check(s.substr(first_diff + 1, n - first_diff))) {
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << s.substr(0, first_diff + 1) << " " << s.substr(first_diff + 1, n - first_diff) << endl;
        return;
    }

    if (first_diff == 1 || first_diff == n / 2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << 2 << endl;
    cout << s.substr(0, first_diff + 2) << " " << s.substr(first_diff + 2, n - first_diff - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}