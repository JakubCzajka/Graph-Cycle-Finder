/** @file */
#ifndef POZOSTALE_H
#define POZOSTALE_H
#include "struktury.h"
#include "wierzcholki.h"
#include "cykle.h"
#include <string>
#include <fstream>
#include <cstring>


/** Funkcja interpretuje parametry wywo�ania programu.
@param argc liczba parametr�w
@param argv[] tablica parametr�w
@param[out] nazwa_pliku_wejsciowego nazwa pliku, w kt�rym znajduje si� graf
@param[out] nazwa_pliku_wyjsciowego nazwa pliku, do kt�rego funkcja zapisze znalezione cykle
@return true je�eli uda�o si� odczyta� obie nazwy plik�w, false je�li nie
*/
bool Odczyt_parametrow(int argc, char* argv[], std::string& nazwa_pliku_wejsciowego, std::string& nazwa_pliku_wyjsciowego);

/** Funkcja tworzy list� wierzcho�k�w na podstawie pliku wej�ciowego.
@param nazwa_pliku nazwa pliku, w kt�rym znajduje si� graf
@return adres pocz�tku listy wierzcho�k�w
*/
wierzcholek* Odczyt_z_pliku(std::string nazwa_pliku);

/** Funkcja zapisuje wszystie cykle z listy do pliku o podanej nazwie, a nast�pnie usuwa list� cykli.
@param[in,out] pListaCykli lista cykli, kt�re zostan� zapisane, po wykonaniu funkcji pListacykli=nullptr
@param nazwa_pliku nazwa pliku, do kt�rego cykle zostan� zapisane
*/
void zapis_do_pliku(cykl*& pListaCykli, std::string nazwa_pliku);

/**Funkcja przeszukuj�ca graf w g��b w poszukiwaniu cykli.
@param pSprawdzanyWierzcholek wierzcholek, w�r�d kt�rego s�siad�w jest szukany wierzcho�ek startowy
@param startowy_wierzcholek numer startowego wierzcho�ka
@param pPrzebytaDroga droga, kt�r� funkcja przeby�a do obecnego wierzcho�ka
@param pListaCykli lista, do kt�rej s� zapisywane znalezione cykle
*/
void znajdz_cykle(wierzcholek* pSprawdzanyWierzcholek, const int startowy_wierzcholek, droga*& pPrzebytaDroga, cykl*& pListaCykli);
#endif