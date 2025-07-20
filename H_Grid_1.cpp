// jha
// 22-06-2025
#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define f(n) for(int i = 0 ; i < n ; i++)
#define f1(n) for(int i = 1 ; i <= n ; i++)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define vi vector<int>
#define vs vector<string>
#define vii vector <vector <int>>
#define mi map<int,int>
#define T(t) int t ; cin >> t ; while( t -- )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MXI 1000000007LL
using namespace std;
#define debug(...) 42
 
int solve(int row , int col , vs& vec , vii& dp)
{
    if(row == 0 && col == 0) return 1 ;
    if(row < 0 || col < 0) return 0 ; 
    if(vec[row][col] == '#') return 0 ; 
 
    if(dp[row][col] != -1) return dp[row][col] ; 
 
    int a = solve(row - 1 , col , vec , dp) ; 
    int b = solve(row , col - 1 , vec , dp) ; 
 
    return  dp[row][col] = (a + b)%MXI ; 
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n , m; cin >> n >> m; 
 
    vs vec(n) ; 
    f(n) cin >> vec[i] ; 
 
    vii dp(n , vi(m , -1)) ;
 
    // for(int i = 0 ; i <  n ; i ++)
    // {
    //     vi fresh (n , 0) ;
    //     for(int j = 0 ; j < n ; j ++)
    //     {
    //         if(vec[i][j] == '*') fresh[j] = 0 ; 
    //         else if(i == 0 && j == 0) fresh[j] = 1 ; 
    //         else
    //         {
    //             if(i > 0 && j > 0) fresh[j] = (dp[j] + fresh[j-1]) % MXI ; 
    //             else if(i == 0 && !j == 0) fresh[j] = (fresh[j-1]) % MXI ; 
    //             else fresh[j] = (dp[j]) % MXI ;  
    //         }
    //     }
    //     dp = fresh ; 
    // }
 
 
    if(vec[0][0] == '.' && vec[n - 1][m - 1] == '.') cout << solve(n - 1 , m - 1, vec , dp);
    else cout << 0;
 
 
    
    
    
    return 0;
}