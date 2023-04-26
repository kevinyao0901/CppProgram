#include<bits/stdc++.h>
using namespace std;

vector<int> display_arr(vector<int> v)
{
    vector<int> r;
    int i = 0;
    while (i < v.size())
    {
        int cnt = 1;
        while (i!=v.size()-1 && v[i] == v[i + 1])
        {
            i++;
            cnt++;
        }
        r.push_back(cnt);
        r.push_back(v[i]);
        i++;
    }
    return r;
}

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}


int main()
{
    int n = 0;
    cin >> n;
    vector<int> v;
    v.push_back(1);
    n--;
    while (n > 0)
    {
        v = display_arr(v);
        n--;
    }
    print(v);
}