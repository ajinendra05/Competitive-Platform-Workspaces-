#include <bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
const int m = mod;

// Hardest

// Good + Hard
class SolutionNumeratorDenomenator
{
    string s;
    map<int, bool> checck;
    vector<int> frac;

public:
    void addfracValue(int numerator, int denominator)
    {

        if (checck[numerator] == false && numerator != 0)
        {
            checck[numerator] = true;
            int newVal = (numerator * 10);
            frac.push_back(newVal / denominator);
            // cout<<newVal / denominator;
            addfracValue(newVal % denominator, denominator);
        }
        else
        {
            bool flag = false;
            for (int i = 0; i < frac.size(); i++)
            {
                int newVal = (numerator * 10);
                if (frac[i] == (newVal / denominator) || flag)
                {
                    if (flag == false)
                    {
                        string temp = to_string(frac[i]);
                        s = s + '(';
                        s = s + temp;
                        flag = true;
                    }
                    else
                    {
                        string temp = to_string(frac[i]);
                        s = s + temp;
                    }
                    if (i == (frac.size() - 1))
                    {
                        s = s + ')';
                    }
                }
                else
                {
                    string temp = to_string(frac[i]);
                    s = s + temp;
                }
            }
            return;
        }
    }
    string fractionToDecimal(int numerator, int denominator)
    {

        int num = numerator / denominator;
        s = to_string(num);
        if (abs(numerator) < denominator)
        {
            if (numerator < 0 ^ denominator < 0)
            {
                s = '-' + s;
            }
        }
        if (numerator % denominator == 0)
            return s;
        if (numerator < 0)
            numerator = numerator * (-1);
        if (denominator < 0)
            denominator = denominator * (-1);
        int rem = numerator % denominator;
        s = s + '.';
        addfracValue(rem, denominator);
        return s;
    }
};

class UndergroundSystem
{
    map<int, string> userS;
    map<int, map<string, int>> userST;
    map<string, int> avrg;
    map<string, int> count;

public:
    UndergroundSystem()
    {
        return;
    }

    void checkIn(int id, string stationName, int t)
    {
        userS[id] = stationName;
        userST[id][stationName] = t;
        return;
    }

    void checkOut(int id, string stationName, int t)
    {
        avrg[userS[id] + " " + stationName] = avrg[userS[id] + " " + stationName] + (t - userST[id][userS[id]]);
        count[userS[id] + " " + stationName]++;
        return;
    }

    double getAverageTime(string startStation, string endStation)
    {
        int _avg = avrg[startStation + " " + endStation];
        int _count = count[startStation + " " + endStation];
        double result;
        result = double(double(_avg) / double(_count));
        cout << _avg << "  " << _count << "  " << result << endl;
        return result;
    }
};

