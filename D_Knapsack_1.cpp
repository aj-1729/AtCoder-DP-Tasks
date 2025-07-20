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

int solve(int ind , vector<pii>& vec , int target , vii& dp)
{
    if(ind == 0)
    {
        if((target - vec[ind].first) >= 0) return vec[ind].second;
        return 0;
    }

    if(dp[ind][target] != - 1) return dp[ind][target] ; 

    int t = 0 , nt = 0;

    if(target - vec[ind].first >= 0) t = vec[ind].second + solve(ind - 1 , vec , target - vec[ind].first , dp);

    nt = solve(ind - 1 , vec , target , dp);


    return dp[ind][target] = max(t , nt);


}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n , w ; cin >> n >> w; 

    vector<pii> vec(n);
    f(n) 
    {
        int u , v ;
        cin >> u >> v;
        vec[i].first = u ;
        vec[i].second = v;
    }

    vii dp(n , vi((w + 1) , -1));

    cout << solve((n - 1) , vec , w , dp) ;




    
    return 0;
}