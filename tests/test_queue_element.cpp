#include "gmock/gmock.h"
#include "stub.h"
#include "mock_queue_element.h"

using ::testing::_;
using ::testing::Return;
using ::testing::SaveArgPointee;
using ::testing::SetArgPointee;
using ::testing::SaveArg;
using ::testing::SetArgReferee;
using ::testing::SetArrayArgument;
using ::testing::DoAll;

/**
* @Description: Test to Push element in queue
* @Input: 
* @Result: No return - OK
* @FunctionSafety: no
* @Security: non-SPR
* @TestMaturity: Released
*/
TEST(test_Push, test_Push_OK)
{
	QUEUE_CoreTestMockEnv q_mock;
	int imenu_choose = 2;
	int value_push = 1;
	
    EXPECT_CALL(*q_mock.GetInstance())
        .WillOnce();
	
	Push(value_push);
}

/**
* @Description: Test to Pop element in queue
* @Input: 
* @Result: No return - OK
* @FunctionSafety: no
* @Security: non-SPR
* @TestMaturity: Released
*/
TEST(test_Pop, test_Pop_OK)
{
	QUEUE_CoreTestMockEnv q_mock;
	int imenu_choose = 1;
	int value_pop;
	
    EXPECT_CALL(*q_mock.GetInstance())
        .WillOnce();
	
	value_pop = Pop();
	
	EXPECT_TRUE(value_pop == 1)
}
