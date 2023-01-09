#include<iostream>
#include <cstring>
#include "lib/TPcolors.h"
#include <unistd.h>
#include "lib/TPpermutacion.h"
using namespace std;

// Variables globales
char TPnombre[] = "Thelman Jihat Pabón Quevedo";
char TPcorreo[] = "thelman.pabon@epn.edu.ec";
int TPcedula = 1500826555;

void p_bar(string icon, float lengt, float time, string nombre){ // Icono █, Largo, Tiempo 
	string x = icon;float porc = 1; float timer = time * 1000000;
	string v = "";
	string nombrefinal = "";
	
	for(int i=0; i<=lengt; i++){
		cout<<nombre<<endl;
		system("/bin/clear");
		if(i%2 == 0){
			v = "\\";
		}else{
			v = "/";
		}
		porc = (100/lengt) * i;
		cout<<WHITE<<"["<<CYAN<<v<<WHITE<<"] Cargando "<<CYAN<<lround(porc)<<"% Caracter "<<i<<"/28"<<WHITE<<": "<<GREEN<<x<<CYAN<<" "<<nombrefinal<<WHITE<<endl;
		x += icon;
		nombrefinal += nombre[i];
		usleep(timer);
	}
}
//Combinaciones totales sin repetcicion
long factorial(const int n)
{
    long f = 1;
    for (int i=1; i<=n; ++i)
        f *= i;
    return f;
}

//Numero?
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main(){
	//Variables locales
	string TPuser = ""; int TPpass, counter = 1, opt;

	//Primer intento de logueo
	system("/bin/clear");
	cout<<RED<<"\n\t    LogIn"<<WHITE<<endl;
	cout<<MAGENTA<<"\tIntentos: "<<CYAN<<counter<<"/3"<<WHITE<<endl;
	cout<<CYAN<<"GitHub: https://github.com/Alcatraz2033/ExamenProgramacion.git"<<WHITE<<endl<<endl;
	cout<<"["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" Username: "<<WHITE; cin>>TPuser;
	cout<<"["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" Password: "<<WHITE; cin>>TPpass;
	
	//LImite 3 intentos
	while(TPuser != "Thelman" && TPpass != TPcedula){
		system("/bin/clear");
		cout<<RED<<"\n\t    LogIn"<<WHITE<<endl;
		cout<<MAGENTA<<"\tIntentos: "<<CYAN<<counter<<"/3"<<WHITE<<endl;
		cout<<CYAN<<"GitHub: https://github.com/Alcatraz2033/ExamenProgramacion.git"<<WHITE<<endl<<endl;
		cout<<"["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" Username: "<<WHITE; cin>>TPuser;
		cout<<"["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" Password: "<<WHITE; cin>>TPpass;
		counter++;
		if(counter == 3){
			system("/bin/clear");
			cout<<"["<<RED<<"!"<<WHITE<<"]"<<RED<<" Limite de intentos exeditos"<<WHITE<<endl;	
			exit(0);
		}
	}

	//Menu
	system("/bin/clear");
	cout<<GREEN"\nBIENVENIDO "<<CYAN<<TPnombre<<WHITE<<endl;
	cout<<GREEN"Escoje una opcion: \n\n"<<WHITE;
	cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" 1. Mostraar Usuario"<<WHITE<<endl;
	cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" 2. Barra de Carga"<<WHITE<<endl;
	cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" 3. Combinatoria"<<WHITE<<endl;
	cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" 0. Salir"<<WHITE<<endl<<endl;
	cout<<GREEN<<"Examen@Thelman$ "<<WHITE;cin>>opt;

	//Mostrar Usuario
	if(opt == 1){
		system("/bin/clear");
		cout<<"\n\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" CEDULA: "<<WHITE<<TPcedula<<endl;
		cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" CORREO: "<<WHITE;
	    for (int x=0; x < strlen(TPcorreo); x++){
	        putchar(toupper(TPcorreo[x]));
	    }
		cout<<"\n\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" NOMBRE: "<<WHITE;
	    for (int x=0; x < strlen(TPnombre); x++){
	        putchar(tolower(TPnombre[x]));
	    }cout<<endl;
	}
	
	//Barra de carga
	if(opt == 2){
		p_bar("o", 28, 0.15, TPnombre);
	}
	
	//Combinatorias
	if(opt == 3){
		int n = 20,r = 8,w;
		char nrNombre[] = "Thelman Ji Pbó Quvd";
		system("/bin/clear");
		char items[] = {'T','h','e','l','m','a','m', ' ','J','i','h','a','t',' ','P','a','o','n',' ','Q','u','e','v','e','d','o'};
		cout<<"["<<GREEN<<"?"<<WHITE<<"] Grupos de: ";
		w = factorial(n)/(factorial(r)*factorial(n-r));
		cout<<"\n["<<CYAN<<"+"<<WHITE<<"] Combinaciones sin repeticion: "<<w<<endl;
		cout<<CYAN;combSR(items,20,8);cout<<endl;cout<<WHITE;
		cout<<"\n["<<CYAN<<"+"<<WHITE<<"] Combinaciones sin repeticion: "<<w<<endl;
		cout<<"\n\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" NOMBRE: "<<WHITE<<TPnombre<<endl;
		cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" NOMBRE SIN COMBINACION: "<<WHITE<<nrNombre<<endl;
		cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" LONGITUD DE CADENA: "<<WHITE<<strlen(TPnombre)<<endl;
		cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" LONGITUD DE CONJUNTO: "<<WHITE<<strlen(nrNombre)<<endl;
	}
	if(opt == 0){
		system("/bin/clear");
		cout<<"\t["<<CYAN<<"+"<<WHITE"]"<<CYAN<<" Hasta Pronto!!!"<<WHITE<<endl;
		exit(0);
	}

	return 0;
}
