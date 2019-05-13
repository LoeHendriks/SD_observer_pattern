#include "NewsPaperObserver.h"
#include <iostream>

void NewsPaperObserver::Update()
{
    std::cout << "NewsPaperObserver State: " <<  this->mSubject->GetState() << std::endl;
}