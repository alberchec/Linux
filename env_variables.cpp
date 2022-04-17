//Bash Manual Scraper to obtain list of Environment Variables

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream file("bash_info.txt");
	ofstream fileout("env_variables.txt");
	string line;
	while(getline(file,line) ){
		int pos1 = line.find("Shell");
		int pos2 = line.find("Variables");
		if(pos1 == 3 && pos2 == 9){
			break;
		}
	}
	fileout << "Shell Variables" << endl;
	while(getline(file,line) ){
		if(line.find("Arrays") == 3) break;
		fileout << line << endl;
	}
	file.close();
	fileout.close();
}
