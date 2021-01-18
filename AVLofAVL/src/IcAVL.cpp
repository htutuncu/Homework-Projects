/**
* @file IcAVL.cpp
* @description IcAVL agacinin kokunu ve fonksiyonlarini tanimlar.
* @course 1.Ogretim B grubu
* @assignment 2
* @date 27.12.2020
* @author Hikmet Tutuncu     hikmet.tutuncu1@ogr.sakarya.edu.tr
*/
#include "IcAVL.hpp"
#include "Calisan.hpp"
#include <iostream>
#include <string>

using namespace std;


IcAVL::IcAVL(){
    root = NULL;
}

// Ic AVL agacina ekleme yapar.
void IcAVL::Ekle(string isim,int yil){
    root = AraVeEkle(root,isim,yil);
}

// Ic AVL agacinin her bir dugumunun olusmasi.
Calisan::Calisan(string isim,int yil){
    this->yil = yil;
    calisanAdi = isim;
    sol = NULL;
    sag = NULL;
    yukseklik = 0;
}

// Gonderilen calisan bilgilerine gore Ic AVL agacina ekleme yapar.
Calisan* IcAVL::AraVeEkle(Calisan* alt_dugum,const string isim, const int yil){
    if(alt_dugum == NULL){
        alt_dugum = new Calisan(isim,yil);
    }
    else if( yil >= alt_dugum->yil){
        alt_dugum->sol = AraVeEkle(alt_dugum->sol,isim,yil);
        if(Yukseklik(alt_dugum->sol) - Yukseklik(alt_dugum->sag) == 2){
			// Sol Sol Durumu 
			if(yil >= alt_dugum->sol->yil)
				alt_dugum = SolCocukIleDegistir(alt_dugum); 
			else{ //Sol Sa� Durumu
				alt_dugum->sol = SagCocukIleDegistir(alt_dugum->sol); 
				alt_dugum = SolCocukIleDegistir(alt_dugum);
			}
		}
    }
    else if( 2020-yil < alt_dugum->yil){
        alt_dugum->sag = AraVeEkle(alt_dugum->sag,isim,yil);
        if(Yukseklik(alt_dugum->sag) - Yukseklik(alt_dugum->sol) == 2){
			// Sa� Sa� Durumu
			if(yil < alt_dugum->sag->yil)
				alt_dugum = SagCocukIleDegistir(alt_dugum);
			else{// Sa� Sol Durumu 
				alt_dugum->sag = SolCocukIleDegistir(alt_dugum->sag); 
				alt_dugum = SagCocukIleDegistir(alt_dugum); 
			}
		}
    }

    alt_dugum->yukseklik = Yukseklik(alt_dugum);

    return alt_dugum;
}

// Sola dondurme fonksiyonu.
Calisan* IcAVL::SolCocukIleDegistir(Calisan* alt_Dugum){
    Calisan *tmp = alt_Dugum->sol; 
	alt_Dugum->sol = tmp->sag; 		  
	tmp->sag = alt_Dugum; 
		  
	// Yukseklikleri Guncelle 
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum); 
	tmp->yukseklik = max(Yukseklik(tmp->sol),alt_Dugum->yukseklik)+1;
			
	return tmp;
}

// Saga dondurme fonksiyonu.
Calisan* IcAVL::SagCocukIleDegistir(Calisan* alt_Dugum){
    Calisan *tmp = alt_Dugum->sag; 
	alt_Dugum->sag = tmp->sol;
	tmp->sol = alt_Dugum;
		  
    // Yukseklikleri Guncelle 
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum); 
	tmp->yukseklik = max(Yukseklik(tmp->sag),alt_Dugum->yukseklik)+1;

	return tmp;
}

// Yuksekligi geri dondurur.
int IcAVL::Yukseklik(Calisan* alt_Dugum){
    if(alt_Dugum == NULL ) return -1;
    return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
}

int IcAVL::Yukseklik(){
    return Yukseklik(root);
}

// Gonderilen Ic AVL agacinin postorder olarak ekrana basilmasi.
void IcAVL::Postorder(Calisan *alt_Dugum){
	if(alt_Dugum != NULL){
		Postorder(alt_Dugum->sol);
		Postorder(alt_Dugum->sag);				
		cout<<alt_Dugum->calisanAdi << "–" << alt_Dugum->yil<<" | ";
	}
}

void IcAVL::Postorder(){
    Postorder(root);
}

// maksimum degeri geri donduren yardimci fonksiyon.
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}

