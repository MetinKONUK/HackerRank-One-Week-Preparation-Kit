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