#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Server{
	string location;
	string name;
	float ping_time;
};

int main(){
	system("ls /etc/openvpn/client > servers-names.txt");
	ifstream input("servers-names.txt");
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
	system("rm servers-names.txt");

	for(int i=0;i<servers.size();i++){
		cout << "pinging " + servers[i].location + " server...";
		string cmd = "ping -c 1 " + servers[i].name + ".privacy.network &";
		int a = system(cmd.c_str() );
		cout << "\r";
	}

	for(int i=0;i<servers.size();i++){
		cout << servers[i].location << ' ' << servers[i].ping_time << endl;
	}
}
