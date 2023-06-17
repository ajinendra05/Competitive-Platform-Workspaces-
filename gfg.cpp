#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define rep(i, a, b) for (long long int i = a; i < b; i++)
#define MOD 1000000007
#define pb push_back
#define ff first
#define ss second
#define vb vector<bool>
#define vs vector<string>
#define ll long long int
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define ld long double
#define ull unsigned long long int
#define mod 1e9 + 7
const int m = mod;
// #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
//     #endif

//----------------------------- # --- MAIN CODE --- # -----------------------------//

// User function Template for C++
const int n = 1e5 + 10;
int fact[n];

int finLength(int N, vector<int> color, vector<int> radius)
{

    int count = 0;
    vector<int> c, r;
    c.push_back(color[0]);
    r.push_back(radius[0]);
    for (int i = 1; i < N; i++)
    {
        if (c.size() == 0)
        {
            c.push_back(color[i]);
            r.push_back(radius[i]);
            continue;
        }
        if (color[i] == c[c.size() - 1] && radius[i] == r[r.size() - 1])
        {

            c.pop_back();
            r.pop_back();
            continue;
        }
        c.push_back(color[i]);
        r.push_back(radius[i]);
    }
    return N - count;
}

// subString prefix suffix
int prefixSuffixString(vector<string> &s1, vector<string> s2)
{
    // Code here
    int res;
    st.erase(st.begin(), st.end());
    for (auto x : s1)
    {
        getSubString(x);
    }

    for (auto x : s2)
    {
        if (st.find(x) != st.end())
            res++;
    }
}

unordered_set<string> getSubString(string s)
{

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
}

//
unordered_set<string> st;

// small sum
vector<long long> smallerSum(int n, vector<int> &arr)
{
    // Code here
    vector<int> tempa = arr;
    vector<long long> res;
    long long s;
    vector<long long> s2(n);
    int index = 0;
    sort(tempa.begin(), tempa.end());
    for (int i = 0; i < n; i++)
    {
        s2[i] = (i > 0) ? s2[i - 1] + tempa[i - 1] : 0;
    }
    for (auto x : arr)
    {
        index = binarySearch(tempa, 0, n - 1, x);
        s = (index > 0) ? s2[index] : 0;
        res.push_back(s);
    }
    return res;
}
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class SolutionSantaBanta
{
    public:
    int LargButMinFreq(int arr[], int n) {
       vector<int>  x(0,1000000);
       
    }
};

void frequencyNumber(int arr[],int size)
{
   
  // Creating a HashMap containing integer
  // as a key and occurrences as a value
  unordered_map<int,int>freqMap;
 
  for (int i=0;i<size;i++) {
    freqMap[arr[i]]++;
  }
 
  // Printing the freqMap
  for (auto it : freqMap) {
    cout<<it.first<<" "<<it.second<<endl;
  }
}



class Solutionsantabanta{
public:
vector<int>ans;
    int dfs(int index,int count, vector<vector<int>> &g, vector<bool>&vis ){
        vis[index]=true;
        count++;
        for(auto &it: g[index]){
            if(vis[it])continue;
            count = dfs(it,count,g,vis);
        }
        
        return count;
        
    }
    void precompute(){
         const long long N = 2e6 + 1;
        vector<bool>prime(N, true);
        
        for(long long p = 2; p*p <=N; p++){
            
            if(prime[p]){
                for(long long i = p*p; i <= N; i+=p)
                    prime[i] = false;
            }    
        
        }
        for(long long i = 2; i<=N; i++){
            if(prime[i] == true) ans.push_back(i);
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        if(m==0){
            return -1;
        }
        vector<bool>vis(n+1,false);
        int count =0;
        for(int i =1;i<=n;i++){
            if(vis[i])continue;
            count = max(count , dfs(i,0,g,vis));
        }
        return ans[count-1];
    }
    
};

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

int main()
{ 

    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};
  int size = sizeof(arr)/sizeof(arr[0]);
  frequencyNumber(arr,size);

//     MyHashSet myHashSet =  MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// cout<<myHashSet.contains(1); // return True
// cout<<myHashSet.contains(3); // return False, (not found)
// myHashSet.add(2);      // set = [1, 2]
// cout<<myHashSet.contains(2); // return True
// myHashSet.remove(2);   // set = [1]
// cout<<myHashSet.contains(2); 

