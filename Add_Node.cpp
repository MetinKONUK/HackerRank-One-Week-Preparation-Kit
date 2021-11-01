// MY METHOD
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


//OTHER METHOD