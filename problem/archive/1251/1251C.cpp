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

    string odd, even;
    for (auto c : s) {
        if ((c - '0') & 1) odd += c;
        else even += c;
    }

    string ans;
    int i = 0, j = 0;
    while (i < ssz(odd) || j < ssz(even)) {
        if (i < ssz(odd) && j < ssz(even)) {
            if (odd[i] < even[j]) {
                ans += odd[i++];
            } else {
                ans += even[j++];
            }
        }
        else if (i < ssz(odd)) {
            ans += odd[i++];
        }
        else if (j < ssz(even)) {
            ans += even[j++];
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