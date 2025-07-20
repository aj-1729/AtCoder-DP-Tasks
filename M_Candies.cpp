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
    int n,k ; cin >> n >> k;
    vi vec(n); f(n) cin >> vec[i];

    //dp[i][j] = different ways to give j candies to first i children
    vii dp(n + 1 , vi(k + 1 , 0));
    dp[0][0] = 1;

    for(int i = 1 ; i <= n ; i ++)
    {
        vi ps(k + 2 , 0);
        for(int j = 1 ; j <= k + 1 ; j ++)
        {
            ps[j] = (ps[j - 1] + dp[i - 1][j - 1])%MXI;
        }
        for(int j = 0 ; j <= k ; j ++)
        {
            int low = max(0LL , (j - vec[i - 1]));
            dp[i][j] = (dp[i][j] + ps[j + 1] - ps[low])%MXI;
        }
    }
    cout << dp[n][k] << endl;

    return 0;
}