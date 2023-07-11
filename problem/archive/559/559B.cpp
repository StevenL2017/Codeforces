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

string smallest(string s) {
    if (ssz(s) & 1) return s;
    string s1 = smallest(s.substr(0, ssz(s) / 2));
    string s2 = smallest(s.substr(ssz(s) / 2, ssz(s) / 2));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}

void solve() {
    string a, b; cin >> a >> b;

    cout << (smallest(a) == smallest(b) ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}