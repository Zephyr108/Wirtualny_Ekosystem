#include <iostream>
#include <ustawienia.h>
#include <ustawieniasymulacji.h>
using namespace std;
#include <generatorlosowy.h>
#include <sasiedztwo.h>
#include <nisza.h>
#include <osobniki.h>
#include <fstream>

//LAB 12.2
int main()
{
            Srodowisko ekoSystem=
        Srodowisko::czytajZPliku("start.txt");


            ofstream plikWynikowy("symulacja.txt");
            if(!plikWynikowy.is_open()) return 1;
            string stanSymulacji;

            unsigned long i=0;

            do
            {
                system("cls");
                cout<<"Krok symulacji: "<<i<<endl;
                plikWynikowy<<"Krok symulacji: "<<i<<endl;
                stanSymulacji=ekoSystem.doTekstu();

                cout<<endl<<stanSymulacji<<endl;
                plikWynikowy<<stanSymulacji<<endl;
                cin.ignore(1);
                ekoSystem++;
                i++;
            }
            while(i<200 && !ekoSystem);

            cout<<endl;
            plikWynikowy.close();
            return 0;
}
//LAB 12
//int main()
//{
//        Srodowisko ekoSystem(8,12);

//        ekoSystem.lokuj(new Glon(),0,10);
//        ekoSystem.lokuj(new Glon(),1,10);
//        ekoSystem.lokuj(new Glon(),1,13);
//        ekoSystem.lokuj(new Glon(),3,10);
//        ekoSystem.lokuj(new Grzyb(),1,11);
//        ekoSystem.lokuj(new Grzyb(),0,0);
//        ekoSystem.lokuj(new Bakteria(),3,3);
//        ekoSystem.lokuj(new Bakteria(),2,6);

//        ofstream plikWynikowy("symulacja.txt");
//        if(!plikWynikowy.is_open()) return 1;
//        string stanSymulacji;

//        unsigned long i=0;

//        do
//        {
//            system("cls");
//            cout<<"Krok symulacji: "<<i<<endl;
//            plikWynikowy<<"Krok symulacji: "<<i<<endl;
//            stanSymulacji=ekoSystem.doTekstu();

//            cout<<endl<<stanSymulacji<<endl;
//            plikWynikowy<<stanSymulacji<<endl;
//            cin.ignore(1);
//            ekoSystem++;
//            i++;
//        }
//        while(i<200 && !ekoSystem);

//        cout<<endl;
//        plikWynikowy.close();
//        return 0;
//}
//LAB 11.3
//int main()
//{
//    Srodowisko ekoSystem(8,12);

//    ekoSystem.lokuj(new Glon(),0,10);
//    ekoSystem.lokuj(new Glon(),1,10);
//    ekoSystem.lokuj(new Glon(),0,13);
//    ekoSystem.lokuj(new Glon(),3,10);
//    ekoSystem.lokuj(new Grzyb(),1,11);
//    ekoSystem.lokuj(new Grzyb(),0,0);
//    ekoSystem.lokuj(new Bakteria(),3,3);
//    ekoSystem.lokuj(new Bakteria(),2,6);

//    unsigned long i=0;

//    do
//    {
//        system("cls");
//        cout<< "Krok symulacji: "<<i<<endl;
//        cout << endl<<ekoSystem<<endl;

//        cin.ignore(1);
//        ekoSystem++;
//        i++;
//    } while(i<200 && !ekoSystem);

//    cout <<endl;
//    return 0;
//}
//LAB 11.2
//int main()
//{
//    Srodowisko ekoSystem(8,12);

//    ekoSystem.lokuj(new Glon(),0,10);
//    ekoSystem.lokuj(new Glon(),1,10);
//    ekoSystem.lokuj(new Glon(),0,13);
//    ekoSystem.lokuj(new Glon(),3,10);
//    ekoSystem.lokuj(new Grzyb(),1,11);
//    ekoSystem.lokuj(new Grzyb(),0,0);
//    ekoSystem.lokuj(new Bakteria(),3,3);
//    ekoSystem.lokuj(new Bakteria(),2,6);

//    unsigned long i=0;

//    do
//    {
//        system("clear");
//        cout<< "Krok symulacji: "<<i<<endl
//             << endl<<ekoSystem.doTekstu()<<endl;

//        cin.ignore(1);
//        ekoSystem.wykonjKrokSymulacji();
//        i++;
//    } while(i<200 && !ekoSystem.martwy());

//    cout <<endl;
//    return 0;
//}

//LAB 11
//int main()
//{
//    for(Indeks2D & I:GEN::indeksyLosowe(2,4) )
//    cout<<"{"<<I.wiersz<<", "<<I.kolumna<<"}\n";
//}

//LAB 7
/*
int main()
{
    Nisza nisza;
    nisza.przyjmijLokatora(new Bakteria());

    cout << "Kto w niszy: "
         << nisza.ktoTuMieszka() <<endl;
    cout << "Czy żywy: "
         << nisza.lokatorZywy() << endl;

    Sasiedztwo sasiedztwo;
    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG, GRZYB);
    sasiedztwo.okreslSasiada(G, GRZYB);
    sasiedztwo.okreslSasiada(LG, GLON);
    sasiedztwo.okreslSasiada(L, BAKTERIA);
    sasiedztwo.okreslSasiada(LD, BAKTERIA);
    sasiedztwo.okreslSasiada(D, GLON);
    sasiedztwo.okreslSasiada(PD, PUSTKA);

//    ZamiarMieszkanca zamiar =
//        nisza.aktywujLokatora(sasiedztwo);

//    cout << "Akcja: " << zamiar.akcja << "gdzie: "
//         << zamiar.gdzie << endl;

    cout << endl;
    return 0;
}*/

