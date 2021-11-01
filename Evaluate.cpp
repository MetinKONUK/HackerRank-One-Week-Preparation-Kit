double Evaluate(PolyNode* poly, double x) {
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