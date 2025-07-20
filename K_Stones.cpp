/**
   author : fakeboy75 
   date   : 2025-07-14
**/
#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
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
#define Guess_Who_Is_This ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
#define debug(...) 42

int32_t main(){
    Guess_Who_Is_This
    
    int n, k; cin >> n >> k;
    vi vec(n); 
    for(int i = 0 ; i < n ; i ++) cin >> vec[i];

    vi dp(k + 1 , 0);
    dp[0] = 0;

    for(int i = 1 ; i <= k ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if((i - vec[j]) >= 0 && dp[i - vec[j]] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    if(dp[k]) cout << "First";
    else cout << "Second";
    return 0;
}