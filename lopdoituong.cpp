#include<iostream>
#include<string>
using namespace std;
class car{
private:
	int speed;
	string mark;
	float price;
public:
	void setspeed(int);
	int getspeed();
	void setmark(string);
	string getmark();
	void setprice(float);
	float getprice();
	void init(int,string,float);
	void show();
};
void car::setspeed(int speedin){
	speed=speedin;
}
int car::getspeed(){
	return speed;
}
void car::setmark(string markin){
	mark=markin;
}
string car::getmark(){
	return mark;
}
void car::setprice(float pricein){
	price=pricein;
}
float car::getprice(){
	return price;
}
void car::init(int speedin,string markin,float pricein){
	speed=speedin;
	mark=markin;
	price=pricein;
	return;
}
void car::show(){
	cout<<"this is "<<mark<<" having speed "<<speed<<" its price is $"<<price<<endl;

}
int main(){
	int length;
	float maxPrice=0;
	int index=0;
	car *cars;

	cout<<"so luong xe: ";
	cin>>length;

	cars=new car[length];

	for(int i=0;i<length;i++){
		int speed;
		string mark;
		float price;
		cout<<"xe thu "<<i<<" : "<<endl;
		cout<<" toc do (km/h): ";
		cin>>speed;
		cars[i].setspeed(speed);
		cout<<"nhan hieu: ";
		cin>>mark;
		cars[i].setmark(mark);
		cout<<"gia: ";
		cin>>price;
		cars[i].setprice(price);
		if(maxPrice<price){
			maxPrice=price;
			index=i;
		}
	}
	for(int i=0;i<length;i++)
		if(i==index){
			cars[i].show();
			break;
		}
		delete [] cars;
}

