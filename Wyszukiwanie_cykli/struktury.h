/** @file */
#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <iostream> 

struct wierzcholek;
/**Element listy s¹siedztwa*/
struct sasiad {
	wierzcholek* pSasiad;///<wskaŸnik na koñcowy wierzcho³ek krawêdzi
	sasiad* pNastepny;///<wskaŸnik na nastêpny element listy
};

/**Element listy wierzcho³ków*/
struct wierzcholek {
	int numer;///<numer(identyfikator) wierzcho³ka
	sasiad* pSasiedzi;///<wskaŸnik na listê s¹siedztwa
	wierzcholek* pNastepny;///<wskaŸnik na nastêpny element listy
};

/**Element listy reprezentuj¹cej drogê w grafie*/
struct droga {
	int numer_wierzcholka;///<numer odwiedzonego wierzcho³ka
	droga* pNastepny;///<wskaŸnik na nastêpny element listy
};

/**Element listy cykli*/
struct cykl {
	int ID_cyklu;///<identyfikator cyklu
	droga* pDroga;///<wskaŸnik na drogê, która jest cyklem
	cykl* pNastepnyCykl;///<wskaŸnik na nastêpny element listy cykli
};


#endif