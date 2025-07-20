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

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n ,m ; cin >>n>>m;

    vii adj(n + 1) ; 

    f(m)
    {
        int u,v ;
        cin >> u >> v;

        adj[u].pb(v);
    }

    vi indegree(n + 1 , 0) ; 
    f1(n)
    {
        for(int j = 0 ; j < adj[i].size() ; j++)
        {
            indegree[adj[i][j]] ++ ;
        }
    }

    queue<int> q; 
    f1(n)
    {
        if(indegree[i] == 0) q.push(i);
    }

    vi dis((n + 1) , 0);
    //dis[1] = 0;

    while(!(q.empty()))
    {
        int node = q.front();
        q.pop();

        for(int i = 0 ; i < adj[node].size() ; i ++)
        {
            int e = adj[node][i];
            if(dis[node] + 1 > dis[e]) dis[e] = dis[node] + 1;

            indegree[e] -- ;
            if(indegree[e] == 0) q.push(e);
        }
    }

    cout << *max_element(dis.begin() + 1 , dis.end());
    
    return 0;
}