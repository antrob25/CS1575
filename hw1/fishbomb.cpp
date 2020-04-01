// Programmer Name: Anthony Robles    Section: cs1575 101

#include <iostream>

using namespace std;

int main()
{
	// Variable Declarations
	int t,h,w,x1,y1,x2,y2,x3,y3,f;
	int temp,sum1 = 0, sum2 = 0, sum3 = 0;
	int **p;
	
	cin >> t;
	
	for (int i=1; i<=t; i++) // Loops the test cases
	{
		cin >> h >> w;
			
		p = new int*[w];
			
		for(int j=0; j<w; j++) // creates 2D array
			p[j] = new int[h];
				
		for(int j=0; j<h; j++) // inputs values into the array
		{
			for(int k=0; k<w; k++)
				cin >> p[j][k];
						
		}
			 
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			
		for(int j=(x1-2);j<=(x1+2);j++) // sums fish caught in first coordinate
		{
			for(int k=(y1-2);k<=(y1+2);k++)
			{
				temp = p[j][k];
				p[j][k] = 0;
				sum1+= temp;
						
			}
		} 
			
		for(int j=(x2-2);j<=(x2+2);j++) // sums fish caught in second coordinate
		{
			for(int k=(y2-2);k<=(y2+2);k++)
			{
				temp = p[j][k];
				p[j][k] = 0;
				sum2+= temp;
						
			}
		} 
			
		for(int j=(x3-2);j<=(x3+2);j++) // sums fish caught in third coordinate
		{
			for(int k=(y3-2);k<=(y3+2);k++)
			{
				temp = p[j][k];
				p[j][k] = 0;
				sum3+= temp;
						
			}
		} 

		f = sum1+ sum2 + sum3; // sums total fish
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;

		cout<< "#"<< i << ": Bender catches "<< f << " fish.\n";
		
		for (int i = 0; i < w; i++)
			delete[]p[i];
		delete[]p;
		p = NULL;
			
	}
	return 0;
}
