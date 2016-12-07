// TrainReservation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

// struct Ticket {
// 	int train_number;
// 	int position;
// 	int price;
// };

// struct Train {
// 	string name;
// 	int train_number;
// 	Ticket tickets;
// 	int number_of_tickets;
// };

// struct Road {
// 	string start;
// 	string end;
// 	double duration_h;
// 	Train trains;
// };




// struct Node {
// 	Node* prev;
// 	Road value;
// 	Node* next;
// };

// class List {
// 	Node* head;
// 	int size;
// 	Node* last;

// public:
// 	List() {
// 		head = NULL;
// 		size = 0;
// 		last = NULL;
// 	}

// 	void insert(Road nw) {
// 		Node* temp = (Node*)malloc(sizeof(Node));
// 		if (head == NULL) {
// 			head = temp;
// 		}
// 		temp->value = nw;
// 		temp->next = NULL;
// 		if (last != NULL) {
// 			last->next = temp;
// 		}
// 		last = temp;
// 		size++;
// 	}
// };













//-----------------------------------------------------------TRAIN-----------------------------------------------------------


struct Compartments {
	int places;
	int price_for_place;
};

class Train{
    string from;
    string towards;
	int train_id;
	int number_of_compartments;
	Compartments cms[][];
	bool bar;

public:
	Train(int id, int n, bool i, string f, string t) {
		train_id = id;
		number_of_compartments = n;
		bar = i;
		from = f;
		towards = t;
	}

	void change_id(int new_id) {
		train_id = new_id;
	}

	void change_n_of_compartments(int new_n) {
		number_of_compartments = new_n;
	}

	void change_bar(bool new_i) {
		bar = new_i;
	}

	void change_cmsinfo(int num, int pr) {
		cms.places = num;
		cms.price_for_place = pr;
	}
	
	void change_start(string s){
	    from = s;
	}
	
	void change_destination(string d){
	    towards = d;
	}

    string get_start(){
        return from;
    }
    
    string get_destination(){
        return towards;
    }
    
	int get_id() {
		return train_id;
	}

	int get_n_of_compartments() {
		return number_of_compartments;
	}

	int get_cmsprice() {
		return cms.price_for_place;
	}

	int get_cmsplaces() {
		return cms.places;
	}

	bool get_bar() {
		if (bar == true) {
			return true;
		}
		else{false};
	}
};






//--------------------------------------------------------------TREE IMPLEMENTATION--------------------------------------------------




template <class T>
struct Node{
    Node* left;
    T value;
    Node* right;
};


template <class T>
class Tree{
    Node<T>* head;
    
    public:
    
    Tree(){
        head = NULL;
    }
    
    ~Tree(){
        head = NULL;
    }
    
    
    
    
    
    
    void inserthelper(Node<T>*& parent, Node<T>* newnode){
        if(parent==NULL){
            parent = newnode;
        }
        else if(parent->value > newnode->value){
            inserthelper(parent->left, newnode);
        }
        else{
            inserthelper(parent->right, newnode);
        }
    }
    
    void insert(T data){
        Node<T>* newnode = (Node<T>*) malloc(sizeof(Node<T>));
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->value = data;
        
        inserthelper(head, newnode);
    }
    
    
    
    
    
     void postorder_traversehelper(Node<T>* parent){
        if(parent!=NULL){
            postorder_traversehelper(parent->left);
            postorder_traversehelper(parent->right);
            cout<<parent->value<<endl;
        }else{
            return;
        }
    }
    
     void preorder_traversehelper(Node<T>* parent){
        if(parent!=NULL){
            
            cout<<parent->value<<endl;
            preorder_traversehelper(parent->left);
            preorder_traversehelper(parent->right);
        }else{
            return;
        }
    }
    
    void inorder_traversehelper(Node<T>* parent){
        if(parent!=NULL){
            inorder_traversehelper(parent->left);
            cout<<parent->value<<endl;
            inorder_traversehelper(parent->right);
        }else{
            return;
        }
    }
    
