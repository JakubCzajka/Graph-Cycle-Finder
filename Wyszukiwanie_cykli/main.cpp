/** @file */
#include "struktury.h"
#include "wierzcholki.h"
#include "cykle.h"
#include "pozostale.h"

#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
	std::string nazwa_pliku_wejsciowego;
	std::string nazwa_pliku_wyjsciowego;
	if (Odczyt_parametrow(argc, argv, nazwa_pliku_wejsciowego, nazwa_pliku_wyjsciowego))
	{
		wierzcholek* pGraf = Odczyt_z_pliku(nazwa_pliku_wejsciowego);
		if (pGraf != nullptr)
		{
			cykl* pListaCykli = nullptr;
			droga* pPrzebytaDroga = nullptr;
			wierzcholek* p = pGraf;
			while (p != nullptr)
			{
				znajdz_cykle(p, p->numer, pPrzebytaDroga, pListaCykli);
				p = p->pNastepny;
			}
			zapis_do_pliku(pListaCykli, nazwa_pliku_wyjsciowego);
			usun_liste_wierzcholkow(pGraf);
			usun_droge(pPrzebytaDroga);
		}

	}
	return 0;
}