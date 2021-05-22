#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#define N 50

using namespace std;

class Graph {
private:
	int matrix[N][N]{};
	int m;

public:
	explicit Graph(const string& file);

	int get_m() const {
		return m;
	}

	void print();
	int travelling_salesman_problem(int start, int* shortest_path, int* time);
	void dijkstra(int start);
};

int minimum_distance(const int *distances, const bool *distances_flags, int vertexes);
void print_dijkstra(int *distances, int vertexes, int start);

#endif //GRAPHS_GRAPH_H
