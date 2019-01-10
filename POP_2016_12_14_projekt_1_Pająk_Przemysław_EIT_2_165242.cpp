#include <iostream>
#include <windows.h>
#include <string.h>
int nr_lekow[100];
int tab[50][50];

using namespace std;
//definiuje strukture w ktorej jest lek, ten lek ma dwie nazwy: krotka i dluga
struct lek {			
 string nazwa_dluga;
 string nazwa_krotka;
};

//funkcja do ktorej wchodzi tablica leki, kazdy element tablicy sie odwoluje do dwoch nazw w strukturze 'lek'
void struktura (lek leki[])

{	
	cout<<"DOSTEPNE LEKI DO WYBORU PLANU LECZENIA: ";
	cout<<endl;

	leki[1].nazwa_dluga="Apap";
	leki[1].nazwa_krotka="Ap";
	leki[2].nazwa_dluga="Ibuprom";
	leki[2].nazwa_krotka="Ib";
	leki[3].nazwa_dluga="Nurofen";
	leki[3].nazwa_krotka="Nu";
	leki[4].nazwa_dluga="Polopiryna";
	leki[4].nazwa_krotka="Po";
	leki[5].nazwa_dluga="Otrivin";
	leki[5].nazwa_krotka="Ot";
	leki[6].nazwa_dluga="Flavamed";
	leki[6].nazwa_krotka="Fl";
	leki[7].nazwa_dluga="Febrisan";
	leki[7].nazwa_krotka="Fe";
	leki[8].nazwa_dluga="Paracetamol";
	leki[8].nazwa_krotka="Pa";
	leki[9].nazwa_dluga="Cerutin";
	leki[9].nazwa_krotka="Ce";
	leki[10].nazwa_dluga="Gripex";
	leki[10].nazwa_krotka="Gr";
	
	cout<<endl;
	//funkcja wypisujaca leki, indeksowana od 1 tak jak leki
	for(int i=1; i<=10; i++)
	{	
		cout<<"Lek "<<i<<": "<<"Nazwa pelna: "<<leki[i].nazwa_dluga;
		cout<<endl;
		cout<<"Nazwa skrocona: "<<leki[i].nazwa_krotka;
		cout<<endl;			
	}	
	cout<<endl;	
}


//funkcja w ktorej przypiusuje leki na potrzeby ulozenia planu kuracji
void wprowadz_leki (int &n, int nr_lekow[])
{
	bool spr=false; //zmienna boolowska zdefinowana aby wykluczyc powtarzajace sie indeksy lekow
	int warunek=1; 
	do
	{
		spr=false;
		cout<<"Wprowadz liczbe lekarstw do wyboru planu kuracji z zakresu [2;10]: ";
		//warunek sprawdzajacy poprawnosc liczby n z zakresu od [2:10]
		do
		{	
			cin >> n;
			if(n>1 and n<=10)
				{
					break;
				}
			else cout<<"Wprowadziles liczbe spoza zakresu, podaj ponownie liczbe: ";
		}
		while(warunek);
	cout<<endl;
	
		
	//petla wczytujaca numery struktury, zapisje je w tablicy nr_lekow
	cout<<"Wprowadz numery lekarstw z tabeli (liczby rozne, nalezace do [1,10]).";
	cout<<endl;
	for(int i=1; i<=n; i++)
	{
		cout<<"Podaj numer leku "<<i<<": ";
		do
		{
			cin >> nr_lekow[i];
			if(nr_lekow[i]>=1 and nr_lekow[i]<=10)
			{
				break;
			}
			else cout<<"Wprowadziles liczbe spoza zakresu, podaj ponownie liczbe: ";
		}
		while(warunek);		
	}		
	
	//porzadkowanie wprowadzonych lekow			
		int buf;
		for (int p = n-1; p >= 0; p--)
		{		
			for (int i = 0; i <= p; i++)
				if (nr_lekow[i] > nr_lekow[i+1])
				{	
					buf = nr_lekow[i+1];
					nr_lekow[i+1] = nr_lekow[i];
					nr_lekow[i] = buf;
				}					
		}
		
	//wypisanie komunikatu jezeli wprowadzone liczby nie sa rozne	
		for(int i=1; i<=n; i++)
		{
			if(nr_lekow[i]==nr_lekow[i+1])
			{
				cout<<"Liczby nie sa rozne, podaj liczby ponownie."<<endl;
				spr=true;
				break;
			}
		}
		cout<<endl;
	}
	while(spr==true);
	system("cls");
	
}
//funkcja wypisuja pusta tabele 
void wypisz_pusta (int n, lek leki[], int nr_lekow[])
{	
	cout << "PUSTA TABELA UTWORZONA NA PODSTAWIE PODANYCH LEKOW: " << endl << endl;
		cout<<"      "; // kursor odjedzie od lewej strony, po czym wypisze wszystkie numery wprowadzonych lekow(krotkie)
		for(int i=1; i<=n; i++)
		{
			cout <<leki[nr_lekow[i]].nazwa_krotka<<" ";	
		}
	
		cout<<endl;
		cout<<"_____"; // kursor odkresli taka sama ilosc od lewej strony, po czym wypisze tyle podkreslen ile wczesniej wypisal nazw lekow
		for(int j=1; j<=n; j++)
		{
			cout<<"___";			
		}
		cout<<endl;
		// kursor wypisze krotka nazwe , nastepnie wszedzie wstawi X
		for(int i=1; i<=n; i++)  // petla chodzaca po wierszach
		{
			cout <<leki[nr_lekow[i]].nazwa_krotka<<"  |";
			for(int j=1; j<=n; j++)  // petla chodzaca po kolumnach
			{	
				cout<<"  X";
			}
			cout<<endl;
		}
    
    
    cout<<endl;
}

