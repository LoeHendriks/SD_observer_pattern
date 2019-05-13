#ifndef APPOBSERVER_H
#define APPOBSERVER_H

#include "IObserver.h"

class AppObserver : public IObserver{
public:
    AppObserver(ISubject* s):IObserver(s){}
    void Update() override;
};

#endif