#include<bits/stdc++.h>
using namespace std;
   char find_nextalfabetical(char arr[],int n,char k)
      { 
        int lb=0;int ub=n-1;
        char res='#';
        while(lb<=ub)
        {
        	int mid=(lb+ub)/2;
         if(arr[mid]==k)
         	lb=mid+1;
         else if(k<arr[mid])
         	 {res=arr[mid];
         	 ub=mid-1;}
         	else
         	 lb=mid+1;
        }
        if(res=='#')
          return '#';
         else
         	return res;
      }
int main()
{
  int size;
  cin>>size;
  char arr[size];
  for(int i=0;i<size;i++)
     {
        char input;
        cin>>input;
        arr[i]=input;
     }
     char k;
     cout<<"enter the character";
     cin>>k;
  char ans=find_nextalfabetical(arr,size,k)<<endl;
  cout<<ans;
  return 0;
}