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
    string s; cin >> s;

    int i = 0;
    while (i < ssz(s) && isalpha(s[i])) {
        i++;
    }
    string a = s.substr(0, i);

    int j = i;
    while (j < ssz(s) && isdigit(s[j])) {
        j++;
    }
    string d1 = s.substr(i, j - i);

    string ans;
    if (j == ssz(s)) {
        int d2 = 0;
        rep(i, ssz(a)) {
            d2 *= 26;
            d2 += a[i] - 'A' + 1;
        }
        string col;
        while (d2) {
            col = (char)(d2 % 10 + '0') + col;
            d2 /= 10;
        }
        ans += 'R';
        ans += d1;
        ans += 'C';
        ans += col;
    } else {
        string col = s.substr(j + 1, ssz(s) - j);
        int d2 = 0;
        rep(i, ssz(col)) {
            d2 *= 10;
            d2 += col[i] - '0';
        }
        while (d2) {
            ans = (char)((d2 % 26 + 25) % 26 + 'A') + ans;
            if (d2 % 26 == 0) {
                d2--;
            }
            d2 /= 26;
        }
        ans += d1;
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