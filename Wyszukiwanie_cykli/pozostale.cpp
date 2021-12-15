#include "pozostale.h"

bool Odczyt_parametrow(int argc, char* argv[], std::string& nazwa_pliku_wejsciowego, std::string& nazwa_pliku_wyjsciowego)
{
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-g") == 0)
		{
			++i;
			if (i < argc)
			{
				nazwa_pliku_wejsciowego.assign(argv[i]);
			}
		}
		if (strcmp(argv[i], "-c") == 0)
		{
			++i;
			if (i < argc)
			{
				nazwa_pliku_wyjsciowego.assign(argv[i]);
			}
		}
	}
	if (nazwa_pliku_wejsciowego.length() == 0 || nazwa_pliku_wyjsciowego.length() == 0)
	{
		std::cout << "Nieprawidlowe argumenty wywolania programu." << std::endl;
		std::cout << "Prawidlowe przelaczniki wywolania programu:" << std::endl;
		std::cout << "-g plik wejsciowy z grafem" << std::endl;
		std::cout << "-c plik wyjsciowy ze znalezionymi cklami" << std::endl;
		std::cout << "Pliki powinny miec rozszerzenie .txt" << std::endl << std::endl;
		std::cout << "Przykladowy sposob wywolania programu:" << std::endl;
		std::cout << "Program.exe -g dane.txt -c cykle.txt" << std::endl;
		return false;
	}
	return true;
}

wierzcholek* Odczyt_z_pliku(std::string nazwa_pliku)
{
	std::ifstream plik(nazwa_pliku);
	if (!plik.is_open())
	{
		std::cout << "Nie udalo sie otworzyc pliku wejsciowego." << std::endl;
		return nullptr;
	}
	else
	{
		int pierwszy_wierzcholek, drugi_wierzcholek;
		std::string strzalka;
		char strzalka1, strzalka2;
		char przecinek;
		wierzcholek* pListaWierzcholkow = nullptr;
		while (plik >> pierwszy_wierzcholek >> strzalka1 >> strzalka2 >> drugi_wierzcholek)
		{
			strzalka = "";
			strzalka = strzalka + strzalka1 + strzalka2;
			if (strzalka != "->")
			{
				std::cout << "Nie udalo sie odczytac pliku wejsciowego." << std::endl;
				std::cout << strzalka << " zamiast ->" << std::endl;
				usun_liste_wierzcholkow(pListaWierzcholkow);
				plik.close();
				return nullptr;
			}
			utworz_krawedz(pListaWierzcholkow, pierwszy_wierzcholek, drugi_wierzcholek);
			if (!(plik >> przecinek))
			{
				break;
			}
			else if (przecinek != ',')
			{
				std::cout << "Nie udalo sie odczytac pliku wejsciowego." << std::endl;
				std::cout << przecinek << " zamiast ," << std::endl;
				usun_liste_wierzcholkow(pListaWierzcholkow);
				plik.close();
				return nullptr;
			}
		}
		if (plik.fail() && !plik.eof())
		{
			std::cout << "Nie udalo sie odczytac pliku wejsciowego." << std::endl;
			usun_liste_wierzcholkow(pListaWierzcholkow);
			plik.close();
			return nullptr;
		}
		plik.close();
		return pListaWierzcholkow;
	}
}

void zapis_do_pliku(cykl*& pListaCykli, std::string nazwa_pliku)
{
	std::ofstream plik(nazwa_pliku);
	if (!plik.is_open())
	{
		std::cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << std::endl;
		usun_liste_cykli(pListaCykli);
		plik.close();
		return;
	}
	if (pListaCykli == nullptr)
	{
		plik << "W podanym grafie nie ma cykli." << std::endl;
	}
	else
	{
		cykl* pZaisywanyCykl = pListaCykli;
		while (pZaisywanyCykl != nullptr)//pêtla zapisuj¹ca wszystkie cykle z listy w osobnych liniach
		{
			droga* pZapisywanaDroga = pZaisywanyCykl->pDroga;
			while (pZapisywanaDroga != nullptr)
			{
				plik << pZapisywanaDroga->numer_wierzcholka;
				if (pZapisywanaDroga->pNastepny != nullptr)
					plik << "->";
				pZapisywanaDroga = pZapisywanaDroga->pNastepny;
			}
			plik << std::endl;
			pZaisywanyCykl = pZaisywanyCykl->pNastepnyCykl;
		}
	}
	usun_liste_cykli(pListaCykli);
	plik.close();
}

void znajdz_cykle(wierzcholek* pSprawdzanyWierzcholek, const int startowy_wierzcholek, droga*& pPrzebytaDroga, cykl*& pListaCykli)
{
	dodaj_do_drogi(pPrzebytaDroga, pSprawdzanyWierzcholek->numer); //Od³o¿enie obecnego wierzcho³ka na koniec przebytj drogi
	sasiad* pSprawdzany = pSprawdzanyWierzcholek->pSasiedzi;
	while (pSprawdzany != nullptr) //pêtla przegl¹dajaa s¹siadów w celu znalezienia wierzcho³ka startowego
	{
		if (pSprawdzany->pSasiad->numer == startowy_wierzcholek)
		{
			dodaj_do_drogi(pPrzebytaDroga, pSprawdzany->pSasiad->numer);
			dodaj_cykl(pListaCykli, pPrzebytaDroga);//od³o¿enie przebytej drogi na liste cykli
			usun_z_konca_drogi(pPrzebytaDroga);
		}
		else
		{
			if (!(Czy_odwiedzony(pPrzebytaDroga, pSprawdzany->pSasiad->numer)))
			{
				znajdz_cykle(pSprawdzany->pSasiad, startowy_wierzcholek, pPrzebytaDroga, pListaCykli); //rekurencyjne wywo³anie dla nieodwiedzonych s¹siadów
			}
		}
		pSprawdzany = pSprawdzany->pNastepny;
	}
	usun_z_konca_drogi(pPrzebytaDroga); // usuniêcie opuszczanego wierzcho³ka z koñca przebytej dorgi
	return;
}
