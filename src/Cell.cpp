//
// Created by Angel on 18/02/2017.
//

#include "Cell.h"
#include "Board.h"

/** CLASES HEREDADAS */
#include "ExtendedCells/CellTypeA.h"
#include "ExtendedCells/CellTypeB.h"
#include "ExtendedCells/CellTypeC.h"

ostream& operator<<(ostream& os, const Cell& cell)
{
    cell.print(os);
    return os;
}

ostream& Cell::print(ostream& os) const
{
    
    if (state_) { os << "F"; } // Si está viva ¡fallo! No puede estar viva celula base
    else { os << " "; }
    
    return os;
}

Cell::~Cell()
{

}

bool Cell::is_dead() const
{
    return !state_;
}

void Cell::set_state(bool state)
{
    state_=state;
}

int Cell::CountNearAlife(const Board& board, int position_i, int position_j)
{
    int counter=0;

    for( int i=position_i-1; i<=position_i+1; ++i){
        if(i>=0 && i<board.getHeight()) {
            for (int j = position_j-1; j <= position_j+1; ++j) {
                if(j>=0 && j<board.getWidth()) {
                    if( (position_i!=i || position_j!=j) && !(board.getCell(i,j)->is_dead()) ) { counter++; }
                }
            }
        }
    }

    return counter;
}

bool Cell::update(Board &board, int i, int j)
{}

Cell* Cell::CreateNewCell(Board &board, int i, int j)
{
    
    if (CellTypeA::CheckCanBorn(board,i,j))
        return (new CellTypeA);
    else if (CellTypeB::CheckCanBorn(board,i,j))
        return (new CellTypeB);
    else if (CellTypeC::CheckCanBorn(board,i,j))
        return (new CellTypeC);
    
    return nullptr;
}

Cell* Cell::CreateRandomCell(){
    
    int random_option = rand()%3 + 1;
    
    switch (random_option) {
        case 1: return (new CellTypeA); break;
        case 2: return (new CellTypeB); break;
        case 3: return (new CellTypeC); break;
        default: cout << "No debería usar default\n"; break;
    }
}

