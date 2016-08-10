#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<string> a;
		vector<int> b;
		int i,j,n=0;	
		string s,temp;
		char space;
		scanf("%c",&space);
		getline(cin,s);
		int turns;
		cin>>turns;	
		
		int len=s.length();
		for(i=0;i<len;i++)
		{
			if(n==0)
			{
				temp.erase();
				while(s[i]!=' ')
				{
					temp.push_back(tolower(s[i]));
					i++;
				}
			a.push_back(temp);
			n=1;
			}
			else
			{
				int x1=0;
				while(i<len && s[i]!=' ' && s[i] != '\n')
				{
					int no=(int)s[i]-48;
					if(x1==0)
					x1=no;
					else
					x1=(x1*10)+no;
					i++;
				}
				b.push_back(x1);
				n=0;
			}
		}
		n=a.size();
		int m=b.size();
		int pos_min,temp1;
		int l=1;
		int g1=0,g2=0;
		while(l<=turns)
		{
			if(l%2==0)
			{
					i=g1;
	    			pos_min = i;		
					for (j=i+1; j < m; j++)
					{
						if (b[j] < b[pos_min])
            			pos_min=j;
					}
					if (pos_min != i)
					{
						temp1 = b[i];
            			b[i] = b[pos_min];
            			b[pos_min] = temp1;	
					}
					g1++;
            		
        			
			}
			else
			{
					i=g2;
	    			pos_min = i;		
					for (j=i+1; j < n; j++)
					{
						if((a[j]<a[pos_min]))
            			pos_min=j;
					}
					if (pos_min != i)
					{
        				temp = a[i];
            			a[i] = a[pos_min];
            			a[pos_min] = temp;
					}
					g2++;
			}
		l++;
		}
		
		for(i=0;i<n-1;i++)
		{
			cout<<a[i];
			printf(" %d ",b[i]);
		}
		cout<<a[n-1];
		printf(" %d\n",b[n-1]);
	}
return 0;
}
		