    // fastio();
    // ll t;

    return 0;
}
class MyHashSet
{
    vector<int> hashSet;

public:
    

    void add(int key){

        if(!binarySearch(this->hashSet,0,this->hashSet.size(),key)){
            hashSet.push_back(key);
            sort(hashSet.begin(),hashSet.end());
        }
     
    // {if(key>this->hashSet[this->hashSet.size()-1]){
    //     hashSet.push_back(key);
    //     return;
    // }
    // if(key<this->hashSet[0]){
    //     hashSet.insert(hashSet.begin(),key);
    //     return;
    // }
    // addbinarySearch(hashSet,0,hashSet.size(),key);
    }

    void remove(int key)
    { if(hashSet[hashSet.size()-1]==key){
        hashSet.erase(hashSet.begin()+(hashSet.size()-1));
        return;
    }
        // std::remove(this->hashSet.begin(),this->hashSet.end(),key);
        deleteBybinarySearch(hashSet,0,hashSet.size()-1,key);

    }
   void deleteBybinarySearch(vector<int> v, int s, int e, int element)
    {
        if (s > e)
            return ;
        int mid = s + (e - s) / 2;
        if (v[mid] == element)
        {
            hashSet.erase(hashSet.begin()+mid);
            return ;
        }
        if (v[mid] < element)
        {
            binarySearch(v, mid + 1, e, element);
            return;
        }
       binarySearch(v, s, mid - 1, element);
       return;
    }
    // binarySearch(vector<int> v, int s, int e, int element)
    // {
    //     if (s > e)
    //         return false;
    //     int mid = s + (e - s) / 2;
    //     if (v[mid] == element)
    //     {
    //         return ;
    //     }
    //     if (v[mid] < element&& element<v[mid+1])
    //     {
            
    //     }
    //     if (v[mid] < element)
    //     {
    //         return binarySearch(v, mid + 1, e, element);
    //     }
    //     return binarySearch(v, s, mid - 1, element);
    // }
    bool binarySearch(vector<int> v, int s, int e, int element)
    {
        if (s > e)
            return false;
        int mid = s + (e - s) / 2;
        if (v[mid] == element)
        {
            return true;
        }
        if (v[mid] < element)
        {
            return binarySearch(v, mid + 1, e, element);
        }
        return binarySearch(v, s, mid - 1, element);
    }
    bool contains(int key)
    {
        return binarySearch(this->hashSet, 0, this->hashSet.size(), key);
    }
};

class s2AddTwoNumbers
{
    int remainder = 0;

public:
    void addResulet(ListNode *a, ListNode *b, ListNode *back)
    {
        if (a == NULL && b == NULL && remainder == 0)
        {
            return;
        }
        else if (a == NULL && b == NULL)
        {
            if (remainder > 9)
            {
                ListNode *temp = new ListNode(remainder % 10);
                back->next = temp;
                back = temp;
                remainder = remainder / 10;
                addResulet(a, b, back);
                return;
            }
            ListNode *temp = new ListNode(remainder);
            remainder = remainder / 10;
            back->next = temp;
            back = temp;
            // if (remainder != 0)
            //     addResulet(a, b, back);
            return;
        }
        else if (a == NULL)
        {
            int x;
            x = remainder + b->val;
            if (x > 9)
            {

                remainder = x / 10;
                x = x % 10;

                ListNode *temp = new ListNode(x);
                back->next = temp;
                back = temp;
                addResulet(a, b->next, back);
                return;
            }
            ListNode *temp = new ListNode(x);
            remainder = 0;
            back->next = temp;
            back = temp;
            addResulet(a, b->next, back);
        }
        else if (b == NULL)
        {
            int x;
            x = remainder + a->val;
            if (x > 9)
            {

                remainder = x / 10;
                x = x % 10;

                ListNode *temp = new ListNode(x);
                back->next = temp;
                back = temp;
                addResulet(a->next, b, back);
                return;
            }
            ListNode *temp = new ListNode(x);
            remainder = 0;
            back->next = temp;
            back = temp;
            addResulet(a->next, b, back);
        }
        else
        {
            int x = this->remainder + a->val + b->val;
            if (x > 9)
            {
                remainder = x / 10;
                x = x % 10;

                ListNode *temp = new ListNode(x);
                back->next = temp;
                back = temp;
                addResulet(a->next, b->next, back);
                return;
            }
            ListNode *temp = new ListNode(x);
            remainder = 0;
            back->next = temp;
            back = temp;
            addResulet(a->next, b->next, back);
        }
        return;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *back = res;
        int x = l1->val + l2->val;
        if (x > 9)
        {
            remainder = x / 10;
            x = x % 10;
        }
        res->val = x;

        addResulet(l1->next, l2->next, back);

        return res;
    }
};
class s1603DesignParkingSystem
{
    int minCost(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        divide(cuts, 0, n);
    }

