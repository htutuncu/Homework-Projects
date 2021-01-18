/**
* @file Firma.hpp
* @description DisAVL agacinin her bir dugumunu temsil eder. Icerisinde calisanlarin AVL agacini tutar.
* @course 1.Ogretim B grubu
* @assignment 2
* @date 27.12.2020
* @author Hikmet Tutuncu     hikmet.tutuncu1@ogr.sakarya.edu.tr
*/
#ifndef FIRMA_HPP
#define FIRMA_HPP
#include <string>
#include "Calisan.hpp"
#include "IcAVL.hpp"

class Firma{
    public:
        int calisanSayisi;
        string firmaAdi;
        IcAVL* icAVL;
        int yukseklik;
        Firma* sag;
        Firma* sol;

        Firma();
        Firma(string firma,Calisan* kisi);
        IcAVL* olustur(Calisan kisi);
};


#endif /* FIRMA_HPP */