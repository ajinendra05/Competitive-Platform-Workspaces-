
#include <bits/stdc++.h>
#define mod 1e9 + 7
const int m = mod;

using namespace std;

class Solution1
{
    int in;
    int out;

public:
    Solution1()
    {
        in = 0;
        out = 0;
    }
    bool isIn(int r, int c, int n)
    {
        if (r >= 0 && r < n && c < n && c >= 0)
        {
            return true;
        }
        return false;
    }
    double checkKnight(int n, int k, int r, int c)
    {
        double count = 0;
        if (k == 0)
        {

            return 1;
        }

        if (isIn(r + 2, c + 1, n))
        {
            // cout<<"1";
            // cout<<checkKnight(n,k-1,r+2,c+1)/double(8);
            count = count + (checkKnight(n, k - 1, r + 2, c + 1) / double(8));
            cout << "1" << count;
        }
        if (isIn(r + 2, c - 1, n))
        {
            // cout<<"12";
            count = count + (checkKnight(n, k - 1, r + 2, c - 1) / double(8));
        }
        if (isIn(r - 2, c + 1, n))
        {
            // cout<<"13";
            count = count + (checkKnight(n, k - 1, r - 2, c + 1) / double(8));
        }
        if (isIn(r - 2, c - 1, n))
        {
            count = count + (checkKnight(n, k - 1, r - 2, c - 1) / double(8));
        }

        if (isIn(r + 1, c + 2, n))
        {
            count = count + (checkKnight(n, k - 1, r + 1, c + 2) / double(8));
        }
        if (isIn(r - 1, c - 2, n))
        {
            count = count + (checkKnight(n, k - 1, r - 1, c - 2) / double(8));
        }
        if (isIn(r + 1, c - 2, n))
        {
            count = count + (checkKnight(n, k - 1, r + 1, c - 2) / double(8));
        }

        if (isIn(r - 1, c + 2, n))
        {
            count = count + (checkKnight(n, k - 1, r - 1, c + 2) / double(8));
        }
        cout << count << endl;
        return count;
    }
    double knightProbability(int n, int k, int row, int column)
    {
        double proba = checkKnight(n, k, row, column);
        // double proba=double(in)/double(in+out);
        // in=0;
        // out=0;
        return proba;
    }
};

class Solution
{
    map<pair<int, int>, bool> isVisited;
    vector<vector<char>> m;
    vector<int> entr;

public:
    bool isSafe(vector<int> tocheck)
    {
        if (tocheck[0] < 0 || tocheck[1] < 0 || tocheck[0] >= m.size() || tocheck[1] >= m[0].size())
        {
            return false;
        }
        if (m[tocheck[0]][tocheck[1]] == '+')
        {
            return false;
        }
        return true;
    }
    int addPath(vector<int> curr)
    {
        if (curr != entr)
            ;
        if (curr[0] == 0 || curr[0] == m.size() - 1 || curr[1] == 0 || curr[1] == m[0].size() - 1)
        {
            return 0;
        }
        if (isVisited[make_pair(curr[0], curr[1])] == true)
        {
            return 20000;
        }
        isVisited[make_pair(curr[0], curr[1])] = true;
        int a = 20000, b = 20000, c = 20000, d = 20000;
        if (isSafe({curr[0] + 1, curr[1]}))
        {
            // isVisited[make_pair(curr[0] + 1, curr[1])] = true;
            a = addPath({curr[0] + 1, curr[1]}) + 1;
            isVisited[make_pair(curr[0] + 1, curr[1])] = false;
        }
        if (isSafe({curr[0], curr[1] + 1}))
        {
            // isVisited[make_pair(curr[0], curr[1] + 1)] = true;
            b = addPath({curr[0], curr[1] + 1}) + 1;
            isVisited[make_pair(curr[0], curr[1] + 1)] = false;
        }
        if (isSafe({curr[0] - 1, curr[1]}))
        {
            // isVisited[make_pair(curr[0] - 1, curr[1])] = true;
            c = addPath({curr[0] - 1, curr[1]}) + 1;
            isVisited[make_pair(curr[0] - 1, curr[1])] = false;
        }
        if (isSafe({curr[0], curr[1] - 1}))
        {
            // isVisited[make_pair(curr[0], curr[1] - 1)] = true;
            d = addPath({curr[0], curr[1] - 1}) + 1;
            isVisited[make_pair(curr[0], curr[1] - 1)] = false;
        }
        return min(a, min(b, min(c, d)));
    }
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        m = maze;
        entr = entrance;
        isVisited[make_pair(entrance[0], entrance[1])] = true;
        return addPath(entrance);
    }
};

