#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Server{
	string location;
	string name;
	float ping_time;
	bool operator < (Server& s){
		if(ping_time >= s.ping_time) return true;
		else 			     return false;
	}
};

int main(){
	ifstream input("home/alberto/alberto/Linux/vpn_servers_ping/servers-names");
	string server;
	vector<string> server_file;
	vector<Server> servers;
	while(getline(input,server) ){
		if(server.find(".ovpn") != -1){
			int pos = server.find(".ovpn");
			server = server.substr(0,pos);
			server_file.push_back(server);
		}
	}
	input.close();

	for(int i=0;i<server_file.size();i++){
		input.open("/etc/openvpn/client/" + server_file[i] + ".ovpn" );
		while(getline(input,server) ){
			if(server.find("remote ") != -1){
				int pos = server.find(".privacy.network");
				server = server.substr(7,pos-7);
				Server serv;
				serv.location = server_file[i];
				serv.name = server;
				serv.ping_time = 65000;
				servers.push_back(serv);
				break;
			}
		}
		input.close();
	}

	cout << "\n";

	for(int i=0;i<servers.size();i++){
		cout << "Pinging " << servers[i].location << " server...";
		string cmd = "ping -c 1 " + servers[i].name + ".privacy.network | grep \"64 bytes\" > /home/alberto/alberto/Linux/vpn_servers_ping/" + servers[i].location + ".txt";
		system(cmd.c_str() );
		cout << "\b\b\b" << " OK\n";
	}

	for(int i=0;i<servers.size();i++){
		input.open("/home/alberto/alberto/Linux/vpn_servers_ping/" + servers[i].location + ".txt");
		getline(input,server);
		int pos = server.find("time=");
		server = server.substr(pos + 5);
		pos = server.find(" ms");
		server = server.substr(0,pos);
		servers[i].ping_time = stof(server);
		input.close();
	}
	sort(servers.begin(),servers.end());
	cout << "\n\n";

	for(int i=0; i<servers.size(); i++){
		cout.width(20);
		cout << left << servers[i].location << servers[i].ping_time << " ms" << endl;
	}
	cout << "\n";

	system("rm /home/alberto/alberto/Linux/vpn_servers_ping/*.txt");
}
