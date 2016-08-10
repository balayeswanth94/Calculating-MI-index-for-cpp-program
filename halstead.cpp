#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;
string s;
set<string> opr;
vector<char> ope;
int count_occurence(string t)
{
	int occ=0;
	size_t nPos = s.find(t, 0);
    while(nPos != string::npos)
    {
    	if(s[nPos+1]>='0' && s[nPos+1]<='9')
    	ope.push_back(s[nPos+1]);
        occ++;
        nPos = s.find(t, nPos+1);
    }
	return occ;	
}
int main()
{
	int ink=0;
	int n1=0,n2=0,N1=0,N2=0,N,n;
	freopen("b.cpp","r",stdin);
	getline(cin,s);
	while(s[s.length()-1]!='{')
		getline(cin,s);
	getline(cin,s);
	while((s!="return 0;")&&(ink<100))
	{
	if(s[0]=='i' && s[1]=='n' && s[2]=='t')
	{
	int temp=count_occurence(",");
	n2+=temp+1;
	}
	else if(s[0]=='f' && s[1]=='l' && s[2]=='o' && s[3]=='a' && s[4]=='t')
	{
	int temp=count_occurence(",");
	n2+=temp+1;
	}
	else if(s[0]=='b' && s[1]=='o' && s[2]=='o' && s[3]=='l')
	{
	int temp=count_occurence(",");
	n2+=temp+1;
	}
	else if(s[0]=='s' && s[1]=='t' && s[2]=='r' && s[3]=='i' && s[4]=='n' && s[5]=='g')
	{
	int temp=count_occurence(",");
	n2+=temp+1;
	}
	if(s.find("if") != std::string::npos)
	{
	N1++;
	opr.insert("if");
	}
	if(s.find("else if") != std::string::npos)
	{
	N1++;
	opr.insert("else if");
	}
	if(s.find("else") != std::string::npos)
	{
	N1++;
	opr.insert("else");
	}
	if(s.find("\"") != std::string::npos)
	{
	N1+=count_occurence("\"");
	opr.insert("\"");
	}
	if(s.find("(") != std::string::npos)
	{
	N1+=count_occurence("(");
	opr.insert("(");
	}
	if(s.find(")") != std::string::npos)
	{
	N1+=count_occurence(")");
	opr.insert(")");
	}
	if(s.find(">") != std::string::npos && (s[s.find(">")+1]!='=' && s[s.find(">")+1]!='>'))
	{
	int temp=count_occurence(">");
	N1+=temp;
	//cout<<temp<<"dd"<<N2<<endl;
	N2+=temp+1;
	opr.insert(">");
	}
	if(s.find(">=") != std::string::npos)
	{
	int temp=count_occurence(">=");
	N1+=temp;
	N2+=temp+1;
	opr.insert(">=");
	}
	if(s.find("<") != std::string::npos && (s[s.find("<")+1]!='=' && s[s.find("<")+1]!='<'))
	{
	int temp=count_occurence("<");
	N1+=temp;
	//cout<<s<<temp<<endl;
	N2+=temp+1;
	opr.insert("<");	
	}
	if(s.find("<=") != std::string::npos)
	{
	int temp=count_occurence("<=");
	N1+=temp;
	N2+=temp+1;
	opr.insert("<=");
	}
	if(s.find("cout") != std::string::npos)
	{
	N1++;
	opr.insert("cout");
	}
	if(s.find("cin") != std::string::npos)
	{
	N1++;
	opr.insert("cin");
	}
	if(s.find("<<") != std::string::npos)
	{
	int temp=count_occurence("<<");
	N1+=temp;
	opr.insert("<<");
	}
	if(s.find(">>") != std::string::npos)
	{
	int temp=count_occurence(">>");
	N1+=temp;
	N2+=temp;
	opr.insert(">>");
	}
	if(s.find(";") != std::string::npos)
	{
	N1++;
	opr.insert(";");
	}
	if(s.find("&&") != std::string::npos)
	{
	int temp=count_occurence("&&");
	N1+=temp;
	N2+=temp+1;
	opr.insert("&&");
	}
	if(s.find("||") != std::string::npos)
	{
	int temp=count_occurence("||");
	N1+=temp;
	N2+=temp+1;
	opr.insert("||");
	}
	if(s.find("+") != std::string::npos)
	{
	int temp=count_occurence("+");
	N1+=temp;
	N2+=temp+1;
	opr.insert("+");
	}
	if(s.find("-") != std::string::npos)
	{
	int temp=count_occurence("-");
	N1+=temp;
	N2+=temp+1;
	opr.insert("-");
	}
	if(s.find("*") != std::string::npos)
	{
	int temp=count_occurence("*");
	N1+=temp;
	N2+=temp+1;
	opr.insert("*");
	}
	if(s.find("/") != std::string::npos)
	{
	int temp=count_occurence("/");
	N1+=temp;
	N2+=temp+1;
	opr.insert("/");
	}
	cout<<ink++<<s<<endl;
	getline(cin,s);
	size_t startpos = s.find_first_not_of(" \t");
	if( string::npos != startpos )
	{
    	s = s.substr( startpos );
	}
	
	}
	vector<char>::iterator it;
	/*for(it=ope.begin();it!=ope.end();it++)
	cout<<endl<<*it<<endl;*/
	n1=opr.size();
	if(opr.find("\"")!=opr.end())
	n1++;
	//N2+=ope.size();
	set<char> op(ope.begin(),ope.end());
	n2+=op.size();
	n=n1+n2;
	N=N1+N2;
	double V,Vs,L,D,Ls,I,E,T;
	V=N*log2(n);
	Vs=(2+n2)*log2(2+n2);
	L=Vs/V;
	D=1/L;
	Ls=((2*1.0)/n1)*((n2*1.0)/N2);
	I=Ls*V;
	E=V/L;
	T=E/12;
	ofstream myfile;
  	myfile.open ("hal.txt");
	myfile <<V;
  	myfile.close();
	cout<<V;
	
	/*cout<<"n1 = "<<n1<<endl;
	cout<<"n2 = "<<n2<<endl;
	cout<<"N1 = "<<N1<<endl;
	cout<<"N2 = "<<N2<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"N = "<<N<<endl;
	
	cout<<"V* = "<<Vs<<endl;
	cout<<"L = "<<L<<endl;
	cout<<"D = "<<D<<endl;
	cout<<"L* = "<<Ls<<endl;
	cout<<"I = "<<I<<endl;
	cout<<"E = "<<E<<endl;
	cout<<"T = "<<T<<endl;*/
	return 0;
}
