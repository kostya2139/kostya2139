#include <iostream>
using namespace std;

class Iterator_circle
{
    int index;
    int length_circle;
public:
    Iterator_circle(int length_of_circle)
        :length_circle(length_of_circle),
         index(0)
    {

    }

    Iterator_circle& operator++()
    {
        if (++index>=length_circle)
            index=0;
        return *this;
    }

    Iterator_circle operator+(int n)
    {
        Iterator_circle result(length_circle);
        result.index=(index+n)%length_circle;
        return result;
    }

    int get_index()
    {
        return index;
    }
};

int length_alphabet_substring(const string &s, const Iterator_circle &first, Iterator_circle &end, int &circles)
{
    end=first;
    int length=1;
    while(s[end.get_index()]+1 == s[(end+1).get_index()])
    {
        ++length;
        ++end;
        if (end.get_index()==0) ++circles;
    }
    if (end.get_index()==s.size()-1) ++circles;
    return length;
}

int main()
{
    int length_circle;
    cin>>length_circle;
    string s;
    cin>>s;
    int circles=0;
    int etalon=0;
    Iterator_circle first(length_circle), end(length_circle);
    while(circles==0)
    {
        etalon=max(etalon, length_alphabet_substring(s, first, end, circles));
        first=end+1;
    }
    cout<<etalon;
    return 0;
}
