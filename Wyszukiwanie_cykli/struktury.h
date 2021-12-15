/** @file */
#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream> 

struct wierzcholek;
/**Element listy s�siedztwa*/
struct sasiad {
	wierzcholek* pSasiad;///<wska�nik na ko�cowy wierzcho�ek kraw�dzi
	sasiad* pNastepny;///<wska�nik na nast�pny element listy
};

/**Element listy wierzcho�k�w*/
struct wierzcholek {
	int numer;///<numer(identyfikator) wierzcho�ka
	sasiad* pSasiedzi;///<wska�nik na list� s�siedztwa
	wierzcholek* pNastepny;///<wska�nik na nast�pny element listy
};

/**Element listy reprezentuj�cej drog� w grafie*/
struct droga {
	int numer_wierzcholka;///<numer odwiedzonego wierzcho�ka
	droga* pNastepny;///<wska�nik na nast�pny element listy
};

/**Element listy cykli*/
struct cykl {
	int ID_cyklu;///<identyfikator cyklu
	droga* pDroga;///<wska�nik na drog�, kt�ra jest cyklem
	cykl* pNastepnyCykl;///<wska�nik na nast�pny element listy cykli
};


#endif