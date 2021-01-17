#include <iostream>

#include "Classes.h"

using namespace std;

bool validate(Point pool[4], double force, const Line& aim)
{
//	VALIDATING THE FORCE INPUT
	if (force < 2 or force > 5)
	{
		cout << "Invalid 'force' input! Should be between 2 and 5!" << endl;
		return false;
	}

//	VALIDATING THE TARGET INPUT
	double width = max(Line(pool[0], pool[1]).length(), Line(pool[1], pool[2]).length());
	if (aim.length() < width/10 or aim.length() > width*3/10)
	{
		cout << "Invalid 'target' input!" << endl;
		return false;
	}

	return true;
}

int main()
{
	ifstream file("pool.txt");
	string x, y, d;

//	GETTING THE CORNERS OF THE TABLE INTO AN ARRAY
	Point pool[4];
	for (auto & i : pool) {
		getline(file, x, ',');
		getline(file, y, '\n');
		try {
			i = Point(stod(x), stod(y));
		} catch (const invalid_argument& err) {
			cout << "Error! " << x << y << endl;
			return 1;
		}
	}

//	GETTING THE INITIAL COORDINATES OF THE BALL
	Ball ball{}, default_coordinates{};
	getline(file, d, ',');
	getline(file, x, ',');
	getline(file, y, '\n');
	ball = default_coordinates = Ball(stod(x), stod(y), stod(d));

//	CREATING THE TABLE EDGE LINES
	Line table[4];
	for(int i = 0; i < 3; ++i)
	{
		table[i] = Line(pool[i], pool[i+1]);
	}
	table[3] = Line(pool[3], pool[0]);

//	SETTING UP THE NEEDED VARIABLES
	string line;
	double force;
	Point target{};

//	CYCLE UNTIL CTRL+D
	while (!cin.eof())
	{
//		GETTING THE FORCE AND THE TARGET COORDINATES
		getline (cin, line, '\n');
		stringstream(line) >> force >> target.x >> target.y;

//		INPUT VALIDATION
		if(!validate(pool, force, Line(ball, target)))
		{
			continue;
		}

//		GETTING THE THEORETICAL NEW POSITION OF THE BALL
		Point new_position = Point
				(
					ball.x - force * (ball.x - target.x),
					ball.y - force * (ball.y - target.y)
				);

//		GETTING THE PATH OF THE BALL
		Line path = Line(ball, new_position);

//		GETTING THE REAL NEW POSITION OF THE BALL
//		AND CHECKING FOR BOUNCES
		for (const auto & edge : table) {
			Point intersection = path.intersection(edge);
			if (intersection != Point(DBL_MAX, DBL_MAX))
			{
				int flag = 0;
				for (auto& corner : pool)
				{
					if (intersection == corner)
					{
						cout << "The ball got into a pocket ";
						intersection.print();
						new_position = default_coordinates;
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					break;
				}
				cout << "The ball bounced into the wall ";
				intersection.print();
				new_position.mirror(edge);
				path = Line(ball, new_position);
			}
		}

//		SETTING THE NEW POSITION OF THE BALL AND PRINTING IT
		ball = new_position;
		ball.print();
	}
}
