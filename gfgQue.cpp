
#include <bits/stdc++.h>

using namespace std;

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

class Solution_bomb
{
    vector<pair<int, int>> inrange;
    map<int, vector<int>> connected;
    map<int, bool> isVisited;
    int count = 0;

public:
    void checkLength(int ind)
    {

        for (int i = 0; i < connected[ind].size(); i++)
        {
            if (isVisited[connected[ind][i]] == false)
            {
                count++;
                isVisited[connected[ind][i]] = true;

                checkLength(connected[ind][i]);
            }
        }
    }
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int max = INT_MIN;
        for (int i = 0; i < bombs.size(); i++)
        {
            for (int j = i + 1; j < bombs.size(); j++)
            {
                double x = sqrt(pow(double(bombs[i][0] - bombs[j][0]), 2) + pow(double(bombs[i][1] - bombs[j][1]), 2));
                if (x <= bombs[i][2])
                {
                    // inrange[i]++;
                    connected[i].push_back(j);
                }
                if (x <= bombs[j][2])
                {
                    // inrange[j]++;
                    connected[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < bombs.size(); i++)
        {
            if (isVisited[i] == false)
            {
                isVisited.clear();
                isVisited[i] = true;
                count = 0;
                checkLength(i);

                max = max > count ? max : count;
            }
        }

        // for(int i=0;i<inrange.size();i++){
        //     max=max>=(inrange[i]+1)?max:(inrange[i]+1);
        // }
        return (max + 1);
    }
};

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
class Solutionfirstlastmid
{
public:
    void findPre(Node *curr, Node *&pre, int key)
    {
        if (curr == NULL)
        {
            return;
        }
        if (curr->key >= key)
        {
            findPre(curr->left, pre, key);
        }
        else if (curr->key < key)
        {
            pre = curr;
            findPre(curr->right, pre, key);
        }
        return;
    }
    void findsuc(Node *curr, Node *&suc, int key)
    {
        if (curr == NULL)
        {
            return;
        }
        if (curr->key <= key)
        {
            findsuc(curr->right, suc, key);
        }
        else if (curr->key >= key)
        {
            suc = curr;
            findsuc(curr->left, suc, key);
        }
        return;
    }
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        pre = NULL;
        suc = NULL;
        findPre(root, pre, key);
        findsuc(root, suc, key);
    }
};

void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] < 0)
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        else if (rightArray[indexOfSubArrayTwo] < 0)
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        else
        {
            break;
        }
    }

    // while (indexOfSubArrayOne < subArrayOne)
    // {
    //     if (leftArray[indexOfSubArrayOne] <0)
    //     {
    //         array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    //         indexOfSubArrayOne++;
    //         indexOfMergedArray++;
    //     }
    // }

    // while (indexOfSubArrayTwo < subArrayTwo)
    // {
    //      if (rightArray[indexOfSubArrayTwo] <0)
    //     {
    //         array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    //         indexOfSubArrayTwo++;
    //         indexOfMergedArray++;
    //     }
    // }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void Rearrange(int arr[], int n)
{
    // Your code goes here
}
class Solution
{
    vector<int> res;
    int size = 0;

public:
    void buildList(int s, int e, int val)
    {
        if (val > res[0])
        {
            res.insert(res.begin(), val);
            res.pop_back();
            return;
        }

        int mid = s + (e - s) / 2;
        if (e < s)
        {
            if (val > res[size - 1])
            {
                res.pop_back();
                res.push_back(val);
            }
        }
        if (res[mid] <= val && res[mid - 1] >= val)
        {
            res.insert(res.begin() + mid, val);
            res.pop_back();
            return;
        }
        if (res[mid] < val)
        {
            buildList(s, mid - 1, val);
            return;
        }
        else
        {
            buildList(mid, e, val);
            return;
        }
    }
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        // int sizek = 1;
        // res.push_back(arr[0]);
        // for (int i = 1; i < n; i++)
        // {
        //     if (sizek == k)
        //     {
        //         if (res[sizek - 1] < arr[i])
        //         {
        //             res.pop_back();
        //             if (res[0] > arr[i])
        //                 res.insert(res.begin(), arr[i]);
        //             else
        //                 res.push_back(arr[i]);
        //         }
        //     }
        //     else
        //     {
        //         if (res[sizek - 1] < arr[i])
        //         {

        //             if (res[0] > arr[i])
        //                 res.insert(res.begin(), arr[i]);
        //             else
        //                 res.push_back(arr[i]);

        //             size++;
        //         }
        //     }
        // }

        if (size == 0)
        {
            res.push_back(arr[0]);
            size++;
        }
        if (size == 1)
        {
            if (arr[1] > res[0])
            {
                res.insert(res.begin(), arr[1]);
            }
            else
                (res.push_back(arr[1]));

            size++;
        }
        for (int i = 2; i < n; i++)
        {
            if (size == k)
            {
                if (res[size - 1] > arr[i])
                {
                    continue;
                }
                buildList(0, size - 1, arr[i]);
            }
            else
            {
                buildList(0, size - 1, arr[i]);
                size++;
            }
        }
    }
};

class Solution
{
    vector<int> ans;
    int size;

public:
    void buildList(int s, int e, int val)
    {

        int mid = s + (e - s) / 2;
        if (e < s)
        {
            if (val > ans[size - 1])
            {
                ans.pop_back();
                ans.push_back(val);
            }
            return;
        }

        if (ans[mid] == val)
        {
            ans.insert(ans.begin() + mid + 1, val);
            ans.pop_back();
        }
        if (ans[mid] < val)
        {
            if (ans[mid - 1] >= val)
            {
                ans.insert(ans.begin() + mid, val);
                ans.pop_back();
                return;
            }
            else
            {
                buildList(s, mid - 1, val);
                return;
            }
        }
        else
        {
            if (ans[mid + 1] <= val)
            {
                ans.insert(ans.begin() + mid + 2, val);
                ans.pop_back();
                return;
            }
            else
            {
                buildList(s, mid + 1, val);
                return;
            }
        }
    }
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[i]);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        size = k;
        for (int i = k; i < n; i++)
        {
            if (ans[k - 1] > arr[i])
            {
                continue;
            }
            if (ans[0] <= arr[i])
            {
                ans.pop_back();
                ans.insert(ans.begin(), arr[i]);
                continue;
            }
            buildList(0, k - 1, arr[i]);
        }
    }
};

class Solution
{
public:
    long long minTime(int n, vector<int> &locations, vector<int> &types)
    {
        // code here
        vector<pair<int, int>> x;
       
    

    }
};

int main()
{
    // Solution s;
    // cout<<s.kthPermutation(4,3);
    // vector<vector<int>> x = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    // cout << s.maximumDetonation(x);
}
