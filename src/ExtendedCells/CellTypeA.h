//
// Created by Angel on 12/03/2017.
//

#ifndef AEDA_CELLTYPEA_H
#define AEDA_CELLTYPEA_H

#include "../Cell.h"

const vector<int> A_AliveRequired{2,3}; /** Indica los vecinos que la celula requiere para que siga viva. **/
const vector<int> A_DeadRequired{3};    /** Indica los vecinos que la celula requiere para que nazca. **/
const int A_CellColor=FG_RED;

class CellTypeA : public Cell {
    
public:

    CellTypeA(bool state = true) : Cell(true){}
    virtual bool update(Board &board, int i, int j);
    static bool CheckCanBorn(Board &board, int i, int j);
    
protected:

    virtual ostream& print(ostream& os) const;
    
};

#endif //AEDA_CELLTYPEA_H
