#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	ifstream source("sc01.cfg");
	ofstream result;
	result.open("result.txt",ofstream::out|ofstream::trunc);
	string data;
	stringstream tempdata;
	int pos;
	if(!source.good()){
		cout<<"File not found or something";
		cin>>data;
		return 0;
	}
	tempdata<<source.rdbuf();
    vector<string> splitted;
    while (getline(tempdata, data, '_')) {
       splitted.push_back(data);
    }
    for(int ii=0;ii<splitted.size();ii++){
    	data=splitted[ii];
    	if(data[0]=='\"'){
    		data=data.substr(1,data.length()-1);
		}
		else if(data[1]=='\"'){
    		data=data.substr(2,data.length()-2);
		}
		else continue;
		pos=data.find("\"");
		if(pos!=string::npos){
			data=data.substr(0,pos);
			result<<data<<endl;
		}
	}
}
