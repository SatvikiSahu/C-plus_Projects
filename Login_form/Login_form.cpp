#include<iostream>
#include<fstream>

using namespace std;
class select{
    string username, email, password;
     string searchname, searchpassword,semail;
    fstream file;
    public:
    void login();
    void signup();
    void forgotPassword();
}obj;
int main() {
    char choice;
    cout<<"\n1-login";
    cout<<"\n2-Sign-up";
    cout<<"\n3-Forgot Password";
    cout<<"\n4-Exit";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    Switch(choice){
        case '1':
           obj.login();
        break;
         case '2':
           obj.signup();
        break;
         case '3':
           obj.forgotPassword();
         break;
        case '4':
           return 0;
        break;
        default:
        cout<<"\nInvalid choice!";
    }
}
void select::signup(){
    cout<<"\nEnter your username: ";
    getline(cin,username);
    cout<<"\nEnter your email: ";
    getline(cin,email);
    cout<<"\nEnter your password: ";
    getline(cin,password);
    file.open("logindata.txt",ios :: out | ios::app);
    file<<username<<","<<email<<","<<password<<endl;
    file.close();
    cout<<"\nSignup successful!";
}
void select::login(){
    cout<<"-----------------LOGIN------------------"<<endl;
    cout<<"\nEnter your username: "<<endl;
    getline(cin,searchname);
    cout<<"\nEnter your password: "<<endl;
    getline(cin,searchpassword);
    file.open("logindata.txt",ios :: in);
    getline(file,username, ',');
    getline(file, email, ',');
    getline(file, password, '\n');
    
    while(!file.eof()){
    if(username == searchname && password == searchpassword){
        Cout<<"\nLogin successful!";
    } else {
        cout<<"\nInvalid username or password!";
    }
    getline(file,username, ',');
    getline(file, email, ',');
    getline(file, password, '\n');
    }
    file.close();
}
void select::ForgotPassword(){ 
    cout<<"\nEnter your registered email: ";
    getline(cin, semail);
    cout<"\nEnter your username: ";
    getline(cin, searchname);
    file.open("logindata.txt",ios :: in);
    getline(file, username, ',');
    getline(file, email, ',');
    getline(file, password, '\n');
    
    while(!file.eof()){
    if(semail == email && username == searchname){
        cout<<"\nYour password is: "<<password;
    } else {
        cout<<"\nNo account found with this email and username!";
    }
    getline(file, username, ',');
    getline(file, email, ',');
    getline(file, password, '\n');
    }
    file.close();
}