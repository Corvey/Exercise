﻿#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

map<string, int> cnt;
vector<string> words;

string BiaoZhunHua(const string& buff)
{
    string ans = buff;
    for(int i=0; i<ans.length(); ++i)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(void)
{
    string s;
    while(cin >> s)
    {
        if(s[0] == '#')
            break;
        words.push_back(s);
        string temp = BiaoZhunHua(s);
        if(!cnt.count(temp))
            cnt[temp] = 0;
        ++cnt[temp];
    }
    vector<string> ans;
    for(int i=0; i<words.size(); ++i)
    {
        if(cnt[BiaoZhunHua(words[i])] == 1)
            ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); ++i)
        cout << ans[i] << "\n";
}
