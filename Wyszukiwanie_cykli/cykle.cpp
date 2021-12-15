#include "cykle.h"

void usun_droge(droga*& pDroga)
{
	droga* p;
	while (pDroga != nullptr)
	{
		p = pDroga->pNastepny;
		delete pDroga;
		pDroga = p;
	}
}

void dodaj_do_drogi(droga*& pDroga, int nr_wierzcholka)
{
	if (pDroga == nullptr)
	{
		pDroga = new droga{ nr_wierzcholka,nullptr };
	}
	else
	{
		droga* p = pDroga;
		while (p->pNastepny != nullptr)
		{
			p = p->pNastepny;
		}
		p->pNastepny = new droga{ nr_wierzcholka,nullptr };
	}
}

void usun_z_konca_drogi(droga*& pDroga)
{
	if (pDroga == nullptr)
	{
		return;
	}
	if (pDroga->pNastepny == nullptr)
	{
		delete pDroga;
		pDroga = nullptr;
	}
	else
	{
		droga* p = pDroga;
		while (p->pNastepny->pNastepny != nullptr)
		{
			p = p->pNastepny;
		}
		delete p->pNastepny;
		p->pNastepny = nullptr;
	}
}

droga* Kopia_drogi(const droga* pDroga)
{
	if (pDroga == nullptr)
	{
		return nullptr;
	}
	else
	{
		droga* pKopia = nullptr;
		while (pDroga)
		{
			dodaj_do_drogi(pKopia, pDroga->numer_wierzcholka);
			pDroga = pDroga->pNastepny;
		}
		return pKopia;
	}
}

bool Czy_odwiedzony(const droga* pDroga, int nr_sprawdzanego)
{
	while (pDroga)
	{
		if (pDroga->numer_wierzcholka == nr_sprawdzanego)
			return true;
		pDroga = pDroga->pNastepny;
	}
	return false;
}

void usun_liste_cykli(cykl*& pListaCykli)
{
	cykl* p;
	while (pListaCykli != nullptr)
	{
		usun_droge(pListaCykli->pDroga);
		p = pListaCykli->pNastepnyCykl;
		delete pListaCykli;
		pListaCykli = p;
	}
}

void dodaj_cykl(cykl*& pListaCykli, droga* pDroga)
{
	if (pListaCykli == nullptr)
	{
		pListaCykli = new cykl{ 1,Kopia_drogi(pDroga),nullptr };
	}
	else
	{
		cykl* p = pListaCykli;
		while (p->pNastepnyCykl != nullptr)
		{
			p = p->pNastepnyCykl;
		}
		p->pNastepnyCykl = new cykl{ p->ID_cyklu + 1,Kopia_drogi(pDroga),nullptr };
	}
}