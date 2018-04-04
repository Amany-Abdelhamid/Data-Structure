#include"list.h"
#include<iostream>
#include<string>
#include<math.h>

class poly{
	list l;
public:
	poly(list p);
	int Evaluate(int num);
	string Multiply(poly *p);
	string differentiate();
};

poly::poly(list p){
	l = p;
}

int poly::Evaluate(int num){
	int sum = 0; int order = l.size()-1;
	for (int i = 0; i <= order; i++)
		sum += (l.getNodeData(i + 1)*pow(num, order - i));
	return sum;
}

string poly::Multiply(poly *p){
	list l1;  string s; 
	int *prod = new int[p->l.size() + l.size() + 1];
	for (int i = 0; i<p->l.size() + l.size() + 1; i++)
		prod[i] = 0;

	for (int i = 0; i< p->l.size(); i++)
	{
		for (int j = 0; j < l.size(); j++)
		{
			prod[i + j] += (p->l.getNodeData(i + 1) * l.getNodeData(j + 1));
		}
	}
	int k; s = "P[x] = ";
	for (k = 0; k < p->l.size() + l.size() - 2; k++)
	{
		l1.add_end(prod[k]);
		s = s + "(" + std::to_string(prod[k]) + ")" + "x^" + std::to_string(p->l.size() + l.size() - 2 - k) + " + ";
	}
	l1. add_end(prod[k]);
	s = s + "(" + std::to_string(prod[k]) + ")" + "\n\n";
	return s;
}

string poly::differentiate(){
	list p; string st;
	int order = l.size() - 1;     int counter = order;
	for (int i = 1; i < l.size()-1; i++)
	{
		p.add_end(l.getNodeData(i)*counter);
		counter--;
	}
	int k; st = "P[x] = ";
	for (k = 1; k <= p.size()-1; k++)
	{
		st = st + "(" + std::to_string(p.getNodeData(k)) + ")" + "x^" + std::to_string(p.size()-k) + " + ";
	}
	st = st + "(" + std::to_string(p.getNodeData(k)) + ")" + "\n\n";
	return st;
}

