/**
* @file BenimListem.hpp
* @description Iki yonlu dairesel bagli listenin tanimlamasini icerir.
* @course 1.Ogretim B grubu
* @assignment 1
* @date 14.11.2020
* @author Hikmet Tutuncu        hikmettutuncu@outlook.com
*/
#ifndef BENIMLISTEM_HPP
#define BENIMLISTEM_HPP

#include "Dugum.hpp"

class BenimListem{
    private:
        int kapasite;
    public:
        Dugum *ListeOrta;
        BenimListem();
        BenimListem(int kapasite);
        void Ekle(int* dizi);
        void Yazdir();
        int getKapasite() const;
};



#endif