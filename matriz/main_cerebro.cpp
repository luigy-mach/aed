#include "matriz.h"
#include <fstream>
#include "CImg.h"
#include <map>
#include <string>
#include <cstring>
using namespace cimg_library;
using namespace std;


#include <sstream>

typedef map< double, double > COLUMNA;
typedef map< double, COLUMNA > MATRIZ;
typedef map< int, MATRIZ > CEREBRO;

typedef map< double,double >::iterator IT_COL;
typedef map< double,COLUMNA >::iterator IT_MA;
typedef map< int,MATRIZ >::iterator IT_CERE;


template <class T>
inline std::string to_string (const T& t)
{
   std::stringstream ss;
   ss << t;
   return ss.str();
}

COLUMNA copiar_columna(CImg<double>& a, int fila){
	COLUMNA co;
	for(int i=0;i<a.width();i++){
		co[i]=a(fila,i);
	}
	return co;
}

MATRIZ copiar(CImg<double>& a){
	MATRIZ ma;		
	for(int i=0;i<a.height();i++){
		ma[i]=copiar_columna(a,i);
	}
	return ma;	
}


void imprimir(CEREBRO& ce){
	fstream file("cerebro.vti");

/*	IT_CE it_ce;
	IT_MA it_ma;
	IT_COL it_col
*/

	file<<"# vtk dataFile Version 1.0"<<endl;
	file<<"ASCII"<<endl;
	file<<"DATASET POLYDATA"<<endl;
	file<<"POINTS "<<1057855<<" double"<<endl;
	for(int k=0;k<ce.size(); k++){
		for(int i=0;i<ce[k].size();i++){
			for(int j=0;j<ce[k][i].size();j++){
				if(ce[k][i][j]==255.0)
					file<<i<<" "<<j<<" "<<k*10<<endl;
			}
		}
	}
	
/*	for(int k=0,it_ce=ce.begin();it_ce!=ce.end(); k+=10,it_ce++){
		for(int i=0, it_ma=it_ce->second->begin();it_ma!=it_ce->second->end();i++,it_ma++){
			for(int j=0,it_col=it_ma->second->begin();it_col!=it_ma->second->end();j++,it_col++){
				if(it_col->second==255.0)
					file<<i<<" "<<j<<" "<<k<<endl;
			}
		}
	}*/
	

	
	file.close (); 
}


int main()
{
	CEREBRO ce;

	for(int i=0;i<39;i++){
		string a="img_brain/"+to_string(i+1)+".BMP";
		CImg<double> M(a.c_str());
		ce[i]=copiar(M);
	}

	imprimir(ce);
	


   return 1;
}