    int divide(vector<int> &c, int s, int e)
    {

        if ((e - s) % 2 == 0)
        {
            if (find(c.begin(), c.end(), (e - s) / 2) != c.end())
            {
                return e - s + divide(c, s, (e - s) / 2) + divide(c, (e - s) / 2, e);
            }
        }
        int cost = INT_MAX;

        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] > s && c[i] < e)
            {
                cost = min(cost, (e - s + divide(c, s, c[i]) + divide(c, c[i], e)));
            }
        }
        return cost == INT_MAX ? 0 : cost;
    }
};


//
// int Solution::flag = 0;
static int flag;
int bestNumbers(int N, int A, int B, int C, int D)
{
    int len = N;

    int ansC = 0;

    if (flag == 0)
    {
        countFact();
        flag++;
    }
    for (int i = 0; i <= len / 2; i++)
    {
        bool ansflag1 = false;
        bool ansflag2 = false;
        int c1 = (i * A) + ((len - i) * B);
        int c2 = (i * B) + ((len - i) * A);

        while (c1 >= 1)
        {
            if (c1 % 10 == C || c1 % 10 == D)
            {
                ansflag1 = true;
                break;
            }
            c1 = c1 / 10;
        }
        if (c1 != c2)
        {
            while (c2 >= 1)
            {
                if (c2 % 10 == C || c2 % 10 == D)
                {
                    ansflag2 = true;
                    break;
                }
                c2 = c2 / 10;
            }
        }

        if (ansflag1)
        {
            int c3 = fact[len];
            int c4 = (fact[i] * 1LL * fact[N - i]) % m;
            int ans;

            ans = (c3 * binexp(c4, m - 2, m)) % m;

            ansC += ans;
        }
        if (ansflag2)
        {
            int c3 = fact[len];
            int c4 = (fact[i] * 1LL * fact[N - i]) % m;
            int ans;

            ans = (c3 * 1LL * binexp(c4, m - 2, m)) % m;

            ansC += ans;
        }
    }

    return ansC % m;
}
void countFact()
{
    fact[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % m;
    }
}

int binexp(int a, int b, int m)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }

    return result;
}

// solution
int minimumNumber(int n, vector<int> &arr)
{
    // Code here
    int result = findGCD(arr, n);
    return result;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int findGCD(vector<int> &arr, int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

int solve(int N, vector<int> p)
{
    // code here
    vector<int> n(N + 1, 0);
    int total = N - 1;
    for (int i = 1; i < N; i++)
    {
        n[p[i]]++;
        n[i]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (n[i] == 0)
        {
            total--;
        }
    }

    if (total < 0)
        return 0;
    return total;
}



//good + medium
class SolutionKthSequenceOfPermutationofN
{
    string ans;
    int fact[10];
    map<int, bool> isVisited;

public:
    SolutionKthSequenceOfPermutationofN()
    {
       
        fact[0] = 1;
        for (int i = 1; i < 9; ++i)
        {
            fact[i] = (fact[i - 1] * i);
        }
    }

    string kthPermutation(int n, int k)
    {
        vector<int> valToadd = {'1', '2', '3', '4', '5','6', '7', '8', '9','0'};
        int digitcovered = 0;
        ans="";

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if ((j * fact[n - i] + digitcovered) >= k)
                {
                    ans.push_back(valToadd[j - 1]);
                    digitcovered = digitcovered+ fact[n - i] * (j - 1);
                    // valToadd[j - 1] = valToadd[j ];
                    valToadd.erase(valToadd.begin()+(j-1));

                    break;
                }
            
            }
        }
        return ans;
    }
};

// xxx