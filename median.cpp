#include <bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int r,int k);
int findMedian(int arr[],int n)
{
	sort(arr,arr+n);
	return arr[n/2];
}
int kthSmallest(int arr[],int l,int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int i;
		int n=r-l+1;
		int median[(n+4)/5];
		for(i=0;i<n/5;i++)
			median[i]=findMedian(arr+l+i*5,5);
		if(i*5<n)
		{
			median[i]=findMedian(arr+l+i*5,n%5);
			i++;
		}
		int mom=(i==1)?median[i-1]:kthSmallest(median,0,i-1,i/2);
		int pos=partition(arr,l,r,mom);
		if(pos-l==k-1)
			return arr[pos];
		if(pos-l>k-1)
			return kthSmallest(arr,l,pos-1,k);
		return kthSmallest(arr,pos+1,r,k-pos+l-1);
	}
	return INT_MAX;
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int l,int r,int x)
{
	int i;
	for(i=0;i<r;i++)
	{
		if(arr[i]==x)
			break;
	}
	swap(&arr[i],&arr[r]);
	i=l;
	for(int j=l;j<=r-1;j++)
	{
		if(arr[j]<=x)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	swap(&arr[i],&arr[r]);
	return i;
}
int main() 
{  
	int n;
	cin >> n;
	int t=n;
	int a[n];
	int l=0;
	while(t--)
	{
		cin >> a[l++];
		if(l==1)
		{
			float p=a[0];
			cout << fixed << setprecision(1) << p<< endl;
		}
		else
		{
			if(l%2!=0)
			{
				float mom=kthSmallest(a,0,l-1,l/2+1);
				cout << fixed << setprecision(1) << mom << endl;
			}
			else
			{
				double mom1=kthSmallest(a,0,l-1,l/2);
				double mom2=kthSmallest(a,0,l-1,l/2+1);
				double ans=(mom1+mom2)/2;
				cout << ans << endl;
			}
		}
	}

return 0; 
}
