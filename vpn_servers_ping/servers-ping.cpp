#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(){
	system("ls /etc/openvpn/client > servers-names.txt");
	ifstream input("servers-names.txt");
	string server;
	vector<string> server_file;
	vector<string> server_name;
	while(getline(input,server) ){
		if(server.find(".ovpn") != -1){
			server_file.push_back(server);
		}
	}
	input.close();
	
	ofstream output("servers-dns.txt", ios::app);
	for(int i=0;i<server_file.size();i++){
		input.open("/etc/openvpn/client/" + server_file[i] );
		while(getline(input,server) ){
			if(server.find("remote ") != -1){
				int pos = server.find(" 1198");
				server = server.substr(7,pos-7);
				output << server << endl;
				break;
			}
		}
		input.close();
	}
	system("rm servers-names.txt");
}
