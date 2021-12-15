/** @file */
#ifndef CYKLE_H
#define CYKLE_H

#include "struktury.h"
#include "wierzcholki.h"

/** Funkcja usuwa dan� drog�.
@param[out] pDroga droga do usuni�cia, po wykonaniu funkcji pDroga=nullptr
*/
void usun_droge(droga*& pDroga);

/** Funkcja dodaje na koniec drogi numer wierzcho�ka.
@param pDroga droga, do kt�rej dodany zostanie numer odwiedzonego wierzcho�ka
@param nr_wierzcholka numer, kt�ry zostanie dodany na koniec drogi
*/
void dodaj_do_drogi(droga*& pDroga, int nr_wierzcholka);

/** Funkcja usuwa ostatni element drogi.
@param pDroga droga, z kt�rej zostanie usuni�ty ostatni element
*/
void usun_z_konca_drogi(droga*& pDroga);

/**Funkcja kopiuj�ca drog�.
@param[in] pDroga droga, kt�ra zostanie skopiowana
@return wska�nik na utworzon� kopi� drogi
*/
droga* Kopia_drogi(const droga* pDroga);

/**Funkcja sprawdzaj�ca czy dany numer znajduje si� w drodze.
@param pDroga droga, w kt�rej szukany jest numer
@param nr_sprawdzanego szukany numer
@return true je�eli numer wyst�puje w danej drodze, false je�li nie wyst�puje
*/
bool Czy_odwiedzony(const droga* pDroga, int nr_sprawdzanego);

/**Funkcja usuwa list� cykli.
@param[in,out] pListaCykli lista cykli do usuni�cia, po wykonaniu funkcji pListacykli=nullptr
*/
void usun_liste_cykli(cykl*& pListaCykli);

/**Funkcja dodaje nowy cykl do listy.
@param pListaCykli lista, do kt�rej zostanie dodany cykl
@param pDroga droga, kt�ra jest cyklem do dodania
*/
void dodaj_cykl(cykl*& pListaCykli, droga* pDroga);

#endif