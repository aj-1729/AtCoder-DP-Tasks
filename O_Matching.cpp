// jha
// 2025-07-12
#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define f(n) for(int i = 0 ; i < n ; i++)
#define f1(n) for(int i = 1 ; i <= n ; i++)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define vi vector<int>
#define vii vector<vector<int>>
#define vs vector<string>
#define mi map<int,int>
#define pii pair<int,int>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<type>>
#define T(t) int t ; cin >> t ; while( t -- )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MXI 1000000007LL
using namespace std;
#define debug(...) 42

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vii adj(n , vi(n));
    f(n) for(int j = 0 ; j < n ; j ++) cin >> adj[i][j];

    vi dp((1 << n) , 0); dp[0] = 1;
    for(int i = 0 ; i < (1 << n) ; i ++)
    {
        int till = __builtin_popcount(i);
        for(int j = 0 ; j < n ; j ++)
        {
            if(!(i & (1 << j))) 
            {
                if(adj[till][j] == 1) dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i])%MXI;
            }
        }
    }
    cout << dp[(1 << n) - 1];
    return 0;
}