#include "AppObserver.h"
#include <iostream>

void AppObserver::Update()
{
    std::cout << "AppObserver State: " <<  this->mSubject->GetState() << std::endl;
}