void Print(PolyNode *poly) {
	PolyNode* node = poly;
	if (node == NULL) {
		cout << "<NULL>";
	}
	cout << "<";
	while (node != NULL) {
		double coef = node->coef;
		int exp = node->exp;
		if (coef > 0) {
			cout << "+";
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