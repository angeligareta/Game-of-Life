//
// Created by Angel on 18/02/2017.
//

#ifndef AEDA_CELL_H
#define AEDA_CELL_H

#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

enum Code {
    FG_BLACK    = 30,
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_BROWN    = 33,
    FG_BLUE     = 34,
    FG_MAGENTA  = 35,
    FG_CYAN     = 36,
    FG_GRAY     = 37,
    FG_DEFAULT  = 39,
};
inline const void SetColor(int color) { cout << "\033[" << color << "m"; }

class Board; // Para que no entre en bucle, avisamos al compilador de que luego le decimos la clase Board

class Cell {

    friend ostream& operator<<(ostream& os, const Cell& cell);

protected:

    bool state_;

public:
    Cell (bool state = false): state_(state) {}

    virtual ~Cell();

    bool is_dead() const;

    void set_state(bool state);
    
    virtual ostream& print(ostream& os) const;
    
    virtual bool update(Board& board, int i, int j);
    
    static Cell* CreateNewCell(Board &board, int i, int j);
    
    static Cell* CreateRandomCell();

protected:

    /**Estática por que no tiene sentido que se necesite un objeto, ya le pasamos uno*/
    static int CountNearAlife (const Board& board, int position_i, int position_j);

};

#endif //AEDA_CELL_H
