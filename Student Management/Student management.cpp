#include<iostream>
#include<fstream>
using namespace std;
class manage(
 string  rollnum,name,fName,address,search;
 fstream file;
 void addstu();
 void displayAll();
 void searchStu();
)obj;
int main() {
    int choice;
 cout<<"----------------------------------------";
 cout<<"1- Add New Student Record\n";
 cout<<"2- Display All Student Records\n";
 cout<<"3- Search Student Record\n";
 cout<<"4- Exit\n";
 cout<<"----------------------------------------";
 cin>>choice;

 switch(choice){
    case 1:
        obj.addstu();
        break;
    case 2:
        obj.displayAll();
        break;
    case 3:
        obj.searchStu();
        break;
    case 4:
        return 0;
        break;
    default:
        cout<<"Invalid choice!";
 }
}

void  manage:: addstu(){
    cout<<"Enter Roll Number: ";
    getline(cin,rollnum);
    cout<<"Enter Name: ";
    getline(cin,name);
    cout<<"Enter Father's Name: ";
    getline(cin,fName);
    cout<<"Enter Address: ";
    getline(cin,address);
    file.open("student.txt",ios::app);
    file<<rollnum<<"\t"<<name<<"\t"<<fName<<"\t"<<address<<"\n";
    file.close();
    cout<<"Student Record Added Successfully!";
}

void manage::displayAll(){
file.open("student.txt",ios::in);
getline(file,rollnum);
getline(file,name);
getline(file,fName);
getline(file,address);
while(!file.eof()){
    cout<<"Roll Number: "<<rollnum<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Father's Name: "<<fName<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"----------------------------------------"<<endl;
    getline(file,rollnum);
    getline(file,name);
    getline(file,fName);
    getline(file,address);
} file.close();
}

void manage::searchStu(){
cout<<"Enter Roll Number to Search: ";
getline(cin,search);
file.open("student.txt",ios::in);
    getline(file,rollnum,'\t');
    getline(file,name,'\t');
    getline(file,fName,'\t');
    getline(file,address,'\n');
    while(!file.eof()){
    if(rollnum==search){
        cout<<"Roll Number: "<<rollnum<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Father's Name: "<<fName<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"----------------------------------------"<<endl;
    }
    getline(file,rollnum,'\t');
    getline(file,name,'\t');
    getline(file,fName,'\t');
    getline(file,address,'\n');
    }
    file.close();
}