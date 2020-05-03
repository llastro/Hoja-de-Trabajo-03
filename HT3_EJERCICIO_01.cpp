

#include <fstream>

#include <iostream>

#include <string>

#include <cstdlib>

#include<ctime> 

#include <stdio.h>

#include <vector>

using namespace std;



struct Jugadores{

  string nombre;

  int edad;

  float sueldo;

  bool extranjero=false;

};


int grupo1=0, grupo2=0, grupo3=0, grupo4=0;


std::vector<Jugadores> jugador;


float calcular(int edad, bool extranjero){


  float salario;


  if (extranjero==true){

    salario=800;

  }

  else {

    salario=0;

  }


  if ((edad>=15) and (edad<=20)){

    salario=salario+1400;

    grupo1=grupo1+1;

  }

  else if ((edad>=21) and (edad<=25)){

    salario=salario+1500;

    grupo2=grupo2+1;

  }

  else if ((edad>=26) and (edad<=30)) {

    salario=salario+1200;

    grupo3=grupo3+1;

  }

  else if ((edad>30)) {

    salario=salario+800;

    grupo4=grupo4+1;

  }

  else {

    salario=0;

  }

  return salario;

}


void ingreso(){

  


  string var1;

  bool control=false;


  Jugadores x;


  cout << "Ingrese nombre: " << "\n";

  cin >> x.nombre;

  cout << "Ingrese Edad: "<< "\n";

  cin >> x.edad;


  while (control==false) {

    cout << "Es extranjero, (si/no): "<< endl;

    cin >> var1;

    if ((var1=="si") or (var1=="SI")){

      x.extranjero=true;

      control=true; 

    } else if ((var1=="no") or (var1=="NO")){

      x.extranjero=false;

      control=true; 

    } else {

      cout << "Ingreso una opcion invalida, intente de nuevo " << endl;

    }

  }

 

  x.sueldo=calcular(x.edad, x.extranjero);


  jugador.push_back(x);


}



void reporte(){


  cout << "========== Planilla ==========" << "\n";

  for (int x=0; x<jugador.size(); x++) {

    cout << jugador[x].nombre << "\t" << jugador[x].edad << "\t";

    

    if (jugador[x].extranjero==true){

      cout << "extranjero"<< "\t";

    } else {

      cout << "nacional"<< "\t";

    }

    cout << jugador[x].sueldo << endl;

  }

  cout << "========================================" << "\n \n";


  cout << "Jugadores de 15 a 20 : " << grupo1 << endl;

  cout << "Jugadores de 21 a 25 : " << grupo2 << endl;

  cout << "Jugadores de 26 a 30 : " << grupo3 << endl;

  cout << "Jugadores mayores de 30 : " << grupo4 << "\n \n";


  if ((grupo1>grupo2) and (grupo1>grupo3) and (grupo1>grupo4)) {

    cout << "El rango de Jugadores de 15 a 20 es el mas remunerado";

  }

  else if ((grupo2>grupo3) and (grupo2>grupo4) and (grupo2>grupo1)){

    cout << "El rango de Jugadores de 21 a 25 es el mas remunerado";

  }

  else if ((grupo3>grupo4) and (grupo3>grupo1) and (grupo3>grupo2)){

    cout << "El rango de Jugadores de 26 a 30 es el mas remunerado";

  }

  else if ((grupo4>grupo1) and (grupo4>grupo2) and (grupo4>grupo3)){

    cout << "El rango de Jugadores de mayores de 30 es el mas remunerado";

  }

    cout << "\n";


  string empty;

  getchar();

  getline(cin, empty);

}


void menu(){

  char tecla;

  string empty;

  bool bandera=false;

  

  do

    {

        system("clear");

        cin.clear();

        cout << "Club de futbol" << endl;

        cout << "-----------" << endl << endl;

        cout << "\t1 .- Agregar Jugador" <<endl;

        cout << "\t2 .- Mostrar Reporte" <<endl;

        cout << "\t3 .- Salir" << endl << endl;

        cout << "Elije una opcion: ";

 

        cin >> tecla;

 

    switch(tecla)

        {

      case '1':

        system("clear");

        ingreso();

        break;

 

      case '2':

        system("clear");

        reporte();

        break;

      

      case '3':

        bandera=true;

 

        break;

 

      default:

        system("clear");

        cout << "Opcion no valida.\a\n";

        getchar();

        getline(cin, empty);

        break;

    }

    }while(bandera!=true);

}


int main(){


  menu();

  return 0;

}
