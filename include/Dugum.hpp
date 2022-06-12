#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
using namespace std;

class Dugum
{
	public:
		Dugum(string isim); // parametreli Dugum kurucum
		string isim;
		Dugum* ileri;
		Dugum* geri;
};



#endif
