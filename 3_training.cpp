// who attended training program in random order. Write function for a) Searching whether particular student attended training program or not using Binary search .
#include <iostream>
using namespace std;
int roll_no[50],n,i,key,flag;
void linear_search()
{
    flag=0;
    cout<<"enter roll no. to verify attendance ";
    cin>>key;
    for(i=0;i<n;i++)
    {
        if(roll_no[i]==key)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<key <<" attended the training\n";
    }
    else 
    {
        cout<<key <<" was absent\n";
    }
}
void selection()
{
    int temp,j,i;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(roll_no[i]>roll_no[j])
            {
                temp=roll_no[i];
                roll_no[i]=roll_no[j];
                roll_no[j]=temp;
            }
        }
    }
    
}
void binary_search()
{
    int low = 0, high = 4, mid = 0, key, flag = 0;
    cout << "enter roll no. to verify attendance ";
    cin >> key;
    selection();
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (roll_no[mid] == key)
        {
            flag = 1;
            break;
        }
        else if (roll_no[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (flag == 1)
    {
        cout << key << " attended the training " <<  endl;
    }
    else
    {
        cout << key << " was absent" << endl;
    }
}

int main()
{
    int ch,c;
    cout<<"enter the no of students who attended training \n";
    cin>>n;
    cout<<"\nenter thier roll numbers ";
    for(i=0;i<n;i++)
    {
        cin>>roll_no[i];
    }
    do
    {
         cout<<"\n1.LINEAR SEARCH\n2.BINARY SEARCH\n3.EXIT\n";
         cout<<"Enter the operation choice ";
         cin>>ch;
         switch(ch)
         {
            case 1:linear_search();
                   break;
            case 2:binary_search();
                   break;
            case 3:cout<<"exiting...";
                   break;
            default:cout<<"invalid choice\n";              
         }
         cout<<"[press 1 to continue]\n";
         cin>>c;
    }
    while(c==1);
    return 0;
    
}
