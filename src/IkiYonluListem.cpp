/**
* @file IkiYonluListem.cpp
* @description IkiYonluListem sınıfım için yazdığım fonksiyonlar
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


IkiYonluListem::IkiYonluListem()
{
	this->ilkDugum=0;
}
//Listenin eleman sayısını döndüren fonksiyonum.
int IkiYonluListem::elemanSayisiGetir(){
			int sayac = 0;
			Dugum* gecici = new Dugum(" ");
			gecici = ilkElemanGetir();
			while (gecici->ileri != 0) {
				gecici = gecici->ileri;
				sayac++;
			}
			return sayac;
		}	
//---------------------------------------------------------------------
//parametresi sıra olan indexGetir fonksiyonum listedeki istenilen düğümü döndürür.
Dugum* IkiYonluListem::indexGetir(int sira){
			int sayac=0;
			Dugum* gecici=ilkDugum;
			while(gecici!=0){
				if(sayac==sira)
					return gecici;
				gecici=gecici->ileri;
				sayac++;
			}
		}
//---------------------------------------------------------------------
//Listeyi gezer ve listenin son eleman düğümünü döndürür.
Dugum* IkiYonluListem::sonElemanGetir(){
			Dugum* gecici = new Dugum(" ");
			gecici = ilkElemanGetir();
			while(gecici->ileri != NULL)
				gecici = gecici->ileri;
			return gecici;
		}
//----------------------------------------------------------------------	
//Bu fonksiyon öncelikle düğüm var mı kontrolü yapar yoksa ilk düğüm olarak eklenir, koşul atlanırsa listeyi döner ve en sona boş stringi olan bir düğüm ekler.
//Eklendiğinde de eleman sayısını bir arttırır.
void IkiYonluListem::listeSonunadugumEkle(){		
		Dugum* yeniDugum= new Dugum(" ");
		
			if(ilkDugum==0){
				ilkDugum=yeniDugum;
				ilkDugum->ileri=0;
				ilkDugum->geri=0;
			}
			else{
				
			    Dugum *gecici=ilkDugum;
		        while(gecici->ileri!=0){
			       gecici=gecici->ileri;
		        }
		        gecici->ileri=yeniDugum;
		        yeniDugum->geri=gecici;
		    }
			elemanSayisi++;
			
		}
//-------------------------------------------------------------------------
// Listenin ilk düğümünü getirir.
Dugum* IkiYonluListem::ilkElemanGetir(){
			return ilkDugum;
		}
//-------------------------------------------------------------------------
void IkiYonluListem::arayaEkle(string ad,int sira,IkiYonluListem* ahsen){
			ahsen->listeSonunadugumEkle();// öncelikle var olan listeye boş stringi olan bir düğüm ekler.
			Dugum* gecici = new Dugum(" "); // gecici bir düğüm oluşturulur
			gecici=ahsen->sonElemanGetir(); // geciciye ahsen listesindeki son eleman atanır.
			for(int sayac = 0 ; sayac<ahsen->elemanSayisiGetir()-sira;sayac++) 
			{
				gecici->isim=gecici->geri->isim; // for dögüsünde sayac (listenin eleman sayısı-sıra) kadar sayıda dönecek çünkü araya ad eklendikten 
				gecici= gecici->geri;            //sonra eklenen yerden bir yanına kayacak şekilde ilerlemelidir. 
			}                                    //daha sonra gecicimizin ismi bi gerisini gösterenin ismi olacak, döngüm tamamlanacak.
			gecici->isim=ad;                     //gecicimin artık isim stringi ad olarak atanır.
		}
//------------------------------------------------------------------------
void IkiYonluListem::aradanSil(int sira, IkiYonluListem* ahsen){
			
			Dugum* gecici;
			gecici=indexGetir(sira); // aslında silmek istediğim düğüm ismini indexGetir fonksiyonu ile çağırıp geciciye atarım ve bundan sonra 
			for(int sayac = 0 ; sayac<ahsen->elemanSayisiGetir()-sira;sayac++)  // gecici üzerinden işlemlerime devam ederim
			{
				if(gecici->ileri!=NULL)               
				{
					gecici->isim = gecici->ileri->isim;  //burda da arayaEkle fonksiyonumda yaptığım gibi gecicilerin gösterdiği isim verilerini kaydırırım.
					gecici = gecici->ileri;
				}
			}
			Dugum* geri= gecici->geri;   //burada alt satırdaki koşulları sağlamak adına gerekli atamalar yaparım ve yeni düğümler oluştururum.
			Dugum* ileri= gecici->ileri;
			delete gecici;      //artık son listedeki son düğüme gelmiş atanmış olan geciciyi silerim.
			if(ileri)
				ileri->geri=geri;  //ileri varsa düğüm bağlama
			if(geri)
				geri->ileri=ileri; //gerisi varsa düğüm bağlama işlemleri tamamlanır.
			else
				ilkDugum=ileri;
          
		}	
//------------------------------------------------------------------------	
//Veri.txt dosyayı okuma ve gerekli işlemlerin yapılmasını sağlayan fonksiyon 
void IkiYonluListem::DosyaOkuListeyeYaz(IkiYonluListem* liste) {
		ifstream file("Veri.txt");
		string line;
		string islem;
		string yazilacakIndex;
		string isim;


		int acmaparantezindex = 0;
		int kapamaparantezindex = 0;
		int kareindex = 0;

		if (file.is_open())
		{
			while (getline(file, line)) //dosya satır satır okunur
			{

				islem = line[0];
				if (islem == "E") { //satırda ilk elemanda E görülünce koşulum başlar
					acmaparantezindex = line.find("(");
					kapamaparantezindex = line.find(")");  
					kareindex = line.find("#");

					int yazilacakIndexilk = (acmaparantezindex + 1);  //bulunmasını istediğim karakterin indexlerini tutarım
					int yazilacakIndexorta = kareindex - 1;
					int yazilacakIndexorta2 = kareindex + 1;
					int yazilacakIndexson = kapamaparantezindex - 1;

					if (yazilacakIndexilk == yazilacakIndexorta) {
						yazilacakIndex = line[yazilacakIndexilk];  
					}
					else if (yazilacakIndexorta > yazilacakIndexilk) {
						for (int i = yazilacakIndexilk; i <= yazilacakIndexorta; i++) {
							yazilacakIndex += line[i];  //saklamak istediğim veriyi döngüyle tutarım
						}
					}
					else {
						cout << "index okumada hata" << endl;
					}

					if (yazilacakIndexson > yazilacakIndexorta2) {
						for (int i = yazilacakIndexorta2; i <= yazilacakIndexson; i++) {
							isim += line[i];  //saklamak istediğim veriyi döngüyle tutarım
						}
					}
					else {
						cout << "isim okumada hata" << endl;
					}

				}

				else if (islem == "S") { //satır başlangıcında S okunduğunda yapılacak işlemler
					kapamaparantezindex = line.find(")");
					acmaparantezindex = line.find("(");
					int yazilacakIndexilk = (acmaparantezindex + 1);
					int yazilacakIndexson = kapamaparantezindex - 1;

					if (yazilacakIndexilk == yazilacakIndexson) {
						yazilacakIndex = line[yazilacakIndexilk]; //saklamak istediğim veriyi döngüyle tutarım
					}
					else if (yazilacakIndexson > yazilacakIndexilk) {
						for (int i = yazilacakIndexilk; i <= yazilacakIndexson; i++) {
							yazilacakIndex += line[i]; //saklamak istediğim veriyi döngüyle tutarım
						}
					}
					else {
						cout << "index okumada hata" << endl;
					}

				}
				else {
							//do nothing
				}
				int innndex = atoi(yazilacakIndex.c_str());
				if (islem == "E") {
					liste->arayaEkle(isim, innndex, liste); //liste için araya ekle fonksiyonumu çağırırım
				}
				else if (islem == "S") {
					if (liste->elemanSayisiGetir() < innndex) {  //eğerki listedeki isim sayısından daha büyük bi silme komutu gelirse listenin sonuna gidip en son ismi siler 
						liste->aradanSil(liste->elemanSayisiGetir(), liste);
					}
					else {
						liste->aradanSil(innndex, liste); //liste için aradan sil fonksiyonumu çağırırım
					}

				}
				else {
							//do nothing
				}

						//cout << yazilacakIndex<< isim <<endl;
				yazilacakIndex = "";
				isim = "";
			}
		}


    }
		
//------------------------------------------------------------------------
void IkiYonluListem::yazdir(){
		Dugum* gecici = ilkDugum;
		while (gecici != 0) { //artık son düğümün içinde olup istenilen listeyi yazdıran fonsiyonum.
			
			cout << gecici->isim;
			if(gecici->ileri!=0)
				cout << "<-->";
			gecici = gecici->ileri;
		}
}