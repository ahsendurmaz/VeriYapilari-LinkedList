/**
* @file main.cpp
* @description main sınıfı, fonksiyon çağırımları 
* @course 1A
* @assignment 1.ödev
* @date Kodu 07.11.2021
* @author Ahsen Durmaz ahsen.durmaz@sakarya.edu.tr
*/



#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "IkiYonluListem.hpp"

using namespace std;


int main()
{
	IkiYonluListem* e1 = new IkiYonluListem(); //e1 listem oluşturuldu
	e1->DosyaOkuListeyeYaz(e1);   
	e1->yazdir();
	return 0;
}