/** @file */
#ifndef WIERZCHOLKI_H
#define WIERZCHOLKI_H

#include "struktury.h"
#include <iostream> 
#include <string>
#include <fstream>

/** Funkcja wyszukuje w danej liœcie wierzcho³ków wierzcho³ek o danym numerze i zwraca wskaŸnik na niego.
@param pListaWierzcholkow adres pierwszego elementu listy, w której funkcja szuka wierzcho³ka
@param szukany_nr numer wierzcho³ka, do którego funkca zwróci wskaŸnik
@return wskaŸnik do wierzcho³ka o szukanym numerze lub nullptr jeœli w liœcie nie ma takiego wierzcho³ka
*/
wierzcholek* Wierzcholek_o_numerze(wierzcholek* pListaWierzcholkow, const int szukany_nr);

/** Funkcja wyszukuje w liœcie s¹siadów s¹siada o danym numerze.
@param pListaSasiadow adres pierwszego elementu listy, w której funkcja szuka s¹siada
@param szukany_nr numer s¹siada, którego funkcja szuka
@return true je¿eli taki s¹siad istnieje, false jeœli nie
*/
bool Sasiad_o_numerze(sasiad* pListaSasiadow, int szukany_nr);

/**Funkcja usuwa graf.
@param[in,out] pListaWierzcholkow adres grafu do usuniêcia (po usuniêciu pListaWierzcho³ków=nullptr)
*/
void usun_liste_wierzcholkow(wierzcholek*& pListaWierzcholkow);

/**Funkcja usuwa listê s¹siadów wierzcho³ka.
@param[in,out] pListaSasiadow adres listy do usuniêcia (po usuniêciu pListaSasiadow=nullptr)
*/
void usun_liste_sasiadow(sasiad*& pListaSasiadow);

/**Funkcja tworzy w liœcie wierzcho³ków nowy wierzcho³ek o podanym numerze.
@param[in,out] pListaWierzcholkow adres listy, do której dodany bêdzie wierzcho³ek
@param dodawany_nr identyfikator, który zostanie przypisany do noewgo wierzcho³ka
*/
void dodaj_do_listy_wierzcholkow(wierzcholek*& pListaWierzcholkow, int dodawany_nr);

/**Funkcja tworzy w liœcie s¹siadów nowego s¹siada wskazujacego na wierzcho³ek o podanym numerze.
@param pListaWierzcholkow lista wierzcho³ków potrzebna do zrobycia wskaŸnika na wierzcho³ek o danym numerze
@param[in,out] pListaSasiadow Lista, do której dodany bêdzie wierzcho³ek
@param dodawany_nr identyfikator wierzcho³ka, do którego wskaŸnik bêdzie znajdowa³ siê w polu pSasiad nowego sasiada
*/
void dodaj_do_listy_sasiadow(wierzcholek* pListaWierzcholkow, sasiad*& pListaSasiadow, int dodawany_nr);

/**Funkcja tworzy wierzcho³ki o identyfikatorach podanych w parametrach (je¿eli jeszcze nie istniej¹) a nastêpnie ³¹czy je w krawêdŸ.
@param[in,out] pListaWierzcholkow lista wierzcholkow, w której ma byæ utworzona ga³¹Ÿ
@param startowy_wierzcholek identyfikator pocz¹tkowego wierzcho³ka ga³êzi
@param koncowy_wierzcholek identyfikator koncowego wierzcholka galezi
*/
void utworz_krawedz(wierzcholek*& pListaWierzcholkow, int startowy_wierzcholek, int koncowy_wierzcholek);


#endif
