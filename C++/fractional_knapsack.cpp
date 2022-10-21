#include<bits/stdc++.h>
using namespace std;

float p[100],w[100];
float x[100];

void knapsack(int m,int n)
{
    for(int i = 1; i<=n; i++)
    {
        int maX = i;
        for(int j =i+1; j<=n; j++)
        {
            if(p[j]/w[j] > p[maX]/w[maX])
            {
                maX = j;
            }
        }
        swap(p[maX],p[i]);
        swap(w[maX],w[i]);

    }

    int i,u = m;
    for(i=1; i<=n; i++)
    {
        if(w[i]>u)
            break;
        x[i] = 1;
        u = u-w[i];
    }
    if(i<=n)
    {
        x[i] = u/w[i];
    }

    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
            cout << "Weight of item " << w[i] << " and profit " << p[i] << " full selected" << endl;
        }
        else if(x[i]<=0)
        {
            cout << "Weight of item " << w[i] << " and profit " << p[i] << " is not selected" << endl;
        }
        else
        {
            cout << "Weight of item " << w[i] << " and profit " << p[i] << " selected " << x[i] << endl;
        }
    }
}


void profit_calculation(int n)
{
    float sum = 0;
    for(int i = 1; i<=n; i++)
    {
        cout << sum << " = " << sum << " + " << x[i] << " * " << p[i] << endl;
        sum += x[i]*p[i];
        cout<<"sum = " << sum << endl;
    }
    cout << "Your total profit is: ";
    cout<<sum;
}

int main()
{

    int noumberOFitems,bagSize;
    cout<<"The no. of items : ";
    cin>>noumberOFitems;// n is the number of items
    cout<<"The items Price and weight : "<<endl;
    for(int i = 1; i<=noumberOFitems; i++)
    {
        cin>>p[i]>>w[i];  // Enter Profit space Weight respectively

    }
    cout<<endl;

    cout<< "The carrying capacity of the bag : ";
    cin>>bagSize;

    knapsack(bagSize,noumberOFitems);

    /*cout<<"\nYou can take the items respectively portion of : "<<endl;
    for(int i = 1; i<=noumberOFitems; i++)
        cout<<x[i]<<" ";*/
    cout<<endl;
    //cout<<"your total profit is : ";
    profit_calculation(noumberOFitems);
    return 0;
}
/*
4
12 2
10 1
20 3
15 2
5
*/
