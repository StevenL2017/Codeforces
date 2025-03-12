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

    vi ans1(n);
    int x = n, last = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || s[i] == '>') {
            for (int j = i; j >= last; j--) {
                ans1[j] = x--;
            }
            last = i + 1;
        }
    }

    vi ans2(n);
    x = 1, last = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || s[i] == '<') {
            for (int j = i; j >= last; j--) {
                ans2[j] = x++;
            }
            last = i + 1;
        }
    }

    out(ans1);
    out(ans2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}