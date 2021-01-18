/**
* @file main.cpp
* @description Bu program "sayilar.txt" dosyasini okuyarak her satir icin ayri bir Iki Yonlu Bagli Liste olusturur.
*              Iki yonlu bagli listeler icerisinde sadece orta dugumu gosteren bir gosterici bulundurur.
*              Olusan listeler de ayri bir buyuk listede tutulur. Olusan listelerdeki ListeOrta gostericisinin gosterdigi
*              degerlerden en kucuk ve en buyuk olan iki liste secilir. Bu iki liste caprazlamaya tabi tutulur.
*              Program en sonda bu iki listenin son halini ekrana bastirir.
*              Ekrana yazilan adres de ListeOrta dugumunun heap bellek bolgesindeki adresidir.
* @course 1.Ogretim B grubu
* @assignment 1
* @date 14.11.2020
* @author Hikmet Tutuncu        hikmettutuncu@outlook.com
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BenimListem.hpp"

using namespace std;

void caprazlaVeYazdir(BenimListem*,int);
int kacSatir() throw();

int main(){
    
    try{
        int satirSayisi = kacSatir();       // Satir sayisi hesaplanir.
        ifstream sayilar("sayilar.txt");    // Sayilar dosyadan okumak icin ifstream'e alinir.
        
        // Her satirda olusan Iki yonlu bagli listeler BenimListem tipindeki dizi ile tutulur. Satir sayisi bu dizinin kapasitesidir.
        BenimListem *listelerListesi = new BenimListem [satirSayisi];
        
        int sayici = 0;
        string satir;
        while(getline(sayilar, satir, '\n')){   // Dosyadan okunan her satir okunarak "satir" degiskenine alinir.
            int kapasite = 1;
            
            // Satirda kac adet bosluk oldugunu sayarak, kac adet sayi oldugu hesaplaniyor. Kapasite degiskenine aliniyor.
            for( int j=0; satir[j]!='\0'; j++)
                if( satir[j] == ' ' )
                    kapasite++;
            
            // Satirdaki sayilari saklayacak olan tam sayi dizisi dinamik olarak olusturuluyor.
            // Her satir okundugunda satirdaki sayi kadar kapasiteye sahip yeni bir dizi olusturuluyor.
            int *dizi = new int(kapasite);

            // Okunup string icerisine alinan satiri tam sayilara ayirip diziye atama yapiliyor. Stringstream kullaniliyor.
            stringstream SatirStream;
            SatirStream << satir;
            string geciciBirStr;
            int bulunanSayi,i=0;
            while( !SatirStream.eof()){
                SatirStream >> geciciBirStr;
                if(stringstream(geciciBirStr) >> bulunanSayi ){
                    dizi[i] = bulunanSayi;
                    i++;
                }
                geciciBirStr = "";
            }
            
            // Iki yonlu bagli liste tanimlaniyor ve Ekle() methodu ile tam sayi dizisi bagli listeye eklenmek uzere gonderiliyor.
            BenimListem liste(kapasite);
            liste.Ekle(dizi);
            //liste.Yazdir();   //  Bu yorum satiri acilarak sayilarin dogru sekilde eklenip eklenmedigi gorulebilir.

            // Olusan iki yonlu dairesel bagli liste BenimListem tipindeki diziye ekleniyor ve sayici degiskeni arttiriliyor.
            // Bu sayede her satirda olusan bagli listeler listelerListesi dizisinde saklanmis oluyor.
            listelerListesi[sayici] = liste;
            sayici++;
            delete dizi;        // Her satir sonunda dizi dinamik oldugu icin temizleniyor.
            dizi = nullptr;         
        }


        sayilar.close();
        caprazlaVeYazdir(listelerListesi,satirSayisi);  // Olusan buyuk liste islem yapilmak uzere caprazlaVeYazdir fonksiyonuna gonderiliyor.
    }
    catch(...){         // Dosyanin acilamadigi durumlarda hata verilip program sonlaniyor.
        cout << "Dosya acilamadi." << endl;
    }
    
    return 0;
}


// Bu fonksiyon iki yonlu bagli listelerin saklandigi buyuk diziyi alarak en kucuk ve en buyuk ListeOrta'ya sahip
// listeleri belirler. Bu listeler arasinda caprazlama yapar ve ekrana bastirir.
void caprazlaVeYazdir(BenimListem* liste,int satirSayisi){
    Dugum enKucuk(1);   // ListeOrta degeri en kucuk ve en buyuk olan listelerin listeOrta gostericileri olusturuluyor.
    Dugum enBuyuk(1);
    int enKucukKapasite = liste[0].getKapasite(),enBuyukKapasite = liste[0].getKapasite();
    int enKucukIndis=0,enBuyukIndis=0;

    // ListeOrta degeri en kucuk olan liste ve gerekli bilgiler hesaplaniyor.
    enKucuk.sayi = liste[0].ListeOrta->sayi;
    for(int i=1; i<satirSayisi; i++){
        if(enKucuk.sayi > liste[i].ListeOrta->sayi){
            enKucuk.sayi = liste[i].ListeOrta->sayi;
            enKucukKapasite = liste[i].getKapasite();
            enKucukIndis = i;
        }
    }
    // ListeOrta degeri en buyuk olan liste ve gerekli bilgiler hesaplaniyor.
    enBuyuk.sayi = liste[0].ListeOrta->sayi;
    for(int i=1; i<satirSayisi; i++){
        if(enBuyuk.sayi < liste[i].ListeOrta->sayi){
            enBuyuk.sayi = liste[i].ListeOrta->sayi;
            enBuyukKapasite = liste[i].getKapasite();
            enBuyukIndis = i;
        }
    }
    BenimListem kucukListe(enKucukKapasite);
    BenimListem buyukListe(enBuyukKapasite);

    // Bulunan en kucuk ve en buyuk ListeOrta degeri olan listeler yeni listelere ataniyor.
    kucukListe.ListeOrta = liste[enKucukIndis].ListeOrta;
    buyukListe.ListeOrta = liste[enBuyukIndis].ListeOrta;

    // En buyuk ve en kucuk listelerin orta dugumlerinin degerleri yer degistiriyor. (Swap islemi)
    int geciciSayi;
    geciciSayi = kucukListe.ListeOrta->sayi;
    kucukListe.ListeOrta->sayi = buyukListe.ListeOrta->sayi;
    buyukListe.ListeOrta->sayi = geciciSayi;
    
    
    Dugum *geciciDugum = kucukListe.ListeOrta;
    Dugum *geciciDugum2 = kucukListe.ListeOrta;

    // Kucuk liste icin ilk once dairesel yapi bozularak normal iki yonlu bagli listeye donusturuluyor.
    for(int i=0; i<kucukListe.getKapasite()/2; i++)
        geciciDugum = geciciDugum->sol;
    geciciDugum->sol = NULL;

    for(int i=0; i<kucukListe.getKapasite()/2; i++)
        geciciDugum2 = geciciDugum2->sag; 
    geciciDugum2->sag = NULL;
    // En kucuk orta degerli listenin dugumleri bastan sona yer degistiriyor. ( Reverse islemi)
    while (geciciDugum != NULL) 
    { 
        geciciDugum2 = geciciDugum->sol; 
        geciciDugum->sol = geciciDugum->sag; 
        geciciDugum->sag = geciciDugum2;             
        geciciDugum = geciciDugum->sol; 
    }
    // En son olarak dairesel yapinin korunmasi icin tekrardan ilk ve son dugum baglantisi yapiliyor.
    geciciDugum = kucukListe.ListeOrta;
    geciciDugum2 = kucukListe.ListeOrta;
    for(int i=0; i<kucukListe.getKapasite()/2; i++)
        geciciDugum = geciciDugum->sol;
    for(int i=0; i<kucukListe.getKapasite()/2; i++)
        geciciDugum2 = geciciDugum2->sag;
    geciciDugum->sol = geciciDugum2;
    geciciDugum2->sag = geciciDugum;

    
    geciciDugum = buyukListe.ListeOrta;
    geciciDugum2 = buyukListe.ListeOrta;
    // Buyuk liste icin ilk once dairesel yapi bozularak normal iki yonlu bagli listeye donusturuluyor.
    for(int i=0; i<buyukListe.getKapasite()/2; i++)
        geciciDugum = geciciDugum->sol;
    geciciDugum->sol = NULL;

    for(int i=0; i<buyukListe.getKapasite()/2; i++)
        geciciDugum2 = geciciDugum2->sag; 
    geciciDugum2->sag = NULL;
    // En kucuk orta degerli listenin dugumleri bastan sona yer degistiriyor. ( Reverse islemi)
    while (geciciDugum != NULL) 
    { 
        geciciDugum2 = geciciDugum->sol; 
        geciciDugum->sol = geciciDugum->sag; 
        geciciDugum->sag = geciciDugum2;             
        geciciDugum = geciciDugum->sol; 
    }

    geciciDugum = buyukListe.ListeOrta;
    geciciDugum2 = buyukListe.ListeOrta;

    // En son olarak dairesel yapinin korunmasi icin tekrardan ilk ve son dugum baglantisi yapiliyor.
    for(int i=0; i<buyukListe.getKapasite()/2; i++)
        geciciDugum = geciciDugum->sol;
    for(int i=0; i<buyukListe.getKapasite()/2; i++)
        geciciDugum2 = geciciDugum2->sag;
    geciciDugum->sol = geciciDugum2;
    geciciDugum2->sag = geciciDugum;

    // Son olarak ekrana bastirma islemleri gerceklestiriliyor.
    cout << "En Buyuk Liste Orta Dugum Adres: " << &kucukListe.ListeOrta << endl;
    cout << "En Buyuk Liste Degerler:" << endl;
    kucukListe.Yazdir();
    cout << endl;

    cout << "En Kucuk Liste Orta Dugum Adres: " << &buyukListe.ListeOrta << endl;
    cout << "En Kucuk Liste Degerler:" << endl;
    buyukListe.Yazdir();
    cout << endl;

    
}

// Dosyanin kac satir oldugunu bulmak icin bu fonksiyon kullaniliyor.
// Geri donus degeri toplam satir sayisi.
// Eger dosya acilamaz ise hata firlatiliyor.
int kacSatir() throw(){
    int satirSayisi = 0;
    string str;
    ifstream kacSatir("sayilar.txt");
    if(!kacSatir.is_open())
        throw "Dosya acilamadi.";
    else{
        while(getline(kacSatir,str,'\n'))
            ++satirSayisi;
    }
    kacSatir.close();

    return satirSayisi;
}