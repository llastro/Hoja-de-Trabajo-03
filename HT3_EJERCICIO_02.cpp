

#include <fstream>

#include <iostream>

#include <string>

#include <cstdlib>

#include<ctime> 

#include <stdio.h>

#include <vector>

using namespace std;


struct Pizzas{

  int tipo;

  string descripcion;

  float precio;

  float descuento;

  int pedidas;

};



void mostrar_pizzas(){

  cout << "# Pizza     Precio (Q)    Descuento(%)" << "\n";

  cout << "===========================================" << "\n";

  for (int x=0; x<pizza.size(); x++){

    cout << pizza[x].tipo << " " << pizza[x].descripcion << "\t" << pizza[x].precio << "\t " << "\t " << "\t " << pizza[x].descuento << "\n";

  }

}  


void pedido(){


  mostrar_pizzas();


  string vacio;

  float total;

  float descuento, descuentototal;

  int cantidad;


  int x=0;

  cin >> x;

  

  


  if ((x>=1) and (x<=3)){

    

    x=x-1;


    cout << "Cuantas pizzas de tipo " << pizza[x].descripcion << " es el pedido? " << "\n";

    cin >> cantidad;

    descuento= pizza[x].precio*pizza[x].descuento;

    descuentototal=descuento*cantidad;

    total=(pizza[x].precio - descuento)*cantidad;

    if (cantidad >=1) {

      cout << "El total a pagar es: " << total << "\n";

      pizza[x].pedidas=pizza[x].pedidas+cantidad;

    }

    getchar();

    getline(cin, vacio);


    ofstream archivo("pizzas.txt", ios::out|ios::app);

    


    if(archivo.fail()){

    cout<<"No se pudo abrir el archivo";

    exit(1);

    }


    archivo << pizza[x].tipo << "\t" << pizza[x].descripcion << "\t" << pizza[x].precio << "\t" << "\t"  << cantidad << "\t" << descuento << "\t" << total << "\n";


    archivo.close();


  }

}


void reporte(){

 

  ifstream archivo;


  archivo.open("pizzas.txt",ios::in);

  

  if(archivo.fail()){

  cout<<"No se pudo abrir el archivo";

  exit(1);

  }


  string linea;


  cout << "#   Desc    Precio  Cant Des Total" << endl;

  cout << "======================================" << endl;


  while(getline(archivo,linea))

  {


    cout << linea << endl;

  }


  archivo.close();

  cout << "========================================" << endl;


  float total, descuento, porcentaje;

  float totalglobal=0;


  for (int x=0; x<pizza.size(); x++){


    total=0;

    descuento=0;

    porcentaje=0;


 

    cout << "Pizza de tipo " << pizza[x].descripcion << ": \t" << pizza[x].pedidas << "\n";

    


    descuento=pizza[x].precio*pizza[x].descuento*pizza[x].pedidas;

    

    total=(pizza[x].precio*pizza[x].pedidas)-descuento;


    porcentaje = pizza[x].descuento * 100;


    totalglobal=totalglobal+total;

    


    cout << "Total de venta:" << total << "\n";

    cout << "Total de descuentos " << descuento <<  "\n";

    cout << "Con el porcentaje de "<< porcentaje << "%" << "\n";

    cout << "========================================" << "\n";

  }


  cout << "El total de venta es de " << totalglobal << "\n";



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

        cout << "Pizzeria" << endl;

        cout << "-----------" << endl << endl;

        cout << "\t1 .- Agregar Pedido" <<endl;

        cout << "\t2 .- Mostrar Reporte" <<endl;

        cout << "\t3 .- Salir" << endl << endl;

        cout << "Elije una opcion: ";

 

        cin >> tecla;

 

    switch(tecla)

        {

      case '1':

        system("clear");

        pedido();

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


  inicio_pizzas();


  menu();

  return 0;

}
