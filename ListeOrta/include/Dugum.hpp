/**
* @file Dugum.hpp
* @description Dugum.hpp dosyasi Dugum sinifinin tanimlamasini icerir.
*              Iki Yonlu Dairesel Bagli Liste'nin her bir dugumunu tanimlar.
* @course 1.Ogretim B grubu
* @assignment 1
* @date 14.11.2020
* @author Hikmet Tutuncu        hikmettutuncu@outlook.com
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

class Dugum{
    public:
        int sayi;
        Dugum *sag;
        Dugum *sol;
        
        Dugum();
        Dugum(int);

};


#endif /* DUGUM_HPP */