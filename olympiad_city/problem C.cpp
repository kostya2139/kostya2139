#include <bits/stdc++.h>
using namespace std;

struct Figure
{
    int n, m;
    int mas[3][250];
};

ostream& operator<<(ostream &out, Figure figure)
{
    out<<figure.n<<' '<<figure.m<<'\n';
    for(int i=0; i<figure.n; i++)
        {
            for(int j=0; j<figure.m; j++)
                switch(figure.mas[i][j])
                {
                case 1:
                    cout<<'W';
                    break;
                case 0:
                    cout<<'.';
                    break;
                case -1:
                    cout<<'B';
                    break;
                default:
                    cerr<<"incorrect object struct Figure";
                }
            out<<'\n';
        }
    return out;
}

int main()
{
    int w, b;
    cin>>w>>b;
    Figure figure;
    if(w==b)
    {
        figure.n=1;
        figure.m=2*w;
        for(int i=0; i<w; ++i)
        {
            figure.mas[0][2*i]=1;
            figure.mas[0][2*i+1]=-1;
        }
    }
    if(w>b)
    {
        if(w>3*b+1)
        {
            cout<<-1;
            return 0;
        }
        figure.n=3;
        figure.m=2*b+1;
        for(int i=0; i<b; ++i)
        {
            figure.mas[1][2*i]=1;
            figure.mas[1][2*i+1]=-1;
        }
        figure.mas[1][2*b]=1;
        w-=b+1;
        for(int j=0; j<=2; j+=2)
        {
            for(int i=1; i<2*b; i+=2)
            {
                figure.mas[j][i-1]=0;
                if(w!=0)
                {
                    figure.mas[j][i]=1;
                    --w;
                }
                else figure.mas[j][i]=0;
            }
            figure.mas[j][2*b]=0;
        }
    }
    else if(w<b)
    {
        if(b>3*w+1)
        {
            cout<<-1;
            return 0;
        }
        figure.n=3;
        figure.m=2*w+1;
        for(int i=0; i<w; ++i)
        {
            figure.mas[1][2*i]=-1;
            figure.mas[1][2*i+1]=1;
        }
        figure.mas[1][2*w]=-1;
        b-=w+1;
        for(int j=0; j<=2; j+=2)
        {
            for(int i=1; i<2*w; i+=2)
            {
                figure.mas[j][i-1]=0;
                if(b!=0)
                {
                    figure.mas[j][i]=-1;
                    --b;
                }
                else figure.mas[j][i]=0;
            }
            figure.mas[j][2*w]=0;
        }
    }
    cout<<figure;
    return 0;
}
