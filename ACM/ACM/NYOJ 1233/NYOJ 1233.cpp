#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e3+10;
string str[N], sMax, sMin;
bool cmp(const string a, const string b){
    return (a+b) < (b+a);
}
void Subtract(void)
{
    int len = sMax.length();
    for(int i=len-1; i; --i)
    {
        if(sMax[i] >= sMin[i])
            sMax[i] -= sMin[i] - '0';
        else
            sMax[i] -= sMin[i] - 10 - '0', --sMax[i-1];
    }
    sMax[0] -= sMin[0] - '0';
    int i;
    for(i=0; i<len && sMax[i] == '0'; ++i);
    if(i == len)
        cout << 0 << endl;
    else
    {
        for(; i<len; ++i)
            cout << sMax[i];
        cout << endl;
    }
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    int kase, n;
    cin >> kase;
    while(kase--)
    {
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> str[i];
        sort(str, str+n, cmp);
        sMax = sMin = "";
        for(int i=0; i<n; ++i)
            sMin += str[i];
        for(int i=n-1; i>=0; --i)
            sMax += str[i];
        Subtract();
    }
}
        