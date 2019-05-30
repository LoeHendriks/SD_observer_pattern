#include "../Product/PotmeterControl.h"
#include "../Product/StateManager.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Events.h"
#include <iostream>


using ::testing::Return;
using ::testing::_;

class StateManagerTest : public ::testing::Test
{
public:
    StateManagerTest() 
    {
		sm = new StateManager();
    }

    virtual ~StateManagerTest() 
    {
		delete sm;
		sm = NULL;
    }
    
protected:
	StateManager* sm;
};

TEST_F(StateManagerTest, clock_test)
{
	std::cout << "clock_test" << std::endl;
	sm->UpdateClock(5, TIME_DIALED);
}
