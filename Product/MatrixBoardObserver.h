#ifndef MATRIXBOARDOBSERVER_H
#define MATRIXBOARDOBSERVER_H

#include "IObserver.h"


class MatrixBoardObserver : public IObserver{
public:
    MatrixBoardObserver(ISubject* s):IObserver(s){};
    void Update() override;

};

#endif