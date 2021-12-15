/** @file */
#ifndef POZOSTALE_H
#define POZOSTALE_H
#include "struktury.h"
#include "wierzcholki.h"
#include "cykle.h"
#include <string>
#include <fstream>
#include <cstring>


/** Funkcja interpretuje parametry wywo³ania programu.
@param argc liczba parametrów
@param argv[] tablica parametrów
@param[out] nazwa_pliku_wejsciowego nazwa pliku, w którym znajduje siê graf
@param[out] nazwa_pliku_wyjsciowego nazwa pliku, do którego funkcja zapisze znalezione cykle
@return true je¿eli uda³o siê odczytaæ obie nazwy plików, false jeœli nie
*/
bool Odczyt_parametrow(int argc, char* argv[], std::string& nazwa_pliku_wejsciowego, std::string& nazwa_pliku_wyjsciowego);

/** Funkcja tworzy listê wierzcho³ków na podstawie pliku wejœciowego.
@param nazwa_pliku nazwa pliku, w którym znajduje siê graf
@return adres pocz¹tku listy wierzcho³ków
*/
wierzcholek* Odczyt_z_pliku(std::string nazwa_pliku);

/** Funkcja zapisuje wszystie cykle z listy do pliku o podanej nazwie, a nastêpnie usuwa listê cykli.
@param[in,out] pListaCykli lista cykli, które zostan¹ zapisane, po wykonaniu funkcji pListacykli=nullptr
@param nazwa_pliku nazwa pliku, do którego cykle zostan¹ zapisane
*/
void zapis_do_pliku(cykl*& pListaCykli, std::string nazwa_pliku);

/**Funkcja przeszukuj¹ca graf w g³¹b w poszukiwaniu cykli.
@param pSprawdzanyWierzcholek wierzcholek, wœród którego s¹siadów jest szukany wierzcho³ek startowy
@param startowy_wierzcholek numer startowego wierzcho³ka
@param pPrzebytaDroga droga, któr¹ funkcja przeby³a do obecnego wierzcho³ka
@param pListaCykli lista, do której s¹ zapisywane znalezione cykle
*/
void znajdz_cykle(wierzcholek* pSprawdzanyWierzcholek, const int startowy_wierzcholek, droga*& pPrzebytaDroga, cykl*& pListaCykli);
#endif