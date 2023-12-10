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

    vector<pair<char, int>> sl, su;
    for (int i = 0; i < ssz(s); i++) {
        if (s[i] == 'b') {
            if (!sl.empty()) {
                sl.pop_back();
            }
        }
        else if (s[i] == 'B') {
            if (!su.empty()) {
                su.pop_back();
            }
        }
        else {
            if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
                sl.emplace_back(s[i], i);
            } else {
                su.emplace_back(s[i], i);
            }
        }
    }

    string ans;
    int i = 0, j = 0;
    while (i < ssz(sl) || j < ssz(su)) {
        if (i < ssz(sl) && j < ssz(su)) {
            if (sl[i].second < su[j].second) {
                ans += sl[i++].first;
            } else {
                ans += su[j++].first;
            }
        }
        else if (i < ssz(sl)) {
            ans += sl[i++].first;
        }
        else if (j < ssz(su)) {
            ans += su[j++].first;
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