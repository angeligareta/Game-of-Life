//
// Created by Angel on 12/03/2017.
//

#ifndef AEDA_CELLTYPEC_H
#define AEDA_CELLTYPEC_H

#include "../Cell.h"

const vector<int> C_AliveRequired{5,1}; /** Indica los vecinos que la celula requiere para que siga viva. **/
const vector<int> C_DeadRequired{3,4,6};    /** Indica los vecinos que la celula requiere para que nazca. **/
const int C_CellColor=FG_GREEN;

class CellTypeC : public Cell {
    
public:

    CellTypeC(bool state = true) : Cell(true){}
    virtual bool update(Board &board, int i, int j);
    static bool CheckCanBorn(Board &board, int i, int j);
    
protected:

    virtual ostream& print(ostream& os) const;
    
};

#endif //AEDA_CELLTYPEC_H
