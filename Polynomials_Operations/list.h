#include"node.h"
#include<iostream>

class list
{
	node * chain; 
public: 
	list();
void add_end(int item);     //add at end
void add_mid(int item,int index);     //add at middle ;index is location of node will be added
bool isempty();
int size();
void reverse_list();
float average();
int getNodeData(int x);
void editNodeData(int index,int data);
void remove_end();
friend class poly;
};

list::list() :chain(NULL){}

void list::add_end(int item){
	node * temp = chain;
	if (chain == NULL) chain = new node(item);
	else
	{
		for (; temp->next!= NULL; temp = temp->next);
		temp->next = new node(item);
	}
}

void list::add_mid(int item,int index){
	node * temp = chain; node * temp2; int i;
	if (index == 1)
	{
		temp = new node(item);
		temp->next = chain;
		chain = temp;
	}
	else if (index > 1)
	{
		for ( i = 1; i < index - 1 && temp->next != NULL; i++)
			temp = temp->next;
		if ((index - i) == 1)
		{
			if (temp->next == NULL)
				temp->next = new node(item);
			else
			{
				temp2 = new node(item);
				temp2->next = temp->next;
				temp->next = temp2;
			}
		}
	}

}

bool list::isempty(){
	return chain == NULL;
}

int list::size(){
	node * temp = chain;  int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void list::reverse_list(){
	node * temp1 = NULL, *temp2 = chain, *temp3 = chain->next;
	while (temp3->next != NULL)
	{
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = temp3->next;
	}
	temp2->next = temp1;
	temp3->next = temp2;
	chain = temp3;
}

float list::average(){
	node * temp = chain;
	int sum = 0, num = 0;
	while (temp->next != NULL)
	{
		sum = sum + temp->data;
		temp = temp->next;
		num++;
	}
	sum = sum + temp->data;
	num++;
	return (float)sum / num;
}

int list::getNodeData(int x){
	if (x == 1) { if (chain == NULL) return 0; else return chain->data; }
	if (x > 1){
		node * temp = chain;
		for (int i = 1; i<x && temp != NULL; i++)
			temp = temp->next;
		if (temp == NULL) return 0;
		else
			return temp->data;
	}
	if (x<1) return 0;
} //return data of node x at list

void list::editNodeData(int index,int data){
	if (index == 1) { chain->data=data; }
	if (index > 1){
		node * temp = chain;
		for (int i = 1; i<index && temp != NULL; i++)
			temp = temp->next;
		if (temp == NULL) return;
		else
			temp->data = data;
	}
	if (index < 1) return;
}

void list::remove_end(){
	node * temp = chain, *temp2 = chain->next;
	while (temp2->next != NULL)
	{
		temp = temp->next;
		temp2 = temp2->next;
	}
	temp->next = NULL;
}