class SolutionGridWithoutbacktrack
{
    int path = 1;
    vector<pair<int, int>> pathPoint{pair(0, 0)};

public:
    int checkNext(vector<vector<int>> &grid, int i, int j)
    {

        if (grid[i + 1][j + 1] == 0)
        {
            path++;
            pathPoint.push_back(pair(i + 1, j + 1));
            int x = checkNext(grid, i + 1, j + 1);
        }
        else if (grid[i][j + 1] == 0 && grid[i + 1][j] == 0)
        {

            path++;
            int x = checkNext(grid, i, j + 1);
            int y = checkNext(grid, i + 1, j);
            if (x <= y)
            {
                pathPoint.push_back(pair(i, j + 1));
                return checkNext(grid, i, j + 1);
            }
            pathPoint.push_back(pair(i + 1, j));
            return checkNext(grid, i + 1, j);
        }
        else if (grid[i + 1][j] == 0)
        {
            path++;
            pathPoint.push_back(pair(i + 1, j));
            return checkNext(grid, i + 1, j);
        }

        else if (grid[i][j + 1] == 0)
        {
            path++;
            pathPoint.push_back(pair(i, j + 1));
            return checkNext(grid, i, j + 1);
        }
        else if (grid[i - 1][j + 1] == 0 && grid[i + 1][j - 1] == 0)
        {
            int x = 0;
            int y = 0;

            if (pathPoint[pathPoint.size() - 1] != pair(i - 1, j + 1))
            {

                pathPoint.push_back(pair(i - 1, j + 1));
                x = checkNext(grid, i - 1, j + 1);
            }

            if (pathPoint[pathPoint.size() - 1] != pair(i + 1, j - 1))
            {

                pathPoint.push_back(pair(i + 1, j - 1));
                y = checkNext(grid, i + 1, j - 1);
            }

            path++;

            if (x <= y)
            {
                pathPoint.push_back(pair(i - 1, j + 1));
                return checkNext(grid, i - 1, j + 1);
            }
            pathPoint.push_back(pair(i + 1, j - 1));
            return checkNext(grid, i + 1, j - 1);
        }
        else if (grid[i + 1][j - 1] == 0)
        {
            if (pathPoint[pathPoint.size() - 1] != pair(i + 1, j - 1))
            {

                path++;
                pathPoint.push_back(pair(i + 1, j - 1));
                return checkNext(grid, i + 1, j - 1);
            }
        }

        else if (grid[i - 1][j + 1] == 0)
        {
            if (pathPoint[pathPoint.size() - 1] != pair(i - 1, j + 1))
            {
                path++;
                pathPoint.push_back(pair(i - 1, j + 1));
                int x = checkNext(grid, i - 1, j + 1);
            }
        }

        else if (grid[i - 1][j] == 0)
        {
            if (pathPoint[pathPoint.size() - 1] != pair(i - 1, j))
            {
                path++;
                pathPoint.push_back(pair(i - 1, j));
                return checkNext(grid, i - 1, j);
            }
            path--;
            pathPoint.pop_back();
            return checkNext(grid, i - 1, j);
        }
        else if (grid[i][j - 1] == 0)
        {
            if (pathPoint[pathPoint.size() - 1] != pair(i, j - 1))
            {
                path++;
                pathPoint.push_back(pair(i, j - 1));
                return checkNext(grid, i, j - 1);
            }
            path--;
            pathPoint.pop_back();
            return checkNext(grid, i, j - 1);
        }
        else if (grid[i - 1][j - 1] == 0)
        {
            if (pathPoint[pathPoint.size() - 1] != pair(i - 1, j - 1))
            {
                path++;
                pathPoint.push_back(pair(i - 1, j - 1));
                int x = checkNext(grid, i - 1, j - 1);
            }
            path--;
            pathPoint.pop_back();
            return checkNext(grid, i - 1, j - 1);
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
    }
};

// good +Medium
class SolutionSELLBUYBACKLOG
{

