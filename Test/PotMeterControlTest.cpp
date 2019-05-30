#include "../Product/PotmeterControl.h"
#include "../Product/StateManager.h"
#include "../Product/IPotmeter.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>

#define MIN_IN 1
#define MAX_IN 10

#define MIN_OUT 1
#define MAX_OUT 20

using ::testing::Return;
using ::testing::_;

class PotMeterControlTest : public ::testing::Test
{
public:
    PotMeterControlTest() 
    {
		sm = new StateManager();
		pc = new PotmeterControl(sm);
    }

    virtual ~PotMeterControlTest() 
    {
		delete pc;
		pc = NULL;
    }
    
protected:
	PotmeterControl* pc;
	StateManager* sm;
};

TEST_F(PotMeterControlTest, map_test)
{
	std::cout << "map_test" << std::endl;
	
	uint32_t value = 5;
	uint32_t result = pc->map(value, MIN_IN, MAX_IN, MIN_OUT, MAX_OUT);
	EXPECT_EQ(9, result);
}

TEST_F(PotMeterControlTest, pot_value_convert_test)
{
	std::cout << "pot_value_convert_test" << std::endl;
	
	uint32_t valueToExpect = 3300;
	uint32_t valueToInsert = 1023;
	EXPECT_EQ(valueToExpect, pc->ConvertPotValue(valueToInsert));
}
