#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //function that takes an array and its size as arguments
    int removeDuplicates(int a[],int n){
        int index=0;
        for(int i=1;i<n;i++) {
        
            if(a[i]!=a[index]) { //change index
                index++; //swap next line
                a[index]=a[i]; 
            } 
          }
          return index+1;
    }
};

int main()
{
    int T;
    //taking the number of test cases from user
    cin>>T;
    //running the loop for all test cases
    while(T--)
    {
        int N;
        //taking size input from user
        cout<<"Input Size of Array : ";
        cin>>N;
        cout<<"Size of array you entered : "<<N<<endl;
        int a[N];
        //taking array input from user
        for(int i=0;i<N;i++)
        {   cout<<i<<"th Position : ";
            cin>>a[i];
        }
        Solution ob;
        //calling the removeDuplicates in the Solution class
        int n = ob.removeDuplicates(a,N);
        //printing the array after removing duplicates
        cout<<"Array with no duplicates : ";
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
            cout<<endl;
        }
}