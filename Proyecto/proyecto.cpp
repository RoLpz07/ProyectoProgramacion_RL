#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
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
	string NombreRentador;
	string FechaRenta;
	string Estado;
}peliculas;

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
        getline(stream, movie.NombreRentador, delimitador);
        getline(stream, movie.FechaRenta, delimitador);
        getline(stream, movie.Estado, delimitador);
		
		
		cout<<"================================"<<endl;      
	    cout<<"Id: "<<movie.Id<<endl;
        cout<<"Nombre de la pelicula: "<<movie.NameMovie<<endl;
        cout<<"Genero: "<<movie.Genero<<endl;
        cout<<"Duracion: "<<movie.Duracion<<endl;
        cout<<"Director: "<<movie.Director<<endl;
        cout<<"Precio: "<<movie.Precio<<endl;
        cout<<"FechaLanzamiento: "<<movie.Lanzamiento<<endl;
        cout<<"Rentada a: "<<movie.NombreRentador<<endl;
        cout<<"Rentada el: "<<movie.FechaRenta<<endl;
        cout<<"Estado: "<<movie.Estado<<endl;
        	
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



	// Función para realizar consultas sobre el estado de renta de una película
void ConsultID()
{
		
    	char delimitador = ';';
    	Movies movie;
		string linea;
  		ifstream archivo(Archivo, ios::in);
    	string num_buscar;
    	

       
        
		
			
		cout<<"Ingrese id de la pelicula: "<<endl;
		cin>>num_buscar;
		
        
		
		bool existe = false;
        getline(archivo,linea);
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, movie.Id, delimitador);
	        getline(stream, movie.NameMovie, delimitador);
	        getline(stream, movie.Genero, delimitador);
	        getline(stream, movie.Duracion, delimitador);
	        getline(stream, movie.Director, delimitador);
	        getline(stream, movie.Precio, delimitador);
	        getline(stream, movie.Lanzamiento, delimitador);
	        getline(stream, movie.NombreRentador, delimitador);
	        getline(stream, movie.FechaRenta, delimitador);
	        getline(stream, movie.Estado, delimitador);

            if(num_buscar.compare(movie.Id) == 0){
                existe = true;
            cout<<"================================"<<endl;      
	    	cout<<"Nombre de la pelicula: "<<movie.NameMovie<<endl;
        	if (movie.Estado == "RENTADA") {
            cout << "Estado: " << movie.Estado << " Por " << movie.NombreRentador << "." <<endl;
        	}
		 	else {
            cout << "Estado: " << "DISPONIBLE" <<endl;
        	}
               
                
           	 }
            
       	}
		   
       	
       	archivo.close();
		   }
		   
		   
       	 
void ConsultName()
{
	char delimitador = ';';
    	Movies movie;
		string linea;
  		ifstream archivo(Archivo, ios::in);
    	string nombre_buscar;
    	

       
        
		
			
		cout<<"Ingrese nombre de la pelicula: "<<endl;
		cin>>nombre_buscar;
		
        
		
		bool existe = false;
        getline(archivo,linea);
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, movie.Id, delimitador);
	        getline(stream, movie.NameMovie, delimitador);
	        getline(stream, movie.Genero, delimitador);
	        getline(stream, movie.Duracion, delimitador);
	        getline(stream, movie.Director, delimitador);
	        getline(stream, movie.Precio, delimitador);
	        getline(stream, movie.Lanzamiento, delimitador);
	        getline(stream, movie.NombreRentador, delimitador);
	        getline(stream, movie.FechaRenta, delimitador);
	        getline(stream, movie.Estado, delimitador);

            if(nombre_buscar.compare(movie.NameMovie) == 0){
                existe = true;
            cout<<"================================"<<endl;
			cout<<"ID: "<<movie.Id<<endl;      
	    	cout<<"Nombre de la pelicula: "<<movie.NameMovie<<endl;
        	if (movie.Estado == "RENTADA") {
            cout << "Estado: " << movie.Estado << " Por " << movie.NombreRentador << "." <<endl;
        	}
		 	else {
            cout << "Estado: " << "DISPONIBLE" <<endl;
        	}
               
                
           	 }
            
       	}
		   
       	
       	archivo.close();
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
			cout << "(3) Realizar consulta de estado de las peliculas"<<endl;
			cout << "(4) Finalizar programa"<< endl;
			
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
				int k;
				cout<<"Como desea buscar la pelicula:  "<<endl;
				cout<< "(1)ID "<<endl;
				cout<< "(2)Nombre "<<endl;
				
        		cin>>k;
				
				if(1==k)
				{
					ConsultID();
				}
				if(k==2)
				{
					ConsultName();
					
				}
				
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

