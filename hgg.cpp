#include<bits/stdc++.h>
using namespace std;

bool fun(string s, int n)
{

    if (!((s[0] >= 'a' && s[0] <= 'z')|| (s[0] >= 'A' && s[0] <= 'Z')||  (s[0] == '_'  )||(s[0]=='$')))
        return 0;

    for (int i = 1; i < s.length(); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s[i] <= '9') || (s[i] == '_')||(s[i]=='$')))
        return 0;
    }

    return true;
}

int main()
{
    string s = "_";
    int n = s.length();

    if (fun(s, n))
        cout << "Valid  identifire"<<endl;
    else
        cout << "Invalid identifire"<<endl;

    return 0;
}
