#include <bits/stdc++.h>
using namespace std;

int cnt_digs_in_numeral_system(long long num, int base=10)
{
    if(num==0) return 1;
    int cnt=0;
    while(num)
    {
        num/=base;
        ++cnt;
    }
    return cnt;
}

int main()
{
    long long k;
    cin>>k;
    cout<<cnt_digs_in_numeral_system(k, 2)-1;
    return 0;
}
