//with the help of peak element we have to search in the bitonic array//
#include<bits/stdc++.h>
using namespace std;
int find_peak(vector<int> arr,int search,int n)
 {        
   if(arr[0]>arr[1])
     return 0;
   else if(arr[n-1]>arr[n-2])
      return n-1;
    else
    {
      int lb=0;
      int ub=n-1;
      while(lb<=ub)
      {
       int mid=lb+(ub-lb)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
           return mid;
        else if(arr[mid-1]<arr[mid])
             lb=mid+1;
         else 
             ub=mid-1;
      }
    }
 }
 int binary_search(vector<int> v,int lb,int ub,int search)
 {
     while(lb<=ub)
     {
       int mid=(lb+ub)/2;
       if(v[mid]==search)
          return mid;
        else if(search<v[mid])
            ub=mid-1;
        else 
            lb=mid+1;
     }
     return -1; 
 }
 int binary_search1(vector<int> v,int lb,int ub,int search)//this binary search applied on the element when the elements are in the decreasing
   {
     while (lb<=ub)
     {
        int mid=(lb+ub)/2;
        if(v[mid]==search)
         return mid;
         else if(search<v[mid])
             lb=mid+1;
         else
            ub=mid-1;
     }
     return -1;
   }
int main()
{
  vector<int> v;
  int val;int size;cin>>size;
  for (int i=0;i<size;i++)
  {
    cin>>val;
    v.push_back(val);
  }
  int search;
  cin>>search;
  int index_of_peak=find_peak(v,search,v.size());
  int lb=0;int ub=v.size()-1;
   int res1=binary_search(v,lb,index_of_peak-1,search);
   int res2=binary_search1(v,index_of_peak,ub,search);
       int ans=max(res1,res2);
       cout<<ans<<endl;
return 0;
}  