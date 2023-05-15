#include "geesespotter_lib.h"
//g++ -o main geesespotter.cpp geesespotter_lib.cpp -std=c++11
char * createBoard(std::size_t xdim, std::size_t ydim){
    char *size {new char[xdim*ydim]{0}};
    return size;
}

void cleanBoard(char *board){
delete [] board;
board = nullptr; 
return;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim){  
    for (int k{0}; k < (xdim*ydim); k++) {
        if ((k % xdim == 0 && (k != 0))) {
                std::cout << "\n";
                }
        if ((board[k] & (1 << 4))) {
            std::cout << "M";
            }
        else if (int(board[k]) <= 9){
            std::cout << char(board[k] + 48);
            }
        else {
            std::cout << "*";
            }
        }
    std::cout << "\n";    
    return;
    }
// if (board[i] & (1 << 5)) {
//  std::cout << "* "
//}


void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim) {
    int decimal {0};
    for (int k{0}; k < (xdim*ydim); k++) {
        if (int(board[k]) != 9) {
            if (k == 0) {
                if (int(board[k+1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[xdim+1]) == 9) {
                    decimal += 1;
                    }
                }
            else if (k == xdim-1) {
                if (int(board[k-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim-1]) == 9) {
                    decimal += 1;
                    }
                }
            else if (k == (xdim*ydim)-xdim) {
                if (int(board[k+1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim+1]) == 9) {
                    decimal += 1;
                    }
                }
            else if (k == (xdim*ydim)-1) {
                if (int(board[k-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim-1]) == 9) {
                    decimal += 1;
                    }
                }
            else if (k < xdim-1) {
                if (int(board[k-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim+1]) == 9) {
                    decimal += 1;
                    }
                }
            else if (k % xdim == 0) {
                if (int(board[k+1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim+1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim+1]) == 9) {
                    decimal += 1;
                    }
                }
            else if (((k+1) % xdim) == 0) {
                if (int(board[k-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim-1]) == 9) {
                    decimal += 1;
                    }
                }
            else {
                if (int(board[k-xdim-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-xdim+1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim-1]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim]) == 9) {
                    decimal += 1;
                    }
                if (int(board[k+xdim+1]) == 9) {
                    decimal += 1;
                    }
                }
            board[k] = decimal;
            decimal = 0;
            } 
        }
        return;
    }