/*static Nisza n1, n2, n3;

static char sep = UstawieniaSymulacji::
                  pobierzUstawienia().znakSeparator;

void wyswietlNisze()
{
    cout << n1.jakiSymbol() << sep
         << n2.jakiSymbol() << sep
         << n3.jakiSymbol() << endl;
}

int main()
{
    cout << "Puste nisze: ";
    wyswietlNisze();

    cout << "Lokowanie mieszkancow: ";
    n1.przyjmijLokatora(new Glon());
    n3.przyjmijLokatora(new Grzyb());
    wyswietlNisze();

    cout << "przesuwanie lokatorow: ";
    n2=n1;
    wyswietlNisze();

    cout << "przesuwanie lokatorow: ";
    n3=n2;
    wyswietlNisze();

    cout << endl;
    return 0;
}*/


//lab 5
/*string nazwaRodzaju(RodzajMieszkanca rodzaj){
    switch (rodzaj) {
        case GLON: return "GLON";
        case GRZYB: return "GRZYB";
        case BAKTERIA: return "BAKTERIA";
        case PUSTKA: return "PUSTKA";
        case SCIANA: return "SCIANA";
        case TRUP: return "TRUP";
        case NIEZNANE: return "NIEZNANE";
    }
}

int main()
{
    Sasiedztwo sasiedztwo;

    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG,GRZYB);
    sasiedztwo.okreslSasiada(G,GRZYB);
    sasiedztwo.okreslSasiada(LG,GLON);
    sasiedztwo.okreslSasiada(L,BAKTERIA);
    sasiedztwo.okreslSasiada(LD,BAKTERIA);
    sasiedztwo.okreslSasiada(D,GLON);
    sasiedztwo.okreslSasiada(PD,PUSTKA);

    cout << "Przeglad sasiada: " << endl;

    for(int i=0; i<8; i++){

        Polozenie p=static_cast<Polozenie>(i);
        RodzajMieszkanca
                r=sasiedztwo.ktoJestSasiadem(p);

        cout<<"polozenie="<<p<<"rodzaj="
           <<nazwaRodzaju(r)<< endl;
    }

    cout << endl<< "Policzenie sasiadow "
         <<"okreslonego rodzaju:"<<endl
        <<"glony="<<sasiedztwo.ile(GLON) <<endl
       << "grzyby=" <<sasiedztwo.ile(GRZYB)<<endl
       <<"trupy=" <<sasiedztwo.ile(TRUP) <<endl;

    cout <<endl<< "Wylosowanie sasiada:" <<endl
        <<"glon->"
       <<sasiedztwo.losujSasiada(GLON)<<endl
      <<"pustka->"
     <<sasiedztwo.losujSasiada(PUSTKA)<<endl
    <<"trup->"
    <<sasiedztwo.losujSasiada(TRUP)<< endl;

    long wiersz, kolumna;
    cout<<endl
       <<"Zmiana indekow [5] [7]"
      <<"wg polozenia: "<<endl;

    for(int i=0; i<8; i++){
        Polozenie p=static_cast<Polozenie>(i);
        wiersz =5; kolumna=7;

        Sasiedztwo::
                zmienIdeksyWgPolozenia(p, wiersz,kolumna);

        cout<<"polozenie: "<<p<<"->["<<wiersz
           <<"]["<<kolumna<<"]"<<endl;
    }
    cout<<endl;

    return 0;
}*/





/*int main() //lab_4
{
    cout << "Liczby losowe typu int:" << endl;
    cout << " od O do 5: ";
    for(int i=0; i<10; i++)
        cout << GEN::losujOdZeraDo(5) << " ";
    cout << endl << " od O do 3: ";
    for(int i=0; i<10; i++)
        cout << GEN::losujOdZeraDo(3) << " ";
    cout << endl << " od 0   do 20: ";
    for(int i=0; i<10; i++)
        cout << GEN::losujOdZeraDo(20) << " ";
    cout << endl << endl;
    cout << "Liczby losowe typu long: " << endl;
    cout << " od -2 do 2:";
    for(int i=0; i<10; i++)
        cout << GEN::losujPomiedzy(-2L, 2L) <<" ";
    cout << endl << endl
         << "Liczby losowe typu unsigned short: " << endl;
    cout << " od 2 do 6: ";
    unsigned short min=2, max=6;
    for(int i=0; i<10; i++)
        cout << GEN::losujPomiedzy(max, min) <<" ";
    cout << endl << endl;
    return 0;
}*/

/*void wyswietl(UstawieniaSymulacji & UST){
    cout<<"znak glon:"<<UST.znakGlon
       <<"zycieMin="<<UST.glonZycieMin
      <<"zycieMax="<<UST.glonZycieMax<<endl;
}

int main() //LAB_3
{
    //1. Dostep do obiektu klasy UstawieniaSymulacji
    UstawieniaSymulacji & UST1
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji & UST2
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji & UST3
            = UstawieniaSymulacji::pobierzUstawienia();

    cout << "Pobieranie ustawien 3x" <<endl;
    cout << "UST1: "; wyswietl(UST1);
    cout << "UST2: "; wyswietl(UST2);
    cout << "UST3: "; wyswietl(UST3);

    cout << endl <<"Zmiana wartosci tylko 1x" <<endl;
    UST2.glonZycieMax = 100;
    cout << "UST1: "; wyswietl(UST1);
    cout << "UST2: "; wyswietl(UST2);
    cout << "UST3: "; wyswietl(UST3);
    return 0;
}*/
