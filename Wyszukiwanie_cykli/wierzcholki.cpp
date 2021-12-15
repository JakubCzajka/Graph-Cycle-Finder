#include "wierzcholki.h"

wierzcholek* Wierzcholek_o_numerze(wierzcholek* pListaWierzcholkow, const int szukany_nr)
{
	wierzcholek* pWynik = nullptr;
	while (pListaWierzcholkow != nullptr)
	{
		if (pListaWierzcholkow->numer == szukany_nr)
		{
			pWynik = pListaWierzcholkow;
			return pWynik;
		}
		pListaWierzcholkow = pListaWierzcholkow->pNastepny;
	}
	return pWynik;
}

bool Sasiad_o_numerze(sasiad* pListaSasiadow, int szukany_nr)
{
	while (pListaSasiadow != nullptr)
	{
		if (pListaSasiadow->pSasiad->numer == szukany_nr)
		{
			return true;
		}
		pListaSasiadow = pListaSasiadow->pNastepny;
	}
	return false;
}

void usun_liste_wierzcholkow(wierzcholek*& pListaWierzcholkow)
{
	wierzcholek* p;
	while (pListaWierzcholkow != nullptr)
	{
		usun_liste_sasiadow(pListaWierzcholkow->pSasiedzi);
		p = pListaWierzcholkow->pNastepny;
		delete pListaWierzcholkow;
		pListaWierzcholkow = p;
	}
}

void usun_liste_sasiadow(sasiad*& pListaSasiadow)
{
	sasiad* p;
	while (pListaSasiadow != nullptr)
	{
		p = pListaSasiadow->pNastepny;
		delete pListaSasiadow;
		pListaSasiadow = p;
	}
}

void dodaj_do_listy_wierzcholkow(wierzcholek*& pListaWierzcholkow, int dodawany_nr)
{
	wierzcholek* p;
	if (pListaWierzcholkow == nullptr || pListaWierzcholkow->numer > dodawany_nr)
	{
		pListaWierzcholkow = new wierzcholek{ dodawany_nr,nullptr,pListaWierzcholkow };
	}
	else
	{
		p = pListaWierzcholkow;
		while (p->pNastepny != nullptr && p->pNastepny->numer < dodawany_nr)
		{
			p = p->pNastepny;
		}
		p->pNastepny = new wierzcholek{ dodawany_nr,nullptr, p->pNastepny };
	}
}

void dodaj_do_listy_sasiadow(wierzcholek* pListaWierzcholkow, sasiad*& pListaSasiadow, int dodawany_nr)
{
	sasiad* p;
	if (pListaSasiadow == nullptr || pListaSasiadow->pSasiad->numer > dodawany_nr)
	{
		pListaSasiadow = new sasiad{ Wierzcholek_o_numerze(pListaWierzcholkow,dodawany_nr), pListaSasiadow };
	}
	else
	{
		p = pListaSasiadow;
		while (p->pNastepny != nullptr && p->pNastepny->pSasiad->numer < dodawany_nr)
		{
			p = p->pNastepny;
		}
		p->pNastepny = new sasiad{ Wierzcholek_o_numerze(pListaWierzcholkow,dodawany_nr), p->pNastepny };
	}
}

void utworz_krawedz(wierzcholek*& pListaWierzcholkow, int startowy_wierzcholek, int koncowy_wierzcholek)
{
	if (Wierzcholek_o_numerze(pListaWierzcholkow, startowy_wierzcholek) == nullptr)//sprawdzenie czy istnieje startowy wierzcho³ek
	{
		dodaj_do_listy_wierzcholkow(pListaWierzcholkow, startowy_wierzcholek);
	}
	if (Wierzcholek_o_numerze(pListaWierzcholkow, koncowy_wierzcholek) == nullptr)//sprawdzenie czy istnieje koñcowy wierzcho³ek
	{
		dodaj_do_listy_wierzcholkow(pListaWierzcholkow, koncowy_wierzcholek);
	}
	wierzcholek* pStartowyWierzcholek = Wierzcholek_o_numerze(pListaWierzcholkow, startowy_wierzcholek);
	if (Sasiad_o_numerze(pStartowyWierzcholek->pSasiedzi, koncowy_wierzcholek) == false)
	{
		dodaj_do_listy_sasiadow(pListaWierzcholkow, pStartowyWierzcholek->pSasiedzi, koncowy_wierzcholek);
	}
}
