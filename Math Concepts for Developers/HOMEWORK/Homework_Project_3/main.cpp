#include <string>
#include <iostream>
#include <fstream>

#include "Graph.h"

using namespace std;

int main(int argc, char* argv[])
{
//	CHECKING IF A FILE IS GIVEN
	if (argc < 2)
	{
		perror("There's no file given!");
		return 1;
	}
	ifstream file(argv[1]);
	if (!file.is_open()) {
		perror("There's no file given!");
		return 1;
	}

//	GETTING THE FILE INTO A MATRIX REPRESENTATION OF GRAPH
	Graph graph(argv[1]);
	graph.print();

//	GETTING THE NUMBER OF THE STARTING VERTEX
	int start;
	cout << "Starting node -> ";
	cin >> start;
	if (start > graph.get_m() - 1 or start < 0) {
		cout << "The graph does NOT have a vertex with number " << start << "!" << endl;
		return 1;
	}

//	SOLVING THE PROBLEM
	int shortest_path[graph.get_m()];
	int time;
	int flag = graph.travelling_salesman_problem(start, shortest_path, &time);

//	CHECKING IF THERES A PATH THAT GOES THROUGH ALL THE CITIES
	if (flag) {
		cout << "There is not a path that goes through all the cities!" << endl;
		return 1;
	}

//	PRINTING THE RESULTS
	cout << "Path:";
	for (int num : shortest_path) {
		cout << " " << num;
	}
	cout << endl << "Time: " << time << " minutes" << endl << endl;

//	BONUS FUNCTION FOR THE CONDITION OF THE TASK
	graph.dijkstra(start);

	return 0;
}
