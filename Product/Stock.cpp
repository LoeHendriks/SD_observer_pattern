#include "Stock.h"
#include <iostream>
Stock::Stock()
{
    this->mState = 0;
}



void Stock::Attach(IObserver* observer)
{
    std::cout << "adding" << std::endl;
    this->mObserverList.push_back(observer);
}


void Stock::Detach(IObserver* observer)
{
    int32_t size = this->mObserverList.size();
    for(uint32_t i = 0; i < size;i++)
    {
        if(this->mObserverList[i] == observer)
        {
            this->mObserverList.erase(this->mObserverList.begin()+i-1);
            continue;
        }
    }
}

std::vector<IObserver*> Stock::GetList()
{
    return this->mObserverList;
}

void Stock::Update(int32_t value)
{
    if(GetList().empty())
    {
        std::cout << "No observers" << std::endl;
    }
    else{
        mState = value;
        Notify();
    }
}

void Stock::Notify()
{
    for(uint32_t i = 0; i < this->mObserverList.size();i++)
    {
        this->mObserverList[i]->Update();
    }
}

void Stock::SetState(int32_t state)
{
    this->mState = state;
}

int32_t Stock::GetState()
{
    return this->mState;
}
