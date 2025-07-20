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

// int solve(int i , int j , string& a , string& b , vii&dp)
// {
//     if(i < 0 || j < 0) return 0 ; 

//     if(dp[i][j] != -1) return dp[i][j] ; 

//     if(a[i] == b[j]) 
//     {
//         int x = 1 + solve(i - 1 , j - 1 , a , b , dp);
//         return dp[i][j] = x;
//     }

//     int t = solve(i - 1 , j , a , b , dp);
//     int nt = solve(i , j - 1, a ,b , dp);

//     return dp[i][j] = max(t ,nt); 
// }

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1,s2;

    cin>>s1>>s2;

    int a = s1.size();
    int b = s2.size();

    vii dp((a + 1) , vi((b + 1) , - 1)) ; 
    
    for(int i = 0 ; i <= b ; i ++) dp[0][i] = 0 ;
    for(int i = 0 ; i <= a ; i ++) dp[i][0] = 0 ; 

    for(int i = 1 ; i <= a ; i ++)
    {
        for(int j = 1 ; j <= b ; j ++)
        {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1] ;
            else
            {
                dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]) ; 
            }
        }
    }
    string ans = "" ; 
    int x = a , y = b ;

    while(x > 0 && y > 0)
    {
        if(s1[x - 1] == s2[y - 1]) 
        {
            ans.push_back(s1[x - 1]) ; 
            x -- ; y -- ;
        }
        else
        {
            if(dp[x - 1][y] >= dp[x][y - 1]) x -- ;
            else y -- ;
        }   
    }
    reverse(all(ans));
    cout << ans << endl ;






    return 0;
}