#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#include "matrix.h"

matrix::matrix(int r, int c)
{
	row =r;
	col = c;
    m=new vector[row];
    for(int i=0;i<row;i++)
		m[i].modif_dim(col);
}

matrix::matrix(const matrix& mat)
{
	row =mat.row;
	col = mat.col;
    m=new vector[row];
    for(int i=0;i<row;i++)
		m[i]=mat.m[i];
}

matrix::~matrix()
{
	delete [] m;
}

void matrix::print()const
{
	//version I - uses function print() defined in class vector
	/*	
	cout << fixed << setprecision(2);
	for(int i=0;i<row;i++)
	{ 
		m[i].print();
		cout<<endl;
	}
	*/

	// version II - is possible to be used if class matrix is a friend of vector
	/*
	cout << fixed << setprecision(2);
	for(int i=0;i<row;i++)
	{ 
		for(int j=0; j<col; j++)
		{
			cout.width(8);
			cout<<m[i].arr[j];	// access private member of vector "arr"
		}
		cout<<endl;
	}
	*/

	//version III - uses operator[] defined in class vector
	cout << fixed << setprecision(2);
	for(int i=0;i<row;i++)
	{ 
		for(int j=0; j<col; j++)
		{
			cout.width(8);
			cout<<m[i][j];
		}
		cout<<endl;
	}
}

void matrix::read()
{
	for(int i=0; i<row ; i++)
	{
		cout<<"\nrow ("<<i<<"): \n";
		m[i].read();
	}
}

matrix matrix::operator +(const matrix& a)const
{
	if(row>a.row)
	{
		matrix mat(*this);
		for (int i=0; i<a.row;i++)
			mat.m[i] = this->m[i]+a.m[i];
		return mat;
	}
	else
	{
		matrix mat(a);
		for (int i=0; i<this->row;i++)
			mat.m[i] = this->m[i]+a.m[i];
		return mat;
	}
}

matrix& matrix::operator=(const matrix& y)
{
	if(row != y.row || col != y.col)
	{
		delete [] m;
		row = y.row;
		col = y.col;
		m = new vector[row];
	}
	for(int i=0;i<row;i++)
		m[i]=y.m[i];
	return *this;
}

double matrix::max()const	// it returns the biggest element
{
      double max=0;
      for(int i=0; i<row; i++)
		  max=m[i].max();
      return max;
}