    void traverse(int ch){
        if(ch == 1){
            cout<<"In inorder_traverse"<<endl;
            inorder_traversehelper(head);
        }
        else if(ch == 2){
            cout<<"Postorder traverse"<<endl;
            postorder_traversehelper(head);
        }
        else if(ch == 3){
            cout<<"Preorder traverse"<<endl;
            preorder_traversehelper(head);
        }
        else{
            cout<<"PROBLEM";
        }
    }
    
    
    
    
    
    
    bool searchhelper(Node<T>* parent, T val){
        if(parent!=NULL){
            if(parent->value > val){
                if(searchhelper(parent->left, val)){return true; cout<<"True left";};
            }
            else if(parent->value < val){
                if(searchhelper(parent->right, val)){return true; cout<<"True right";};
            }
            else if(parent->value = val){
                return true;
            }
            else{
                return false;
            };
        }
        else{
            return false;
        }
    }
    
    bool search(T val){
        if(searchhelper(head, val)){
            return true;
        }
        return false;
    }
    
    
    
    
    
    bool removehelper(Node<T>*& parent, T val){
        if(parent->value > val){
            removehelper(parent->left, val);
        }
        else if(parent->value < val){
            removehelper(parent->right, val);
        }
        else if(parent->value = val){
            if(parent->left == NULL && parent->right == NULL){
                parent = NULL;
                cout<<"Removed!"<<endl;
            }
            else{
                cout<<"The value is not a leaf!!"<<endl;
            }
        }
        else{
            return 0;
        }
    }
    
    void removenode(T val){
        cout<<"inside remove"<<endl;
        if(search(val)){
            cout<<"search of the value is true"<<endl;
            removehelper(head, val);
        }
        else{
            cout<<"search of the value is false"<<endl;
            cout<<"There is no such value."<<endl;
        }
    }
    
    
    
    
    int count(Node<T>* parent){
        if(parent == NULL){
            return 0;
        }
        else{
            int left=1;
            int right=1;
            
            left = left + count(parent->left);
            right = right + count(parent->right);
            
            if(left>right){
                return left;
            }
            else{
                return right;
            }
        }
    }
    
    int get_height(){
        return count(head);
    }
};








//----------------------------------------------------------------USER && ADMIN -----------------------------------------------------------



struct User {
	string name;
	string surname;
	string passport_id;
	string Address;
	int phone_number;
};

int place_price(int train_id, int place) {
	return 0;
}

void admin() {
	int c = 0;
	while (c != 3) {
		cout << endl << "~~~///  Menu for admin  \\\~~~" << endl;
		cout << "Choose    -  1 : Add new train,      2 : Change train details,     3 : End";
		cin >> c;
		switch (c) {
			case 1: {
			    string starting_p, ending_p;
			    int ID, num_comp;
			    bool bar;
			    
                cout<<"Insert following details about new train."<<endl<<"ID: ";
                cin>>ID;
                cout<<endl<<"Number of compartments: ";
                cin>>num_comp;
                cout<<endl<<"Bar existance(if yes->1, no->0): ";
                cin>>bar;
                cout<<endl<<"Starting point: ";
                cin>>starting_p;
                cout<<endl<<"Ending Point: ";
                cin>>ending_p;
                
                
                
                
				break;
			}
			case 2: {

			}
		}
	}
}





int main()
{
	int c=0;
	cout << "Train reservation center." << endl <<endl;
	while (c != 3) {
		cout << endl <<"~~~~~~~Main Menu~~~~~~~~~~"<< endl << "Choose   -   1 : Admin,       2 : User,     3 : End" << endl << "Your choice: ";
		cin >> c;
		cout << endl;
		switch (c) {
		case 1: {
			string pass;
			cout << "Enter password: ";
			cin >> pass;
			if (pass == "778k") {
				//admin();
			}
			else {
				cout << "Your password is not correct." << endl;
			};
			break;
		}
		case 2: {
			//user();
			break;
		}
		default:
			break;
		}
	}
}

