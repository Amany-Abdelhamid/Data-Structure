#include <iostream>
#include <string>

using namespace std;

class node {

	//every node has a next pointer and a down pointer

	int data; //room id
	int startdate;
	int enddate;
	string name;
	int period;
	node * next;
	node * down;

public: node() { data = 0; next = NULL; down = NULL; }
		node(int d) { data = d; next = NULL; down = NULL; }
		node(int d, string n, int p, int s, int e){ data = d; next = NULL; down = NULL; period = p; name = n; startdate = s; enddate = e; }
		node(int d, string n, int p, int s){ data = d; next = NULL; down = NULL; period = p; name = n; startdate = s; }
		int getData() { return data; }
		void setData(int d) { data = d; }
		node * getNext() { return next; }
		void setNext(node * n) { next = n; }
		node * getDown() { return down; }
		void setDown(node * D) { down = D; }
		int getstartdate() { return startdate; }
		void setstartdate(int d) { startdate = d; }
		int getenddate() { return enddate; }
		void setenddate(int d) { enddate = d; }
		string getname() { return name; }
		void setname(string d) { name = d; }
		int getperiod() { return period; }
		void setperiod(int d) { period = d; }

};
class list {

	//chain is the horizontal head chain2 is any vertical head

	node * chain;
	node * chain2;

	//2 chains are needed


public:  list(){ chain = NULL; chain2 = NULL; };
		 list(int d){ chain = new node(d); chain2 = chain; }
		 list(int d, string n, int p, int s, int e){ chain = new node(d, n, p, s, e); chain2 = chain; }
		 list(int d, string n, int p, int s){ chain = new node(d, n, p, s); chain2 = chain; }
		 //initially both heads are the same head


		 //////////////////////////////////////////////////////

		 void printallnext() //prints the first row id
		 {
			 node *p = chain;
			 while (p != NULL)
			 {
				 cout <<"Room Id = " <<p->getData() << "\n";
				 cout << "Name = " << p->getname() << "\n";
				 cout << "Start date is " << p->getstartdate() << "\n";
				 cout << "Preiod (in days) = " << p->getperiod() << "\n";
				 p = p->getNext();
				 // or p=p->next;
			 }
		 }

		 void printalldown(node * c) //prints any vertical coloumn id
		 {
			 node *p = c;
			 while (p != NULL)
			 {
				 cout << p->getData() << "\t";
				 p = p->getDown();

			 }
		 }
		 //////////////

		 void printallnextperiod() //prints the first row id
		 {
			 node *p = chain;
			 while (p != NULL)
			 {
				 cout << p->getperiod() << "\t";
				 p = p->getNext();
				 // or p=p->next;
			 }
		 }

		 void printalldownperiod(node * c) //prints any vertical coloumn id
		 {
			 node *p = c;
			 while (p != NULL)
			 {
				 cout << p->getperiod() << "\t";
				 p = p->getDown();

			 }
		 }
		 /////////////////

		 void printallnextSTART() //prints the first row id
		 {
			 node *p = chain;
			 while (p != NULL)
			 {
				 cout << p->getstartdate() << "\t";
				 p = p->getNext();
				 // or p=p->next;
			 }
		 }

		 void printalldownSTART(node * c) //prints any vertical coloumn id
		 {
			 node *p = c;
			 while (p != NULL)
			 {
				 cout << p->getstartdate() << "\t";
				 p = p->getDown();

			 }
		 }
		 ///////////////

		 void printallnextEnd() //prints the first row id
		 {
			 node *p = chain;
			 while (p != NULL)
			 {
				 cout << p->getenddate() << "\t";
				 p = p->getNext();
				 // or p=p->next;
			 }
		 }

		 void printalldownEnd(node * c) //prints any vertical coloumn id
		 {
			 node *p = c;
			 while (p != NULL)
			 {
				 cout << p->getenddate() << "\t";
				 p = p->getDown();

			 }
		 }
		 //////////

		 void printallnextName() //prints the first row id
		 {
			 node *p = chain;
			 while (p != NULL)
			 {
				 cout << p->getname() << "\t";
				 p = p->getNext();
				 // or p=p->next;
			 }
		 }

		 void printalldownName(node * c) //prints any vertical coloumn id
		 {
			 node *p = c;
			 while (p != NULL)
			 {
				 cout << p->getname() << "\t";
				 p = p->getDown();

			 }
		 }

		 //////////////////////////////////////////////////////

		 node* getChain(){ return chain; } //returns first element of first row
		 node* getChain2(){ return chain2; } //returns first element of any coloumn
		 void setChain2(node * c){ chain2 = c; } // very important function used if you want to point to a certain coloumn

		 //////////////////////////////////////////////////////

		 bool isEmpty(){
			 if (chain == NULL){ return true; }
			 else { return false; }
		 }

		 ///////////////////////////////////////////////////////
		 void addFront(int item) // add at front bt5le el node el gdeda abl el chain fel first row
		 {
			 node * temp = new node(item);
			 temp->setNext(chain);
			 chain = temp;
			 // or temp->next=chain; chain =temp;
		 }


