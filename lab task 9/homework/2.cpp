#include<iostream>
using namespace std;

class Car{
	protected:
		string model;
		float price;
	public:
		Car(string m, float p){
			model=m;
			price=p;
		}
		string getModel(){
			return model;
		}
		float getPrice(){
			return price;
		}
		void setModel(string m){
			model=m;
		}
		virtual float setPrice(float p)=0;
		
		virtual void display(){
			cout<<"Model: "<<model<<endl;
			cout<<"Price: "<<price<<endl;
		};
		
		virtual ~Car(){
		}
};

class Color: public Car{
	private:
		string color;
	public:
		Color(string m,float p, string c): Car(m,p), color(c){}
		
		string getColor(){
			return color;
		}
		void setColor(string c){
			color=c;
		}
		float setPrice(float p)override{
			price=p;
		}
		void display() override{
			cout << "Model: " << model << endl;
            cout << "Price: " << price << endl;
			cout<<"Color:"<<color<<endl;
		}
};

class Company: public Car{
	private:
		string company;
	public:
		Company(string m, float p,string co): Car(m,p), company(co){}
		
		string getCompany(){
			return company;
		}
		void setCompany(string co){
			company=co;
		}
		float setPrice(float p) override {
        price = p;
        }
		void display() override{
			cout << "Model: " << model << endl;
            cout << "Price: " << price << endl;
			cout<<"Company:"<<company<<endl;
		}
};

int main(){
	Color b("BMW-X5", 50000, "Black");
    Company h("Civic", 32000, "Honda");

    b.display();
    cout << endl;

    h.display();
    cout << endl;

    b.setPrice(52000);
    h.setPrice(34000);

    cout << "After price update:\n";
    b.display();
    cout << endl;
    h.display();

	
	return 0;
}
