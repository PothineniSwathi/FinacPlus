#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    string a,s;
    cin>>a;
    transform(a.begin(),a.end(),a.begin(),::toupper);
    int n;
    cin>>n;
    char c=a[0];
    int i=1,k=1;
    while(i<a.size())
    {
        while(c==a[i] && i<a.size())
        {
            k++;
            i++;
        }
        if(c!=a[i])
        {
            s=(k>1)?s+c+to_string(k):s+c ;
            c=a[i];
            i++;
            k=1;
        }
    }
    s=(k>1)?s+c+to_string(k):s+c;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        s[i] ='A'+(s[i]-'A'+n)%26;
    }
    cout<<s;
}