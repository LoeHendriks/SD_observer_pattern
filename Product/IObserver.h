#ifndef IOBSERVER_H
#define IOBSERVER_H
#include <vector>
#include "ISubject.h"

class IObserver{
public:
    IObserver(ISubject* s) {
        mSubject = s;
        mSubject->Attach(this);
    };
    virtual void Update() = 0;
    ISubject* mSubject;
};


#endif