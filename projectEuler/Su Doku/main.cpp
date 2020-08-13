//मनुष्य होना मेरा भाग्य लेकिन
//हिन्दू होना मेरा सौभाग्य है..!!
//"रामसेतू" और अयोध्या में "मन्दिर" उस समय से है..!!
//जब इस धरती पर न जीजस थे,
//और न ही इस्लाम का कोई अस्तित्व था..!!
//जय श्री राम
//everything could depending on what you do today
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define em emplace_back
#define mp make_pair
using namespace std;
class solution
{
    int n;
    vector<vector<int>>input;
    public:
    solution ()
    {
        input.resize(9,vector<int>(9,0));
    }
    bool checkEven(long long num)
    {
        if(!(num&1))
        return false;
        else
        return true;
    }
    inline int mod(int a, int b)
    {
        int ret = a%b; 
        return ret>=0? ret: ret+b; 
    }
    template<typename T>
    int getLength(T &input)
    {
        return input.size();
    }
    template<typename T,typename Q>
    void swap(T &a,Q &b)
    {
        a=a^b;
        b=a^b;
        a=a^b;
    }
    template<typename T>
    void display(vector<T>input)
    {
        for(auto i:input)
        cout<<i<<" ";
        cout<<endl;
    }
    template<typename T>
    void display2D(vector<vector<T>>input)
    {
        for(auto i:input)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    template<typename T>
    void displayPair(vector<pair<T,T>>input)
    {
        for(auto i:input)
        cout<<i.first<<" "<<i.second<<endl;
    }
    void takeInput()
    {
        for(int i=0;i<9;i+=1)
        {
            string str;
            cin>>str;
            for(int j=0;j<str.size();j+=1)
            input[i][j]=str[j]-'0';
        }
        //display2D(input);
    }
    void solve()
    {
        findAns(0,0);
    }
    bool issafe(int row,int col,int num)
    {
        for(int i=0;i<9;i+=1)
        {
            if(input[row][i]==num)
            return false;
        }
        for(int i=0;i<9;i+=1)
        {
            if(input[i][col]==num)
            return false;
        }
        int r=3*(row/3);
        int c=3*(col/3);
        for(int i=r;i<r+3;i+=1)
        {
            for(int j=c;j<c+3;j+=1)
            {
                if(input[i][j]==num)
                return false;
            }
        }
        return true;
    }
    bool findAns(int row,int col)
    {
        if(row>=9)
        {
            display2D(input);
            return true;
        }
        if(col>=9)
        {
            col=0;
            row+=1;
        }
        if(row>=9)
        {
            display2D(input);
            return true;
        }
        if(input[row][col]==0)
        {
            for(int i=1;i<=9;i+=1)
            {
                if(issafe(row,col,i))
                {
                    input[row][col]=i;
                    if(findAns(row,col+1))
                    return true;
                    input[row][col]=0;
                }
            }
        }
        else
        {
            if(findAns(row,col+1))
            return true;
        }
        return false;
    }
    string getAns()
    {
        string str;
        str+=to_string(input[0][0]);
        str+=to_string(input[0][1]);
        str+=to_string(input[0][2]);
        return str;
    }
};
int main()
{
    
    string str;
    long long sum=0;
    while(cin>>str && !cin.eof())
    {
        solution sc;
        cin>>str;
        sc.takeInput();
        sc.solve();
        string ans=sc.getAns();
        sum+=stoi(ans);
    }
    cout<<sum<<endl;
    return 0;
}