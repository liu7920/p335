#include <iostream>
using namespace std;

class Power{
	int kick;
	int punch;
public:
	Power(int kick=0, int punch=0){
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+ (Power op2);
	Power operator- (Power op2);
	Power operator* (Power op2);
	Power operator/ (Power op2);
	bool operator== (Power op2);
	Power& operator+= (Power op2);
	Power& operator++ ();
	Power& operator << (int n);
	bool operator! ();
};

void Power::show(){
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator+(Power op2){
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

Power Power::operator-(Power op2){
	Power tmp;
	tmp.kick = this->kick - op2.kick;
	tmp.punch = this->punch - op2.punch;
	return tmp;
}

Power Power::operator*(Power op2){
	Power tmp;
	tmp.kick = this->kick * op2.kick;
	tmp.punch = this->punch * op2.punch;
	return tmp;
}

Power Power::operator/(Power op2){
	Power tmp;
	tmp.kick = this->kick / op2.kick;
	tmp.punch = this->punch / op2.punch;
	return tmp;
}

bool Power::operator ==(Power op2){
	if(kick==op2.kick && punch==op2.punch) return true;
	else return false;
}

Power& Power::operator +=(Power op2){
	kick = kick + op2.kick;
	punch = punch + op2.punch;
	return *this;
}

Power& Power::operator ++(){
	kick++;
	punch++;
	return *this;
}

bool Power::operator !(){
	if(kick == 0 && punch == 0) return true;
	else return false;
}

Power& Power::operator << (int n){
	kick += n;
	punch += n;
	return *this;
}

int main() {
	Power a(3,4), b(3,4), c, d, e, f;
	c = a + b;
	d = a - b;
	e = a * b;
	f = a / b;
	a.show();
	b.show();
	c.show();
	d.show();
	e.show();
	f.show();
	if(a==b){
		cout << "두 파워가 같다" << endl;
	}
	else{
		cout << "두 파워가 같지 않다." << endl;
	}
	a+=b;
	a.show();
	++a;
	a.show();
	if(!a) cout << "a의 파워가 0이다." << endl;
	else cout << "a의 파워가 0이 아니다." << endl;

	a << 3 << 5 << 6;
	a.show();
	return 0;
}
