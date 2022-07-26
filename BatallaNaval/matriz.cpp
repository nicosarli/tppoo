#include "matriz.h"
#include <iostream>
#include <iomanip>

Matriz::Matriz()
{

}


int Matriz::getTamanioMatriz() const
{
    return tamanioMatriz;
}

void Matriz::setTamanioMatriz(int newTamanioMatriz)
{
    tamanioMatriz = newTamanioMatriz;
}

bool Matriz::lugarDisponible(int posX, int posY, int tamanio, char orientacion)
{
     bool disponibilidad = true;
     int restoY = posY-(tamanio/2);
     int restoX = posX-(tamanio/2);

     switch(orientacion){
     case 'H':
         //posicion X HORIZONAL
             for (int i=0;i<tamanio;i++){
                 if(matriz[posY][i+restoX] != '-')
                     disponibilidad = false;
            }
         break;
     case 'V':
         //posicion X VERTICAL
             for (int i=0;i<tamanio;i++){
                 if(matriz[i+restoY][posX] != '-')
                     disponibilidad = false;
              }
        break;
     }
     return disponibilidad;
}

//    if(this->matriz[posY][posX] == '-')
//        return true;
//        else return false;}



    void Matriz::crear_matriz(){
        //CREAR MATRIZ
    this->matriz= new char*[this->tamanioMatriz];
    for(int i=0;i<this->tamanioMatriz;i++){
       this->matriz[i]=new char[this->tamanioMatriz];
    }

    //BORDES
    int A = 64;
    int num = 48;
    for(int i=0;i<this->tamanioMatriz;i++){
        //this->matriz[i][0]= A;    LETRAS
        this->matriz[i][0]= num;
        this->matriz[0][i]= num;
        A +=1;
        num+=1;
    }

    //RELLENAR " - "
    for(int i=1;i<this->tamanioMatriz;i++){
        for(int j=1;j<this->tamanioMatriz;j++){
            this->matriz[i][j]= '-';
        }

    }

    /*  MATRIZ INT VIEJA

        this->matriz= new int*[this->filas];

        for(int i=0;i<this->filas;i++){
           this->matriz[i]=new int[this->columnas];
        }
        for(int i=0;i<this->filas;i++){
            for(int j=0;j<this->columnas;j++){
                this->matriz[i][j]= 0;
            }
        }*/
}

void Matriz::mostrar_matriz()
{
    for(int i=0;i<this->tamanioMatriz;i++){
        for(int j=0;j<this->tamanioMatriz;j++){
            std::cout<<std::setw(3)<<this->matriz[i][j];
        }std::cout<<std::endl;

    }
}

void Matriz::agregar_barco(Barco *barco)
{
    //si no hay barcos en esa pos:-
    //if(lugarDisponible(barco->getX(), barco->getY(), barco->getTamanio(), barco->getOrientacion())){
        int tamanio = barco->getTamanio();
        char orientacion = barco->getOrientacion();
        int x = barco->getX();
        int y = barco->getY();
        int restoY = y-(tamanio/2);
        int restoX = x-(tamanio/2);

        switch(orientacion){
        case 'H':
            //posicion X HORIZONAL
                for (int i=0;i<tamanio;i++){
                this->matriz[y][i+restoX] = barco->getNum();
               }
            break;
        case 'V':
            //posicion X VERTICAL
                for (int i=0;i<tamanio;i++){
                this->matriz[i+restoY][x] = barco->getNum();
        }
            break;
        }
        //en el caso de que haya algun barco en es pos:
//    }else{
//        std::cout<<"\nEl barco no se pudo agregar porque hay otro barco en la misma pos"<<std::endl;
//    }
}


