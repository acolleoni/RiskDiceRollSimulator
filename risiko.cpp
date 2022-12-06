// Simuatore di RISIKO

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Tripletta {
	int a;
	int b;
	int c;
};

struct Squadre {
	int rosso;
	int blu;
};

Tripletta ordina(int a, int b, int c){
	int min, med, max;
	struct Tripletta ordinata;
	
	if(a>b){
		max=a;
		min=b;
	}
	else{
		max=b;
		min=a;
	}
	
	if(c>max){
		med=max;
		max=c;
	}
	else if(c<min){
		med=min;
		min=c;
	}
	else {
		med=c;
	}
	
	ordinata.a=max;
	ordinata.b=med;
	ordinata.c=min;
	return ordinata;
}

Tripletta tira (){
	struct Tripletta dado;
	dado.a=rand()%6+1;
	dado.b=rand()%6+1;
	dado.c=rand()%6+1;
	return dado;
}

Squadre contamorti(Tripletta rosso, Tripletta blu, bool view){
	Squadre morti= {0, 0};
	
   // Dado più alto
   if (rosso.a>blu.a){
	if(view)	   cout << "Il dado rosso piu alto vince";
	if(view)	   cout << endl;
	   morti.blu++;
   }else{
	if(view)	   cout << "Il dado blu piu alto vince";
	if(view)	   cout << endl;
	   morti.rosso++;
   }
   
   //Dado intermedio
   if (rosso.b>blu.b){
	if(view)	   cout << "Il dado rosso intermedio vince";
	if(view)	   cout << endl;
	   morti.blu++;
   }else{
	if(view)	   cout << "Il dado blu intermedio vince";
	if(view)	   cout << endl;
	   morti.rosso++;
   }	   
   
   //Dado scarso
   if (rosso.c>blu.c){
	if(view)	   cout << "Il dado rosso piu scarso vince";
	if(view)	   cout << endl;
	   morti.blu++;
   }else{
	if(view)	   cout << "Il dado blu piu scarso vince";
	if(view)	   cout << endl;
	   morti.rosso++;
   }
   
   return morti;
  
}

void lancimultipli() {
	struct Tripletta rosso;
	struct Tripletta blu;
	struct Squadre morti;
	int contatore=0;
	double mortirossi=0;
	double mortiblu=0;
	double rapporto;
	int tiri;
	bool view;
	
	cout << "Quanti tiri vuoi fare? (scrivi il numero e premi invio) ";
	cin >> tiri;
	cout << "Vuoi visualizzare i risultati parziali? (scrivi 1 per si e 0 per no, poi premi invio) ";
	cin >> view;
	cin.get();
	cout << "In caso di numeri troppo alti, se passa troppo tempo e\' possibile interrompere l'operazione premendo CTRL+C" << endl;

	while(contatore < tiri){
		
		//Tiro i dadi
		rosso=tira();
		blu=tira();
		
		// Mostro i risultati
		if(view)	cout << endl << "Il rosso ha fatto: " << rosso.a << " " << rosso.b << " " << rosso.c << endl;
		if(view)	cout << "Il blu ha fatto: " << blu.a << " " << blu.b << " " << blu.c << endl;
		
		//Metto in ordine
		rosso=ordina(rosso.a, rosso.b, rosso.c);
		blu=ordina(blu.a, blu.b, blu.c);

		//Vediamo chi ha vinto
		morti=contamorti(rosso, blu, view);
		mortirossi=mortirossi+morti.rosso;
		mortiblu=mortiblu+morti.blu;
		if(view)	cout << endl << "Morti rosso: " << morti.rosso << endl;
		if(view)	cout << "Morti blu: " << morti.blu << endl;
	  
		contatore++;
	}

	rapporto=mortirossi/mortiblu;
	cout << endl << "Morti finali rosso: " << setprecision(0) << setiosflags(ios::fixed) << mortirossi << endl;
	cout << "Morti finali blu: " << setprecision(0) << setiosflags(ios::fixed) << mortiblu << endl;
	cout << "Il rapporto morti rossi / morti blu e: ";
	cout << setprecision(9) << setiosflags(ios::fixed) << rapporto << endl;

}

void battaglia(){
	struct Tripletta rosso;
	struct Tripletta blu;
	struct Squadre morti;
	int mortirossi=0;
	int mortiblu=0;
	bool view;
	int dadiblu;
	int dadirosso;
	bool noend=0;
	
	cout << "Quanti carroarmatini possiede il rosso? (scrivi il numero e premi invio) ";
	cin >> dadirosso;
	cout << "Quanti carroarmatini possiede il blu? (scrivi il numero e premi invio) ";
	cin >> dadiblu;
	cout << "Vuoi visualizzare i risultati parziali? (scrivi 1 per si e 0 per no, poi premi invio) ";
	cin >> view;
	cin.get();
	cout << "In caso di numeri troppo alti, se passa troppo tempo e\' possibile interrompere l'operazione premendo CTRL+C" << endl;

	while((dadiblu>=3) && (dadirosso>=3)){
		//Tiro i dadi
		rosso=tira();
		blu=tira();
		
		// Mostro i risultati
		if(view)	cout << endl << "Il rosso ha fatto: " << rosso.a << " " << rosso.b << " " << rosso.c << endl;
		if(view)	cout << "Il blu ha fatto: " << blu.a << " " << blu.b << " " << blu.c << endl;
		
		//Metto in ordine
		rosso=ordina(rosso.a, rosso.b, rosso.c);
		blu=ordina(blu.a, blu.b, blu.c);

		//Vediamo chi ha vinto
		morti=contamorti(rosso, blu, view);
		mortirossi=mortirossi+morti.rosso;
		mortiblu=mortiblu+morti.blu;
		dadiblu=dadiblu-morti.blu;
		dadirosso=dadirosso-morti.rosso;
		if(view)	cout << endl << "Morti rosso: " << morti.rosso << endl;
		if(view)	cout << "Morti blu: " << morti.blu << endl << endl;
		
	}
	
	if (((dadiblu<3) && (dadiblu>0)) || ((dadirosso<3) && (dadirosso>0))) {
			cout << endl << "Uno dei giocatori e rimasto con meno di tre dadi. Ti lascio fare gli ultimi lanci." << endl;
			cout << "Il rosso ha ancora " << dadirosso << " carroarmatini e il blu ne ha " << dadiblu << "."<< endl;
			cout << "Buona fortuna!";
			noend=1;
		}

if(!noend)	cout << endl << "Carroarmatini finali rosso: " << setprecision(0) << setiosflags(ios::fixed) << dadirosso << endl;
if(!noend)	cout << "Carroarmatini finali blu: " << setprecision(0) << setiosflags(ios::fixed) << dadiblu << endl;

}

int main(){
	while(1){
		bool scelta;
		srand(time(NULL));

		cout << endl << "Benvenuto in questo simulaltore di RISIKO" << endl << endl;
		cout << "Se vuoi simulare un numero a scelta di lanci di 3 dadi contro 3 dadi digita 0 e premi invio." << endl;
		cout << "Se vuoi simulare una battaglia digita 1 e premi invio." << endl;
		cin >> scelta;
		cin.get();
		cout << endl;
		
		if (!scelta) lancimultipli();
		if (scelta) battaglia();
		
		cout << endl << endl;
		cout << "Per chiudere il programma digita 0, per riavviarlo digita 1, poi premi invio." << endl;
		cin >> scelta;
		cin.get();
		if (!scelta) break;
	}
}