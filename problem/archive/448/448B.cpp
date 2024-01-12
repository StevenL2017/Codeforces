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
    string s, t;
    cin >> s >> t;

    if (ssz(s) < ssz(t)) {
        cout << "need tree" << endl;
        return;
    }

    int n = ssz(s), m = ssz(t);
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == t[j]) j++;
        if (j == m) {
            cout << "automaton" << endl;
            return;
        }
    }

    vi cs(26), ct(26);
    for (auto c: s) {
        cs[c - 'a']++;
    }
    for (auto c: t) {
        ct[c - 'a']++;
    }

    bool eq = true;
    for (int i = 0; i < 26; i++) {
        if (cs[i] < ct[i]) {
            cout << "need tree" << endl;
            return;
        } else if (cs[i] > ct[i]) {
            eq = false;
        }
    }

    if (eq) cout << "array" << endl;
    else cout << "both" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}