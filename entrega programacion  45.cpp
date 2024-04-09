#include <iostream>
#include <cstdlib>
using namespace std;

int inicia[50];
int ordenado[50];
int trabajo[10][50];
int cta;
int cntr;
int unid;
int canti=5;
int parte=canti;
int cambio;


void intercambio (int subindi) {
	int indi1;
	int cta;
	parte=7;
	
	for(indi1=0;indi1<parte;indi1++) {	
		for(cta=0;cta<parte;cta++){
			if (trabajo[subindi][cta] > 0) {
				if (trabajo[subindi][cta] > trabajo[subindi][cta+1]) {
					if (trabajo[subindi][cta+1] > 0) {
					cambio=trabajo[subindi][cta];
					trabajo[subindi][cta]=trabajo[subindi][cta+1];
					trabajo[subindi][cta+1]=cambio;
					}
				}
			}
		}
		parte--;
	}
}
	
void iniciamatriz() {
	for(cta=0;cta<10;cta++) {
		for(unid=0;unid<canti;unid++) {
			trabajo[cta][unid]=0;
		}
	}
}	

int main(){

	do {
		cout<<"Cuantos numeros quiere ingresar  (maximo 20): ";
		cin >>canti;
	} while (canti>20);
	
	//capturamos los datos
	cout<<"REGISTRE NUMEROS INFERIORES A 1000"<<endl;
	for(cta=0;cta<canti;cta++) {
		do {
			//cout<<"Digite el numero de la posicion ("<<cta+1 << ")  ahora -->";
			inicia[cta]=rand();
		} while (inicia[cta]>999);
	}
	//inicializa matriz en cero
	iniciamatriz();	
	//creamos la matriz por uniades
	for(cta=0;cta<canti;cta++) {
		unid=inicia[cta]%10;
		cntr=0;
		while (trabajo[unid][cntr] > 0) {
			cntr++;
		}
		trabajo[unid][cntr]=inicia[cta];
	}
	//ordemamos cada vector de lamatriz de unidades
	for (cta=0;cta<10;cta++) {
		intercambio(cta);
	}
	//Cramos el vector ordenadio por unbidades
	unid=0;
	for (cta=0;cta<10;cta++) {
		for(cntr=0;cntr<canti;cntr++) {
			if(trabajo[cta][cntr] > 0) {
				ordenado[unid++]=trabajo[cta][cntr];
			}		
		}
	}
	//inicializa matriz en cero
	iniciamatriz();
	//creamos la matriz por decenas
	for(cta=0;cta<canti;cta++) {
		unid=(ordenado[cta]%100-ordenado[cta]%10)/10;
		cntr=0;
		while (trabajo[unid][cntr] > 0) {
			cntr++;
		}
		trabajo[unid][cntr]=ordenado[cta];
	}
	//ordemamos cada vector de lamatriz de unidades
	for (cta=0;cta<10;cta++) {
		intercambio(cta);
	}
	//Cramos el vector ordenadio por decenas
	unid=0;
	for (cta=0;cta<10;cta++) {
		for(cntr=0;cntr<canti;cntr++) {
			if(trabajo[cta][cntr] > 0) {
				ordenado[unid++]=trabajo[cta][cntr];
			}
		}
	}
	//inicializa matriz en cero
	iniciamatriz();
	//creamos la matriz por centenas
	for(cta=0;cta<canti;cta++) {
		unid=(ordenado[cta]%1000-ordenado[cta]%100)/100;
		cntr=0;
		while (trabajo[unid][cntr] > 0) {
			cntr++;
		}
		trabajo[unid][cntr]=ordenado[cta];
	}
	//ordemamos cada vector de lamatriz de unidades
	for (cta=0;cta<10;cta++) {
		intercambio(cta);
	}
	//Cramos el vector ordenadio por decenas
	unid=0;
	for (cta=0;cta<10;cta++) {
		for(cntr=0;cntr<canti;cntr++) {
			if(trabajo[cta][cntr] > 0) {
				ordenado[unid++]=trabajo[cta][cntr];
			}
		}
	}
	
	//Mostrar EL Rsultado Final
	cout << "Los Valores ingresados fueros : " << endl;
	for(unid=0;unid<canti;unid++) {			
		cout<<inicia[unid]<<"--";
	}	
	cout<<endl;
	cout<<" Y ordeanmos quedaron asi:" << endl;
	for(unid=0;unid<canti;unid++) {			
		cout<<ordenado[unid]<<"--";
	}	
}
