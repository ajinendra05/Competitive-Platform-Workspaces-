
#include <bits/stdc++.h>
// GFG

// potd 
// https://practice.geeksforgeeks.org/problems/7a3e0427cbb1ea9fbfec499dc6fce377ffdf7aed/1

/*#define mod 1e9 + 7
const int m = mod;
const int n = 1e5 + 10;
int fact[n];

class Solution
{

public:
    static int flag;
    int bestNumbers(int N, int A, int B, int C, int D)
    {
        int len = N;

        long long ansC = 0;
        if(A==B){
            int c0=N*A;
             while (c0 >= 1)
            {
                if (c0 % 10 == C || c0 % 10 == D)
                {
                    
                   return 1;
                }
                c0 = c0 / 10;
            }
        }
        if (flag == 0)
        {
            countFact();
            flag++;
        }
        for (int i = 0; i <= len; i++)
        {
            bool ansflag1 = false;
            
            int c1 = (i * A) + ((len - i) * B);
            
         
            while (c1 >= 1)
            {
                if (c1 % 10 == C || c1 % 10 == D)
                {
                    ansflag1 = true;
                    break;
                }
                c1 = c1 / 10;
            }
          
            if (ansflag1)
            {
                int c3 = fact[len];
                int c4 = (fact[i] * 1LL * fact[N - i]) % m;
                int ans;

                 ans = (c3*1LL*binexp(c4,m-2,m))%m;

                ansC = (ansC%m+ans)%m;
            }
    
        }

        return ansC;
    }
    void countFact()
    {
        fact[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            fact[i] = (fact[i - 1] * 1LL * i) % m;
        }
    }

    long long binexp(long long a, long long b, long long m)
    {
        long long result = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                result = (result  * a) % m;
            }
            a = (a  * a) % m;
            b >>= 1;
        }

        return result%m;
    }
};
int Solution::flag = 0;
*/

class Solution_TopologySort
{
    vector<int> list;
    map<int, bool> visited;

public:
    void visit(vector<int> adj[], int index)
    {
        if (visited[index] == true)
            return;
        if (adj[index].empty())
        {

            list.push_back(index);
            visited[index] = true;
            return;
        }
        for (int i = 0; i < adj[index].size(); i++)
        {
            visit(adj, adj[index][i]);
        }
        list.push_back(index);
        visited[index] = true;
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {

        for (int i = 0; i < V; i++)
        {
            visit(adj, i);
        }
        vector<int> newList;
        for (int i = list.size() - 1; i >= 0; i--)
        {
            newList.push_back(list[i]);
        }
        // for(int i=0;i<list.size();i++){
        //     cout<<list[i];
        // }
        return newList;
    }
};