class Solution2
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        int left = index;
        int right = n - index - 1;
        int remain = maxSum - n;
        int unocright = right;
        int unocleft = left;
        int total = 1;
        while (unocleft > 0 || unocright > 0)
        {
            if (remain <= 0)
            {
                return total;
            }
            if (remain >= 1 + (right - unocright) + (left - unocleft))
            {
                total++;
                remain = remain - (1 + (right - unocright) + (left - unocleft));
                if (unocleft > 0)
                {
                    unocleft--;
                }
                if (unocright > 0)
                {
                    unocright--;
                }
            }
            else
            {
                return total;
            }
        }
        total = total + (remain / n);
        return total;
    }
};

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int max = INT_MIN;
        int currCount = 1;
        char lastchar;
        int numofpair = 0;
        lastchar = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (lastchar == s[i])
            {
                if (numofpair == 0)
                {
                    numofpair++;
                    currCount++;
                }
                else
                {
                    max = max > currCount ? max : currCount;
                    currCount = 2;
                    numofpair = 1;
                    if (i > 1)
                    {
                        if (s[i] != s[i - 2])
                        {
                            currCount = 3;
                            numofpair = 1;
                        }
                    }
                    if (i < s.size() - 1)
                    {
                        if (s[i] == s[i + 1])
                        {
                            currCount = 1;
                            numofpair = 0;
                        }
                    }
                }
            }
            else
            {
                currCount++;
                lastchar = s[i];
            }
        }
        max = max > currCount ? max : currCount;
        return max;
    }
};

