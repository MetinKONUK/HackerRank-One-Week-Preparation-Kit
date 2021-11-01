#include <iostream>
using namespace std;
#include<string>;
#include<vector>;
#include<map>;
// Each polynomial node consists of a coefficient and an exponent
struct PolyNode {
	double coef;             // Coefficient
	int exp;                 // Exponent
	struct PolyNode* next;   // Next polynomial node
}; //end-PolyNode

void list_elements(PolyNode* poly) {
	PolyNode* node = poly;
	int i = 0;
	while (node != NULL) {
		cout << node->coef << "," << node->exp << "   ";
		node = node->next;
		i += 1;
	}
}
void sortList(PolyNode* first) {
	PolyNode* head = first;
	// Node current will point to head
	struct PolyNode* current = head, * index = NULL;
	int temp;
	if (head == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			// Node index will point o node next to current
			index = current->next;
			while (index != NULL) {
				//If current node's data is greater than index's node
				//data, swap the data between them
				if (current->exp < index->exp) {
					temp = current->exp;
					current->exp = index->exp;
					index->exp = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void Print(PolyNode *poly) {
	PolyNode* node = poly;
	if (node == NULL) {
		cout << "<NULL>";
	}
	cout << "<";
	bool first = false;
	while (node != NULL) {
		double coef = node->coef;
		int exp = node->exp;
		if (coef > 0 && first) {
			cout << "+";
		}
		if (!first) {
		first = true;
		}
		if (coef == -1) {
			cout << "-";
		}
		if (coef != 1 && coef != -1) {
		cout << coef;
		}
		if (exp != 0) {
			cout << "x";
		}
		if (exp != 1 && exp != 0) {
			cout << "^" << exp;
		}
		node = node->next;
	}
	cout << ">";
}
double Evaluate(PolyNode *poly, double x) {
	PolyNode* node = poly;
	double result = 0;
	while (node != NULL)
	{
		int exp = node->exp;
		double coef = node->coef;
		result += (coef * pow(x, exp));
		node = node->next;
	}
	return result;
}
PolyNode *Derivative(PolyNode* poly) { // original pointer
	PolyNode *copy_poly = poly, *head = new PolyNode(), * copy_head = head;
	while (true) {
		double d_coef = copy_poly->coef * copy_poly->exp;
		int d_exp = copy_poly->exp - 1;

		copy_head->next = new PolyNode();

		copy_head->coef = d_coef;
		copy_head->exp = d_exp;

		if (copy_poly->next == NULL || (copy_poly->next->coef * copy_poly->next->exp) == 0) {
			copy_head->next = NULL;
			break;
		}

		copy_head = copy_head->next;
		copy_poly = copy_poly->next;
	}
	return head;
}
PolyNode *Add(PolyNode* poly1, PolyNode* poly2) {
	PolyNode *node1 = poly1, *node2 = poly2, *head = new PolyNode(), *copy = head, *xhead = new PolyNode(), *xcopy = xhead;
	vector<PolyNode*>ads;
	/*
	FIND THE TERMS WITH SAME EXPONENT IN BOTH POLYNOMS
	AND ADD THEM TO COPY-HEAD LINKED LIST
	AND PUSH THEIR ADDRESSES TO VECTOR
	*/
	while (node1 != NULL) {
		node2 = poly2;
		while (node2 != NULL) {
			if (node1->exp == node2->exp) {
			ads.push_back(node1);ads.push_back(node2);
			int exp = node1->exp;
			double coef = node1->coef + node2->coef;
			copy->exp = exp;
			copy->coef = coef;
			copy->next = new PolyNode();
			copy = copy->next;
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	// LINK COPY-HEAD LINKED LIST'S LAST NODE TO NULL
	copy = head;
	while (copy != NULL) {
		if (copy->next->coef == 0) {
			copy->next = NULL;
			break;
		}
		copy = copy->next;
	}

	copy = head;
	node1 = poly1;
	node2 = poly2;

	/*
	TRANSFER NODES OF COPY-HEAD LINKED LIST TO XCOPY-HEAD LINKED LIST
	THESE ARE THE SUMMED UP NODES
	*/
	while (copy != NULL) {
		xcopy->coef = copy->coef;
		xcopy->exp = copy->exp;

		copy = copy->next;
		xcopy->next = new PolyNode();
		xcopy = xcopy->next;
	}

	/*
		FIND THE NODES WITH UNIQUE EXPONENTS AND ADD THEM TO XCOPY-HEAD LINKED LIST
		IN BOTH LINKED-LISTS (NODE1-HEAD AND NODE2-HEAD LINKED LIST)
	*/
	while (node1 != NULL) {
		bool isin = false;
		for (int i = 0; i < ads.size(); i++) {
			if (ads[i] == node1) {
				isin = true;
			}
		}
		if (!isin) {
			xcopy->coef = node1->coef;
			xcopy->exp = node1->exp;
			xcopy->next = new PolyNode();
			xcopy = xcopy->next;
		}
		node1 = node1->next;
	}
	while (node2 != NULL) {
		bool isin = false;
		for (int i = 0; i < ads.size(); i++) {
			if (ads[i] == node2) {
				isin = true;
			}
		}
		if (!isin) {
			xcopy->coef = node2->coef;
			xcopy->exp = node2->exp;
			xcopy->next = new PolyNode();
			xcopy = xcopy->next;
		}
		node2 = node2->next;
	}
	// LINK XCOPY-HEAD LINKED LIST'S LAST NODE TO NULL
	xcopy = xhead;
	while (xcopy != NULL) {
		if (xcopy->next->coef == 0) {
			xcopy->next = NULL;
			break;
		}
		xcopy = xcopy->next;
	}
	sortList(xhead);
	//RETURN THE POINTER WHICH IS POINTING TO THE SUMMED UP POLYNOM'S HEAD(XHEAD)
	return xhead;
}
PolyNode *Substract(PolyNode* poly1, PolyNode* poly2) {
	PolyNode* node1 = poly1, * node2 = poly2, * head = new PolyNode(), * copy = head, * xhead = new PolyNode(), * xcopy = xhead;
	vector<PolyNode*>ads;
	/*
	FIND THE TERMS WITH SAME EXPONENT IN BOTH POLYNOMS
	AND ADD THEM TO COPY-HEAD LINKED LIST
	AND PUSH THEIR ADDRESSES TO VECTOR
	*/
	while (node1 != NULL) {
		node2 = poly2;
		while (node2 != NULL) {
			if (node1->exp == node2->exp) {
				ads.push_back(node1); ads.push_back(node2);
				int exp = node1->exp;
				double coef = node2->coef - node1->coef;
				copy->exp = exp;
				copy->coef = coef;
				copy->next = new PolyNode();
				copy = copy->next;
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	// LINK COPY-HEAD LINKED LIST'S LAST NODE TO NULL
	copy = head;
	while (copy != NULL) {
		if (copy->next->coef == 0) {
			copy->next = NULL;
			break;
		}
		copy = copy->next;
	}

	copy = head;
	node1 = poly1;
	node2 = poly2;

	/*
	TRANSFER NODES OF COPY-HEAD LINKED LIST TO XCOPY-HEAD LINKED LIST
	THESE ARE THE SUMMED UP NODES
	*/
	while (copy != NULL) {
		xcopy->coef = copy->coef;
		xcopy->exp = copy->exp;

		copy = copy->next;
		xcopy->next = new PolyNode();
		xcopy = xcopy->next;
	}

	/*
		FIND THE NODES WITH UNIQUE EXPONENTS AND ADD THEM TO XCOPY-HEAD LINKED LIST
		IN BOTH LINKED-LISTS (NODE1-HEAD AND NODE2-HEAD LINKED LIST)
	*/
	while (node1 != NULL) {
		bool isin = false;
		for (int i = 0; i < ads.size(); i++) {
			if (ads[i] == node1) {
				isin = true;
			}
		}
		if (!isin) {
			xcopy->coef = node1->coef;
			xcopy->exp = node1->exp;
			xcopy->next = new PolyNode();
			xcopy = xcopy->next;
		}
		node1 = node1->next;
	}
	while (node2 != NULL) {
		bool isin = false;
		for (int i = 0; i < ads.size(); i++) {
			if (ads[i] == node2) {
				isin = true;
			}
		}
		if (!isin) {
			xcopy->coef = node2->coef;
			xcopy->exp = node2->exp;
			xcopy->next = new PolyNode();
			xcopy = xcopy->next;
		}
		node2 = node2->next;
	}
	// LINK XCOPY-HEAD LINKED LIST'S LAST NODE TO NULL
	xcopy = xhead;
	while (xcopy != NULL) {
		if (xcopy->next->coef == 0) {
			xcopy->next = NULL;
			break;
		}
		xcopy = xcopy->next;
	}
	sortList(xhead);
	//RETURN THE POINTER WHICH IS POINTING TO THE SUMMED UP POLYNOM'S HEAD(XHEAD)
	return xhead;
}
PolyNode* Multiply(PolyNode* poly1, PolyNode* poly2) {
	map<int, double> terms;
	PolyNode* node1 = poly1, * node2 = poly2, * head = new PolyNode(), * copy = head;
	while (node1 != NULL) {
		node2 = poly2;
		while (node2 != NULL) {
			int exp = node1->exp + node2->exp;
			double coef = node1->coef * node2->coef;
			if (terms.find(exp) == terms.end()) {
				terms[exp] = 0.0;
			}
			terms[exp] += coef;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	for (auto itr = terms.begin(); itr != terms.end(); itr++) {
		copy->next = new PolyNode();
		copy->exp = itr->first;
		copy->coef = itr->second;
		copy = copy->next;
	}
	copy = head;
	while (true) {
		if (copy->next->coef == 0) {
			copy->next = NULL;
			break;
		}
		copy = copy->next;
	}
	sortList(head);
	return head;
}

int main()
{
	/*FIRST POLYNOM*/
	//CREATING NODES
	PolyNode* first = new PolyNode();
	PolyNode* second = new PolyNode();
	PolyNode* third = new PolyNode();
	//ASSIGNING VALUES TO NODES
	first->coef = 8;
	first->exp = 2;

	second->coef = 17;
	second->exp = 1;

	third->coef = -5;
	third->exp = 0;

	//LINKING NODES
	first->next = second;
	second->next = third;
	third->next = NULL;

	/*SECOND POLYNOM*/
	//CREATING NODES 2nd
	PolyNode* f2 = new PolyNode();
	PolyNode* s2 = new PolyNode();
	PolyNode* t2= new PolyNode();
	PolyNode* fo2 = new PolyNode();

	//ASSIGNING VALUES TO NODES 2nd
	f2->coef = 9;
	f2->exp = 9;

	s2->coef = -25;
	s2->exp = 2;

	t2->coef = -11;
	t2->exp = 1;

	fo2->coef = 9;
	fo2->exp = 0;


	//LINKING NODES 2nd
	f2->next = s2;
	s2->next = t2;
	t2->next = fo2;
	fo2->next = NULL;



	//Print(first);
	//cout << Evaluate(first,2.0);
	//Derivative(first);
	//Print(f2);
	//Print(Add(first, f2));
	//Print(Substract(f2, first));
	std::cout << "Multiplication: ";
	Print(Multiply(f2, first));
	cout << endl;
	std::cout << "Substraction: ";
	Print(Substract(f2, first));
	cout << endl;
	std::cout << "Addition: ";
	Print(Add(f2, first));
	cout << endl;
	std::cout << "Derivation: ";
	Print(Derivative(f2));

	return 0;
}
