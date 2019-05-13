#ifndef NEWSPAPEROBSERVER_H
#define NEWSPAPEROBSERVER_H

#include "IObserver.h"

class NewsPaperObserver : public IObserver{
public:
    NewsPaperObserver(ISubject* s):IObserver(s){}
    void Update() override;
};

#endif