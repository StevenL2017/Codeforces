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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    int n = ssz(s), i = 0;
    while (i < n && s[i] == '0') {
        i++;
    }

    int ans = 0;
    while (i < n) {
        while (i < n && s[i] == '1') {
            i++;
        }
        int i0 = i;
        while (i < n && s[i] == '0') {
            i++;
        }
        if (i == n) ans += a;
        else ans += min(a, b * (i - i0));
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