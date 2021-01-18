/**
* @file Calisan.hpp
* @description IcAVL agacinin her bir dugumunu temsil eder.
* @course 1.Ogretim B grubu
* @assignment 2
* @date 27.12.2020
* @author Hikmet Tutuncu     hikmet.tutuncu1@ogr.sakarya.edu.tr
*/
#ifndef CALISAN_HPP
#define CALISAN_HPP
#include <string>
using namespace std;

class Calisan{
    public:
        int yil;
        string calisanAdi;
        Calisan* sag;
        Calisan* sol;
        int yukseklik;
    
        Calisan(string isim,int yil);
};


#endif /* CALISAN_HPP */