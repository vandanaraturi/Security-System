#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

class security{

    int a,i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2],cp[2];
    public:
    void output(){ 
    cout<<"     SECURITY SYSTEM    "<<endl;
    cout<<"________________________"<<endl<<endl;
    cout<<"|    1.REGISTER        |"<<endl;
    cout<<"|    2.LOGIN           |"<<endl;
    cout<<"|    3.CHANGE PASSWORD |"<<endl;
    cout<<"|____4.END PROGRAM_____|"<<endl<<endl;
    }

    void func()
    {
        do{
        cout<<endl<<endl;
        cout<<"ENTER YOUR CHOICE:- ";
        cin>>a;
        switch(a)
       {
        case 1:{
                cout<<"____________________"<<endl<<endl;
                cout<<"|-----REGISTER-----|"<<endl;
                cout<<"|__________________|"<<endl<<endl;
                cout<<"PLEASE ENTER USERNAME:- ";
                cin>>name;
                cout<<"PLEASE ENTER PASSWORD:- ";
                cin>>password0;
                cout<<"PLEASE ENTER YOUR AGE:- ";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"REGISTRATION SUCCESSFULL"<<endl;
                }
                 break;
        }
        case 2:{
               cout<<"____________________"<<endl<<endl;
               cout<<"|-------LOGIN------|"<<endl;
               cout<<"|__________________|"<<endl<<endl;

               ifstream of2;
               of2.open("file.txt");
               cout<<"PLEASE ENTER USERNAME:- ";
                cin>>user;
               cout<<"PLEASE ENTER PASSWORD:- ";
                cin>>pass;

                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2,text))
                        {
                            istringstream iss(text);
                            iss>>word;
                            creds[i]=word;
                            i++;
                        }
                        if(user==creds[0] && pass==creds[1])
                        {
                            cout<<"---LOG IN SUCCESSFULL---";
                            cout<<endl<<endl;

                            cout<<"DETAILS: "<<endl;

                            cout<<"USERNAME: "+name<<endl;
                            cout<<"PASSWORD: "+pass<<endl;
                            cout<<"AGE: "+ age<<endl;
                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"INCORRECT CREDENTIALS"<<endl;
                            cout<<"|   1.PRESS 2 TO LOGIN             |"<<endl;
                            cout<<"|   2.PRESS 3 TO CHANGE PASSWORD   |"<<endl;  
                            break;
                        }
                    }
                }
                break;
        }
        case 3:{

                ifstream read("file.txt");
					cout<<"Enter your old password:";
					cin>>old;
					while(read>>password0)
					{
						
						if(old==password0)
						{
							read.close();
							ofstream write("file.txt");
							cout<<"ENTER YOUR NEW PASSWORD:";
							cin>>password1;
							cout<<"CONFIRM YOUR NEW PASSWORD:";
							cin>>password2;
							if(password1==password2)
							{
								write<<password1;
								cout<<"CONGRATS! PASSWORD HAS BEEN CHANGED SUCCESSFULLY"<<endl<<endl;     
							}
							write.close();
							break;
						}
						else
						{
							cout<<"Please, enter valid password."<<endl<<endl;
						}
					}
					break;

        }
         
         case 4:{

            cout<<"____________THANK YOU__________";
            break;
         }
         default:
         cout<<"ENTER A VALID CHOICE";
       } 

    }while(a!=4);
    }
                 
};

int main()
{
                                                                                     
    security sobj;
    sobj.output();
    sobj.func();
                       
    return 0;
}