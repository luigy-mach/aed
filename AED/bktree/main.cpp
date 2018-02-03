#include "BKTree.h"

//---------------------------------
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;



int main()
{

	BKTree bk;

    std::pair<std::string, int> pety = std::make_pair(std::string("pety"), 8);

    bk.add(pety);
    
    MAP_OUT result;
    
    
    bk.query(std::string("puta"), 2, result);
    
    std::cout << result.begin()->first << " " << result.begin()->second << std::endl;
	
	
  

	return 0;
}
