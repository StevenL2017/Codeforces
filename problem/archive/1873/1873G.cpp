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

    int n = ssz(s);
    bool all = false;
    if (s[0] == 'B' || s[n - 1] == 'B') all = true;
    int tot = 0, mn = n;
    for (int i = 0; i < n; ) {
        int i0 = i;
        while (i < n && s[i] == s[i0]) {
            i++;
        }
        if (s[i0] == 'A') {
            tot += i - i0;
            mn = min(mn, i - i0);
        } else if (i - i0 > 1) {
            all = true;
        }
    }

    cout << (all ? tot : tot - mn) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}