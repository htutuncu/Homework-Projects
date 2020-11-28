/**
* @file BenimListem.cpp
* @description BenimListem.cpp dosyasi BenimListem olarak olusan Iki Yonlu Dairesel Bagli listenin fonksiyon iceriklerini icerir.
* @course 1.Ogretim B grubu
* @assignment 1
* @date 14.11.2020
* @author Hikmet Tutuncu        hikmettutuncu@outlook.com
*/
#include <iostream>

using namespace std;
#include "Dugum.hpp"
#include "BenimListem.hpp"

Dugum::Dugum(int sayi){
    this->sayi = sayi;
}


BenimListem::BenimListem(){}

BenimListem::BenimListem(int kapasite){
    this->kapasite = kapasite;
}

// Ekle methodu gonderilen diziyi alarak iki yonlu dairesel bagli liste olusturur.
void BenimListem::Ekle(int* dizi){
    ListeOrta = new Dugum(dizi[0]);     // Dizinin ilk elemani ListeOrta gostericisinin degeridir.
    
    Dugum *gecici = ListeOrta;

    for(int i=1; i<=this->kapasite/2; i++){     // Listenin sol tarafina dugumler ekleniyor.
        Dugum *yeniDugum = new Dugum(dizi[i]);
        gecici->sol = yeniDugum;
        yeniDugum->sag = gecici;
        gecici = gecici->sol;
        gecici->sol = NULL;
        
    }
    Dugum *gecici2 = ListeOrta;
    for(int j = kapasite/2+1; j<=kapasite; j++){    // Listenin sag tarafina dugumler ekleniyor.
        Dugum *yeniDugum = new Dugum(dizi[j]);
        gecici2->sag = yeniDugum;
        yeniDugum->sol = gecici2;
        gecici2 = gecici2->sag;
        gecici2->sag = NULL;
    }
    // Iki yonlu bagli listenin ilk ve son elemanlari birbirine baglaniyor. Dolayisiyla dairesel liste olmus oluyor.
    gecici->sol = gecici2;
    gecici2->sag = gecici;
}

// Yazdir methodu iki yonlu dairesel bagli listeyi ekrana bastirir.
void BenimListem::Yazdir(){
    Dugum *geciciDugum = ListeOrta;

    for(int i=0; i<kapasite/2; i++)
        geciciDugum = geciciDugum->sol;

    for(int i=0; i<kapasite; i++){
        cout << geciciDugum->sayi << " " ;
        geciciDugum = geciciDugum->sag;
    }
    cout << endl;
}

int BenimListem::getKapasite() const{
    return this->kapasite;
}