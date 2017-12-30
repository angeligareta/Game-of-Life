//
// Created by Angel on 18/02/2017.
//
#include "Board.h"

ostream& operator<<(ostream &os, const Board& board) {

    os << "┌"; for (int i=0; i<board.width_; ++i) { os << "─"; } os << "┐" << endl;

    for (int i=0; i<board.height_; ++i) {
        for( int j=0; j<board.width_; ++j) {
            if (j==0) { os << "|"; }
            os << *board.board_[i][j];
            if (j==board.width_-1) { os << "|"; }
        }
        os << endl;
    }

    os << "└"; for (int i=0; i<board.width_; ++i) { os << "─"; } os << "┘" << endl;

    return os;
}

Board::Board(int height, int width):
    height_(height),
    width_(width){
    for (int i = 0; i < height_; ++i) {
        VectorCell vectorcell;
        for (int j = 0; j < width_; ++j) {
            vectorcell.push_back(new Cell);
        }
        board_.push_back(vectorcell);
    }
}

Board::~Board()
{
    for (int i=0; i<height_; ++i){
        for( int j=0; j<width_; ++j) {
            delete board_[i][j];
        }
    }
}

int Board::getWidth() const
{
    return width_;
}

int Board::getHeight() const
{
    return height_;
}

Cell* Board::getCell(int i, int j) const
{
    return board_[i][j];
}

void Board::Initialize(const SetPosition &set_position)
{
    if (set_position.empty()) { // Si no ha seleccionado posiciones de la matriz se generan aleatorios
        InitializeRandom();
    }
    else {
        for( auto position : set_position){
            delete board_[position.first][position.second];
            board_[position.first][position.second]=Cell::CreateRandomCell();
        }
    }
}

void Board::InitializeRandom()
{

    srand(time(NULL)); // Semilla para obtener valores aleatorios
    
    int loop_limit=(rand()%height_ + height_/4) *width_;
    
    for( int i=0; i<loop_limit; ++i){
        int random_i=rand()%height_, random_j=rand()%width_; // Aleatorio entre 0 y max-1
        delete board_[random_i][random_j];
        board_[random_i][random_j]=Cell::CreateRandomCell();
    }
}

void Board::update()
{

    for (int i=0; i<height_; ++i){
        for( int j=0; j<width_; ++j) {
            if (board_[i][j] -> is_dead()) { // Si la célula está muerto miro a ver si un tipo puede nacer.
                if ( Cell::CreateNewCell(*this,i,j)!=nullptr) {
                    delete board_[i][j];
                    board_[i][j] = Cell::CreateNewCell(*this,i,j);
                }    
            }
            else { //Si está vivo miro si sobrevive, si no creo una nueva célula
                if (board_[i][j]->update(*this,i,j) == 0) {
                    delete board_[i][j];
                    board_[i][j] = new Cell;
                }
            }
        }
    }
}