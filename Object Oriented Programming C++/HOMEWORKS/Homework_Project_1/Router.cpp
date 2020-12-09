#include "Router.h"
#include <iostream>
#include <cstring>

// OPERATOR < FOR THE ROUTE_PATH STRUCT USED FOR SORTING THE ROUTING_TABLE
bool route_path::operator<(const route_path& rp) const {
	return this->packages_sent < rp.packages_sent;
}

//	ROUTER CLASS CONSTRUCTOR
Router::Router(const string& name, const string& ip) {
	this->name = name;
	this->ip = ip;
}

//	FUNCTION FOR ADDING A ROUTER TO CONNECTED_ROUTERS AND THE ROUTING TABLE
void Router::add_router(const Router& router) {
	try {
		if (router.ip == "0.0.0.0") {
			throw "Trying to add a router with address 0.0.0.0.";
		} else if (router.ip == "127.0.0.0") {
			throw "Trying to add a router with address 127.0.0.0.";
		} else {
			connected_routers.push_back((Router*)(&router));
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
	}

}

// FUNCTION FOR SEARCHING A ROUTE TO AN IP
int Router::query_route(const string& address, const int hop_count) {
//	IF THE IP OF THE CURRENT ROUTER IS THE SEARCHED ONE
	if (ip == address) { return 1; }

//	SEARCHING FOR THE IP IN THE ROUTING TABLE
	for (auto & route : routing_table) {
		if (route.ip == address) { return 1; }
	}

//	SEARCHING FOR THE IP ELSEWHERE
	if (hop_count > 1) {
		int id = 0;
		for (auto &router : connected_routers) {
			if (router->query_route(address, hop_count - 1)) {
				bool flag = true;
				for (auto& iter : routing_table) {
					if(iter.ip == address) {
						flag = false;
						break;
					}
				}
				if (flag) {
					if (routing_table.size() == max_known_paths) {
						routing_table.pop_back();
					}
					this->routing_table.push_back(route_path{address, id, 0});
					return 1;
				}
				return 1;
			}
			++id;
		}
	}

//	RETURNING 0 IF THE IP IS NOT FOUND
	return 0;
}

// FUNCTION FOR SENDING A PACKAGE
void Router::send_package(const Package &package) {
//	CHECKING FOR EXCEPTIONS
	try {
		if (!strcmp(package.get_content(), "")) {
			throw "Trying to send an empty package!";
		}
		else if (package.get_receiver_ip() == "0.0.0.0") {
			throw "Trying to send a package with address 0.0.0.0!";
		}
		else if (package.get_receiver_ip() == "127.0.0.0") {
			throw "Trying to send a package with address 127.0.0.0!";
		}
		else
		{
			cout << "Sending Package: "
				 << package.get_package_number()
				 << " to ip: " << package.get_receiver_ip()
				 << "." << endl;

//			IF THE PACKAGE IS MEANT FOR THIS ROUTER
			if (package.get_receiver_ip() == this->ip) {
				cout << "Package received by Router: "
					 << this->name << ". SUCCESS\n" << endl;
				return;
			}

			cout << "Searching for the package receiver in the routing table..." << endl;

//			SEARCHING FOR THE RECEIVER IN THE ROUTING TABLE
			for (auto & it : routing_table) {
				if (it.ip == package.get_receiver_ip()) {
					it.packages_sent++;
					connected_routers[it.id]->send_package(package);
//					SORTING THE ROUTING_TABLE LIST
					if (it.packages_sent % 10 == 0) {
						this->routing_table.sort();
						this->routing_table.reverse();
					}
					return;
				}
			}

			cout << "Receiver not found in the routing table.\n"
					"Searching with query_route..." << endl;

//			SEARCHING WITH QUERY ROUTE
			if (this->query_route(package.get_receiver_ip(), Router::hops)) {
				for (auto& route : routing_table) {
					if (route.ip == package.get_receiver_ip()) {
						cout << "Route for the package found. Redirecting..." << endl;
						route.packages_sent++;
//		    			SORTING THE ROUTING_TABLE LIST
					    if (route.packages_sent % 10 == 0) {
						    this->routing_table.sort();
						    this->routing_table.reverse();
					    }
						connected_routers[route.id]->send_package(package);
						return;
					}
				}
			}

			cout << "Error: Package could not be send! Aborting." << endl;
			return;
		}
	}
//	CATCHING EXCEPTIONS IF ANY
	catch(const char* err) {
		cout << err << endl;
		return;
	}
}

//	GETTER FUNCTIONS
string Router::get_name() {
	return name;
}
void Router::get_connected_routers() {
	cout << this->name << "'s connected routers:" << endl;
	for(auto & router : connected_routers)
	{
		cout << (*router).ip << endl;
	}
	cout << endl;
}
void Router::get_routing_table() {
	cout << this->name << "'s routing table:" << endl;
	if (routing_table.empty()) {
		cout << "EMPTY" << endl;
	} else {
		for(auto & path : routing_table)
		{
			cout <<"Route: "<< path.ip
				 << ", id: " << path.id
				 << ", packages sent: " << path.packages_sent << endl;
		}
	}
	cout << endl;
}
