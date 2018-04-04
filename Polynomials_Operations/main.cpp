#include<iostream>
#include"list.h"
#include"polynomial.h"
#include<string>

using namespace std;

int main(){
	list l1, l2, l3; poly *p1, *p2; int coeff, order, order2, coeff2, num, x; string res;
	cout << "Enter the polynomial order: ";
	cin >> order;
	cout << "Enter the polynomial coefficients starting with higher power's coeff: \n";
	for (int i = 0; i <= order; i++)
	{
		cout << "coeff of X^" << order - i << " = ";
		cin >> coeff;
		l1.add_end(coeff);
	}
	string operation;
	cout << "Enter required operation : ";
	cin >> operation;

	if (operation == "Evaluate")
	{
		cout << "Enter the number to be evaluated : ";
		cin >> num;
		p1 = new poly(l1);
		x = p1->Evaluate(num);	
		cout << "\n\tP[" << num << "] =  " << x << "\n\n";
	}

	else if (operation == "Multiply")
	{
		cout << "Enter the second polynomial order: ";
		cin >> order2;
		cout << "Enter the polynomial coefficients starting with higher power's coeff: \n";
		for (int i = 0; i <= order2; i++)
		{
			cout << "coeff of X^" << order2 - i << " = ";
			cin >> coeff2;
			l2.add_end(coeff2);
		}
		p2 = new poly(l2);
		res = p2->Multiply(p1);
		cout <<"\n" <<res << "\n\n";
	}

	else if (operation == "Differentiate")
	{
		res = p1->differentiate();
		cout << "\n" << res << "\n\n";
	}

	system("pause");
	return 0;
}