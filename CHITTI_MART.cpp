#include<bits/stdc++.h>
using namespace std;
struct DETAILS
{
	int total_amount,total_items,Visited;
	string MOB;
};
class ChittiMart
{
	private:
		int Product_id;
		string Product_name;
	public:
		unordered_map<string,string> U_DATA;
		unordered_map<string,struct DETAILS> U_DETAILS;
		vector<string> IT;
		vector<int> AVLB;	
		vector<int> PRC;
		void intial()
		{
			IT.push_back(" ");
		IT.emplace_back("HORLICKS");
		IT.emplace_back("BOOST");
		IT.emplace_back("COMPLAN");
		IT.emplace_back("MILK");
		IT.emplace_back("GOODDAY");
		IT.emplace_back("HIDE&SEEK");
		IT.emplace_back("MILKIBIKS");
		for(int i=0;i<8;i++)
		AVLB.emplace_back(10);
	
		for(int i=0;i<8;i++)
		PRC.emplace_back(i*100);
		}
		void Menu();
		void CUSTOMER();
		void ADMIN();
		void NEW_USER();
		void EXISTING_USER();
		void DISPLAY(string);
		void MENU_CARD();
		void ADD_CART(string);
	
};
void ChittiMart::DISPLAY(string User)
{
	cout<<"HELLO --->"<<User;
	cout<<"TOTAL BILL PAID : "<<U_DETAILS[User].total_amount<<"\n";
	cout<<"TOTAL ITEM BOUGHT: "<<U_DETAILS[User].total_items<<"\n";
	cout<<"TIMES VISITED :"<<U_DETAILS[User].Visited<<"\n";
	cout<<"MOBILE NO :"<<U_DETAILS[User].MOB<<"\n";
}
void ChittiMart::Menu()
{
	cout<<"\t\t<----Welcome to Chitti Mart---->\t\t\n\n\t\t<----Happy Shopping---->\t\t\n";
	int N;
	do{
	
	cout<<"1--> ADMIN LOGIN\n2--> CUSTOMER LOGIN\n3--> QUIT\n";
	cout<<"choose below options\n";
	
	input:
		cin>>N;
	switch(N)
	{
		case 1:
			ADMIN();
			break;
		case 2:
			CUSTOMER();
			break;
		case 3:
			break;
		default:
			cout<<"INVALID!! TRY AGAIN\n";
			goto input;
	}
		}while(N!=3);
		cout<<"THANK YOU _/\\_\n";
}
void ChittiMart::CUSTOMER()
{
	cout<<"1-->NEW USER \n 2-->EXISTING USER\n";
	int US;
	input:
	cin>>US;
	switch(US)
	{
		case 1:
			NEW_USER();
			break;
		case 2:
			EXISTING_USER();
			break;
		default:
			cout<<"INVALID !! Try Again\n";
			goto input;
	}
	
}
void ChittiMart::MENU_CARD()
{
	
	cout<<"\t\t\t<-------MENU CARD-------->\t\t\n";
	for(int i=1;i<IT.size();i++)
	cout<<"\t\t\t|\t"<<i<<"-->"<<IT[i]<<"\n";
	cout<<"\t\t\t|\t"<<IT.size()<<"-->"<<"EXIT"<<"\n";
	
}
void ChittiMart::NEW_USER()
{
	cout<<"WELCOME! You can be a Daily Customer of ChittiMart by Providing Your Details\n";
	string User,Pass;
	cout<<"Provide a name for Login Purpose\n";
	cin>>User;
	cout<<"Protect with a Strong PassWord";
	cin>>Pass;
	U_DATA[User]=Pass;	
	struct DETAILS D;
	D.total_amount=0;
	D.total_items=0;
	D.Visited=0;
	cout<<"Enter Mobile NO :\n";
	cin>>D.MOB;
	U_DETAILS[User]=D;
	DISPLAY(User);
	MENU_CARD();
	ADD_CART(User);
	
}
void ChittiMart::EXISTING_USER()
{
	string User,pass;
	input :
	{	
	cout<<"USER_NAME:\n";
	
	cin>>User;
	cout<<"Password:\n";
	cin>>pass;
	}
	if(U_DATA.find(User)==U_DATA.end())
	{
		cout<<"INVALID USER\n";
		goto input;
	}
	else if(U_DATA[User]!=pass)
	{
		cout<<"INVALID PassWord\n";
		goto input;
	}
	else if(U_DATA[User]==pass)
	{
		cout<<"Welcome "<<User<<"\n";
		DISPLAY(User);
		MENU_CARD();
		ADD_CART(User);
		
	}
}
void ChittiMart::ADD_CART(string User)
{
	int Present_BILL=0,Present_Items=0;
	unordered_map <int,pair<int,int>> BILL;
	int CH;
	do
	{
		
		cout<<"Choose from Menu\n";
		cin>>CH;
			if(CH!=IT.size())
			{
			
				if(AVLB[CH]>0)
				{
					int Q;
					cout<<"enter Quantity\n";
					cin>>Q;
					if(AVLB[CH]>=Q)
					{
						AVLB[CH]-=Q;
						Present_BILL+=(PRC[CH])*Q;
						Present_Items+=Q;
						if(BILL.find(CH)==BILL.end())
						BILL.insert({CH,{Q,(PRC[CH])*Q}});
						else
						BILL.insert({CH,{BILL[CH].first+Q,BILL[CH].second+(PRC[CH])*Q}});
					}	
					else
					{
						cout<<"SORRY !! INSUFFICIENT QUANTITY\n";
					}
				}
				else
				{
					cout<<"SORRY !! OUT OF STOCK \n";
				}
			}
		}while(CH!=IT.size());
		U_DETAILS[User].total_amount+=Present_BILL;
		U_DETAILS[User].total_items+=Present_Items;
		U_DETAILS[User].Visited+=1;
		int c=0;
		cout<<"\t\t\t<-------BILL-------->\t\t\n";
		for(auto it :BILL)
		cout<<"\t\t\t|\t"<<c++<<"-->"<<it.first<<"-->"<<it.second.first<<"-->"<<it.second.second<<"\n";
		cout<<"\t\t\t|\t"<<"Total Items"<<"-->"<<Present_Items<<"\n";
		cout<<"\t\t\t|\t"<<"Total BILL"<<"-->"<<Present_BILL<<"\n";
		cout<<"<------PLEASE RECHECK------>"<<"\n";
		
}
void ChittiMart::ADMIN()
{
	
}
int main()
{
	ChittiMart ob;
	ob.intial();
	ob.Menu();
	
	
}
