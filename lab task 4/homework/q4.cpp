#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class book{
	private:
		string author;
		string title;
		double price;
		string publisher;
		int stock_position;
		
	public:
		book(string author, string title, double price, string publisher, int stock_position){
		this->author=author;
		this->title=title;
		this->price=price;
		this->publisher=publisher;
		this->stock_position=stock_position;	
		}
		
		string getTitle() {
			return title;
		}
			
		
        string getAuthor() {
		    return author;
		}

		
		void check_availability(string t, string a){
		    if(t==title && a==author){
				cout<<"available"<<endl;
		    	cout<<"Enter The number of copies you want: "<<endl;
		    	int copies;
		    	cin>>copies;
		    	if(stock_position>=copies){
		    		cout<<"Total: "<<price*copies<<endl;
		    		stock_position-=copies;
				}
				else{
					cout<<"Not enough copies"<<endl;

		    }
		}
		    else{
		    	cout<<"not available"<<endl;
			}
	
		}
};

int main(int argc, char* argv[]){
	if(argc!=3){
		return 1;
	}
	
	string t=argv[1];
	string a=argv[2];
	
	book b1("J.K. Rowling", "Harry Potter", 39.99, "Bloomsbury", 10);
    book b2("J.R.R. Tolkien", "The Hobbit", 29.99, "HarperCollins", 5);
    book b3("George Orwell", "1984", 19.99, "Secker & Warburg", 7);
    
    book books[]={b1,b2,b3};
    bool found = false;
    
    for (int i = 0; i < 3; i++) {
        if (t == books[i].getTitle() && a == books[i].getAuthor()) {
            books[i].check_availability(t, a);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Book not available." << endl;
    }
	
	return 0; 
}
