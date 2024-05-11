#include <iostream>
#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <list>
#include <random> // Incluimos <random> en lugar de <experimental/random>
#include "Archivo.hpp" // Asumiendo que los archivos de Archivo.hpp y Dibujo.hpp están en el mismo directorio que main.cpp
#include "Dibujo.hpp" 

using namespace ftxui;
using namespace std;

int main(int argc, char const *argv[])
{
    Archivo alien("./assets/images/alien.txt");

    list<Dibujo> dibujos;
    // Crear Aliens
    for (size_t i = 0; i < 20; i++)
    {
        Dibujo d = alien.CrearDibujo();
        d.EstablecerPosicion(
            random() % 20,
            random() % 20
        );
        dibujos.push_back(d);
    }

    // Crear monitos
    for (int i = 0; i < 20; i++)
    {
        list<string> c;
        c.push_back("Personaje:" + to_string(i));
        c.push_back("  O");
        c.push_back("--|-- ");
        c.push_back(" / \\");

        Dibujo contenido(
            c,
            random() % 50, // PosX
            random() % 50  // PosY
        );
        dibujos.push_back(contenido);
    }    

    auto Pantalla = Screen::Create(
        Dimension::Full(), 
        Dimension::Full()
    );

    while(true){
        Pantalla.Clear();
        this_thread::sleep_for(0.1s);

        // Actualizar
        for (auto &&i : dibujos)
        {
            i.DesplazarX(random() % 3 - 1); // Modificamos los desplazamientos para que estén entre -1 y 1
            i.DesplazarY(random() % 3 - 1); // Modificamos los desplazamientos para que estén entre -1 y 1
        }

        // Dibujar
        for (auto &&i : dibujos)
        {
            i.Dibujar(Pantalla);
        }
        
        Pantalla.Print();
        cout<<Pantalla.ResetPosition();          
    }

    return 0;
}