		 void addUp(int item) // add at front bt5le el node el gdeda fo2 el head bta3 a specific coloumn so you  must set chain2 each time before using it
		 {
			 node * temp = new node(item);
			 temp->setDown(chain2);
			 chain2 = temp;

		 }
		 /////////////////
		 void addFrontall(int item, string n, int sd, int ed, int p) // add at front bt5le el node el gdeda abl el chain fel first row
		 {
			 node * temp = new node(item, n, p, sd, ed);
			 temp->setNext(chain);
			 chain = temp;


			 // or temp->next=chain; chain =temp;
		 }


		 void addUpall(int item, string n, int sd, int ed, int p) // add at front bt5le el node el gdeda fo2 el head bta3 a specific coloumn so you  must set chain2 each time before using it
		 {
			 node * temp = new node(item, n, p, sd, ed);
			 temp->setDown(chain2);
			 chain2 = temp;

		 }

		 ///////////////////////////////////////////////////////////


		 void addEnd(int item) //add item to the end of the first row
		 {
			 node * temp = chain;
			 if (chain == NULL) chain = new node(item);
			 else {
				 for (; temp->getNext() != NULL; temp = temp->getNext())
					 ;
				 temp->setNext(new node(item));
			 }
		 }

		 void addDown(int item) //add item to the end of a specific coloumn so set chain2 before using it
		 {
			 node * temp = chain2;
			 if (chain2 == NULL) chain2 = new node(item);
			 else {
				 for (; temp->getDown() != NULL; temp = temp->getDown())
					 ;
				 temp->setDown(new node(item));
			 }
		 }

		 //////////////////
		 void addEndall(int item, string n, int p, int sd) //ok //add item to the end of the first row
		 {
			 node * temp = chain;
			 if (chain == NULL) chain = new node(item, n, p, sd);
			 else {
				 for (; temp->getNext() != NULL; temp = temp->getNext())
					 ;
				 temp->setNext(new node(item, n, p, sd));
			 }
		 }
		

		 void addDownall(int item, string n, int sd, int ed, int p) //ok //add item to the end of a specific coloumn so set chain2 before using it
		 {
			 node * temp = chain2;
			 if (chain2 == NULL) chain2 = new node(item, n, p, sd, ed);
			 else {
				 for (; temp->getDown() != NULL; temp = temp->getDown())
					 ;
				 temp->setDown(new node(item, n, p, sd, ed));
			 }
		 }
		 //////////////////
		 //////////////////////////////////////////////////////
		 void add_horizontally(int item, int index) //adds item to the first row
		 {
			 if (isEmpty()){ addFront(item); }
			 else if (index == 0){
				 addFront(item);
				 return;
			 }
			 node* A = chain;
			 while (--index != 0){
				 A = A->getNext();
				 if (A == NULL){ return; }
			 }
			 node * now = new node(item);
			 now->setNext(A->getNext());
			 A->setNext(now);
			 //node * sd;
			 //sd= A->getNext();
			 //now->setNext(sd);
			 //A->getNext()= now;
		 }

		 void add_vertically(int item, int index) //adds item to a specific coloumn so set chain2 first before using it
		 {
			 if (isEmpty()){ addUp(item); }
			 else if (index == 0){
				 addUp(item);
				 return;
			 }
			 node* A = chain2;
			 while (--index != 0){
				 A = A->getDown();
				 if (A == NULL){ return; }
			 }
			 node * now = new node(item);
			 now->setDown(A->getDown());
			 A->setDown(now);
		 }

		 ////////////////
		 void add_horizontallyall(int item, string n, int sd, int ed, int p, int index) //adds item to the first row //ok
		 {
			 if (isEmpty()){ addFrontall(item, n, p, sd, ed); }
			 else if (index == 0){
				 addFrontall(item, n, p, sd, ed);
				 return;
			 }
			 node* A = chain;
			 while (--index != 0){
				 A = A->getNext();
				 if (A == NULL){ return; }
			 }
			 node * now = new node(item, n, p, sd, ed);
			 now->setNext(A->getNext());
			 A->setNext(now);
			 //node * sd;
			 //sd= A->getNext();
			 //now->setNext(sd);
			 //A->getNext()= now;
		 }

		 void add_verticallyall(int item, string n, int sd, int ed, int p, int index) //ok //adds item to a specific coloumn so set chain2 first before using it
		 {
			 if (isEmpty()){ addUpall(item, n, p, sd, ed); }
			 else if (index == 0){
				 addUpall(item, n, p, sd, ed);
				 return;
			 }
			 node* A = chain2;
			 while (--index != 0){
				 A = A->getDown();
				 if (A == NULL){ return; }
			 }
			 node * now = new node(item, n, p, sd, ed);
			 now->setDown(A->getDown());
			 A->setDown(now);
		 }

		 //////////////////////////////////////////////////////
		 int getSize_horizontally(){ //gets size of first row
			 if (isEmpty()){ return 0; }
			 else{
				 int size = 1;
				 node* A = chain;
				 while ((A->getNext()) != NULL){
					 size++;
					 A = A->getNext();

				 }
				 return size;
			 }
		 }

		 int getSize_vertically(){ //gets size of a specific coloumn so set chain2 before using it
			 if (isEmpty()){ return 0; }
			 else{
				 int size = 1;
				 node* A = chain2;
				 while ((A->getDown()) != NULL){
					 size++;
					 A = A->getDown();

				 }
				 return size;
			 }
		 }


};


