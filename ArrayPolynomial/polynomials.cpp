#include<iostream>
#include<cstring>

using namespace std;


struct polyNode {
	int coef;
	int expon;
	polyNode* link;

};

class Polynomials {
private:
	int sum;

public:
	Polynomials() {
		
		sum = 0;
	}
	polyNode* padd(polyNode* a, polyNode* b);
	void attach(double coefficient, int exponent, polyNode* ptr);
	void erase(polyNode* a);
};

polyNode* Polynomials::padd(polyNode* a, polyNode* b) {

	int sum = 0;
	polyNode* c;
	polyNode* temp;
	polyNode* rear=new polyNode;

	while (a && b) {
		switch ((a->expon, b->expon)) {

			//a->expon < b->expon
		case -1: 
			attach(b->coef, b->expon, rear);
			b = b->link;
			break;

			//a->expon = b->expon
		case 0:
			sum = a->coef + b->coef;
			if (sum != 0) attach(sum, a->expon, rear);
			a = a->link;
			b = b->link;
			break;

			//a->expon > b->expon
		case 1:
			attach(a->coef, a->expon, rear);
			a = a->link;
			break;
		}
	}

	for (; a; a = a->link) {
		attach(a->coef, a->expon, rear);
		
	}

	for (; b; b = b->link) {
		attach(b->coef, b->expon, rear);
	}
	
	rear->link = NULL;

	temp = c;
	c = c->link;
	delete temp;

	return c;
}

void Polynomials::attach(double coefficient, int exponent, polyNode* ptr) {
	polyNode* temp= new polyNode;
	temp->coef = coefficient;
	temp->expon = exponent;

	ptr->link = temp;
	ptr = temp;
}

void Polynomials::erase(polyNode* a) {
	polyNode* temp;

	while (a) {
		temp = a;
		a = a->link;
		delete temp;
	}
}



int main() {

	Polynomials a;
	

}