    vector<pair<int, int>> sell;
    vector<pair<int, int>> buy;

public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {

        for (auto x : orders)
        {   int u=0;
            if (x[2] == 0)
            {
                buy.push_back(make_pair(x[0], x[1]));
               
                if (min(sell.at(0).first, x[0]) >
                 buy.at(buy.size() - 1).first)
            {
                continue;
            }
            }
            else
            {

                sell.push_back(make_pair(x[0], x[1]));
                if (sell.at(0).first > 
                max(buy.at(buy.size() - 1).first, x[0]))
            {
                continue;
            }
            }
            if (sell.size() == 0 || buy.size() == 0)
            {
                continue;
            }
            // if (min(sell.at(0).first, sell.at(sell.size() - 1).first) > max(buy.at(buy.size() - 1).first, buy.at(buy.size() - 2).first))
            // {
            //     continue;
            // }
            sort(sell.begin(), sell.end());
            sort(buy.begin(), buy.end());
            int nbuy = 0;
            int nsell = 0;

            while (sell.at(0).first <= buy.at(buy.size() - 1).first)
            {
                nbuy = buy.at(buy.size() - 1).second;
                nsell = sell.at(0).second;
                if (nsell == nbuy)
                {
                    buy.pop_back();
                    sell.erase(sell.begin());
                }
                else if (nsell > nbuy)
                {
                    buy.pop_back();
                    sell.at(0).second -= nbuy;
                    // sell.erase(sell.begin());
                }
                else if (nsell < nbuy)
                {
                    buy.at(buy.size() - 1).second -= nsell;
                    sell.erase(sell.begin());
                }
                if (sell.size() == 0 || buy.size() == 0)
                {
                    break;
                }
            }
        }
        // sort(sell.begin(), sell.end());
        // sort(buy.begin(), buy.end());
        // int nbuy = 0;
        // int nsell = 0;

        // while (sell.at(0).first <= buy.at(buy.size() - 1).first)
        // {
        //     nbuy = buy.at(buy.size() - 1).second;
        //     nsell = sell.at(0).second;
        //     if (nsell == nbuy)
        //     {
        //         buy.pop_back();
        //         sell.erase(sell.begin());
        //         totalB -= nsell;
        //         totalS -= nsell;
        //     }
        //     else if (nsell > nbuy)
        //     {
        //         buy.pop_back();
        //         sell.at(0).second -= nbuy;
        //         // sell.erase(sell.begin());
        //         totalB -= nbuy;
        //         totalS -= nbuy;
        //     }
        //     else if (nsell < nbuy)
        //     {
        //         buy.at(buy.size() - 1).second -= nsell;
        //         sell.erase(sell.begin());
        //         totalB -= nsell;
        //         totalS -= nsell;
        //     }
        //     if(sell.size()==0||buy.size()==0){
        //         break;
        //     }
        // }
        int total = 0;
        for (auto x : buy)
        {
            total = ((total % m) + (x.second % m)) % m;
        }
        for (auto x : sell)
        {
            total = ((total % m) + (x.second % m)) % m;
        }
        return total;
    }
};
// Hard

// Meadium

//  Easy
class SolutionTelephoneMap
{
    string wordMap[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    map<string, string> wordmap2;
    vector<string> wordsList;
    string word;

public:
    SolutionTelephoneMap()
    {
        for (int i = 2; i <= 9; i++)
        {
            cout << to_string(i);
            wordmap2[to_string(i)] = wordMap[i - 2];
        }
    }
    void calWord(string str, string str2)
    {

        if (str2.empty())
        {
            if (!str.empty())
            {
                wordsList.push_back(str);
            }
            return;
        }
        string s = "";
        s.push_back(str2.at(0));

        for (int i = 0; i < wordmap2[s].size(); i++)
        {

            calWord(str + wordmap2[s].at(i), str2.substr(1));
        }
    }
    vector<string> letterCombinations(string digits)
    {
        calWord("", digits);
        return wordsList;
    }
};
class Solutionfreq
{
public:
    int LargButMinFreq(int arr[], int n)
    {

        unordered_map<int, int> freqMap;

        for (int i = 0; i < n; i++)
        {
            freqMap[arr[i]]++;
        }

        int minFreq = INT_MAX;
        int maxVal;
        vector<int> val;
        for (int i = 0; i < n; i++)
        {
            if (minFreq > freqMap[arr[i]])
            {
                val.clear();
                val.push_back(arr[i]);
                maxVal = arr[i];
                minFreq = freqMap[arr[i]];
            }
            else if (minFreq == freqMap[arr[i]])
            {
                val.push_back(arr[i]);
                if (maxVal < arr[i])
                    maxVal = arr[i];
            }
        }
        return maxVal;
    }
};
class SolutionNegativeNumberIngrid
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ans = 0;
        //    int minline=min(grid.size(),grid[0].size());
        //     for(int i=1;i<=minline;i++){
        //         if(grid[grid.size()-i][grid[0].size()-i]<0){
        //             ans=i*i;
        //             continue;
        //         }

        //     }
        int curC = 0;
        int curR = grid.size() - 1;
        while (!curC == grid[0].size())
        {

            if (grid[curR][curC] < 0)
            {
                ans = ans + grid[0].size() - curC;
                if (curR == 0)
                {
                    break;
                }
                curR--;
            }
            else
            {
                curC++;
            }
        }
        return ans;
    }
};
class node
{
public:
    int key;
    node *left;
    node *right;
    node(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
    void setleft(node *left)
    {
        this->left = left;
    }
    void setright(node *left)
    {
        this->right = left;
    }
};

class FrontMiddleBackQueue
{
    node *head;
    node *tail;
    node *mid;
    int size;

public:
    FrontMiddleBackQueue()
    {
        this->head = this->tail = this->mid = NULL;
        this->size = 0;
    }

