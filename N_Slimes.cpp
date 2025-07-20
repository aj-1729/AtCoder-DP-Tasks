/**
   author : ashwini_jha 
   date   : 2025-07-21
**/
#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define vi vector<int>
#define f(n) for(int i = 0 ; i < n ; i ++)
#define vii vector<vector<int>>
#define mi map<int,int>
#define pii pair<int,int>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type, vector<type>, greater<type>>
#define T(t) int t ; cin >> t ; while( t -- )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MXI 1000000007LL
#define Guess_Who_Is_This ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
#define debug(...) 42

int32_t main(){
    Guess_Who_Is_This
    int n; cin >> n;
    vi vec(n); f(n) cin >> vec[i];
    vi ps(n + 1 , 0);
    for(int i = 1 ; i <= n ; i ++)
    {
        ps[i] = ps[i - 1] + vec[i - 1];
    }

    vii dp(n , vi(n , 1e18));
    for(int i = 0 ; i < n ; i ++) dp[i][i] = 0;

    for(int x = 2 ; x <= n ; x ++)
    {
        for(int i = 0 ;  i <= n - x ; i ++)
        {
            int j = i + x - 1;
            for(int k = i ; k < j ; k ++)
            {
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k + 1][j] + ps[j + 1] - ps[i]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}