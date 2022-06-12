#ifndef IkiYonluListem_hpp
#define IkiYonluListem_hpp
#include "Dugum.hpp"

class IkiYonluListem
{
	private:
		Dugum* ilkDugum;
		int elemanSayisi=0;
		int index=0;
	public:
		IkiYonluListem();
		int elemanSayisiGetir();
		Dugum* indexGetir(int sira);
		Dugum* sonElemanGetir();
		void listeSonunadugumEkle();
		Dugum* ilkElemanGetir();
		void arayaEkle(string ad,int sira,IkiYonluListem* ahsen);
		void aradanSil(int sira, IkiYonluListem* ahsen);
		void DosyaOkuListeyeYaz(IkiYonluListem* liste);
		void yazdir();
};


#endif