#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d ",&t);
	queue<int> q;
	while(t--)
	{
		
		int n;
		cin >> n;
		if(n==1)
		{
			int n2;
			cin >> n2;
			q.push(n2);
		}
		else if(n==2)
		{
			if(!q.empty())
				q.pop();
			else
				cout << "Dequeue not possible as the queue is empty" << endl;
		}
		else if(n==3)
		{
			if(!q.empty())
				cout << q.front() << endl;
			else
				cout << "Cannot print the first element as the queue is empty" << endl;
		}

	}
	
}
