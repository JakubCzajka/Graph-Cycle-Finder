/** @file */
#ifndef WIERZCHOLKI_H
#define WIERZCHOLKI_H

#include "struktury.h"
#include <iostream> 
#include <string>
#include <fstream>

/** Funkcja wyszukuje w danej li�cie wierzcho�k�w wierzcho�ek o danym numerze i zwraca wska�nik na niego.
@param pListaWierzcholkow adres pierwszego elementu listy, w kt�rej funkcja szuka wierzcho�ka
@param szukany_nr numer wierzcho�ka, do kt�rego funkca zwr�ci wska�nik
@return wska�nik do wierzcho�ka o szukanym numerze lub nullptr je�li w li�cie nie ma takiego wierzcho�ka
*/
wierzcholek* Wierzcholek_o_numerze(wierzcholek* pListaWierzcholkow, const int szukany_nr);

/** Funkcja wyszukuje w li�cie s�siad�w s�siada o danym numerze.
@param pListaSasiadow adres pierwszego elementu listy, w kt�rej funkcja szuka s�siada
@param szukany_nr numer s�siada, kt�rego funkcja szuka
@return true je�eli taki s�siad istnieje, false je�li nie
*/
bool Sasiad_o_numerze(sasiad* pListaSasiadow, int szukany_nr);

/**Funkcja usuwa graf.
@param[in,out] pListaWierzcholkow adres grafu do usuni�cia (po usuni�ciu pListaWierzcho�k�w=nullptr)
*/
void usun_liste_wierzcholkow(wierzcholek*& pListaWierzcholkow);

/**Funkcja usuwa list� s�siad�w wierzcho�ka.
@param[in,out] pListaSasiadow adres listy do usuni�cia (po usuni�ciu pListaSasiadow=nullptr)
*/
void usun_liste_sasiadow(sasiad*& pListaSasiadow);

/**Funkcja tworzy w li�cie wierzcho�k�w nowy wierzcho�ek o podanym numerze.
@param[in,out] pListaWierzcholkow adres listy, do kt�rej dodany b�dzie wierzcho�ek
@param dodawany_nr identyfikator, kt�ry zostanie przypisany do noewgo wierzcho�ka
*/
void dodaj_do_listy_wierzcholkow(wierzcholek*& pListaWierzcholkow, int dodawany_nr);

/**Funkcja tworzy w li�cie s�siad�w nowego s�siada wskazujacego na wierzcho�ek o podanym numerze.
@param pListaWierzcholkow lista wierzcho�k�w potrzebna do zrobycia wska�nika na wierzcho�ek o danym numerze
@param[in,out] pListaSasiadow Lista, do kt�rej dodany b�dzie wierzcho�ek
@param dodawany_nr identyfikator wierzcho�ka, do kt�rego wska�nik b�dzie znajdowa� si� w polu pSasiad nowego sasiada
*/
void dodaj_do_listy_sasiadow(wierzcholek* pListaWierzcholkow, sasiad*& pListaSasiadow, int dodawany_nr);

/**Funkcja tworzy wierzcho�ki o identyfikatorach podanych w parametrach (je�eli jeszcze nie istniej�) a nast�pnie ��czy je w kraw�d�.
@param[in,out] pListaWierzcholkow lista wierzcholkow, w kt�rej ma by� utworzona ga���
@param startowy_wierzcholek identyfikator pocz�tkowego wierzcho�ka ga��zi
@param koncowy_wierzcholek identyfikator koncowego wierzcholka galezi
*/
void utworz_krawedz(wierzcholek*& pListaWierzcholkow, int startowy_wierzcholek, int koncowy_wierzcholek);


#endif
