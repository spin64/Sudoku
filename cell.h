#ifndef _cell_H_
#define _cell_H_

class cell{
    int n;
    char type;
public:
    cell(int n, char t);
    ~cell();
    int getN();
    void setN(int k);
    char getType();
};

#endif