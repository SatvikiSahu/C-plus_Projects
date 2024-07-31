

#include <iostream>
#include<fstream>

using namespace std;
class temp{
 string id,name,author,search_index;
 fstream file;
 public:
 void addBook();
 void showBooks();
 void extractBook();
}obj;
int main() {
    int choice;
    cout<<"-------------------------------------------"<<endl;
    cout<<"1. SHOW ALL BOOKS IN LIBRARY"<<endl;
    cout<<"2. EXTRACT BOOK FROM LIBRARY"<<endl;
    cout<<"3. ADD NEW BOOK TO LIBRARY"<<endl;
    cout<<"4. EXIT"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;
    switch(choice){
    case 1:
cin.ignore();
obj.showBooks();
    break;
    case 2:
cin.ignore();
    obj.extractBook();
    break;
    case 3:
cin.ignore();
    obj.addBook();
    break;
    case 4:
cin.ignore();
    cout<<"Exiting..."<<endl;
    return 0;
    break;  
    dafault:
    cout<<"Invalid choice! Please enter a valid number."<<endl;
    }
    return 0;
}
void temp::addBook(){
  cout<<"Enter Book ID: ";
  getline(cin,id);
  cout<<"Enter Book Name: ";
  getline(cin,name);
  cout<<"Enter Author Name: ";
  getline(cin,author);
  file.open("bookdata.txt",ios:: out | ios::app);
  file<<id<<"\t"<<name<<"\t"<<author<<"\n";
  file.close();
  cout<<"Book added successfully!"<<endl;
}
void temp::showBooks(){
  file.open("bookdata.txt",ios::in);
  getline(file,id,'\t');
  getline(file,name,'\t');
  getline(file,author,'\t');
  cout<<"\n\n";
   cout<<"\t\tBookId\t\tBookname\t\tauthor\n";
  while(!file.eof()){
    cout<<"\t\t"<<id<<"\t\t"<<name<<"\t\t"<<author<<"\n";
    getline(file,id,'\t');
  getline(file,name,'\t');
  getline(file,author,'\t');
}
file.close();
}
void temp::extractBook(){
  showBooks();
  cout<<"Enter Book ID to extract: ";
  getline(cin,search_index);
  file.open("bookdata.txt",ios ::in);
  getline(file,id,'*');
  getline(file,name,'*');
  getline(file,author,'\n');

  cout<<"\n\n";
   cout<<"\t\tBookId\t\tBookname\t\tauthor\n";
   while(!file.eof()){
    if(search_index==id){
      cout<<"\t\t"<<id<<"\t\t"<<name<<"\t\t"<<author<<"\n";
      cout<<"Book extracted successfully!"<<endl;
    }
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
}
file.close();
}