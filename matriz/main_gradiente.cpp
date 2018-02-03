#include "matriz.h"
#include <fstream>
#include "CImg.h"
using namespace cimg_library;
using namespace std;

bool tof(double a){
	return a<127?0:1;
}

CImg<bool> Bi(CImg<double>& M){
	CImg<bool> bina(M);
	for(int i=0;i<M.width();i++)
           for(int j=0;j<M.height();j++)
		bina(i,j)=tof(M(i,j));
	return bina;
}
	


CImg<double> Dx(CImg<double> & M)
{
	CImg<double> ddx(M);  
	for(int i=0;i<M.width();i++)
           for(int j=0;j<M.height()-1;j++)
		if((M(i+1,j)-M(i,j))>10.0)
	             ddx(i,j)=M(i+1,j) - M(i,j);
		else
		     ddx(i,j)=255;

	return ddx;
}


CImg<double> Dy(CImg<double> & M)
{
	CImg<double> ddy(M);  
	for(int i=0;i<M.width();i++)
		for(int j=0;j<M.height()-1;j++)
			if((M(i,j+1)-M(i,j))>10.0)
		             ddy(i,j)=M(i,j+1) - M(i,j);
			else
			     ddy(i,j)=255;
	return ddy;
}


CImg<double> Gr(CImg<double>& M){
	CImg<double> grad(M);
	CImg<double> ddx = Dx(M);
	CImg<double> ddy = Dy(M);
	for(int i=0;i<M.width()-1;i++)
		for(int j=0;j<M.height()-1;j++)
			grad(i,j)=sqrt(pow(ddx(i,j),2)+(ddy(i,j),2));
	
	return grad;
}



int main()
{
   CImg<double>  A("lena.pgm");
   CImg<double>  ddx = Dx(A);
   CImg<double>  ddy = Dy(A);
   CImg<bool>    bina= Bi(A);
   CImg<double>  grad= Gr(A);
   (A,ddx,ddy,bina,grad).display();

   return 1;
}


///Para compilarlo
//g++ matriz.h main.cpp -lpthread -lX11
//./a.out
