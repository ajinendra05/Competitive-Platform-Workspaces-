#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define REP(i, a, b) for (long long int i = a; i < b; i++)
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

// #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
//     #endif

//----------------------------- # --- MAIN CODE --- # -----------------------------//

#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n, x, y;
    cin>>n;

    map<int, int > m1;
    map<int, int > m2;

    priority_queue<pair<int, int>> pq1;
    priority_queue<pair<int, int>> pq2;

    for(int i=0; i<n; i++){
        cin>>x>>y;
        pq1.push({x, y});
        pq1.push({y, x});

        m1[x]++;
        m2[y]++;
    }



}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int n, x, sum = 0;
    cin >> n;

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.push(x);
    }

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        sum += pq.top();
        ans[i] = sum;

        pq.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    int x, n;
    unordered_set<int> st;
    unordered_map<int, bool> flag;
    int count = 0;
    int ans = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (flag[x] == false)
        {
            flag[x] = true;

            count++;
            ans = max(count, ans);
        }
        else
        {
            count--;
            flag[x] = false;
        }
    }

    cout << count;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    int x, y, price;
    cin >> x >> y >> price;

    int extra = price / 30;
    x += extra;

    if (x % y == 0)
        cout << x / y << endl;
    else
        cout << x / y + 1 << endl;
}

int main()
{

    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    int lastd = 0;
    int digit = 0;
    int c = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        x = (int)log2(v[i]) + 1;
        if (x > digit)
        {
            c = 1;
            lastd = digit;
            digit = x;
        }
        else if (x == digit)
        {
            c++;
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    if (c == 1)
    {
        cout << c << endl;
    }
    else if (c == n || (digit > (lastd + 1)))
    {
        int rem = c % 2;
        cout << (c / 2) + rem << endl;
    }
    else
    {
        cout << c << endl;
    }
}

int main()
{

    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int n = words.size();
        vector<string> revwords;
        string s;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            s = words[i];
            reverse(s.begin(), s.end());

            revwords.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; i < n; i++)
            {
                if (words[i] == revwords[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution
{
public:
    int longestString(int x, int y, int z)
    {
        int sum = 0;
        int m = min(x, y);
        int M = max(x, y);

        sum = (m * 2) + min((m + 1) * 2, M * 2) + (z * 2);
        return sum;
    }
};

class Solution
{
    int k;

public:
    int traversee(vector<string> &words, string s, int i)
    {
        if (i == k)
            return s.size();

        string s1;
        string s2;

        if (s[0] == words[i].back() && s.back() == words[i][0])
        {
            s.size() > 1 ? s1 = words[i] + s.substr(1, s.size() - 1) : s1 = words[i];
            words[i].size() > 1 ? s2 = s + words[i].substr(1, s.size() - 1) : s2 = s;
            return min(traversee(words, s1, i + 1), traversee(words, s2, i + 1));
        }
        if (s[0] == words[i].back() || (words[i].size() == 1 && s[0] == words[i][0]))
        {
            s1 = words[i] + s.substr(1, s.size() - 1);
            return min(traversee(words, s1, i + 1), traversee(words, s + words[i], i + 1));
        }
        if (s.back() == words[i][0] || (s.size() == 1 && s[0] == words[i][0]))
        {
            s2 = s + words[i].substr(1, s.size() - 1);
            return min(traversee(words, words[i] + s, i + 1), traversee(words, s2, i + 1));
        }
        return min(traversee(words, words[i] + s, i + 1), traversee(words, s + words[i], i + 1));
    }

    int minimizeConcatenatedLength(vector<string> &words)
    {
        k = words.size();
        return traversee(words, words[0], 1);
    }
};

class Solution
{
    int GCD(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        return GCD(b % a, a);
    }

public:
    int countBeautifulPairs(vector<int> &nums)
    {
        int n = nums.size();
        int x1, x2;
        int dig;
        int count = 0;
        int m, M;
        for (int i = 0; i < n; i++)
        {
            dig = log10(nums[i]);
            x1 = nums[i] / pow(10, dig);
            for (int j = i + 1; j < n; j++)
            {
                x2 = nums[i] % 10;
                m = min(x1, x2);
                M = max(x1, x2);
                if (gcd(m, M) == 1)
                    count++;
            }
        }
        return count;
    }
};

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        if (num1 <= num2)
            return -1;

        int ans = num1;
        int count = 0;
        int bits;
        ans = num1 - num2;
        while (ans > 0)
        {
            (ans & 1) == 1 ? count++ : count;
            ans = ans >> 1;
        }
        // while (num1 != 0)
        // {
        //     //   ans-=(num2);
        //     //   bits=log2(ans);
        //     //   count++;
        //     //   ans-=pow(2,bits);
        //     count++;
        //     for (int i = 0; i <= 60; i++)
        //     {
        //         if (((num1 - pow(2, i)) == num2))
        //         {
        //             return count;
        //         }
        //         if (((num1 - pow(2, i) - num2) < num2))
        //         {
        //             num1 = num1 - (num2 + pow(2, i - 1));
        //             // num1-=pow(2,i-1);
        //             break;
        //         }
        //     }
        // }
        return count + 1;
    }
};

class Solution
{
    int fact[100];
    const int m = 1e9 + 7;
    void countFact()
    {
        fact[0] = 1;
        for (int i = 1; i < 100; ++i)
        {
            fact[i] = (fact[i - 1] * 1LL * i) % m;
        }
    }

public:
    Solution()
    {
        countFact();
    }
    int numberOfGoodSubarraySplits(vector<int> &nums)
    {
        int n = nums.size();
        int ones = 0;
        for (auto x : nums)
        {
            if (x == 1)
                ones++;
        }
        if (ones == 1)
            return 1;
        long long ans = fact[n - ones] / fact[ones];
    }
};