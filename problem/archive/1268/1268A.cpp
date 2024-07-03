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
    cin >> n >> k;
    string s;
    cin >> s;

    string t(n, '1');
    for (int i = 0; i < n; i++) {
        if (i < k) t[i] = s[i];
        else t[i] = t[i % k];
    }

    if (t >= s) {
        cout << n << endl << t << endl;
        return;
    }

    for (int i = k - 1; i >= 0; i--) {
        if (t[i] != '9') {
            t[i]++;
            for (int j = i + 1; j < k; j++) {
                t[j] = '0';
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        t[i] = t[i % k];
    }

    cout << n << endl << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}