#ifndef STOCK_H
#define STOCK_H

#include <string>
#include "IObserver.h"

class Stock : public ISubject{
public:
    Stock();
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    std::vector<IObserver*> GetList() override;
    void Notify() override;

    void SetState(int32_t state);
    int32_t GetState() override;
    void Update(int32_t value) override;
private:
    int32_t mState;

};

#endif