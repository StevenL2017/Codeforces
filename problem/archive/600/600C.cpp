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

    map<char, int> cnt;
    for (auto c: s) {
        cnt[c]++;
    }

    vector<char> odd;
    for (auto [k, v]: cnt) {
        if (v & 1) {
            odd.push_back(k);
        }
    }

    for (int i = 0, j = ssz(odd) - 1; i < j; i++, j--) {
        cnt[odd[i]]++;
        cnt[odd[j]]--;
    }

    string ans, mid;
    for (char c = 'a'; c <= 'z'; c++) {
        if (cnt[c] > 0) {
            string cur(cnt[c] / 2, c);
            ans += cur;
            if (cnt[c] & 1) {
                mid = c;
            }
        }
    }

    string rev_ans = ans;
    reverse(begin(rev_ans), end(rev_ans));

    cout << ans + mid + rev_ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}