    void pushFront(int val)
    {
        node *temp = new node(val);
        if (this->size <= 0)
        {
            head = tail = mid = temp;
            size++;
            return;
        }
        else
        {
            temp->setright(head);
            head->setleft(temp);
            head = temp;
            size++;
        }
    }

    void pushMiddle(int val)
    {
        node *temp = new node(val);
        if (this->size <= 1)
        {
            pushFront(val);
            return;
        }
        else
        {
            node *temp2 = head;
            for (int i = 0; i < size / 2; i++)
            {
                temp2 = temp2->left;
            }
            // temp->right=temp2;
            // temp->left=temp2->left;
            // temp2->left->right=temp;
            // temp2->left=temp;

            node *temp3 = temp2->left;
            temp->right = temp2;
            temp->left = temp3;

            temp3->right = temp;
            temp2->left = temp;

            size++;
        }
    }

    void pushBack(int val)
    {
        node *temp = new node(val);
        if (this->size <= 0)
        {
            pushFront(val);
            return;
        }
        else
        {
            temp->setleft(tail);
            tail->setright(temp);
            tail = temp;
            size++;
        }
    }

    int popFront()
    {

        if (this->size <= 0)
        {
            return -1;
        }
        else if (size == 1)
        {
            node *temp = head;
            head = tail = mid = NULL;
            size--;
            return temp->key;
        }
        else
        {
            node *temp = head;

            head = head->right;
            head->left = NULL;

            size--;
            return temp->key;
        }
        return -1;
    }

    int popMiddle()
    {
        if (this->size <= 0)
        {
            return -1;
        }
        else if (size <= 2)
        {
            return popFront();
        }
        else
        {
            int toDivide = size / 2;
            if (size % 2 == 0)
            {
                toDivide = (size - 1) / 2;
            }
            node *temp = head;
            for (int i = 0; i < toDivide; i++)
            {
                temp = temp->left;
            }
            temp->right->left = temp->left;
            temp->left->right = temp->right;

            size--;
            return temp->key;
        }
    }

    int popBack()
    {
        if (this->size <= 0)
        {
            return -1;
        }
        else if (size == 1)
        {
            return popFront();
        }
        else
        {
            node *temp = tail;

            tail = tail->left;
            tail->right = NULL;

            size--;
            return temp->key;
        }
    }
};
class SolutioncountOfFlipbitwiseOr
{
    int count;

public:
    void contOperation(int x, int y, int z)
    {

        if ((x | y) == z)
        {
            cout << " go out" << endl;
            return;
        }

        cout << count << " ";
        bool temp = x == 1;
        cout << x << y << z;
        cout << "hui";
        switch (z)
        {
        case 1:
            this->count++;
            break;
        case 0:
            cout << "this";
            if (x == y)
            {
                this->count += 2;
                cout << "h";
            }
            else
            {
                this->count++;
            }

            break;
        }
    }
    void checckM(int a, int b, int c)
    {
        if (a <= 0 && b <= 0 && c <= 0)
        {
            return;
        }
        // int x=a&1;
        contOperation(a & 1, b & 1, c & 1);
        // contOperation(1,1,0);
        // cout<<x<<endl;
        cout << (a & 1) << " " << (b & 1) << " " << (c & 1) << " " << count << endl;
        // contOperation(a&1,b&1,c&1);
        a = a >> 1;
        b = b >> 1;
        c = c >> 1;

        checckM(a, b, c);
    }
    int minFlips(int a, int b, int c)
    {
        checckM(a, b, c);
        int temp = count;
        count = 0;
        return temp;
    }
};

class Solution1502
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int x = arr[1] - arr[0];
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if ((arr[i + 1] - arr[i]) != x)
            {
                return false;
            }
        }
        return true;
    }
};