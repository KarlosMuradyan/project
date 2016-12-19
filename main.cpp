#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;




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
	Compartments cms;
	bool bar;

public:
	Train() {
		from = "NO";
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
		false;
	}
};








//---------------------------------------------------------------



bool ToBool( const string & s ) {
   return s.at(0) == '1';
}
//------------------------------------------------READ && WRITE ----------------------------------------------





bool append(string k){
    ofstream outfile;
    
    outfile.open("text.txt", ios_base::app);
    outfile<< k<<endl;
    return true;
}

vector<Train>* read(vector<Train>* trains1){
    
    
    cout<<"asdasd";
    ifstream file("text.txt");
    string str;
    vector<Train> trains(5);
    int i=0;
    while (getline(file, str))
    {
        string v[5];
        int j=0;

        istringstream iss(str);
        cout<<str<<endl;
        string s;
        if(str.length() > 5){
            while ( getline( iss, s, ' ' ) ) {
                v[j] = s;
                j++;
            }
            int id = stoi(v[0]);
            int numc = stoi(v[3]);
            bool b = ToBool(v[4]);
            string four = v[1];
            string five = v[2];
            trains[i].change_start(four);
            trains[i].change_destination(five);
            trains[i].change_id(id);
            trains[i].change_bar(b);
            trains[i].change_n_of_compartments(numc);
        }
        i++;
    }  
    
    vector<Train>* ad = &trains;
    cout<<"firstttt    ";
    trains1 = &trains;
    cout<<ad<<endl<<"Trains1 = "<<trains1<<endl;
    return ad;
}


// void rr(vector<Train>* a){
//     int number_of_lines = 0;
//     std::string line;
//     std::ifstream myfile("text.txt");

//     while (std::getline(myfile, line))
//         ++number_of_lines;
    
//     a.resize(number_of_lines);
//     read(a);
// }






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
	while (c != 4) {
		cout << endl << "~~~///  Menu for admin  \\\~~~" << endl;
		cout << "Choose    -  1 : Add new train,      2 : Remove train,     3 : Print List,       4:End "<<endl<<"Your choice: ";  //Print list
		cin >> c;
		switch (c) {
			case 1: {              //New Train
			    string starting_p, ending_p;
			    int Ids, num_comp;
			    bool bar;
			    
                cout<<"Insert following details about new train."<<endl<<"ID: ";
                cin>>Ids;
                cout<<endl<<"Number of compartments: ";
                cin>>num_comp;
                cout<<endl<<"Bar existance(if yes->1, no->0): ";
                cin>>bar;
                cout<<endl<<"Starting point: ";
                cin>>starting_p;
                cout<<endl<<"Ending Point: ";
                cin>>ending_p;
                
                
                string wr = to_string(Ids) +  " " + starting_p + " " + ending_p + " " + to_string(num_comp) + " " + to_string(bar);
                
                append(wr);
                
				break;
				
				
			}
			case 2: {
			    vector<Train> a(5);
			    read(*&a);
			    
			    cout<<setw(5)<< "N" <<setw(15)<<"ID" << setw(15)<< "from" << setw(15) << "to" << setw(15) << "Number of Comp" << setw(15) << "Has bar"<<ednl;
			    
			    for(int i=0; i<a.size(); i++){
			        cout<<stew(5)<< i+1 << setw(15)<< a[i].get_id() << setw(15)<< a[i].get_from() << setw(15) << a[i].get_destination() << setw(15) << a[i].get_n_of_compartments << setw(15) << a[i].get_bar()<<endl;
			    }
			    int ind;
			    cout<<"Which train you want to remove. Give the index: ";
                cin>>ind;
                
                for(int i=ind-1; i<a.size()-1; i++){
                    a[i] = a[i+1];
                }
                a.resize(a.size()-1);
                
                cout<<"Deleted!"<<endl;
                
                break;
                // cout<<endl<<"First"<<a[0].get_start();
			}
			
			case 3:{
			    vector<Train> a(5);
			    read(*&a);
			    
			    cout<<setw(5)<< "N" <<setw(15)<<"ID" << setw(15)<< "from" << setw(15) << "to" << setw(15) << "Number of Comp" << setw(15) << "Has bar"<<ednl;
			    
			    for(int i=0; i<a.size(); i++){
			        cout<<stew(5)<< i+1 << setw(15)<< a[i].get_id() << setw(15)<< a[i].get_from() << setw(15) << a[i].get_destination() << setw(15) << a[i].get_n_of_compartments << setw(15) << a[i].get_bar()<<endl;
			    }
			    
			    break;
			}
			
			default:{
			    break;
			}
			
			
		}
	}
}





