/**
* @file DisAVL.cpp
* @description Dis AVL agac yapisini olusturur. Her bir dugum icerisinde ic AVL agaci bulunmaktadir.
* @course 1.Ogretim B grubu
* @assignment 2
* @date 27.12.2020
* @author Hikmet Tutuncu     hikmet.tutuncu1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <string>
#include "Firma.hpp"
#include "Calisan.hpp"
#include "DisAVL.hpp"
#include "IcAVL.hpp"

using namespace std;

DisAVL::DisAVL(){
    root = NULL;
}


Firma::Firma(){}

// Dis agacin her bir dugumu olusturuluyor. Her dugum icerisinde bir de ic AVL agaci bulunuyor.
Firma::Firma(string firma,Calisan* kisi){
    icAVL = new IcAVL();
    icAVL->Ekle(kisi->calisanAdi,kisi->yil);
    firmaAdi = firma;
    yukseklik = 0;
    sag = NULL;
    sol = NULL;
    calisanSayisi = 1;
}

// Dis AVL agaci icin main'den cagirilacak olan ekleme fonksiyonu.
// Eger gonderilen firma ismi daha onceden varsa o firmanin bilgilerini gunceller ve calisan
// agacina ekleme yapar. Eger daha once o firma yoksa normal ekleme yapar.
void DisAVL::Ekle(Firma* firma,Calisan* kisi){
    
    Firma* alt_Dugum = ssearch(firma->firmaAdi,root);
    if( alt_Dugum == NULL){
        root = AraVeEkle(root,firma,kisi);
    }
    else{
        alt_Dugum->calisanSayisi += 1;
        alt_Dugum->icAVL->Ekle(kisi->calisanAdi,kisi->yil);
        if( alt_Dugum->sag != NULL && alt_Dugum->calisanSayisi > alt_Dugum->sag->calisanSayisi ){
            string strtmp = alt_Dugum->firmaAdi;
            int inttemp = alt_Dugum->calisanSayisi;
            IcAVL* tmp = alt_Dugum->icAVL;
            alt_Dugum->icAVL = alt_Dugum->sag->icAVL;
            alt_Dugum->sag->icAVL = tmp;
            alt_Dugum->calisanSayisi = alt_Dugum->sag->calisanSayisi;
            alt_Dugum->firmaAdi = alt_Dugum->sag->firmaAdi;
            alt_Dugum->sag->firmaAdi = strtmp;
            alt_Dugum->sag->calisanSayisi = inttemp;

        }
        else if( alt_Dugum->sol != NULL && alt_Dugum->calisanSayisi < alt_Dugum->sol->calisanSayisi){
            string strtmp = alt_Dugum->firmaAdi;
            int inttemp = alt_Dugum->calisanSayisi;
            IcAVL* tmp = alt_Dugum->icAVL;
            alt_Dugum->icAVL = alt_Dugum->sol->icAVL;
            alt_Dugum->sol->icAVL = tmp;
            alt_Dugum->calisanSayisi = alt_Dugum->sol->calisanSayisi;
            alt_Dugum->firmaAdi = alt_Dugum->sol->firmaAdi;
            alt_Dugum->sol->firmaAdi = strtmp;
            alt_Dugum->sol->calisanSayisi = inttemp;
        }
    }
}

// Bu fonksiyon gonderilen firma bilgisine gore Dis AVL agacinda arama yapar.
// Eger aranan firmayi bulursa o dugumu geri dondurur.
Firma* DisAVL::ssearch(string name, Firma* firma){
    if(firma != NULL){
        if(firma->firmaAdi == name){
           return firma;
        } else {
            Firma* foundNode = ssearch(name, firma->sol);
            if(foundNode == NULL) {
                foundNode = ssearch(name, firma->sag);
            }
            return foundNode;
         }
    } else {
        return NULL;
    }
}

// Gonderilen firma bilgisine gore DisAVL agacina sifirdan ekleme yapar. Dondurme islemlerini de burada yapar.
// Dis AVL agacinin koku geri dondurulur.
Firma* DisAVL::AraVeEkle(Firma* alt_Dugum,const Firma* firma,Calisan* kisi){
    if( alt_Dugum == NULL)
        alt_Dugum = new Firma(firma->firmaAdi,kisi);
    else if( firma->calisanSayisi <= alt_Dugum->calisanSayisi ){
        alt_Dugum->sol = AraVeEkle(alt_Dugum->sol,firma,kisi);
        if(Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2){
			// Sol Sol Durumu 
			if(firma->calisanSayisi <= alt_Dugum->sol->calisanSayisi)
				alt_Dugum = SolCocukIleDegistir(alt_Dugum); 
			else{ //Sol Sa� Durumu
				alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol); 
			    alt_Dugum = SolCocukIleDegistir(alt_Dugum);
			}
		}
    }
    else if( firma->calisanSayisi > alt_Dugum->calisanSayisi ){
        alt_Dugum->sag = AraVeEkle(alt_Dugum->sag,firma,kisi);
        if(Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2){
			// Sa� Sa� Durumu
			if(firma->calisanSayisi > alt_Dugum->sag->calisanSayisi)
				alt_Dugum = SagCocukIleDegistir(alt_Dugum);
			else{// Sa� Sol Durumu 
				alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag); 
				alt_Dugum = SagCocukIleDegistir(alt_Dugum); 
		    }
		}
    }
    alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
    return alt_Dugum;
}

// Sola dondurme fonksiyonu.
Firma* DisAVL::SolCocukIleDegistir(Firma* alt_Dugum){
    Firma* tmp = alt_Dugum->sol; 
	alt_Dugum->sol = tmp->sag; 		  
	tmp->sag = alt_Dugum; 
		  
	// Yukseklikleri Guncelle 
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum); 
	tmp->yukseklik = max(Yukseklik(tmp->sol),alt_Dugum->yukseklik)+1;
			
	return tmp;
}

// Saga dondurme fonksiyonu.
Firma* DisAVL::SagCocukIleDegistir(Firma* alt_Dugum){
    Firma* tmp = alt_Dugum->sag; 
	alt_Dugum->sag = tmp->sol;
	tmp->sol = alt_Dugum;
	
	// Y�kseklikleri G�ncelle 
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum); 
	tmp->yukseklik = max(Yukseklik(tmp->sag),alt_Dugum->yukseklik)+1;
	return tmp;
}

// Gonderilen dugumun yuksekligini hesaplar ve geri dondurur. 
// Ders dokumanlarinda kullanilan fonksiyonlardan donusturulmustur.
int DisAVL::Yukseklik(Firma* alt_Dugum){
	if(alt_Dugum == NULL) return -1; // Ortada d���m yoksa y�kseklik anlams�zd�r. Kodun �al��mas� ad�na -1 verilmektedir.
	    return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
}


int DisAVL::Yukseklik(){
    return Yukseklik(root);
}

// Gonderilen kok dugumun postorder olarak ekrana basilmasi.
void DisAVL::Postorder(Firma* alt_Dugum){
	if(alt_Dugum != NULL){
		Postorder(alt_Dugum->sol);
		Postorder(alt_Dugum->sag);				
		cout<<alt_Dugum->firmaAdi<<endl;
        alt_Dugum->icAVL->Postorder();
        cout<<endl;
	}
}

void DisAVL::Postorder(){
	Postorder(root);
}




