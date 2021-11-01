PolyNode* Derivative(PolyNode* poly) { // original pointer
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
	list_elements(head);
	return head;
}