#include <iostream>
#include <vector>
using namespace std;

class Graph {

public:

	int n; // number of nodes
	vector<vector<bool> > A; // adjacency matrix

	// create graph of n nodes
	Graph(int n) {
		this->n = n;
		this->A = vector<vector<bool> >(n + 1, vector<bool>(n + 1, false));
	}

	void set_edge(int v_i, int v_j) {
		this->A[v_i][v_j] = this->A[v_j][v_i] = true;
	}

	// print E in ascending order
	void print() {
		for (int v_i = 1; v_i <= this->n; v_i++) {
			for (int v_j = v_i + 1; v_j <= this->n; v_j++) {
				// print (v_i, v_j) if it exists
				if (this->A[v_i][v_j]) {
					std::cout << v_i << " " << v_j << "\n";
				}
			}
		}
	}

};

int main() {


	int n; // nodes 數量
	std::cin >> n;
	Graph G(n); //創建有n個node的graph

	int m; //edges 數量
	std::cin >> m;

	// read E
	for (int i = 0; i < m; ++i) {
		int v_i, v_j; // edge: (v_i, v_j)
		std::cin >> v_i >> v_j; // read edge
		G.set_edge(v_i, v_j); // set edge
	}

	G.print(); // display E_sorted

	return 0;

}