class Solution
{
public:
    int sumDistance(vector<int> &nums, string s, int d)
    {

        vector<int> right;
        vector<int> left;
        vector<int> pairrr;
        // pair<int, int> x;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s[i] == 'R')
            {
                right.push_back(nums[i]);
            }
            else
            {
                left.push_back(nums[i]);
            }
        }
        while (d > 0)
        {
            int minDist = 0;
            for (int i = 0; i < right.size(); i++)
            {
                for (int j = 0; j < left.size(); j++)
                {
                    if (minDist >= left[j] - right[i] && (left[i] > right[i]))
                    {

                        pairrr.push_back(i);
                        pairrr.push_back(j);
                        minDist = left[j] - right[i];
                    }
                }
            }
            minDist = minDist / 2;

            d = d - minDist;
            if (d <= 0 || minDist == 0)
            {
                for (int j = 0; j < left.size(); j++)
                {
                    left[j] -= d;
                }
                for (int i = 0; i < right.size(); i++)
                {
                    right[i] += d;
                }
                break;
            }
            for (int j = 0; j < left.size(); j++)
            {
                left[j] -= minDist;
            }
            for (int i = 0; i < right.size(); i++)
            {
                right[i] += minDist;
            }
            for (int i = 0; i < pairrr.size(); i++)
            {
                if (i % 2 == 0)
                {
                    right.push_back(left[pairrr[i]]);
                    left.erase(left.begin() + pairrr[i]);
                }
                else
                {
                    left.push_back(right[pairrr[i]]);
                    right.erase(right.begin() + pairrr[i]);
                }
            }
            for (auto x : pairrr)
            {
                if (s[x] == 'R')
                {
                    s[x] = 'L';
                }
                else
                {
                    s[x] = 'R';
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < right.size(); i++)
        {
            for (int j = 0; j < left.size(); j++)
            {
                ans = ans + abs(right[i] - left[i]);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    bool isFascinating(int n)
    {

        int num;
        int x;
        map<int, bool> isVisited;
        for (int i = 1; i < 4; i++)
        {
            num = n * i;
            for (int j = 0; j < 3; j++)
            {
                x = num % 10;
                if (isVisited[x] == true)
                {
                    return false;
                }
                else
                {
                    isVisited[x] = true;
                }
                num = num / 10;
            }
        }
        for (int i = 1; i < 10; i++)
        {
            if (isVisited[i] == false)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    int findNonMinOrMax(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return -1;
        }
        int a = nums[0], b = nums[1], c = nums[2];
        if (a > b)
        {
            if (b > c)
            {
                return b;
            }
            if (a > c)
            {
                return c;
            }
            return a;
        }
        else
        {
            if (a > c)
            {
                return a;
            }
            if (b > c)
            {
                return c;
            }
            return b;
        }
        return -1;
    }
};

class Solution3
{
public:
    long long minCost(vector<int> &nums, int x)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long start = nums[0];
        long long sum = nums[0];
        int lengthSmall = 1;
        for (int i = 1; i < n; i++)
        {

            if (sum + x + start > sum + nums[i])
            {
                // lengthSmall++;
                sum += nums[i];
            }
            else
            {
                sum += (x + start);
            }
        }
        return sum;
    }
    long long minCost2(vector<long long> &nums, int x)
    {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long sumCurr = accumulate(nums.begin(), nums.end(), 0LL);
        long long n = nums.size();
        for (int i = 1; i < n + 1; i++)
        {
            int temp = nums[n - 1];
            for (int j = n - 2; j >= 0; j--)
            {
                if (nums[j] < nums[j + 1])
                {
                    nums[j + 1] = nums[j];
                }
            }
            if (temp < nums[0])
            {
                nums[0] = temp;
            }
            sumCurr = accumulate(nums.begin(), nums.end(), 0LL) + long(x * i);
            if (sum > sumCurr)
            {
                sum = sumCurr;
            }
        }
        return sum;
    }
};
// [733,200,839,515,852,615,8,584,250,337]
// 537
class Solution
{
public:
    string smallestString(string s)
    {
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != 'a')
            {
                break;
            }
            else
            {
                start++;
            }
        }
        if (start == s.size())
        {
            s[s.size() - 1] = 'z';
            return s;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (s[i] == 'a')
            {
                break;
            }
            s[i] = s[i] - 1;
        }
        return s;
    }
};

class SnapshotArray
{
    vector<int> arr;
    map<int, map<int, int>> snaps;
    int snapID = 0;
    int currSnapID = 0;
    map<int, int> sameSnap;

    bool flag = false;

public:
    SnapshotArray(int length)
    {
        // vector<int> temp(length,0);
        // snaps.push_back({{-1, 0}});

        // arr=temp;
    }

    void set(int index, int val)
    {
        snaps[snapID][index] = val;
        flag = false;
        // arr[index]=val;
    }

    int snap()
    {
        // snaps.push_back(arr);
        if (flag == true)
        {

            sameSnap[snapID] = currSnapID;
            snapID++;
            return snapID - 1;
        }
        snaps[snapID] = snaps[snapID];
        // push_back(snaps[snapID]);
        currSnapID++;
        snapID++;
        flag = true;
        return snapID - 1;
    }

    int get(int index, int snap_id)
    {
        //  vector<int> temp;
        //  temp=snaps[snap_id];
        if (sameSnap[snap_id] > 1)
        {
            return snaps[sameSnap[snap_id]][index];
        }

        return snaps[snap_id][index];
    }
};

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> colulmns(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                colulmns[i].push_back(grid[j][i]);
            }
        }
        int count = 0;
        map<int, bool> isVisited;
        vector<int> x(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i] == colulmns[j])
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
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        int n = arr1.size();
        vector<int> maxForEach(n);
        int m = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {

            if (arr1[i] < i)
            {
                return -1;
            }
            if (arr1[i] >= m)
            {
                m=arr1[i];
            }
            else if (arr1[i] < m)
            {

                m++;
                maxForEach[i] = m;
            }

            // if (m > arr1[i])
            // {
            //     m--;
            //     if (m < 0)
            //     {
            //         return -1;
            //     }
            //     maxForEach[i] = m;
            // }
            // else
            // {

            //     maxForEach[i] = arr1[i];
            //     m = arr1[i];
            // }
        }
        int j = 0;
        int n2 = arr2.size();
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] > maxForEach[i])
            {
                while (1)
                {
                    if (j >= n2)
                    {
                        return -1;
                    }
                    if (arr2[j] <= maxForEach[i])
                    {
                        arr1[i] = arr2[j];
                        ans++;
                        j++;
                        break;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    //     Solution s = Solution();
    //     vector<vector<int>> x={{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
    //    cout<<s.getNumberOfBacklogOrders(x);
    // cout<<s.minFlips(2,6,5);
    // cout << s.knightProbability(3, 2, 0, 0);
    return 0; // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
}
