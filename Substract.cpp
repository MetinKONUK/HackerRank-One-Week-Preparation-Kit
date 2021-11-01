PolyNode* Substract(PolyNode* poly1, PolyNode* poly2) {
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
	//RETURN THE POINTER WHICH IS POINTING TO THE SUMMED UP POLYNOM'S HEAD(XHEAD)
	return xhead;
}