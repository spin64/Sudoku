#include "cell.h"

cell::cell(int n, char t): n{n}, type{t} {}

cell::~cell(){}

int cell::getN(){
    return n;
}

void cell::setN(int k){
    this->n = k; 
}

char cell::getType(){
    return type;
}