// funkcja wczytujaca pary lekow ktore wchodza ze soba w interakcje i wypisuje je
void interakcja (int n, lek leki[], int nr_lekow[], int tab[][50])
{
	int k, l, m, warunek=1;
	cout<<"INTERAKCJA MIEDZY LEKAMI"<<endl;
	cout<<endl;
	cout<<"Leki wchodzace w interakcje musza byc rozne i nalezace to przedzialu: [1;"<<n<<"]"<<endl;
	cout<<"Maksymalna liczba roznych par to: "<<(n*n-n)/2;
	cout<<endl;
	cout<<endl;
	cout<<"Podaj liczbe par lekow, ktore wchodza ze soba w interakcje: ";
  	do
	{
		cin >> m;
		if(m>=1 and m<=(n*n-n)/2)
			{
				break;
			}
		else cout<<"Wprowadziles liczbe spoza zakresu, podaj ponownie liczbe: ";
	}
	while(warunek);
	
  	cout<<endl;
  	cout<<"Podaj kolejno indeks wiersza i kolumny (kazda liczbe zatwierdz enterem)."<<endl;
  	for( int i = 1; i <= m; i++)
 	 {
 	 	//funkcja wczytuje numer wiersza i kolumny kolejno do tablicy tab[11][11]
  		cout << "Podaj numer wiersza " << i << " pary: ";
		do
			{
				cin >> k;
				if(k >= 1 and k <= n)
					{
						break;
					}
				else cout << "Wprowadziles liczbe spoza zakresu, podaj ponownie liczbe: ";
			}
		while(warunek);
		cout << "podaj numer kolumny " << i << " pary: ";
		do
			{
				cin >> l;
				if(l != k)
				{
					if((l >= 1 and l <= n))
					{
						break;
					}
					else cout<<"Wprowadziles liczbe spoza zakresu, podaj ponownie liczbe: ";
				}
				
				else cout<<"Wprowadziles liczbe spoza zakresu, podaj ponownie liczbe: ";
			}
		while(warunek);
		tab[k][l] = 1;
		tab[l][k] = 1;
 	 }

		cout<<endl;
		cout<<"      "; 
		for(int i = 1; i<= n; i++)
		{
			cout <<leki[nr_lekow[i]].nazwa_krotka<<" ";	
		}
		cout<<endl;
		
		cout<<"_____";
		for(int j = 1; j <= n; j++)
		{
			cout<<"___";			
		}
		cout<<endl;
		
		for(int i = 1; i <= n; i++) //petla poruszajaca sie po wierszach, 
 		 {
 		 	cout <<leki[nr_lekow[i]].nazwa_krotka<<"  |"; //najpierw w kazdym wierszu wpisywana jest krotka nazwa, nastepnie wypelniana jest tablica
  		    for(int j = 1; j <= n; j++)
   	 	    {
   	 	    	if(i==j)								//jezeli indeksy wiersza i kolumny sa takie same to wpisywana jest wartosc "X"
   	 	    	{
   	 	    		cout<<" "<<"X"<<" ";	    		
				}
				
				else
				{
   	 	    		cout<<" "<<tab[i][j]<<" ";				//w przeciwnym wypadku wpisywana jest wartosc do tablicy 0 lub 1
   	 	    	}
   		    }
   	 cout<<endl;  	
}
}

