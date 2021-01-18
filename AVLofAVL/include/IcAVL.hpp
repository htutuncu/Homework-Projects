/**
* @file IcAVL.hpp
* @description IcAVL agacinin kokunu ve fonksiyonlarini tanimlar.
* @course 1.Ogretim B grubu
* @assignment 2
* @date 27.12.2020
* @author Hikmet Tutuncu     hikmet.tutuncu1@ogr.sakarya.edu.tr
*/
#ifndef ICAVL_HPP
#define ICAVL_HPP 
#include "Calisan.hpp"

class IcAVL{
    public:
        Calisan* root;
        IcAVL();
        Calisan* AraVeEkle(Calisan* alt_dugum,const string isim, const int yil);
        void Postorder(Calisan*);
        int Yukseklik(Calisan* alt_Dugum);
        Calisan* SolCocukIleDegistir(Calisan* alt_Dugum);
        Calisan* SagCocukIleDegistir(Calisan* alt_Dugum);
        void Ekle(string isim,int yil);
        void Postorder();
        int Yukseklik();
};







#endif