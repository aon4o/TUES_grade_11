#include "Package.h"
#include "Router.h"

#include <fstream>

using namespace std;

int main()
{
//	OPENING, READING AND CHECKING FOR ERRORS FROM 'ROUTERS.TXT'
	ifstream routers_file("routers.txt");
	vector<Router> routers;
	if (routers_file.is_open())
	{
		string name, ip;
		while (!routers_file.eof())
		{
			getline(routers_file, name, ' ');
			getline(routers_file, ip, '\n');
			routers.emplace_back(Router(name, ip));
		}
		routers_file.close();
	}
	else
	{
		perror("open: 'routers.txt'");
		return 1;

	}

//	OPENING, READING AND CHECKING FOR ERRORS FROM 'NETWORK.TXT'
	ifstream network_file("network.txt");
	if (network_file.is_open())
	{
		string name1, name2;
		while (!network_file.eof())
		{
			getline(network_file, name1, ' ');
			getline(network_file, name2);
			for (auto & router1 : routers) {
				if (router1.get_name() == name1) {
					for (auto & router2 : routers) {
						if (router2.get_name() == name2) {
							router1.add_router(router2);
							router2.add_router(router1);
							break;
						}
					}
					break;
				}
			}
		}
		network_file.close();
	}
	else
	{
		perror("open: 'network.txt'");
		return 1;
	}

//	OPENING, READING AND CHECKING FOR ERRORS FROM 'PACKAGES.TXT'
	ifstream packages_file("packages.txt");
	vector<Package*> packages;
	if (packages_file.is_open())
	{
		string sender, receiver, content;
		while (!packages_file.eof())
		{
			getline(packages_file, sender, ' ');
			getline(packages_file, receiver, ' ');
			getline(packages_file, content, '"');
			getline(packages_file, content, '"');
			packages.emplace_back(new Package{content, sender, receiver});
		}
		packages_file.close();

	} else
	{
		perror("open: 'packages.txt'");
		return 1;
	}


//	TESTS ROUTER NAMES
//	cout << routers[1].get_name() << endl;
//	cout << routers[2].get_name() << endl;

//	TEST QUERY_ROUTE
//	routers[0].get_routing_table();
//	routers[0].query_route("175.152.47.162", 10);
//	routers[0].get_routing_table();
//	routers[0].query_route("158.187.103.60", 10);
//	routers[0].get_routing_table();

//	BASIC SEND_PACKAGE TEST
//	routers[0].send_package(*packages[1]);
//	routers[0].get_routing_table();

//	COMPLICATED SEND_PACKAGE TEST
//	routers[0].send_package(*packages[3]);
//	routers[0].get_routing_table();
//	routers[2].get_routing_table();

//	SEND_PACKAGE PATH IN ROUTING TABLE BUT NOT IN CONNECTED ROUTERS TEST
//	routers[0].query_route("158.187.103.60", 10);
//	routers[0].send_package(*packages[4]);
//	routers[0].get_routing_table();
//	routers[2].get_routing_table();


//	TESTING THE SORTING OF ROUTING TABLES
//	routers[0].query_route("219.213.251.176", 10);
//	routers[0].query_route("175.152.47.162", 10);
//	routers[0].get_routing_table();
//	routers[0].get_routing_table();
//	for (int i = 0; i < 12; ++i) {
//		routers[0].send_package(*packages[1]);
//	}
//	routers[0].get_routing_table();


//	TESTING THE VALIDATION METHOD
//	if (packages[1]->validate())
//	{
//		cout << "Package 1's content is valid" << endl;
//	} else
//	{
//		cout << "Package 1's content is NOT valid" << endl;
//	}
	return 0;
}