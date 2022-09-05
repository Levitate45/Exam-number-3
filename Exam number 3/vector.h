
//class matrix;

#pragma once
class vector
{
  int nrel;
  double * arr;
public:
  vector(int=8);		
  vector(const vector&);
  ~vector();
  void read(); 	
  void print()const;	
  void modif_el(int, double);	
  void modif_dim(int);	
  vector& operator=(const vector&);
  friend vector operator+(const vector&, const vector&);
  double& operator[](int);
  double max()const;
  double avg()const;      
  
};
