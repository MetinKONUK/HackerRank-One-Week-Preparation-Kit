#include <iostream>
#include <string>
using std::string;
struct PolyNode
{
	int exp;
	double coef;
	struct PolyNode* next;
};



PolyNode* CreatePoly(string expr) {
	PolyNode* node = new PolyNode();
	for (int i = 0; i < expr.length(); i++) {
		std::cout << expr[i];
	}
	return node;
}

void sortList(PolyNode* first) {
	PolyNode* head = first;
	// Node current will point to head
	struct PolyNode *current = head, *index = NULL;
	int temp;
	double temp2;
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
					temp2 = current->coef;

					current->exp = index->exp;
					current->coef = index->coef;

					index->exp = temp;
					index->coef = temp2;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void list_elements(PolyNode* head) {
	PolyNode* node = head;
	int i = 0;
	while (node != NULL) {
		std::cout << node->coef << "," << node->exp << std::endl;
		node = node->next;
		i++;
	}
	std::cout << "Element Count: " << i << std::endl;
}

void AddNode(PolyNode* head,double coef, int exp) {
	PolyNode* node = head;
	while (node != NULL) {
		if (node->next == NULL) {
			node->next = new PolyNode();
			node->next->coef = coef;
			node->next->exp = exp;
			node->next->next = NULL;
			break;
		}
		node = node->next;
	}
}



int main()
{
	PolyNode* first = new PolyNode();
	PolyNode* second = new PolyNode();
	PolyNode* third = new PolyNode();

	first->coef = 10, first->exp = 2;
	second->coef = 4.5, second->exp = 4;
	third->coef = 6, third->exp = 1;

	first->next = second;
	second->next = third;
	third->next = NULL;
	AddNode(first, 3.1, 5);
	AddNode(first, 6.5, 7);
	//std::cout << "Before sorting: " << std::endl;
	//list_elements(first);
	//std::cout << "After sorting: " << std::endl;
	sortList(first);
	//list_elements(first);
	CreatePoly("-x^3 - 6x^2 + 4x + 22");
	//const char* str = "-x^3 - 6x^2 + 4x + 22";

}