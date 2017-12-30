//
// Created by Angel on 18/02/2017.
//

#ifndef AEDA_BOARD_H
#define AEDA_BOARD_H

#include <cstdlib>
#include <vector>
#include <set>
#include <ostream>

#include "Cell.h"

using namespace std;

typedef pair<int,int> Position;
typedef set<Position> SetPosition;
typedef vector<Cell*> VectorCell; /** Puntero a célula porque cambiaremos el tipo dinámicamente */
typedef vector<VectorCell> MatrixCell;

class Board {

    friend ostream& operator<<(ostream& os, const Board& board);

private:

    MatrixCell board_;
    int width_;
    int height_;

public:

    Board(int height, int width);

    ~Board();

    int getWidth() const;

    int getHeight() const;

    Cell* getCell(int i, int j) const;

    void Initialize(const SetPosition& set_position);

    void update();

private:

    void InitializeRandom();

};

#endif //AEDA_BOARD_H
