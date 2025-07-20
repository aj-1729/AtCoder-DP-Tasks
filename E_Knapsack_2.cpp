// jha
// 23-06-2025
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

int solve(int ind , int target , vector<pii>& vec , vii& dp)
{
    if(target == 0) return 0;
    if(ind < 0) return 1e18;

    if(dp[ind][target] != - 1) return dp[ind][target]; 

    int s = solve(ind - 1 , target , vec , dp);

    if(target - vec[ind].second >= 0) 
    s = min(s , vec[ind].first + solve(ind - 1 , target - vec[ind].second , vec , dp));

    return dp[ind][target] = s;


}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n , w ; cin >> n >> w; 

    vector<pii> vec(n);
    int total = 0 ;
    f(n) 
    {
        int u , v ;
        cin >> u >> v;
        vec[i].first = u ;
        vec[i].second = v;
        total+=v;
    }
    int ans = 0 ;

    vii dp(n , vi(total + 1 , - 1)) ;
    for(int i = 0 ; i <= total ; i ++)
    {
        if(solve((n - 1) , i , vec , dp) <= w) ans = i ;
    }

    cout << ans ;

    




    
    return 0;
}