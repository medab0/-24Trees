#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Node {
	Node* parent;
	int size;
	int* data;
	Node** children;
	
	public:
		Node (int num, Node* parent) {
			data = (int*) malloc (sizeof(int) * 4);
			data[0] = num;
			size = 1;	
			
			children = (Node**) calloc (sizeof(Node*) , 5);
			this -> parent = parent;
		}
		
		int getSize() {
			return size;
		}
		
		int getData(int i) {
			return data[i];
		}
		
		Node* getChild(int i) {
			return children[i];
		}
		
		void setChildren(Node* wp, Node* w2p, int pos) {
			for (int i = size; i >= pos; i--){
				children[i+1] = children[i];
			}
			children[pos] = wp;
			children[pos + 1] = w2p;
		}
		
		int indexOf(Node* child) {
			for (int i = 0; i <= size; i++) {
				if (child == children[i]){
					return i;
				}
			}
			return -1; // should not work
		}
		
		Node* getParent() {
			return parent;
		}
		
		bool addKey (int num) {
//			return true if it didnt overflow
//			overflows after 4 
			int i;
			for (i = size; i > 0; i--) {
				if (data[i-1] > num) {
					data[i] = data [i-1];
				} else {
					break;
				}
			}
			data[i] = num;
			return ++size != 4;
		}
		
		void print () {
			 print("", this);
		}
		
		void print (string prefix, Node* n) {
			if (!n) {
				return;
			}
			cout << prefix;
			for(int i = 0; i < n->size; i++) {
				cout << n->data[i] << " ";
			}
			cout << endl;
			
			for (int i = 0; i < n->size+1; i++) {
				print (prefix + "--" + ": ", n->children[i]);
			}
		}
		
};
