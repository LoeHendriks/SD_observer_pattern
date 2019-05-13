#include "MatrixBoardObserver.h"
#include <iostream>



void MatrixBoardObserver::Update()
{
    std::cout << "MatrixBoardObserver State: " <<  this->mSubject->GetState() << std::endl;
}