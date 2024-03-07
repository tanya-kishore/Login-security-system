#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<sstream>

using namespace std;
int main(){
    int a,i=0;
    string text,old,password1,password2,pass,username,password0,age,user,word,word1;
    string credentials[2],cp[2];
    cout<<"                                "<<endl;
    cout<<"      Login Security System        "<<endl;
    cout<<"________________________________"<<endl<<endl;
    cout<<"|      1.Register              |"<<endl;
    cout<<"|      2.Login                 |"<<endl;
    cout<<"|      3.Change Password       |"<<endl;
    cout<<"|      4.End Program           |"<<endl;
    
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice:- "<<endl;
        cin>>a;
        switch(a)
        {
            case 1:{
                cout<<"        Register       "<<endl;
                cout<<"Username : ";
                cin>>username;
                cout<<"Password :  ";
                cin>>password0; 
                cout<<"Age : ";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<username<<"\n";
                    of1<<password0;
                    cout<<"Registration successful"<<endl;
                }
                break;
            }
            case 2:{
                i=0;
                cout<<"         Login         "<<endl;
                
                ifstream of2;
                of2.open("file.txt");
                cout<<"Username: ";
                cin>>user;
                cout<<"Password : ";
                cin>>pass;

                if(of2.is_open()){
                    while(of2.eof()){
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word;
                            credentials[i]=word;
                            i++;
                        }
                        if(user==credentials[0] && pass==credentials[1]){
                            cout<<"    Log in successful   ";
                            cout<<endl<<endl;
                            cout<<"Details: "<<endl;
                            cout<<"Username: "+username<<endl;
                            cout<<"Password: "+pass<<endl;
                            cout<<"Age: "+age<<endl;
                        }
                        else{
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|   Press 2 to login             |"<<endl;
                            cout<<"|   Press 3 to change password   |"<<endl;
                        }
                    }
                }
                break;
            }
            case 3:{
                i=0;
                cout<<"          Change Password       "<<endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"Old password: ";
                cin>>old;
                if(of0.is_open()){
                    while(of0.eof()){
                        while(getline(of0,text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }
                        if(old==cp[1]){
                            of0.close();
                            ofstream of1;
                            if(of1.is_open()){
                                cout<<"New password : ";
                                cin>>password1;
                                cout<<"Enter again : ";
                                cin>>password2;

                                if(password1==password2){
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changed successfully"<<endl;
                                }
                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password did not match"<<endl;
                                }
                            }
                        }
                    }
                }
                else{
                    cout<<"Please enter a valid password"<<endl;
                }
                break;   
            }
            case 4:
            {
                cout<<"       Thank you!     ";
                break;
            }
            default:
            cout<<"Enter a valid choice";
        }
    } 
    while(a!=4);
    return 0;   
}