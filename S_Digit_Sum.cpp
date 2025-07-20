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
int solve(int pos , int mod , int flag , string s , int d , vector<vii>& dp)
{
    int n = s.size();
    if(pos == n) return (mod == 0);

    if(dp[pos][mod][flag] != - 1) return dp[pos][mod][flag];

    int limit;
    if(flag) limit = s[pos] - '0';
    else limit = 9;
    int ans = 0;
    for(int i = 0 ; i <= limit ; i ++)
    {
        int nmod = (mod + i)%d;
        int nflag;
        if(flag == 1 && i == limit) nflag = 1;
        else nflag = 0;

        ans = (ans + solve(pos + 1 , nmod , nflag , s , d , dp))%MXI;
    }

    return dp[pos][mod][flag] = ans;
}
int32_t main(){
    Guess_Who_Is_This
    string s; cin >> s;
    int d; cin >> d;
    int n = s.size();
    vector<vii> dp(n + 1 , vii(d , vi(2 , -1)));

    cout << (solve(0 , 0 , 1 , s , d , dp) - 1 + MXI)%MXI;

    return 0;
}