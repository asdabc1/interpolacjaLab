#include <iostream>
#include <vector>
#include <algorithm>
#include "polynomial.h"

Polynomial Lagrange(std::vector<double>& nodes, std::vector<double>& values);

int main() {
	using namespace std;

	vector<double> a = { -2,0,1,2,3 };
	vector<double> b = { -240,24,18,-16,-60 };
	Polynomial ans = Lagrange(a, b);
	cout << ans.value(1);
	return 0;
}

Polynomial Lagrange(std::vector<double>& nodes, std::vector<double>& values) {
	const int NODES_AMOUNT = nodes.size();

	std::unique(nodes.begin(), nodes.end());
	if (nodes.size() != NODES_AMOUNT)
		return Polynomial();

	Polynomial LGBase, result, tem;
	double temp;

	for (int i = 0; i < NODES_AMOUNT; i++) {
		temp = 1;
		tem = Polynomial();

		for (int j = 0; j < NODES_AMOUNT; j++) {
			if (j == i)
				continue;

			temp *= nodes[i] - nodes[j];
			tem *= {1, -1 * nodes[j]};
		}

		temp = 1 / temp;
		tem = tem * temp;

		if (i == 0)
			result = tem * values[0];
		else
			result = result + (tem * values[i]);
	}

	return result;
}