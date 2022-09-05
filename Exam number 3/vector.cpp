#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#include "vector.h"

vector::vector(int n)
{  nrel=n;
   arr=new double[nrel];
   for (int i=0; i<nrel; i++)
     arr[i]=0;
}

vector::vector(const vector& t)
{
  nrel=t.nrel;
  arr=new double[nrel];
  for (int i=0; i<nrel; i++)
      arr[i]=t.arr[i];
}

vector::~vector()
{  delete []arr;  }

void vector::read()
{  for(int i=0; i<nrel; i++)
    {      cout<<"arr["<<i<<"]=";
            cin>>arr[i];
    }
}

void vector::print()const
{  cout<<endl;
    for(int i=0; i<nrel; i++)
      cout<<"arr["<<i<<"]="<<arr[i]<<endl;
}
vector& vector::operator=(const vector& v)
{
	if(this !=&v)
	{
		if (nrel != v.nrel)
		{
			nrel = v.nrel;
			delete [] arr;
			arr = new double[nrel];
		}
		for(int i=0; i<nrel;i++)
			arr[i] = v.arr[i];
	}
	return *this;
}
void vector::modif_dim(int dim)
{   
   double * aux;
	int i;
    aux= new double[dim];
    if (dim<=nrel)
    {  for( i=0; i<dim; i++)
  	  aux[i]=arr[i];
        nrel=dim;
        delete []arr;
        arr=aux;
    }
  if (dim>nrel)
    { for(i=0; i<nrel; i++)
	aux[i]=arr[i];
       for( ; i<dim; i++)
	aux[i]=0;
      nrel=dim;
      delete []arr;
      arr=aux;
    }
}

void vector::modif_el(int i, double val)
{
  if (i<nrel)
      arr[i]=val;
}

double vector::max()const
{
  double maxim=arr[0];
  for(int i=1; i<nrel; i++)
    maxim =arr[i];
  return maxim;
}

double vector::avg()const
{
  double med=0;
  for(int i=0; i<nrel; i++)
    med+=arr[i];
  med/=nrel;
  return med;
}

vector operator+(const vector& v1, const vector& v2)
{
	int i;
	if(v1.nrel>v2.nrel)
	{
		vector v(v1);
		for (i=0; i<v2.nrel;i++)
			v.arr[i] = v.arr[i] + v2.arr[i];
		return v;
	}
	else
	{
		vector v(v2);
		for (i=0; i<v1.nrel;i++)
			v.arr[i] = v.arr[i] + v1.arr[i];
		return v;
	}
}

double& vector::operator [](int i)
{
	if(i>=nrel)
	{
		cout<<"\nparameter is too big, maximum value is "<<nrel-1<<endl;
		return arr[nrel-1];	
	}
	return arr[i];
}
