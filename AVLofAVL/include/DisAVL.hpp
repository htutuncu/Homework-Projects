/**
* @file DisAVL.hpp
* @description DisAVL agacinin kokunu ve fonksiyonlarini tanimlar.
* @course 1.Ogretim B grubu
* @assignment 2
* @date 27.12.2020
* @author Hikmet Tutuncu     hikmet.tutuncu1@ogr.sakarya.edu.tr
*/
#ifndef DISAVL_HPP
#define DISAVL_HPP
#include "Firma.hpp"

class DisAVL{
    private:
        Firma* root;
        Firma* AraVeEkle(Firma* alt_Dugum, const Firma* firma,Calisan* kisi);
        int Yukseklik(Firma* alt_Dugum);
        Firma* SolCocukIleDegistir(Firma* altDugum);
        Firma* SagCocukIleDegistir(Firma* alt_Dugum);
        void Postorder(Firma* alt_Dugum);
    public:
        DisAVL();
        int Yukseklik();
        void Ekle(Firma* firma,Calisan* calisan);
        void Postorder();
        Firma* ssearch(string name, Firma* firma);
};





#endif