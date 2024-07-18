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
    int n, k;
    ll x;
    cin >> n >> k >> x;
    string s;
    cin >> s;

    x--;
    reverse(s.begin(), s.end());
    string ans;
    for (int i = 0; i < n; ) {
        if (s[i] == 'a') {
            ans += 'a';
            i++;
            continue;
        }
        int j = i;
        while (i < n && s[i] == '*') {
            i++;
        }
        int c = (i - j) * k + 1;
        ans += string(x % c, 'b');
        x /= c;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}