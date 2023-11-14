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
}peliculas;
struct Renta
{
	string nombre;
	string apellido;
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
void create()
{
    // file pointer
    fstream fout;
    ifstream file(Archivo);
    string linea;
    fout.open(Archivo, ios::out | ios::app);
    int C=0;
    getline(file,linea);
    while (getline(file,linea))
    {
        C++;
    }
    int x;
	cout<<"Ingrese el numero de peliculas a agregar: "<<endl; cin>>x;
	cout<<'\n';

    for (int i = 0; i < x; i++)
    {
    
	cout << "Escriba los detalles de la pelicula "<<i+1 << endl;
	
	cout << "id: " <<endl ;
    cin >> peliculas.Id;
	cout << "nombre: "<<endl;
    cin >> peliculas.NameMovie;
    cout <<"Genero: "<< endl ;
    cin >> peliculas.Genero;
    cout << "Duracion: "<< endl;
    cin >> peliculas.Duracion;
    cout << "Director: "<< endl;
    cin >> peliculas.Director;
    cout << "Precio: "<<endl;
    cin >>peliculas.Precio;
    cout  << "Fecha de lanzamiento"<<endl;
    cin >> peliculas.Lanzamiento;
    
    
    
    
    
    
    cout << endl;
  
        // Insert the data to file
        fout << peliculas.Id << ";"
            << peliculas.NameMovie << ";"
            << peliculas.Genero << ";"
            << peliculas.Duracion << ";"
            << peliculas.Director << ";"
            << peliculas.Precio << ";"
			<< peliculas.Lanzamiento << ";"
            << "\n";
    }
    
    fout.close();
    file.close();
    
}



int main()
{
	int y=1;
	while(y==1)
	{
	
		int p;
		
		
			cout << "Menu" << endl;
			cout << "(1) Mostrar peliculas" << endl;
			cout << "(2) Agregar peliculas" << endl;
			cout << "(3) NOs vemos "<< endl;
			
		cin>>p;
		switch(p)
		{
			case 1:
				Mostrar();
				break;
			case 2:
				create();
				break;
			
			case 3:
				break;
		}
		
		cout<<""<<endl;
		cout<<"================================"<<endl;   
		cout<<"quieres seguir en el programa? "<<endl;cout<<"(1)Si "<<endl;cout<<"(2)No "<<endl;cin>>y;
		if(y==1)
		{
			cout<<""<<endl;
			cout<<"Genial... Sigamos XD"<<endl;
			cout<<"================================"<<endl;   
			
		}
		else if(y==2)
		{
			cout<<""<<endl;
			cout<<"================================"<<endl;   
			cout<<"Nos vemos "<<endl;
			y=2;
		}
		else
		{
			cout<<""<<endl;
			cout<<"================================"<<endl;   
			cout<<"Opcion erronea, se cerrara el programa por defecto"<<endl;
			y=2;	
		} 
	}
	
	return 0;
	
} 

