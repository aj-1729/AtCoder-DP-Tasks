// jha
// 26-05-2025
#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define f(n) for(int i = 0 ; i < n ; i++)
#define f1(n) for(int i = 1 ; i <= n ; i++)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define vi vector<int>
#define vs vector<string>
#define mi map<int,int>
#define T(t) int t ; cin >> t ; while( t -- )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MXI 1000000007LL
using namespace std;
#define debug(...) 42

int solve(int ind , int last , vector<vi> vec , vector<vi> & dp)
{
    if(ind == 0) 
    {
        int mini = INT_MIN ; 
        f(4)
        {
            if(i != last) mini = max(mini , vec[ind][i]) ; 
        }
        return mini ;        
    }

    if(dp[ind][last] != -1) return dp[ind][last] ; 


    int points = 0 ;
    int maxi = INT_MIN ; 

    f(3)
    {
        if(i != last)
        {
            points = vec[ind][i] + solve(ind - 1 , i , vec , dp) ; 
            maxi = max(points , maxi) ;
        }
             
    }

    return dp[ind][last] = maxi ; 


}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >> n ; 

    vector <vi> vec(n , vi (3)) ; 

    f(n) for(int j = 0 ; j < 3 ; j ++) cin >> vec[i][j] ; 

    vi dp(4 , 0) ; 

    dp[0] = max(vec[0][1] , vec[0][2]) ;
    dp[1] = max(vec[0][2] , vec[0][0]) ; 
    dp[2] = max(vec[0][1] , vec[0][0]) ;
    dp[3] = max(max(vec[0][1] , vec[0][2]) , vec[0][0]) ;




    for(int i = 1 ; i < n ; i ++)
    {
        vi temp (4 , 0) ; 
        for(int j = 0 ; j < 4 ; j ++)
        {
            int points = 0 ; 

            for(int z = 0 ; z < 3 ; z ++)
            {
                if(z != j)
                {
                    
                    temp[j] = max(temp[j] , (vec[i][z] + dp[z])) ; 
                }
            }
        }
        dp = temp ; 
    }

    cout << dp[3] ; 




    return 0;
}