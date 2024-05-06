#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Book{  // Book Class Containing Every Information about the book//
public:
    int identificationno;
    string ISBN;
    string title;
    string subject;
    string publisher;
    string language;
    string author;
   
 Book(int identificationno,string ISBN,string title,string subject,string publisher,string language,string author):
 identificationno(identificationno),ISBN(ISBN),title(title),subject(subject),publisher(publisher),language(language),author(author){}


   // Getter Function//

  string gettitle(){  
     return title;
  }

  string getISBN(){
      return ISBN;
  }

  string getsubject(){
      return subject;
  }

  string getpublisher(){
      return publisher;
  }

  string getlanguage(){
      return language;
  }

};

class Library{  // Library Class that will contain the basic information where it has been Located//
  public:
  string name;
  string address;
  Library(string name,string address):name(name),address(address){}

  void getname(){
      return name;
  }

  void address(){
      return address;
  }
};



class Rack{ // Book Will be Located at a certain place we called that a rack so every book has a specific Rack//
  public:
  int rackno;
  Rack(int rackno):rackno(rackno){}

  void getrackno(){
      cout<<rackno<<endl;
  }
};

class BookItem{ // Every Book Will have a copy and we call it as a Book Item and it will include some additomal Information such as Barcode
      public:
      string barcode;
      string status;
      int price;
      bool availaible;
      Rack r;
      Book b;

      BookItem(string barcode,string status,int price,bool availaible,Rack r,Book b):
      barcode(barcode),status(status),price(price),availaible(true),r(r),b(b){}

     void isavailaible(bool status){
         availaible = status;
         return;
     }

     // Getter Function to get certain data members;
     string getbarcode(){
         return barcode;
     }
     
     Book getthebook(){
         return b;
     }

     string getstatus(){
         return status;
     }

     void setstatus(string& s){
         status = s;
     }
};

class Account{ // A librarian and a Mmeber will have there own Account that will include some informarion such as Password and Email//
    public:
    string email;
    string id;
    string name;
    string barcode;
    string password;
    Account(string email,string id,string name,string barcode,string password):email(email),id(id),name(name),barcode(barcode),password(password){}
};

class Member:public Account{  // This is the Member Class and it will incude the borrowed books//
    public:
    vector<BookItem>booksborrowednbymember;
    Member(string email,string id,string name,string barcode,string password):Account(email,id,name,barcode,password){}
    
    // Some Getter Function to get some details//
    string getbarcode(){
        return barcode;
    }

    string getemail(){
        return email;
    }

    string getid(){
        return id;
    }

    // Some Member Function to implement//
    void borrowabook(BookItem& b){
         booksborrowednbymember.push_back(b);
         b.isavailaible(false);
         string h = "borrowed";
         b.setstatus(h);
    }

    void renewabook(Member& m){
        
    }

    void returnabook(BookItem& b){
        
    }

    vector<BookItem>searchbytitle(BookItem& b){
       vector<BookItem>resultant;
       for(int i=0;i<booksborrowednbymember.size();i++){
           if(b.b.title == booksborrowednbymember[i].b.title){
               resultant.push_back(booksborrowednbymember[i]);
           }
       }
       return resultant;
    }

    vector<BookItem>searchbyauthor(BookItem& b){
          vector<BookItem>resultant;
          for(int i=0;i<booksborrowednbymember.size();i++){
              if(b.b.author == booksborrowednbymember[i].b.author){
                  resultant.push_back(booksborrowednbymember[i]);
              }
          }
          return resultant;
    }

    vector<BookItem>searchbysubject(){
           vector<BookItem>resultant;
          for(int i=0;i<booksborrowednbymember.size();i++){
              if(b.b.subject == booksborrowednbymember[i].b.subject){
                  resultant.push_back(booksborrowednbymember[i]);
              }
          }
          return resultant;
    }
};


class Librarian:public Account{
    public:
    vector<Book>Booksinlibrary;
    vector<Member>TotalMember;

    Librarian(string email,string id,string name,string barcode,string password):Account(email,id,name,barcode,password){}
    // Some Librarian Methods -:Librarian can addBook,addMember,deleteamember,editbook,deleteabook and several others//
    void addBook(Book& b){
          Booksinlibrary.push_back(b);
    }

    void addamember(Member& m){
        TotalMember.push_back(m);
    }

    void deleteamember(){

    }

    void editbook(){

    }

    void deleteabook(){

    }

    vector<Book>searchbytitle(string& title){
         vector<Book>resultant;
         for(int i=0;i<Booksinlibrary.size();i++){
             if(Booksinlibrary[i].title == title){
                 resultant.push_back(Booksinlibrary[i]);
             }
         }
         return resultant;
    }

    vector<Book>searchbyauthor(string& authorr){
        vector<Book>resultant;
        for(int i=0;i<Booksinlibrary.size();i++){
            if(Booksinlibrary[i].author == authorr){
                resultant.push_back(Booksinlibrary[i]);
            }
        }
        return resultant;
    }

    vector<Book>searchbysubject(string& subject){
         vector<Book>resultant;
        for(int i=0;i<Booksinlibrary.size();i++){
            if(Booksinlibrary[i].subject == subject){
                resultant.push_back(Booksinlibrary[i]);
            }
        }
        return resultant;
    }

    void issuebook(BookItem& b,Member& m){
         string reserved = "Issued";
         b.status = reserved;
         cout<<"The book with Title"<<" "<<b.b.title<<" "<<"Is Issued"<<" "<<"by"<<" "<<m.name<<" "<<endl;
    }

    void reserveabook(Member&m,BookItem& b){
            bool flag = false;
            for(int i=0;i<Booksinlibrary.size();i++){
                  if(Booksinlibrary[i].identificationno == b.b.identificationno){
                      b.status = "Reserved";
                      break;
                  }
            }
    }

    void renewabook(){

    }

};

// System class that will handle the notification updation.
class System{
    public:
};

int main() {
    Book b(12,"ankit","ankit","ankit","ankit","ankit","ankit");
    Librarian r("ankit","23","saini","1234","1234");
    r.addBook(b);
    Member M("ankitsaini","12","ankit","1234","123456");

    string search = "ankit";
    vector<Book>ans = r.searchbytitle(search);

    Rack g(20);
    BookItem s("1234","availaible",1234,true,g,b);
    r.issuebook(s,M);
    vector<BookItem>resultant = M.searchbytitle(s);

    for(BookItem b:resultant){
        cout<<b.b.title<<endl;
    }
    return 0;
}
