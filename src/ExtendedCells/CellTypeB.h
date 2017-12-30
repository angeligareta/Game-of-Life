//
// Created by Angel on 12/03/2017.
//

#ifndef AEDA_CELLTYPEB_H
#define AEDA_CELLTYPEB_H

#include "../Cell.h"

const vector<int> B_AliveRequired{3,4}; /** Indica los vecinos que la celula requiere para que siga viva. **/
const vector<int> B_DeadRequired{3,4};    /** Indica los vecinos que la celula requiere para que nazca. **/
const int B_CellColor=FG_BLUE;

class CellTypeB : public Cell {
    
public:

    CellTypeB(bool state = true) : Cell(true){}
    virtual bool update(Board &board, int i, int j);
    static bool CheckCanBorn(Board &board, int i, int j);
    
protected:

    virtual ostream& print(ostream& os) const;
    
};

#endif //AEDA_CELLTYPEB_H
