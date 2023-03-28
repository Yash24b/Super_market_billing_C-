#include<iostream>
#include<fstream>
using namespace std;

class shopping{
	private:
		string pname;
                  float price;
                  float discount;
                  int pcode;
                  public:
                  	void menu();
                  	void administrator();
                  	void buyer();
                  	void add();
                  	void edit();
                  	void rem();
                  	void list();
                  	void recipt();
                  	
};
void shopping :: menu(){
	m:
	int choice;
	string email ;
	string password;
	
	cout<<"\t\t\t\t_______________________\n";
	cout<<"\t\t\t\t                       \n";	
	cout<<"\t\t\t\t supermarket main menu \n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t_______________________\n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t| 1) Administrator     \n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t| 2) Buyer             \n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t| 3) exit              \n";
	cout<<"\n\t\t\t please select:\n";
	cin>>choice;
switch(choice){
case 1:
	cout<<"Enter Email\n";
	cin>>email;
	cout<<"Enter Password\n";
	cin>>password;
	if(email =="yashchandak987@gmail.com" && password == "yash@466"){
	administrator()	;
	}
	else{
		cout<<"Invalid Email and Password\n";
		
	}
	break;
	
	case 2:{
		buyer();
		
	}
	case 3:{
		
		exit(0);
		
	}
	default :{
		
		cout<<"Please select from the given option\n ";
		
	}
}
goto m ;
	
}
void shopping :: administrator(){
	
	m:
		int choice;
	cout<<"\t\t\t\t\n Administrator menu  \n";
	cout<<" \t\t\t\t|                     | \n";
	cout<<" \t\t\t  |1) Add the product   |  \n";
	cout<<" \t\t\t\t|                     | \n";
	cout<<" \t\t\t  |2) Modify the product| \n";
	cout<<" \t\t\t\t|                     | \n";
	cout<<" \t\t\t  |3) Delete the product| \n";
	cout<<" \t\t\t\t|                     | \n";
	cout<<" \t\t\t  |4) Back to main menu | \n";
	cout<<" \t\t\t\t|                     | \n";
	cout<<"\t\t\t   Please enter your choice\n";
	cin>>choice;
	switch(choice){
		case 1:{
			
			add();
			break;
		}
		case 2:
		{
			edit();
			break;
		}
		case 3:{
			
			rem();
			break;
		}
		case 4:{
			menu();
			break;
		}
		default:{
			cout<<"invalid choice\n";
			break;
		}
			
	}
	goto m;
}
void shopping::buyer(){
	m:
		int choice;
	cout<<"\n  buyer\n";
	cout<<"\t\t\t\t______________________\n";
	cout<<"\t\t\t\t                      \n";
	cout<<"\t\t\t 1) Buy product         \n";
	cout<<"\t\t\t\t                      \n";
	cout<<"\t\t\t 2) Go back             \n";
	cout<<"Please select something \n";
	cin>>choice;
	switch(choice){
		case 1:{
			recipt();
			break;
		}
		case 2:{
			menu();
			break;
		}
		default :{
			cout<<"invalid choice";
			break;
		}
		
	}
	
	goto m;
}
void shopping ::add(){
	m:
	fstream data;
	int c;
	int token =0;
	float p;
	float d;
	string n;
	cout<<"\t\t\t\t   enter new product\n";
	cout<<"\t\t\t\t product code of the product \n";
	cin>>pcode;
	cout<<"\n\n\t name of the product\n";
	cin>>pname;
	cout<<"\n\n\t\t price of the product\n";
	cin>>price;
	cout<<"\t\t discount of the product \n";
	cin>>discount;
	data.open("database.txt",ios::in);
	if(! data){
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		while(!data.eof()){
			if(c == pcode){
				token++;
			}
			else{
				data>>c>>n>>p>>d;
			}
			data.close();
			if(token == 1){
				goto m;
				
			}
			else{
				data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";	
			data.close();
			}
			// APPEND = APP
		}
	}
	cout<<"\n record inserted\n";
}
void shopping::edit(){
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n ;
	cout<<"\n /t/t/t Modify the record";
	cout<<"/n/t/t/t/t Product code:";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"/n/n File doesn't exist";

	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
data>>pcode>>pname>>price>>discount;
while (!data.eof())
{
	if(pkey == pcode){
		cout<<"/n/t/t/t Product new code:";
		cin>>c;
		cout<<"/n/t/t Name of the product:";
		cin>>n;
		cout<<"/n/t/t/t Price:";
		cin>>p;
		cout<<"/n/t/t/t Discount:";
		cin>>d;
	data1<<" "<<" "<<" "<<n<<" "<<p<<" "<<d<<"/n";
	cout<<"/n/t/t/t Record edited";
	token++;

	}	
	else{
		data1<<"  "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<" \n";

	}
	data>>pcode>>pname>>price>>discount;

}
data.close();
data1.close();
remove("database.txt");
rename("database1.txt","database.txt");
if(token == 0)
{
	cout<<"/n/t/t/t Record not found sorry";

}	}}
void shopping::rem(){
	fstream data,data1;
	int pkey;
	int token = 0;
	cout<<"/n/t/t/t Delete product";
	cout<<"/n/t/t/t Product code";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"File doesn't exist";

	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>discount;
		while(!data.eof()){
			if(pcode == pkey){
				cout<<"/n/n/t/t product deleted succesfully";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"/n";

			}
			data>>pcode>>pname>>price>>discount;
		}
			data.close();
			data1.close();
			remove("database.txt");
			rename("database1.txt" , "database.txt");
			if(token == 0){
				cout<<"/n/n/n/t/t/t Record not found";

			}
		}
	}
