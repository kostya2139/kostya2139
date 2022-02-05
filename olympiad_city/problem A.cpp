#include <iostream>

using namespace std;

int main()
{
    int n, m, w ,t;
    cin>>n>>m>>w>>t;
    int times_of_permission=1+t/w;
    int n_students_who_are_in=min(n, m*times_of_permission);
    cout<<n_students_who_are_in;
    return 0;
}
