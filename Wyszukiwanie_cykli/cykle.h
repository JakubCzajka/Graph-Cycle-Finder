/** @file */
#ifndef CYKLE_H
#define CYKLE_H

#include "struktury.h"
#include "wierzcholki.h"

/** Funkcja usuwa dan¹ drogê.
@param[out] pDroga droga do usuniêcia, po wykonaniu funkcji pDroga=nullptr
*/
void usun_droge(droga*& pDroga);

/** Funkcja dodaje na koniec drogi numer wierzcho³ka.
@param pDroga droga, do której dodany zostanie numer odwiedzonego wierzcho³ka
@param nr_wierzcholka numer, który zostanie dodany na koniec drogi
*/
void dodaj_do_drogi(droga*& pDroga, int nr_wierzcholka);

/** Funkcja usuwa ostatni element drogi.
@param pDroga droga, z której zostanie usuniêty ostatni element
*/
void usun_z_konca_drogi(droga*& pDroga);

/**Funkcja kopiuj¹ca drogê.
@param[in] pDroga droga, która zostanie skopiowana
@return wskaŸnik na utworzon¹ kopiê drogi
*/
droga* Kopia_drogi(const droga* pDroga);

/**Funkcja sprawdzaj¹ca czy dany numer znajduje siê w drodze.
@param pDroga droga, w której szukany jest numer
@param nr_sprawdzanego szukany numer
@return true je¿eli numer wystêpuje w danej drodze, false jeœli nie wystêpuje
*/
bool Czy_odwiedzony(const droga* pDroga, int nr_sprawdzanego);

/**Funkcja usuwa listê cykli.
@param[in,out] pListaCykli lista cykli do usuniêcia, po wykonaniu funkcji pListacykli=nullptr
*/
void usun_liste_cykli(cykl*& pListaCykli);

/**Funkcja dodaje nowy cykl do listy.
@param pListaCykli lista, do której zostanie dodany cykl
@param pDroga droga, która jest cyklem do dodania
*/
void dodaj_cykl(cykl*& pListaCykli, droga* pDroga);

#endif