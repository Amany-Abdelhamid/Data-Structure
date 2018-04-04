#include<iostream>
#include"list.h"
#include<string>
#include<math.h>
using namespace std;

void Evaluate(){
	list poly; int order, coeff, num, sum = 0;
	cout << "Enter the polynomial order: ";
	cin >> order;
	cout << "Enter the polynomial coefficients starting with higher power's coeff: \n";
	for (int i = 0; i <= order; i++)
	{
		cout << "coeff of X^" << order - i << " = ";
		cin >> coeff;
		poly.add_end(coeff);
	}
	cout << "Enter the number to be evaluated : ";
	cin >> num;
	//Evaluating the polynomial code = O(order) 
	////////////////////////////////////////////////////////////
	for (int i = 0; i <= order; i++)
		sum += (poly.getNodeData(i + 1)*pow(num, order - i));
	/////////////////////////////////////////////////////////////
	cout << "\n\tP[" << num << "] =  " << sum << "\n\n";
};
void Multiply()
{
	list p1, p2, p3; int order1, order2,coeff1,coeff2; 
	cout << "Enter the first polynomial order: ";
	cin >> order1;
	cout << "Enter the polynomial coefficients starting with higher power's coeff: \n";
	for (int i = 0; i <= order1; i++)
	{
		cout << "coeff of X^" << order1 - i << " = ";
		cin >> coeff1;
		p1.add_end(coeff1);
	}
	cout << "Enter the second polynomial order: ";
	cin >> order2;
	cout << "Enter the polynomial coefficients starting with higher power's coeff: \n";
	for (int i = 0; i <= order2; i++)
	{
		cout << "coeff of X^" << order2 - i << " = ";
		cin >> coeff2;
		p2.add_end(coeff2);
	}
	//Multiply code
	/////////////////////////////////////////////////////////////
	int *prod = new int[p1.size() + p2.size() + 1];
	for (int i = 0; i<p1.size() + p2.size() + 1; i++)
		prod[i] = 0;

	for (int i = 0; i< p1.size(); i++)
	{
		for (int j = 0; j < p2.size(); j++)
		{
			prod[i+j] += (p1.getNodeData(i+1) * p2.getNodeData(j+1));
		}
	}
	cout << "\nP[x] = "; int k;
	for ( k = 0; k < p1.size() + p2.size()-2 ; k++)
	{
		p3.add_end(prod[k]);
		cout << "("<<prod[k]<<")" << "x^" << p1.size() + p2.size() -2- k << " + ";
	}
	p3.add_end(prod[k]);
	cout << "(" << prod[k] << ")" << "\n\n";
	//////////////////////////////////////////////////////////////
};
void Differentiate(){
	list poly; int order, coeff, counter;    //counter is count down order
	cout << "Enter the polynomial order: ";
	cin >> order;
	cout << "Enter the polynomial coefficients starting with higher power's coeff: \n";
	for (int i = 0; i <= order; i++)
	{
		cout << "coeff of X^" << order - i << " = ";
		cin >> coeff;
		poly.add_end(coeff);
	}
	counter = order;
	for (int i = 1; i < poly.size(); i++)
	{
			poly.editNodeData(i, (poly.getNodeData(i)*counter));
		counter--;
	}
	poly.remove_end();
	order = order - 1;
	cout << "\nP[x] = "; int k;
	for (k = 0; k < poly.size()-1; k++)
	{
		cout << "(" << poly.getNodeData(k+1) << ")" << "x^" << poly.size()-1-k << " + ";
	}
	cout << "(" << poly.getNodeData(k + 1) << ")" << "\n\n";
};
int main(){

	/*list l;
	cout << "is the list empty? = " << l.isempty() << endl;
	cout << "\nsize of the list = " << l.size() << endl;

	for (int i = 1; i <= 10; i++)
		l.add_end(i);

	cout << "\nlist contains : ";
	for (int i = 1; i <= l.size(); i++)
		cout<<l.getNodeData(i)<<" ";
	cout << "\n";
	cout << "\nis the list empty? = " << l.isempty() << endl;
	cout << "\nsize of the list = " << l.size() << endl;
	cout << "\naverage of list = " << l.average() << endl;

	l.reverse_list();

	cout << "\nReversed list : ";
	for (int i = 1; i <= l.size(); i++)
		cout << l.getNodeData(i) << " ";    cout << "\n";

	l.add_mid(15, 5); l.add_mid(13, 1);  l.add_mid(20, 13); l.add_mid(25,15);

	cout << "\nRevlist after adding some nodes @some locations : ";
	for (int i = 1; i <= l.size(); i++)
		cout << l.getNodeData(i) << " ";
	cout << "\n";
	cout << "\nis the reversedlist empty? = " << l.isempty() << endl;
	cout << "\nsize of the reversedlist = " << l.size() << endl;
	cout << "\naverage of reversedlist = " << l.average() << "\n\n";*/

	 string operation;
	cout << "Enter required operation : ";
	cin >> operation;

	if (operation == "Evaluate")
		Evaluate();

	else if (operation == "Multiply")
		 Multiply();

	else if (operation == "Differentiate")
		Differentiate();

	system("pause");
	return 0;
}