void hideBoard(char *board, std::size_t xdim, std::size_t ydim){
     for (int k{0}; k < (xdim*ydim); k++) {
        board[k] |= (1 << 5);    
        }
    return;
}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
        int decimal = int(board[(xdim*yloc) + xloc]) & 1;
        decimal += int((board[(xdim*yloc) + xloc] & (1 << 1)));
        decimal += int((board[(xdim*yloc) + xloc] & (1 << 2)));
        decimal += int((board[(xdim*yloc) + xloc] & (1 << 3)));
        if (int((board[(xdim*yloc) + xloc]) == 41)) {
            board[(xdim*yloc) + xloc] &= ~(1 << 5);
            return 9;
        } 
        else if (board[(xdim*yloc) + xloc] & (1 << 4)) {
            return 1;
            }
        else if (int(board[(xdim*yloc) + xloc]) <= 30) {
            return 2;
            }
        board[(xdim*yloc) + xloc] &= ~(1 << 5);
        if (decimal == 0 && (xloc == 0) && (yloc == 0)) {
            decimal = int((board[1] & 1)); 
            decimal += int(((board[1] & (1 << 3)))); 
            if (decimal != 9) {
                board[1] &= ~(1 << 5); 
            }
            decimal = int((board[xdim] & 1)); 
            decimal += int((board[xdim] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim] &= ~(1 << 5);
            }
            decimal = int((board[xdim + 1] & 1)); 
            decimal += int((board[xdim + 1] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim + 1] &= ~(1 << 5);
            }
            return 0;
        }
        else if (decimal == 0 && (xloc == xdim-1) && (yloc == 0)) {
            decimal = int((board[xloc - 1] & 1)); 
            decimal += int((board[xloc - 1] & (1 << 3))); 
            if (decimal != 9) {
                board[xloc - 1] &= ~(1 << 5); 
            }
            decimal = int((board[xdim + xloc] & 1)); 
            decimal += int((board[xdim + xloc] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim + xloc - 1] & 1)); 
            decimal += int((board[xdim + xloc - 1] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim + xloc - 1] &= ~(1 << 5);
            }
            return 0;
        }
        else if (decimal == 0 && (xloc == 0) && (yloc == ydim-1)) {
            decimal = int((board[(xdim*yloc) + 1] & 1)); 
            decimal += int((board[(xdim*yloc) + 1] & (1 << 3)));
             if (decimal != 9) {
                 board[(xdim*yloc) + 1] &= ~(1 << 5); 
            }
            decimal = int((board[xdim*(yloc-1)] & 1)); 
            decimal += int((board[xdim*(yloc-1)] & (1 << 3)));
             if (decimal != 9) {
                board[xdim*(yloc-1) + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc-1) + 1] & 1)); 
            decimal += int((board[xdim*(yloc-1) + 1] & (1 << 3)));
             if (decimal != 9) {
                board[xdim*(yloc-1) + 1] &= ~(1 << 5);
            }
            return 0;
        }
        else if (decimal == 0 && ((xloc*yloc) == ((xdim-1)*(ydim-1)))) {
            decimal = int((board[(xdim*ydim) - 2] & 1)); 
            decimal += int((board[(xdim*ydim) - 2] & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*ydim) - 2] &= ~(1 << 5); 
            }
            decimal = int((board[(xdim*ydim) - xdim - 2] & 1)); 
            decimal += int((board[(xdim*ydim) - xdim - 2] & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*ydim) - xdim - 2] &= ~(1 << 5);
            }
            decimal = int((board[(xdim*ydim) - xdim - 1] & 1)); 
            decimal += int((board[(xdim*ydim) - xdim - 1] & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*ydim) - xdim - 1] &= ~(1 << 5);
            }
            return 0;
        }
        else if (decimal == 0 && (yloc == 0)) {
            decimal = int((board[xloc + 1] & 1)); 
            decimal += int((board[xloc + 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xloc + 1] &= ~(1 << 5);
            } 
            decimal = int((board[xloc - 1] & 1)); 
            decimal += int((board[xloc - 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xloc - 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim + xloc] & 1)); 
            decimal += int((board[xdim + xloc]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim + xloc - 1] & 1)); 
            decimal += int((board[xdim + xloc - 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim + xloc - 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim + xloc + 1] & 1)); 
            decimal += int((board[xdim + xloc + 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim + xloc + 1] &= ~(1 << 5);
            }
            return 0;
        }
        else if (decimal == 0 && (xloc == 0)) {
            decimal = int((board[(xdim*yloc) + 1] & 1)); 
            decimal += int((board[(xdim*yloc) + 1] & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*yloc) + 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc-1)] & 1)); 
            decimal += int((board[xdim*(yloc-1)] & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc-1)] &= ~(1 << 5);
            }
            decimal = int((board[(xdim*(yloc-1)) + xloc + 1] & 1)); 
            decimal += int((board[(xdim*(yloc-1)) + xloc + 1] & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc-1) + xloc + 1] &= ~(1 << 5);
            }
            decimal = int((board[(xdim*(yloc+1)) + xloc] & 1)); 
            decimal += int((board[(xdim*(yloc+1)) + xloc] & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc+1) + xloc] &= ~(1 << 5);
            }
            decimal = int((board[(xdim*(yloc+1)) + xloc + 1] & 1)); 
            decimal += int((board[(xdim*(yloc+1)) + xloc + 1] & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*(yloc+1)) + xloc + 1] &= ~(1 << 5);
            }
            return 0;
        }
        else if (decimal == 0 && (xloc == xdim-1)) {
            decimal = int((board[(xdim*yloc) + xloc - 1] & 1)); 
            decimal += int((board[(xdim*yloc) + xloc - 1] & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*yloc) + xloc- 1] &= ~(1 << 5); 
            }
            decimal = int((board[xdim*(yloc-1) + xloc] & 1)); 
            decimal += int((board[xdim*(yloc-1) + xloc]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc-1) + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc-1) + xloc - 1] & 1)); 
            decimal += int((board[xdim*(yloc-1) + xloc - 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc-1) + xloc - 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc+1) + xloc] & 1)); 
            decimal += int((board[xdim*(yloc+1) + xloc]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc+1) + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc+1) + xloc - 1] & 1)); 
            decimal += int((board[xdim*(yloc+1) + xloc - 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc+1) + xloc - 1] &= ~(1 << 5);
            }
            return 0;
        }
        else if (decimal == 0 && (yloc == ydim-1)) {
            decimal = int((board[(xdim*yloc) + xloc + 1] & 1)); 
            decimal += int((board[(xdim*yloc) + xloc + 1]  & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*yloc) + xloc + 1] &= ~(1 << 5); 
            }           
            decimal = int((board[(xdim*yloc) + xloc - 1] & 1)); 
            decimal += int((board[(xdim*yloc) + xloc - 1]  & (1 << 3)));
            if (decimal != 9) {
                board[(xdim*yloc) + xloc - 1] &= ~(1 << 5);
            }            
            decimal = int((board[xdim*(yloc-1) + xloc] & 1)); 
            decimal += int((board[xdim*(yloc-1) + xloc]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc-1) + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc-1) + xloc - 1] & 1)); 
            decimal += int((board[xdim*(yloc-1) + xloc - 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc-1) + xloc - 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc-1) + xloc + 1] & 1)); 
            decimal += int((board[xdim*(yloc-1) + xloc + 1]  & (1 << 3)));
            if (decimal != 9) {
                board[xdim*(yloc-1) + xloc + 1] &= ~(1 << 5);
            }
            return 0;
        }
         else if (decimal == 0) {
            decimal = int((board[(xdim*yloc) + xloc - 1] & 1)); 
            decimal += int((board[(xdim*yloc) + xloc - 1]& (1 << 3))); 
            if (decimal != 9) {
                board[(xdim*yloc) + xloc - 1] &= ~(1 << 5);
            }
            decimal = int((board[(xdim*yloc) + xloc + 1] & 1));  
            decimal += int((board[(xdim*yloc) + xloc + 1] & (1 << 3))); 
            if (decimal != 9) {
                board[(xdim*yloc) + xloc + 1] &= ~(1 << 5);
            } 
            decimal = int((board[xdim*(yloc - 1) + xloc] & 1)); 
            decimal += int((board[(xdim*(yloc - 1) + xloc)] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim*(yloc - 1) + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc - 1) + xloc - 1] & 1)); 
            decimal += int((board[xdim*(yloc - 1) + xloc - 1] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim*(yloc - 1) + xloc - 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc - 1) + xloc + 1] & 1)); 
            decimal += int((board[xdim*(yloc - 1) + xloc + 1] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim*(yloc - 1) + xloc + 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc+1) + xloc] & 1)); 
            decimal += int((board[xdim*(yloc+1) + xloc] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim*(yloc+1) + xloc] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc+1) + xloc + 1] & 1)); 
            decimal += int((board[xdim*(yloc+1) + xloc + 1] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim*(yloc+1) + xloc + 1] &= ~(1 << 5);
            }
            decimal = int((board[xdim*(yloc+1) + xloc - 1] & 1)); 
            decimal += int((board[xdim*(yloc+1) + xloc - 1] & (1 << 3))); 
            if (decimal != 9) {
                board[xdim*(yloc+1) + xloc - 1] &= ~(1 << 5);
            }
            return 0;
        }
        else {
            return 0;
        }
    }


int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
    if (board[xdim*(yloc) + xloc] & (1 << 5)){
        board[(xdim*yloc) + xloc] ^= (1 << 4);
        return 0;
        }
    else {
    return 2;
    }
}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim){
    int geese = 0;
    for (int k{0}; k < (xdim*ydim); k++) {
        if (int(board[k]) == 41) {
            geese += 1;
        }
    }
    if (geese == (xdim*ydim)) {
        return true;
        }
        
    for (int k{0}; k < (xdim*ydim); k++) {
        if ((board[k] & (1 << 5)) && ((board[k] & 0x0F) != 9))  { 
            return false;
        }
    }
   return true;
}