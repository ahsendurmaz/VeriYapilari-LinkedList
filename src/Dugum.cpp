/**
* @file Dugum.cpp
* @description Dugum sınıfı ve içindeki atamalar
* @course 1A
* @assignment 1.ödev
* @date Kodu 07.11.2021
* @author Ahsen Durmaz ahsen.durmaz@sakarya.edu.tr
*/


#include "Dugum.hpp"

Dugum::Dugum(string isim){
		this->isim=isim;
		ileri=NULL;
		geri=NULL;
}