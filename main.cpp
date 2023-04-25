#include <iostream>
#include "organizm.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"
#include "nisza.h"
#include "osobniki.h"
using namespace std;

void drukujOrganizm(const Organizm & o);

void wyswietl(UstawieniaSymulacji &UST)
{
    cout<<"Znak glon:"<<UST.znakGlon
        <<"zycieMin:"<<UST.glonZycieMin
        <<"zycieMax:"<<UST.glonZycieMax<<endl;
}

string nazwaRodzaju(RodzajMieszkanca rodzaj){
    switch(rodzaj){
    case GLON: return "GLON";
    case GRZYB: return "GRZYB";
    case BAKTERIA: return "BAKTERIA";
    case PUSTKA: return "PUSTKA";
    case SCIANA: return "SCIANA";
    case TRUP: return "TRUP";
    case NIEZNANE: return "NIEZNANE";
    }
}

static Nisza n1,n2,n3;
static char sep = UstawieniaSymulacji::pobierzUstawienia().znakSeparator;

void wyswietlNisze()
{
    cout<<n1.jakiSymbol()<<sep<<n2.jakiSymbol()<<sep<<n3.jakiSymbol()<<endl;
}

int main()
{
    Sasiedztwo sasiedztwo;
    sasiedztwo.okreslSasiada(P,GLON);
    sasiedztwo.okreslSasiada(PG,GRZYB);
    sasiedztwo.okreslSasiada(G,GRZYB);
    sasiedztwo.okreslSasiada(LG,GLON);
    sasiedztwo.okreslSasiada(L,BAKTERIA);
    sasiedztwo.okreslSasiada(LD,BAKTERIA);
    sasiedztwo.okreslSasiada(D,GLON);
    sasiedztwo.okreslSasiada(PD,PUSTKA);
    cout<<"Przeglad sasiedztwa:"<<endl;
    for(int i=0;i<8;i++){
        Polozenie p = static_cast<Polozenie>(i);
        RodzajMieszkanca r = sasiedztwo.ktoJestSasiadem(p);
        cout<<"Polozenie: "<< p <<" rodzaj:"<<nazwaRodzaju(r)<<endl;
    }
    cout<<endl<<"Policzenie sasiadow"
        <<"okreslonego rodzaju: "<<endl
        <<" glony="<<sasiedztwo.ile(GLON)<<endl
        <<" grzyb=" <<sasiedztwo.ile(GRZYB)<<endl
        <<" trupy="<<sasiedztwo.ile(TRUP)<<endl;
    cout<<endl<<"Wylosowanie sasiada:"<<endl
        <<"glon ->"
        <<sasiedztwo.losujSasiada(GLON)<<endl
        <<"Pustka ->"
        <<sasiedztwo.losujSasiada(PUSTKA)<<endl
        <<"Trup->"
        << sasiedztwo.losujSasiada(TRUP)<<endl;
    long wiersz, kolumna;
    cout<<endl
       <<"Zmiana Indeksow [1][1]"
      <<"wg polozenia:"<<endl;
    for(int i=0;i<8;i++){
        Polozenie p = static_cast<Polozenie>(i);
        wiersz = 1; kolumna=1;
       Sasiedztwo::zmienIndeksyWgPolozenia(p,wiersz,kolumna);
       cout<<"Polozenie: "<<p<<" ->["<<wiersz<<"]["<<kolumna<<"]"<<endl;
    }

    cout<<"Puste nisze: ";
    wyswietlNisze();
    cout<<"Lokowanie mieszkancow: ";
    n1.przyjmijLokatora(new Glon());
    n3.przyjmijLokatora(new Grzyb());
    wyswietlNisze();

    cout<<"Przesuwanie lokatorow: ";
    n2=n1;
    wyswietlNisze();

    cout<<"Przesuwanie lokatorow: ";
    n3=n2;
    wyswietlNisze();
    cout<<endl;

    Nisza nisza;
    nisza.przyjmijLokatora(new Bakteria());

    cout<<"Kto w niszy: "<<nisza.ktoTuMieszka()<<endl;
    cout<<"Czy zywy: "<<nisza.lokatorZywy()<<endl;

    Sasiedztwo sasiedztwo;
    sasiedztwo.okreslSasiada(P,GLON);
    sasiedztwo.okreslSasiada(PG,GLON);
    sasiedztwo.okreslSasiada(G,GRZYB);
    sasiedztwo.okreslSasiada(LG,GLON);
    sasiedztwo.okreslSasiada(L,BAKTERIA);
    sasiedztwo.okreslSasiada(LD,BAKTERIA);
    sasiedztwo.okreslSasiada(D,GLON);
    sasiedztwo.okreslSasiada(PD,PUSTKA);

    ZamiarMieszkanca zamiar = nisza.aktywujLokatora(sasiedztwo);

    cout<<"Akcja: "<<zamiar.akcja<<" gdzie: "<<zamiar.gdzie<<endl;
    cout<<endl;

    return 0;
}

void drukujOrganizm(const Organizm & o){
    cout<<"licznikZycia: "
        <<o.stanLicznikaZycia()
        <<" licznikPosilkow:"
        <<o.stanLicznikaPosilkow()<<endl
        <<" limitPosilkow:"
        <<o.limitPosilkow
        <<" kosztPotomka:"
        <<o.kosztPotomka<<endl
        <<"glodny: "<<o.glodny()
        <<" paczkujacy: "
        <<o.paczkujacy()<<endl<<endl;
}


