/*
Define class matrix to represent dinamycal allocated arrays with two dimensions.
Matrix is built as an one-dimensional array with elements of type array.
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include "matrix.h"

using namespace std;

int main()
{
	cout<<"\n\n== working with matrix ==" << endl;
	int r, c;
	cout<<"rows number = ";
	cin >> r;
	cout<<"columns number =	";
	cin >> c;

	matrix a(r,c);
	cout<<"\nread matrix a:\n" ;
	a.read();
	cout<<"\nmatrix a is:\n";
	a.print();
	matrix b(r, c);
	cout<<"\nread matrix b\n";
	b.read();
	cout<<"\nmatrix b is:\n";
	b.print();
	
	matrix s=a+b;
	cout<<"\nthe sum s = a+b is:\n";
	s.print();
	
	double max=s.max();
	cout<<"\nmaximum element of s is:"<< max <<"\n";

	cin.ignore(100, '\n');
	cin.get();
}