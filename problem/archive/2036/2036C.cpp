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
    int q;
    cin >> s >> q;

    int n = ssz(s), tot = 0;
    for (int i = 0; i < n - 3; i++) {
        if (s[i] == s[i + 1] && s[i] == '1' && s[i + 2] == s[i + 3] && s[i + 2] == '0') {
            tot++;
        }
    }

    while (q--) {
        int idx, val;
        cin >> idx >> val;

        idx--;
        int cur = 0;
        for (int i = max(0, idx - 3); i <= min(idx, n - 4); i++) {
            if (s[i] == s[i + 1] && s[i] == '1' && s[i + 2] == s[i + 3] && s[i + 2] == '0') {
                cur--;
            }
        }
        s[idx] = '0' + val;
        for (int i = max(0, idx - 3); i <= min(idx, n - 4); i++) {
            if (s[i] == s[i + 1] && s[i] == '1' && s[i + 2] == s[i + 3] && s[i + 2] == '0') {
                cur++;
            }
        }
        tot += cur;
        
        cout << (tot > 0 ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}