void shopping ::list(){
	fstream data;
	data.open("database.txt",ios::in);
	cout<<" /n/t/t_________________________________________/n";
	cout<<"Product number/t/t name/t/t/t/t price";
	cout<<"/n/t________________________________/n";
data>>pcode>>pname>>price>>discount;
while(!data.eof()){
	cout<<pcode<<"/t/t"<<pname<<"/t/t"<<price<<"/n";
	data>>pcode>>pname>>price>>discount;

}
data.close();
}
void shopping ::recipt(){
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount =0;
	float dis = 0;
	float total = 0;
	cout<<"/n/n/t/t/t/t/t RECIPT";
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"/n/n/n Empty database";

	}
	else{
		data.close();
		list();
		cout<<"/n______________________________________/n";
		cout<<"/n|                                     /n";
		cout<<"/n       Please place the order         /n";
		cout<<"/n______________________________________/n";
		cout<<"/n|                                     /n";
do{
	m:
	cout<<"/n/n Enter product code";
	cin>>arrc[c];
	cout<<"/n/n Enter the product quantity";
	cin>>arrq[c];
	for(int i = 0;i<c;i++){
		if(arrc[c]==arrc[i]){
			cout<<"/n/n Duplicate product key . Please try again";
			goto m ;

		}
	}
	c++;
	cout<<"/n/n Do you want to key another product ? If yes then press y else no ";
	cin>>choice;


}
while(choice =='y');
cout<<"/n/n/t/t/t/t/t/t___________________________RECIPT__________________/n";
cout<<"/n product No /t Product name/t product quantity/t tprice /t amount /t amount with discount";
for(int i =0 ;i<c;i++){
	data.open("database.txt",ios::in);
	data>>pcode>>price>>discount;
	while(!data.eof()){
		if(pcode ==arrc[i]){
			amount = price * arrq[i];
			dis = amount -(amount *discount/100);
			total = total +discount;
			cout<<"/n"<<pcode<<"/t/t"<<pname<<"/t/t"<<arrq[i]<<"/t/t"<<price<<"/t/t"<<amount<<"/t/t"<<discount;

		}
		data>>pcode>>pname>>price>>discount;

	}
}
data.close();
		
	}
	cout<<"/n/n________________________________";
	cout<<"/n Total amount:"<<total;

}

int main(){
shopping s;
s.menu();


	return 0;
}
