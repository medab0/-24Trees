#include "node.h"
#include <iostream>

using namespace std;
class Tree24{
	Node* root;
	int size;
	
	public :
		Tree24() {
			root = NULL;
			size = 0;
		}
		
		Node* search (int num) {
			return search(num, root);
		} 
		
		Node* search (int num, Node* n) {
			if (!n) {
				return NULL;
			}
			for (int i = 0; i < n->getSize(); i++) {
				if (num == n->getData(i)) {
					return n;
				}
			}
			int k0 = INT_MIN;
			int kd = INT_MAX;
			Node* res;
			
			if (k0 < num && num < n->getData(0)) {
				res = search(num, n->getChild(0));
			}
			
			for (int i = 1; i < n->getSize()-1; i++) {
				if (n->getData(i) < num && num < n->getData(i+1)) {
					 res = search(num, n->getChild(i));
				} 
			}
			if (n->getData(n->getSize()-1) < num && num < kd) {
				res = search(num, n->getChild(n->getSize()-1));
			}
			
			if(res == NULL) {
				return n;
			}
			return res;
		}
		
		Node* insert(int num) {
			if (!root) {
				root = new Node(num, NULL);
				size++;
				return root;
			}
			Node* res = search(num);
			bool ok = res->addKey(num);
			size++;
			if (!ok) {
				Node* u;
				int pos;
				if (res == root) {
					u = new Node (res->getData(2), NULL);
					root = u;
					pos = 0;
				} else {
					u = res->getParent();
					pos = u->indexOf(res);
				}
				
				Node* wp = new Node (res->getData(0), u);
				wp->addKey(res->getData(1));
				Node* w2p = new Node (res->getData(3), u);
				u->setChildren(wp, w2p, pos);
			}
			return res;
		}
		
		void print() {
			cout << "Size: " << size << endl;
			root -> print();
		}
	
};
