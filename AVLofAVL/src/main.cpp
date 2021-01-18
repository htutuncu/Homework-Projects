/**
* @file main.cpp
* @description Veri.txt dosyasini okuyarak firma, calisan ve yil bilgilerini alir. Bu bilgilere gore ic ice
*			   AVL agaclari olusturur. Dis AVL agacinin her bir dugumu icerisinde calisanlarin da tutuldugu baska bir
*              AVL agaci mevcuttur. main.cpp dosyasi veri.txt'yi okuyarak bilgileri olusturmak icin fonksiyonlara gonderir.
* @course 1.Ogretim B grubu
* @assignment 2
* @date 27.12.2020
* @author Hikmet Tutuncu     hikmet.tutuncu1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Firma.hpp"
#include "Calisan.hpp"
#include "IcAVL.hpp"
#include "DisAVL.hpp"

using namespace std;

int main(int argc, char const *argv[]){

	SetConsoleOutputCP(65001);					// Turkce karakterlerin konsola yazdirilmasi icin kullanildi.
	ifstream dosya("Veri.txt");
	string satir;
	DisAVL* disavl = new DisAVL();				// Dis AVL agaci tanimlaniyor.

	while(getline(dosya, satir, '\n')){			// Dosyadan satir satir okuma yapar.
		istringstream ss(satir);
    	string token;
    	getline(ss,token,'#');					// ilk #'den onceki string firma ismidir.
    	string firmaAdi = token;
		getline(ss,token,'#');
    	string calisanAdi = token;				// Ikinci #'den onceki calisan ismidir.
    	getline(ss,token,'#');
    	int yil = stoi(token);					// Son kalan string calisanin ise giris yilidir.
		
		Calisan* calisan = new Calisan(calisanAdi,yil);		// Calisan dugumu olusturulur.
		Firma* firma = new Firma(firmaAdi,calisan);			// Firma dugumu olusturulur.
		disavl->Ekle(firma,calisan);		// Dis AVL agacina firma ve calisan gonderiliyor.
		
		delete calisan;
		delete firma;
	}
	cout<<endl;
	disavl->Postorder();					// Olusan genel yapinin Postorder olarak ekrana bastirilmasi.
	cout << endl;
	
	delete disavl;
	
	return 0;
}