void user(){

    int c=0;
    cout<<"                  User Menu    ";
    while(c!=3){
        cout<<"Choose:         1: Reserve Train        2: See the list      3:End";
        cin<<c;
        
        vector<Train> a(5);
	    read(*&a);
        
        swich(c){
            case 1:{
                int c1;
                cout<<"Reserving Train:"<<endl;
                cout<<"Choose:       1:Reserve by ID      2: Search by starting point     3: Search by destination     4:End"<<endl;
                cin>>c1;
                swich(c1){
                    case 1:{
                        int res_id;
                        cout<<"Enter ID: ";
                        cin>>res_id;
                        
                        string f_name, s_name, addr, passp;
                        int ph_number;
                        
                        cout<<"Enter your personal information:"<<endl<<"First name: ";
                        cin>>f_name;
                        cout<<"Last Name: ";
                        cin>>s_name;
                        cout<<"Pasport ID: ";
                        cin>>passp;
                        cout<<"Address: ";
                        cin>>addr;
                        cout<<"Phone Number: ";
                        cin>>ph_number;
                        
                        
                        
                        
                        //--------------------------------------------------------------------------------------------???????????????????????????????????????????????
                        
                        
                        
                    } 
                    
                    case 2:{
                        string res_start;
                        cout<<"Enter the starting point of the train: ";
                        cin>>res_start;
                        cout<<setw(15)<<"ID" << setw(15)<< "from" << setw(15) << "to" << setw(15) << "Number of Comp" << setw(15) << "Has bar"<<ednl;
                        
                        for(int i=0; i<a.size(); i++){
                            if(a[i].get_start == res_start){
                                cout<< setw(15)<< a[i].get_id() << setw(15)<< a[i].get_from() << setw(15) << a[i].get_destination() << setw(15) << a[i].get_n_of_compartments << setw(15) << a[i].get_bar()<<endl;
                            }
                        }
                        
                        break;
                    
                    }
                    
                    case 3:{
                        string res_dest;
                        cout<<"Enter the destination of the train: ";
                        cin>>res_dest;
                        cout<<setw(15)<<"ID" << setw(15)<< "from" << setw(15) << "to" << setw(15) << "Number of Comp" << setw(15) << "Has bar"<<ednl;
                        
                        for(int i=0; i<a.size(); i++){
                            if(a[i].get_start == res_dest){
                                cout<< setw(15)<< a[i].get_id() << setw(15)<< a[i].get_from() << setw(15) << a[i].get_destination() << setw(15) << a[i].get_n_of_compartments << setw(15) << a[i].get_bar()<<endl;
                            }
                        }
                        
                        break;
                    }
                    
                    default:{
                        break;
                    }
                }
            }
            
            case 2:{
                cout<<setw(5)<< "N" <<setw(15)<<"ID" << setw(15)<< "from" << setw(15) << "to" << setw(15) << "Number of Comp" << setw(15) << "Has bar"<<ednl;
			    
			    for(int i=0; i<a.size(); i++){
			        cout<<stew(5)<< i+1 << setw(15)<< a[i].get_id() << setw(15)<< a[i].get_from() << setw(15) << a[i].get_destination() << setw(15) << a[i].get_n_of_compartments << setw(15) << a[i].get_bar()<<endl;
			    }
            }
            
            default:{
                break;
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
		case 1: {                           //Admin
			string pass;
			cout << "Enter password: ";
			cin >> pass;
			if (pass == "778k") {
				admin();
			}
			else {
				cout << "Your password is not correct." << endl;
			};
			break;
		}
		case 2: {                           //User
			//user();
			break;
		}
		default:
			break;
		}
	}
}
