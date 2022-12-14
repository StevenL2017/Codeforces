#include <iostream>
#include <fstream>
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
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define each(it,s)        for(vit it = s.begin(); it != s.end(); ++it)
#define sortA(v)          sort(v.begin(), v.end())
#define sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define fill(a)           memset(a, 0, sizeof (a))

#define rep(i, n)         for(int i = 0; i < (n); ++i)
#define repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define repD(i, a, n)     for(int i = a; i >= (n); --i)
#define pq(x)			  priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,compare>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

#define loop(i,start,end) for(auto i=(start<end)?start:start-1;(start<end)?i<end:i>=end;(start<end)?i++:i--)

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    vector<int> cnt(2, 0);
    int mod;
    for (int i = 0; i < n; i++) {
        int m = nums[i] % 2;
        cnt[m]++;
        if (cnt[m] > 1) {
            mod = m;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 != mod) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}