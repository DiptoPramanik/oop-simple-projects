#include<bits/stdc++.h>
using namespace std;
class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    int total_tax;
public:
    Restaurant()
    {
        this->total_tax=0;
    }
    void set_tax(double tax)
    {
        total_tax+=tax;
    }
};
int main()
{
    int n;
    cin>>n;
    Restaurant rt;
    ///taking inputs
    for(int i=0; i<n; i++)
    {
        cin>>rt.food_item_codes[i];
        ///cin>>rt.food_item_names[i];
        cin.ignore();
        getline(cin,rt.food_item_names[i]);
        cin>>rt.food_item_prices[i];
    }
    cout<<endl;
    cout<<endl;
    ///food menu displaying
    while(true)
    {
        cout<<"\t\t\t   MAKE BILL "<<endl;
        cout<<"\t\t________________________________"<<endl;
        cout<<endl;
        cout<<"Item code \t Item Name \t\t\tItem Price"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<rt.food_item_codes[i]<<"\t\t";
            cout<<rt.food_item_names[i]<<"\t\t";
            cout<<rt.food_item_prices[i]<<"\t\t";
            cout<<endl;
        }
        int table_num,sum;
        cout<<endl;
        cout<<"Enter Table number : ";
        cin>>table_num;
        int code[12];
        int Quantity[12];
        int items;
        cout<<"Enter the Number of Items : ";
        cin>>items;
        for(int i=0; i<items; i++)
        {
            int f=0;
            Flag:
            cout<<"Enter Item "<<i+1<<" Code : ";
            cin>>code[i];
            for(int k=0; k<n; k++)
            {
                if(code[i]==rt.food_item_codes[k])
                {
                    f++;
                }
            }
            if(f==0)
            {
                cout<<"Code is not valid,you needs to enter the code again."<<endl;///checking validity of the food code
                goto Flag;
            }
            cout<<"Enter Item "<<i+1<<" Quantity : ";
            cin>>Quantity[i];
        }
        cout<<endl;
        cout<<endl;
        ///displaying the bill paper(online copy)
        cout<<"\t\t\t\t\t BILL SUMMARY"<<endl;
        cout<<"\t\t_________________________________________________________"<<endl;
        cout<<endl;
        cout<<"Table No : "<<table_num<<endl;
        cout<<"Item Code\t Item Name\t Item Price \t Item Quantity \tTotal Price"<<endl;
        for(int i=0; i<items; i++)
        {
            for(int k=0; k<n; k++)
            {
                if(code[i]==rt.food_item_codes[k])
                {
                    cout<<rt.food_item_codes[k]<<"\t\t"<<rt.food_item_names[k]<<"\t"<<rt.food_item_prices[k]<<"\t\t"<<Quantity[i]<<"\t\t"<<rt.food_item_prices[k]*Quantity[i]<<endl;
                    sum+=rt.food_item_prices[k]*Quantity[i];
                }
            }
        }
        cin.ignore();
        double tax=double(5*sum)/100;///calculating tax
        rt.set_tax(tax);
        cout<<"TAX\t\t\t\t\t\t\t\t\t";
        cout<<fixed<<setprecision(2)<<tax<<endl;
        cout<<"_____________________________________________________________________________________________"<<endl;
        cout<<"NET TOTAL\t\t\t\t\t\t\t\t"<<sum+tax<<" Taka"<<endl;///total ammount  you have to pay.
        cout<<endl;
    }
    return 0;
}


