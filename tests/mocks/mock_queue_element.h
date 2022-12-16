#ifndef QUEUE_ELEMENT_H
#define QUEUE_ELEMENT_H

#include "gmock/gmock.h"

template <typename T>

class QUEUE_CLASSTESTMOCK
{
	public:
		MOCK_METHOD0(Queue,void(void));
		MOCK_METHOD0(Count,int(void)); 
		MOCK_METHOD0(Size,int(void));  
		MOCK_METHOD0(Pop,T(void));   
		MOCK_METHOD1(Push,void(T));  
};


class QUEUE_CoreTestMockEnv
{
public:
	QUEUE_CoreTestMockEnv() {
		QUEUE_Test = std::make_shared<QUEUE_CoreTestMock>();
	}
	virtual ~QUEUE_CoreTestMockEnv(){
		QUEUE_Test.reset();
	}
	static std::shared_ptr<QUEUE_CoreTestMock> GetInstance() {
		return QUEUE_Test;
	}


private:
	static std::shared_ptr<QUEUE_CoreTestMock> QUEUE_Test;
};

#endif