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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; cin >> n;
    vector<string> s(n); in(s);

    auto check = [&] (string t) -> bool {
        int m = ssz(t);
        rep(i, (m + 1) / 2) {
            if (t[i] != t[m - 1 - i]) return false;
        }
        return true;
    };

    set<string> vis2, vis3;
    rep(i, n) {
        if (check(s[i])) {
            cout << "YES\n";
            return;
        }
        if (ssz(s[i]) == 2) {
            if (vis2.count(s[i]) || vis3.count(s[i])) {
                cout << "YES\n";
                return;
            }
            string temp = "";
            temp += s[i][1];
            temp += s[i][0];
            vis2.insert(temp);
        }
        else if (ssz(s[i]) == 3) {
            string suf = "";
            suf += s[i][1];
            suf += s[i][2];
            if (vis3.count(s[i]) || vis2.count(suf)) {
                cout << "YES\n";
                return;
            }
            string temp = "";
            temp += s[i][1];
            temp += s[i][0];
            vis3.insert(temp);
            temp = s[i][2] + temp;
            vis3.insert(temp);
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}