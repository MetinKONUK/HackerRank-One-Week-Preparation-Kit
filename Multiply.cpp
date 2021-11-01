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
	return head;
}