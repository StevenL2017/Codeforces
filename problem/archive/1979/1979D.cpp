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

bool check(string s, int k) {
    int n = ssz(s);
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && s[j] == s[i]) {
            j++;
        }
        if ((j - i) != k) {
            return false;
        }
        i = j;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0, j = 0; i < n; ) {
        while (j < n && s[j] == s[i]) {
            j++;
        }
        int l = j - i, start = -1;
        if (l < k) {
            start = j;
        } else if (l > k) {
            start = j - k;
        }
        if (start >= 0) {
            string t = s.substr(start, n - start);
            string pre = s.substr(0, start);
            reverse(pre.begin(), pre.end());
            t += pre;
            if (check(t, k)) {
                cout << start << endl;
            } else {
                cout << -1 << endl;
            }
            return;
        }
        i = j;
    }
    cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}