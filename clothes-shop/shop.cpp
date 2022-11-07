#include<bits/stdc++.h>
using namespace std;
class Shop
{
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];
protected:
    int total_income;
public:
    int get_total()
    {
        return total_income;
    }
    void set_total(int total_income)
    {
        this->total_income+=total_income;
    }

};
int main()
{
    cout<<"Number of products: ";
    int n;
    cin>>n;
    Shop sp;
    ///cout<<"Number of products: "<<n;
    for(int i=1; i<=n; i++)
    {
        ///string product_name;
        ///int product_price,product_quantity;
        ///cin>>product_name>>product_price>>product_quantity;
        cout<<"Product "<<i<<" Name: ";
        cin>>sp.product_name[i];
        cout<<"Product "<<i<<" Price: ";
        cin>>sp.product_price[i];
        cout<<"Product "<<i<<" Quantity: ";
        cin>>sp.product_quantity[i];
        ///cout<<"Product "<<i+1<<"Name: "<<sp.product_name[i]<<endl;
        ///cout<<"Product "<<i+1<<"Price: "<<sp.product_price[i]<<endl;
        ///cout<<"Product "<<i+1<<"Quantity: "<<sp.product_quantity[i]<<endl;
    }
    while(true)
    {
        cout<<endl;
        cout<<"\t\t BUY PRODUCT\t\t"<<endl;
        cout<<"\t\t______________\t\t"<<endl;
        cout<<"Product Index\t\t";
        for(int i=1; i<=n; i++)
        {
            cout<<i<<"\t";
        }
        cout<<endl;
        cout<<"Product Name\t\t";
        for(int i=1; i<=n; i++)
        {
            cout<<sp.product_name[i]<<"\t";
        }
        cout<<endl;
        cout<<"Product Price\t\t";
        for(int i=1; i<=3; i++)
        {
            cout<<sp.product_price[i]<<"\t";
        }
        cout<<endl;
        cout<<"Product Quantity\t";
        for(int i=1; i<=3; i++)
        {
            cout<<sp.product_quantity[i]<<"\t";
        }
        cout<<endl<<endl;
        cout<<"Which product do you want? From 1 to "<<n<<": ";
        int index,quantity;
        cin>>index;
        cout<<"What is the quantity that you want of "<<sp.product_name[index]<<" : ";
        cin>>quantity;
        if(sp.product_quantity[index] < quantity)
        {
            cout<<"This quantity is not available"<<endl;
        }
        else
        {
            sp.set_total(quantity*sp.product_price[index]);
            sp.product_quantity[index]-=quantity;
            cout<<endl;
            cout<<sp.product_name[index]<<" bought "<<quantity<<" pc successfully"<<endl;
            cout<<"Your total income : "<<sp.get_total()<<endl;
        }
    }
    return 0;
}


