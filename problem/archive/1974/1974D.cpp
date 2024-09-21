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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ns = 0, we = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') ns++;
        else if (s[i] == 'S') ns--;
        else if (s[i] == 'W') we++;
        else we--;
    }

    if ((ns & 1) || (we & 1)) {
        cout << "NO" << endl;
        return;
    }

    if (ns == 0 && we == 0 && n < 4) {
        cout << "NO" << endl;
        return;
    }

    string ans(n, 'R');
    if (ns == 0 && we == 0) {
        if (s[0] == 'N') {
            ans[0] = 'H';
            int i = 1;
            while (i < n && s[i] != 'S') {
                i++;
            }
            ans[i] = 'H';
        }
        else if (s[0] == 'S') {
            ans[0] = 'H';
            int i = 1;
            while (i < n && s[i] != 'N') {
                i++;
            }
            ans[i] = 'H';
        }
        else if (s[0] == 'W') {
            ans[0] = 'H';
            int i = 1;
            while (i < n && s[i] != 'E') {
                i++;
            }
            ans[i] = 'H';
        }
        else if (s[0] == 'E') {
            ans[0] = 'H';
            int i = 1;
            while (i < n && s[i] != 'W') {
                i++;
            }
            ans[i] = 'H';
        }
        cout << ans << endl;
        return;
    }

    ns /= 2;
    we /= 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N' && ns > 0) {
            ans[i] = 'H';
            ns--;
        }
        else if (s[i] == 'S' && ns < 0) {
            ans[i] = 'H';
            ns++;
        }
        else if (s[i] == 'W' && we > 0) {
            ans[i] = 'H';
            we--;
        }
        else if (s[i] == 'E' && we < 0) {
            ans[i] = 'H';
            we++;
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