#include<iostream>
#include<fstream>
#include<sstream>
#define Archivo "movies.csv"
using namespace std;
struct Movies
{
	string Id;
	string NameMovie;
	string Genero;
	string Duracion;
	string Director;
	string Precio;
	string Lanzamiento;
};
struct Renta
{
	
	string rent_to;
	string rent_on;
	string status; 
	
};
void Mostrar()
{
	ifstream file(Archivo);
    string linea;
    char delimitador = ';'  ; 
	Movies movie;
    getline(file,linea);
    while (getline(file,linea))
    {
	    
        stringstream stream(linea);
        getline(stream, movie.Id, delimitador);
        getline(stream, movie.NameMovie, delimitador);
        getline(stream, movie.Genero, delimitador);
        getline(stream, movie.Duracion, delimitador);
        getline(stream, movie.Director, delimitador);
        getline(stream, movie.Precio, delimitador);
        getline(stream, movie.Lanzamiento, delimitador);
		
		
		cout<<"================================"<<endl;      
	    cout<<"Id: "<<movie.Id<<endl;
        cout<<"Nombre de la pelicula: "<<movie.NameMovie<<endl;
        cout<<"Genero: "<<movie.Genero<<endl;
        cout<<"Duracion: "<<movie.Duracion<<endl;
        cout<<"Director: "<<movie.Director<<endl;
        cout<<"Precio: "<<movie.Precio<<endl;
        cout<<"FechaLanzamiento: "<<movie.Lanzamiento<<endl;
        	
	}
    file.close();

}	
int main(){
	
	int x;
	
	
		cout << "1. Mostrar data" << endl;
		
	cin>>x;
	switch(x)
	{
		case 1:
			Mostrar();
			break;
	}
	
	
	
	return 0;
	
} 

