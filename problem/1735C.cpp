#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v, T)            sort(v.begin(), v.end(), greater<T>())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans;
    unordered_map<char, char> mp;
    unordered_set<char> used;

    function<bool(char, char)> check = [&](char x, char y) -> bool {
        if (used.find(x) != used.end()) {
            return false;
        }
        int cnt = 0;
        unordered_set<char> visited;
        mp[y] = x;
        while (mp.find(x) != mp.end() && visited.find(x) == visited.end()) {
            cnt++;
            visited.insert(x);
            x = mp[x];
            if (visited.find(x) != visited.end()) {
                if (cnt < 26) {
                    return false;
                }
            }
        }
        return true;
    };

    for (auto &c : s) {
        if (mp.find(c) != mp.end()) {
            ans += mp[c];
            continue;
        }
        rep(i, 26) {
            char x = i + 'a';
            if (check(x, c)) {
                used.insert(x);
                mp[c] = x;
                ans += mp[c];
                break;
            }
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