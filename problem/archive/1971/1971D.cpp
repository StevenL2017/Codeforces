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

    int n = ssz(s), c0 = 0, c1 = 0, i = 0, sub = 0;
    while (i < n) {
        int i0 = i++;
        if (s[i0] == '0') c0++;
        else c1++;
        if (s[i0] == '1' && i0 > 0 && s[i0 - 1] == '0') sub = 1;
        while (i < n && s[i] == s[i0]) i++;
    }

    if (!c0 || !c1) {
        cout << 1 << endl;
        return;
    }
    cout << c0 + c1 - sub << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}