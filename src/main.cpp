#include <iostream>
#include <unistd.h>
#include "Board.h"

void printText()
{
 SetColor(FG_CYAN);
 std::cout << "  ______ _        _                          _____         _            __      ___     _                    \n";
 std::cout << " |  ____| |      | |                        |  __ \\       | |           \\ \\    / (_)   | |                \n";
 std::cout << " | |__  | |      | |_   _  ___  __ _  ___   | |  | | ___  | |     __ _   \\ \\  / / _  __| | __ _            \n";
 std::cout << " |  __| | |  _   | | | | |/ _ \\/ _` |/ _ \\  | |  | |/ _ \\ | |    / _` |   \\ \\/ / | |/ _` |/ _` |        \n";
 std::cout << " | |____| | | |__| | |_| |  __/ (_| | (_) | | |__| |  __/ | |___| (_| |    \\  /  | | (_| | (_| |            \n";
 std::cout << " |______|_|  \\____/ \\__,_|\\___|\\__, |\\___/  |_____/ \\___| |______\\__,_|     \\/   |_|\\__,_|\\__,_|   \n";
 std::cout << "                                __/ |                                                                        \n";
 std::cout << "                               |___/                                                                           ";
 SetColor(FG_DEFAULT); std::cout << "\n";
}

void showIndex()
{
    std::cout << endl;
    SetColor(FG_RED); std::cout << "●"; SetColor(FG_DEFAULT); std::cout << " Célula Tipo A  |  ";
    SetColor(FG_BLUE); std::cout << "●"; SetColor(FG_DEFAULT); std::cout << " Célula Tipo B  |  ";
    SetColor(FG_GREEN); std::cout << "●"; SetColor(FG_DEFAULT); std::cout << " Célula Tipo C " << endl;
}

int main() {
    
    system("clear");
    
    int height,width;
    
    printText();
    
    cout << "-Dimensiones del tablero-\n\n";
    cout << "-Introduzca la altura del tablero:\n"; cin >> height;
    cout << "-Introduzca el ancho del tablero:\n"; cin >> width;
    Board board(height,width);

    cout << "-Inicialización del tablero-\n\n";
    SetPosition set_position;

    bool exit=false;

    while (!exit){

        string answer;
        cout << "-¿Desea introducir la posición de una celula viva en el tablero?(y/n)\n";
        cin >> answer;

        if(answer=="y"){
            int i,j;

            cout << "-Introduzca la fila de la célula:\n"; cin >> i;
            while (i<0 || i>=board.getWidth()) {
                cout << "-¡ERROR!-Introduzca una fila dentro del rango:\n"; cin >> i;
            }

            cout << "-Introduzca la columna de la célula:\n"; cin >> j;
            while (j<0 || j>=board.getHeight()) {
                cout << "-¡ERROR!-Introduzca una columna dentro del rango:\n"; cin >> j;
            }

            set_position.insert(pair<int,int>(i,j));
        }
        else {
            exit=true;
        }
    }

    board.Initialize(set_position); int counter=0;

    while (true) {
        system("clear");
        printText(); showIndex(); std:: cout << "\nTurno " << ++counter << endl;
        cout << board;
        sleep(1);
        //cin.get();
        board.update();
    }
}