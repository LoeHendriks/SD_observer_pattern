#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <string>
#include "IObserver.h"
class IObserver;
class ISubject{
public:
    ISubject(){}
    virtual void Attach(IObserver* observer) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual std::vector<IObserver*> GetList() = 0;
    virtual void Notify() = 0;
    virtual void Update(int32_t value) = 0;
    virtual int32_t GetState() = 0;

    std::vector<IObserver*> mObserverList;    
};

#endif