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

  string getname(){
      return name;
  }

  string getaddress(){
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
      time_t duedate;

      BookItem(string barcode,string status,int price,bool availaible,Rack r,Book b,time_t duedate):
      barcode(barcode),status(status),price(price),availaible(true),r(r),b(b),duedate(duedate){}

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

     void setduedate(){

     }
};

class Account{ // A librarian and a Mmeber will have there own Account that will include some informarion such as Password and Email//
    public:
    string email;
    int  id;
    string name;
    string barcode;
    string password;
    Account(string email,int id,string name,string barcode,string password):email(email),id(id),name(name),barcode(barcode),password(password){}
};

class Member:public Account{  // This is the Member Class and it will incude the borrowed books//
    public:
    vector<BookItem>checkedoutBooks;
    vector<BookItem>Books;
    Member(string email,int id,string name,string barcode,string password):Account(email,id,name,barcode,password){}
    
    // Some Getter Function to get some details//
    string getbarcode(){
        return barcode;
    }

    string getemail(){
        return email;
    }

    int getid(){
        return id;
    }

    int finecalculation(BookItem& b){
        time_t recent = time(0);
        time_t back = b.duedate;
        return 1;
    }


     void borrowabook(BookItem& b){
         if(checkedoutBooks.size() >= 5){
             cout<<"You Can't check out the book";
         }

         else{
             checkedoutBooks.push_back(b);
             time_t now = time(0);
             b.duedate = now + (10*24*60*60);
             string statusname = "Borrowed";
             b.setstatus(statusname);
             cout<<"Book has been Borrowed"<<endl;
         }
     }

    void returnabook(BookItem b){
        // for(auto it=checkedoutBooks.begin();it!=checkedoutBooks.end();it++){
        //     if(*it == b){
        //         BookItem.erase(it);
        //         bookitem.setduedate();
        //         b.isavailaible(true);
        //         b.status = "Availaible";
        //         break;
        //     }
        // }
    }


    void renewabook(BookItem& b){
         if(b.availaible == true){
             cout<<"Book Has been renewed"<<endl;
         }
    }

    vector<BookItem>searchbytitle(BookItem& b){
       vector<BookItem>resultant;

       for(int i=0;i<Books.size();i++){
           if(b.b.title == Books[i].b.title){
               resultant.push_back(Books[i]);
           }
       }
       return resultant;
    }

    vector<BookItem>searchbyauthor(BookItem& b){
          vector<BookItem>resultant;

          for(int i=0;i<Books.size();i++){
              if(b.b.author == Books[i].b.author){
                  resultant.push_back(Books[i]);
              }
          }
          return resultant;
    }

    vector<BookItem>searchbysubject(BookItem& b){
           vector<BookItem>resultant;
          for(int i=0;i<Books.size();i++){
              if(b.b.subject == Books[i].b.subject){
                  resultant.push_back(Books[i]);
              }
          }
          return resultant;
    }
};


class Librarian:public Account{
    public:
    vector<Book>Booksinlibrary;
    vector<Member>TotalMember;
    

    Librarian(string email,int id,string name,string barcode,string password):Account(email,id,name,barcode,password){}
    // Some Librarian Methods -:Librarian can addBook,addMember,deleteamember,editbook,deleteabook and several others//
    void addBook(Book& b){
          Booksinlibrary.push_back(b);
    }

    void addBookItem(BookItem& bookitem,Book& book){
           TotalBookItem[book.identificationno].push_back(bookitem);
    }

    void addamember(Member& m){
        TotalMember.push_back(m);
    }

    void deleteamember(Member& b){
         for(auto it=TotalMember.begin();it!=TotalMember.end();it++){
            //  if(*it == b){
            //      TotalMember.erase(it);
            //      break;
            //  }
         }
    }

    void editbook(Book& b){
         
    }

    void deleteabook(Book& b){
         
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
         string issued = "Issued";
         b.status = issued;
         b.setduedate();
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
    Librarian r("ankitsaini955831@gmail.com",1023,"saini","1234","1234");
    r.addBook(b);
    Member M("ankitsaini",12,"ankit","1234","123456");

    string search = "ankit";
    vector<Book>ans = r.searchbytitle(search);

    Rack g(20);
    BookItem s("1234","availaible",1234,true,g,b,time(0));

    r.issuebook(s,M);
    cout<<endl;

    vector<BookItem>resultant = M.searchbytitle(s);

    // for(BookItem b:resultant){
    //     cout<<b.b.title<<endl;
    // }
    return 0;
}
