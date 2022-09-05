
#include "vector.h"
class matrix
{
		int row, col;	// array dimensions 
		vector* m;		// pointer to allocate memory for array elements
	public:
		matrix(int =0, int =0);	// initialize matrix passing dimenssions 
		matrix(const matrix&);		// copy constructor
		~matrix();				// destructor
		void read();
		void print()const;
		matrix& operator =(const matrix&);	
		matrix operator+(const matrix&)const;
		double max()const;
		//friend matrix operator-(const matrix&, const matrix&); - to define
		//matrix operator*(const matrix&);	- to define
		//void resize(int, int); - to define
		
};
