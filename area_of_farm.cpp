#include <iostream>
using namespace std;
unsigned convert_command_to_int(string);
bool is_integer(int);
void calculate();

class Farm_area
{
	private:
		int p;
		int w;
	public:
		int a, b;
		int x;
		
		Farm_area(int h = 3, int a=0, int b=0, int w=0)
		{
			x = h;
		}
		
		/*Calculates the largest square area possible from parameters a and b.*/
		int algorithm()
		{
			for(int i = 1; i< x-2; i++)
			{
				if ((x-i)%2==0)		p = (x-i)/2;
				else	p = ((x-i)/2)-1;
				if( (i*p) > w)
				{
					b = i;
					a = p;
					w = a*b;
				}
			}
			return 1;
		}
		
	~Farm_area(){};
};


int main()
{
	string task;
	int count=0;
	while(task!="RUN" && task!="EXIT")
	{	cout<<"Run program\nPlease write in uppercase."<<endl;
		cout<<"- RUN"<<endl;
		cout<<"- EXIT"<<endl;
		cin>>task;
		
		int help = convert_command_to_int(task);
		
		switch(help)
		{
			case 1:
				 calculate();
				break;
			case 2:
				system("PAUSE");
				break;
			default:
				cout<<"Wrong command."<<endl;				
		}
		
		if(count>2)
		{
			cout<<"You have given wrong values too many times.\nThe program will end. "<<endl;
			break;
		}
		count++;
	}
	return 0;
}

void calculate(){
	int how_meters, count=0;
	Farm_area a1;
	cout<<"Please write how many meters of fence is available: ";
	cin>>how_meters;
	while(is_integer(how_meters) || how_meters<5)
	{	
		count++;
		cin.clear();
    	cin.sync();
		cout<<"Wrong value. Try again :)"<<endl;
		cout<<"Please write how many meters of fence is available: ";
		cin>>how_meters;
		
		if(count>2)
		{
			cout<<"You have given wrong values too many times.\nThe program will end. "<<endl;
			break;
		}
		count++;
	}
	if(is_integer(how_meters)==0)
	{
		a1.x = how_meters;
		if(a1.algorithm() == 1)
		{
			cout<<"a = "<<a1.a<<" b = "<<a1.b<<endl;
		}				
	}
}


unsigned convert_command_to_int(string str)
{
	if(str == "RUN")	return 1;
	if(str == "EXIT")	return 2;
}

bool is_integer(int a)
{
	if( cin.fail() || a<5)
		return 1;
	else 
		return 0;
}
