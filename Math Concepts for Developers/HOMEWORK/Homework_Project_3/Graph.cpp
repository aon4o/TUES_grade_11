#include <iostream>
#include <bits/stdc++.h>

#include "Graph.h"

using namespace std;

Graph::Graph(const string& input_file)
{
//	GETTING THE NUMBER OF LINES IN THE FILE AND SETTING 'm' AND 'n'
	ifstream get_lines_file(input_file);
	if (get_lines_file.is_open()) {
		int file_lines = 0;
		string line;
		while (getline(get_lines_file, line))
		{
			++file_lines;
		}

//		SETTING THE 'M' VALUE OF THE MATRIX
		m = file_lines;

		get_lines_file.close();
		if (get_lines_file.is_open())
		{
			perror("close");
			return;
		}
	}
	else
	{
		perror("open");
		return;
	}

//	OPENING THE FILE AND SAVING IT IN FORM OF A MATRIX
	ifstream file(input_file);
	if (file.is_open())
	{
		string get;

//		GETTING THE MATRIX
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (j != m - 1) {
					getline(file, get, ' ');
				} else {
					getline(file, get, '\n');
				}
				matrix[i][j] = stoi(get);
			}
		}

//		CLOSING THE FILE AND CHECKING FOR ERRORS
		file.close();
		if (file.is_open())
		{
			perror("close");
			return;
		}
	}
	else
	{
		perror("open");
		return;
	}
}

void Graph::print() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Graph::travelling_salesman_problem(int start, int* shortest_path, int* time) {
//	STORING THE VERTICES WITHOUT THE STARTING ONE
	vector<int> vertices;
	for (int i = 0; i < this->m; i++) {
		if (i != start) {
			vertices.push_back(i);
		}
	}

//	CALCULATING THE MINIMUM TIME
	int minimum_time = INT_MAX;
	do {
		int current_time = 0;
		int flag = 0;

//		CALCULATING THE CURRENT TIME
		int s = start;
		for (int vertex : vertices) {
//			CHECKING IF THE PATH IS UNDER CONSTRUCTION
			if (this->matrix[s][vertex] == -1) {
				flag = 1;
				break;
			}
			current_time += this->matrix[s][vertex];
			s = vertex;
		}
//		CHECKING IF THE PATH IS UNDER CONSTRUCTION (AGAIN)
		if (flag or this->matrix[s][start] == -1) {
			continue;
		}

		current_time += this->matrix[s][start];

//		UPDATING THE RETURN VALUES
		if (minimum_time > current_time) {
			minimum_time = current_time;
			shortest_path[0] = start;
			for (int i = 1; i < this->m; ++i) {
				shortest_path[i] = vertices[i-1];
			}
		}
	} while (next_permutation(vertices.begin(), vertices.end()));

	*time = minimum_time;
	if (minimum_time == INT_MAX) {
		return 1;
	} else {
		return 0;
	}
}

void Graph::dijkstra(int start)
{
//	SETTING UP THE NEEDED VARIABLES
	int distances[this->m];
	bool distances_flags[this->m];
	for (int i = 0; i < this->m; i++) {
		distances[i] = INT_MAX;
		distances_flags[i] = false;
	}
	distances[start] = 0;

//	FINDING THE SHORTEST PATH FOR ALL VERTICES FROM THE STARTING ONE
	for (int i = 0; i < this->m - 1; i++) {
		int u = minimum_distance(distances, distances_flags, this->m);
		distances_flags[u] = true;

		for (int vertex = 0; vertex < this->m; vertex++) {
			if (!distances_flags[vertex] && matrix[u][vertex] && distances[u] != INT_MAX
				&& distances[u] + matrix[u][vertex] < distances[vertex] && matrix[u][vertex] != -1) {
				distances[vertex] = distances[u] + matrix[u][vertex];
			}
		}
	}
	print_dijkstra(distances, this->m, start);
}

int minimum_distance(const int distances[], const bool distances_flags[], int vertexes)
{
	int minimum = INT_MAX;
	int minimum_index;

	for (int vertex = 0; vertex < vertexes; vertex++) {
		if (!distances_flags[vertex] && distances[vertex] <= minimum) {
			minimum = distances[vertex];
			minimum_index = vertex;
		}
	}

	return minimum_index;
}

void print_dijkstra(int distances[], int vertexes, int start)
{
	cout << "Vertex \t\t Distance from starting Vertex (" << start << ")" << endl;
	for (int i = 0; i < vertexes; i++) {
		cout << i << "\t\t\t" << distances[i] << endl;
	}
}