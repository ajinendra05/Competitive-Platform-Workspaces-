#include <bits/stdc++.h>
using namespace std;
int fact[100];
const int m = 1e9 + 7;


struct AnotherVal{
    int value = -1; // can be changed as per requirement 
};
  
map<int, AnotherVal> tempmap;
// int main()
// {
//     map<int, AnotherVal> tempmap;
//     cout << tempmap[1].value << endl;
  
//     return 0;
// } 
// if(mp.find(z)!=mp.end()) =>
//  z is found in mp at any point becouse
//  iterator is not equal to end of set.

// fact count
void countFact()
{
    fact[0] = 1;
    for (int i = 1; i < 100; ++i)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % m;
    }
}

// binary expo
long long binexp(long long a, long long b, long long m)
{
    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }

    return result % m;
}

// 6c3
void combination()
{
    int c3 = fact[6];
    int c4 = (fact[3] * 1LL * fact[6 - 3]) % m;
    int ans;
    int ansC = 0;

    ans = (c3 * 1LL * binexp(c4, m - 2, m)) % m;

    ansC = (ansC % m + ans) % m;
}

// catalan number  https://www.geeksforgeeks.org/program-nth-catalan-number/
unsigned long int catalan(unsigned int n)
{
    // Base case
    if (n <= 1)
        return 1;

    // catalan(n) is sum of
    // catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
}

// GCD_HCF
int GCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return GCD(b % a, a);
}

// gcd of all numbers of array
int findGCD(vector<int> &arr, int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = GCD(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

// fibonachiNumber
int fibonachiNum(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonachiNum(n - 1) + fibonachiNum(n - 2);
}

// fibonachi Number By formula 
int fibonachiForm(int n){
    int a = int(pow((1+sqrt(5))/2,n)- pow((1-sqrt(5))/2,n) )/sqrt(5);
    return a;
}
// Binary Search
int binarySearch(int a[], int target, int s, int e)
{

    if (s > e)
        return -1;
    int m = s + (e - s) / 2;
    if (a[m] == target)
        return m;

    if (a[m] > target)
        return binarySearch(a, target, s, m - 1);

    return binarySearch(a, target, m + 1, e);
}

// Any matching element
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

// first matching element IMPORTANT
int binarySearch(vector<int> &arr, int l, int r, int x)
{
    int idx = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            idx = m;

        if (arr[m] < x)
        {
            l = m + 1;
        }

        else
            r = m - 1;
    }

    return idx;
}

//get frequency of number
void frequencyNumber(int arr[],int size)
{


unordered_map<int,int>freqMap;

for (int i=0;i<size;i++) {
	freqMap[arr[i]]++;
}

for (auto it : freqMap) {
	cout<<it.first<<" "<<it.second<<endl;
}
}
// get all subString of any string
unordered_set<string> getSubString(string s)
{
    unordered_set<string> st;

    string curr;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (i >= 1)
            st.insert(s.substr(i));
        curr += s[i];
        st.insert(curr);
    }
    string last;
    last += s[n - 1];
    st.insert(last);
    return st;
}

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

vector<bool> isPrime(m,true);
void sieveAlgo_AllPrime(){
  
  isPrime[0]==isPrime[1]==false;
  for(int i=2;i<m;i++){
    if(isPrime[i]){
        for(int j=i*2;j<m;j+=i){
            isPrime[j]=false;
        }
    }
  }
}
int main()
{
    // cout << binexp(2, 8, m);
    // cout << fibonachiNum(8);
    int a[] = {4, 5, 6, 8, 7, 2, 33};
    cout << binarySearch(a, 6, 0, (sizeof(a) / sizeof(a[0])) - 1);
}