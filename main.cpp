#include <bits/stdc++.h>
using namespace std;
struct Tries
{
    unordered_map<char,Tries*>mp;
    bool is_end;
    string meaning;
};
Tries *root;
void insert(string a,string meaning)
{
    Tries*current=root;
    for(auto ch:a)
    {
        if(!current->mp.count(ch))
        {
            current->mp[ch]=new Tries;
        }
        current=current->mp[ch];
    }
    current->is_end=true;
    current->meaning=meaning;
}
string search(string a)
{
    Tries*current=root;
    for(auto ch:a)
    {
        if(!current->mp.count(ch))
        {
            return "";
        }
        current=current->mp[ch];
    }
    if(current->is_end==true)
    {
        return current->meaning;
    };
    return "";
}
int main() 
{
    int n;
    cout<<"How many numbers you want to enter in the Dictionary:";
    cin>>n;
    root=new Tries;
    for(int i=0;i<n;i++)
    {
        string a;
        cout<<"Enter the word:";
        cin>>a;
        string meaning;
        cout<<"Enter the meaning:";
        cin>>meaning;
        insert(a,meaning);
        cout<<endl;
    }
    cout<<"How many numbers you want to search in the Dictionary:";
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cout<<"Enter the word to search:";
        string a;
        cin>>a;
        string c=search(a);
        if(c!="")
        {
            cout<<c;
        }
        else
        {
            cout<<a<<" Don't exist in the Dictionary ";
        }
        cout<<endl;
    }
}