//funkcja ustal etapy leczenia do ktorej wejscia wchodzi tablica [50][50]
void ustal_etapy_leczenia (int n, int tab[50][50], lek leki[], int nr_lekow[])
{
	int warunek=1;
	int etapy_leczenia[11][11]; //tablica poruszajaca sie po etapach leczenia (maksymalnie 10 etapow, 11 elementow)
	int g;

	cout << "\nPodaj maksymalna liczbe etapow leczenia z przedzialu [1;10]: ";
	do //wczytywana jest liczba etapow leczenia i sprawdzany warunek
	{	
			cin >> g;
			if(g>=1 and g<=10)
				{
					break;
				}
			else cout<<"Wprowadziles liczbe spoza zakresu, podaj ponownie liczbe: ";
	}
	while(warunek);
	cout << endl;
		
	for (int x = 0; x <= g; x++)   //funkcja ustawiajaca kazdy element a w nim wszystkie wartosci lekow na 0
		for (int p = 0; p <= 11; p++)
		{
			etapy_leczenia[x][p] = 0;
		}
		
	//etapy_leczenia[j][0] - liczniki w kazdym etapie leczenia 
	//nr_lekow[i] - leki do rozmieszczenia 
	// g - liczba etapow, i - liczba lekow
	// j porusza sie po etapach leczenia, k po elementach(wpisywanych lekach) w etapach	
	
    bool e = false;
    int licznik = 0; //licznik do sprawdzania czy liczba wpisanych elementow
 	for(int i=1;i<=n;i++)  //petla przypisuje leki do etapow leczenia, iteruje po wszystkich wybranych lekach						
 		{
		e = false;
		for(int j=1; j<=g; j++) // pêtla przegl¹da etapy leczenia
		 {
		   if(etapy_leczenia[j][0] == 0)	// jezeli licznik w etapie jest rowny 0, wpisuje numer leku do elementu za licznikiem, zwiekszy etapy leczenia
		    {
		     etapy_leczenia[j][etapy_leczenia[j][0]+1] = nr_lekow[i];
		     etapy_leczenia[j][0]++;
		     cout<<"Przydzielono lek: "<<leki[nr_lekow[i]].nazwa_krotka<<" do etapu: "<<j<<endl;
		     licznik++;
		     break;
		    }
		    
		 	else
			{
			
		    	for(int k=1; k<=etapy_leczenia[j][0]; ) //pêtla sprawdza czy wystepuje interakcja z umieszczonymi juz lekami
				{
					if (tab[i][etapy_leczenia[j][k]] == 0) // jezeli na tablicy interakcji nie ma 1
					{ 
						if(k == etapy_leczenia[j][0])
						{
							etapy_leczenia[j][etapy_leczenia[j][0]+1] = nr_lekow[i];
							cout<<"Przydzielono lek: "<<leki[nr_lekow[i]].nazwa_krotka<<" do grupy: "<<j << endl;
							etapy_leczenia[j][0]++;	
							licznik++;
							e=true;
							break;
						}
						else 
						{
							k++;
						}
					}		
					else	if (tab[i][etapy_leczenia[j][k]] == 1 ) // sprawdzenie czy analizowany lek wchodzi w interakcje z juz wpisanymi lekami
					{
						cout<<"Leki ze soba koliduja. " << endl;
						break;								
					}
				
				}
			if(e==true)	break; // jezeli e bedzie prawidziwe po wpisaniu petla przechodzi do kolejnego leku
			} 	  	  
		  }		  
		}
	if ( licznik != n) cout << "Zabraklo etapow aby rozmiescic twoje leki. " << endl;	
	cout << endl << endl;
	
	for ( int y = 1; y <= g; y++) //funkcja wypisuje kazdy etapy leczenia, a w nim wszystkie leki
		{	
			cout << "Etap " << y << ": ";
			
			for ( int z = 1; z <= etapy_leczenia[y][0]; z++)
				{
					cout << leki[etapy_leczenia[y][z]].nazwa_krotka << " ";	 
				}
			cout << endl;
		}	
}


int main()
{
  lek leki[11]; 
  int n;
  struktura(leki);
  wprowadz_leki(n, nr_lekow);
  wypisz_pusta (n,leki, nr_lekow);
  interakcja (n,leki,nr_lekow, tab);
  ustal_etapy_leczenia (n,tab,leki,nr_lekow) ;
  
  

  system("pause");
  return 0;
}
