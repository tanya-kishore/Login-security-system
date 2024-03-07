#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
void login();
void registration();
void forgotPassword();

int main(){
    int choice;
    cout<<"\n                WELCOME TO LOGIN PAGE           \n";
    cout<<"                       MENU                       \n";
    cout<<"|   PRESS 1 TO LOGIN                           |"<<endl; 
    cout<<"|   PRESS 2 TO REGISTER                        |"<<endl; 
    cout<<"|   PRESS 3 TO if you forgot your PASSWORD     |"<<endl; 
    cout<<"|   PRESS 4 TO EXIT                            |"<<endl; 
    cout<<" Please enter your choice: ";
    cin>>choice;
    cout<<endl;

    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3: 
            forgotPassword();
            break;
        case 4:
            cout<<"Thank you!"<<endl;
            break;
        default:
            cout<<"Please enter a valid choice "<<endl;
        main();
    }
}
void login(){
    int count;
    string userId, password,id,pass;
    system("cls");
    cout<<"Please enter your username and password: "<<endl;
    cout<<"USERNAME : ";
    cin>>userId;
    cout<<"PASSWORD : ";
    cin>>password;

    ifstream input("records.txt");
    while(input>>id>>pass){
        if(id==userId && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<userId<<"\nLOGIN SUCCESSFUL \n";
        main();
    }
    else{
        cout<<"LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}
void registration(){
    string ruserId,rpassword,rid,rpass,mobileno;
    system("cls");
    cout<<"USERNAME : ";
    cin>>ruserId;
    cout<<"PASSWORD : ";
    cin>>rpassword;
    cout<<"MOBILE NO. ";
    cin>>mobileno;

    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"Registration is successfull!"<<endl;
    main();
}
void forgotPassword(){
    int option;
    system("cls");
    cout<<"Forgot password? \n";
    cout<<"Press 1 to search your id by username \n";
    cout<<"Press 2 to go back to the main menu \n";
    cout<<"Enter your choice : ";
    cin>>option;
    switch(option){
        case 1:
        {
            int count = 0;
            string suserId,sId,spass;
            cout<<"Enter the username which you remembered : ";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass){
                if(sId==suserId){
                    count=1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"Your account is found! \n";
                cout<<"Your password is : "<<spass;
                main();
            }
            else{
                cout<<"Sorry! your account is not found! \n";
                main();
            }
            break;
        }
        case 2: 
        {
            main();
        }
        default:
            cout<<"Wrong choice! Please try again"<<endl;
            forgotPassword();
    }


}