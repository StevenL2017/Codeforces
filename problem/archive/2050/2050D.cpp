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

    int n = ssz(s);
    for (int i = 0; i < n; i++) {
        int mx = s[i] - '0', k = i;
        for (int j = i; j < min(n, i + 10); j++) {
            int cur = s[j] - '0' - (j - i);
            if (cur > mx) {
                mx = cur;
                k = j;
            }
        }
        while (k > i) {
            swap(s[k], s[k - 1]);
            k--;
        }
        s[i] = char(mx + '0');
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}