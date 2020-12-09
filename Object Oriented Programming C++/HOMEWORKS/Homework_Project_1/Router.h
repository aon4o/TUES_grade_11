#ifndef OOP_HW_1_ROUTER_H
#define OOP_HW_1_ROUTER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Package.h"

using namespace std;

struct route_path {
	string ip;
	int id;
	int packages_sent;

	bool operator<(const route_path& rp) const;
};

class Router {
private:
	string name;
	string ip;
	vector<Router*> connected_routers;
	list<route_path> routing_table;
	const static int max_known_paths = 10;
	const static int hops = 10;

public:
	Router(const string& name, const string& ip);

	void add_router(const Router& router);
	int query_route(const string& address, int hop_count);
	void send_package(const Package& package);

	string get_name();
	void get_connected_routers();
	void get_routing_table();
};

#endif //OOP_HW_1_ROUTER_H
