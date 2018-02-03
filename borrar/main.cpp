#include<vector>
#include<iostream>
using namespace std;



int main(){

	//forma dinamica
	vector< vector<int> > vec;
	
	for (int i = 0; i < 10; i++) {
	        vector<int> fila;
	        for (int j = 0; j < 20; j++) {
		        fila.push_back(i * j); 
    		}
    		vec.push_back(fila); 
	}
	vec[2][2]=10;


	//forma statica

	 vector< vector<int> > vec2(4, vector<int>(4));
	
    	vec2[2][3] = 10;

	vector<int> my;
	my.push_back(6);
	my.push_back(5);
	my.push_back(7);
	for(int j=0;j<my.size();j++)
		cout<<my[j]<<endl;
	cout<<"***"<<endl;
	my.erase(my.begin()+1);
	for(int j=0;my.size()-1;j++)
		cout<<my[j]<<endl;
	return 0;
}
