//
// Created by Angel on 12/03/2017.
//

#include "CellTypeB.h"
#include "../Board.h"

bool CellTypeB::update(Board &board, int i, int j) 
{

    int number_near_alife = Cell::CountNearAlife(board,i,j);
    int iterator=0;

    if ( state_ ) { // Está viva.
        while (iterator!=B_AliveRequired.size()) {
            if (number_near_alife==B_AliveRequired[iterator++]) {
                return true; // Devuelve 1 si sigue viva.
            }
        }
    }
    else { cout << "ERROR-CELULA MUERTA" << endl; }
    
    return false; // Devuelve 0 si tiene que ser destruida.

}

bool CellTypeB::CheckCanBorn(Board &board, int i, int j)
{
    
    int number_near_alife = Cell::CountNearAlife(board,i,j);
    int iterator=0;

    if ( board.getCell(i, j) -> is_dead() ) { // Está muerta
        while (iterator!=B_DeadRequired.size()) {
            if (number_near_alife==B_DeadRequired[iterator++]) {
                return true;
            }
        }
    }
    else { cout << "ERROR-CELULA VIVA" << endl; }
    
    return false;
}

ostream& CellTypeB::print(ostream &os) const 
{

    SetColor(B_CellColor);
    
    if (state_) { os << "●";} // Si está viva
    else { os << " "; }
    
    SetColor(FG_DEFAULT);
    
    return os;
}
