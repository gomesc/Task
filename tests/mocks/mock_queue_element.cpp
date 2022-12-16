#include "mock_queue_element.h"

std::shared_ptr<QUEUE_CoreTestMock> QUEUE_CoreTestMockEnv::QUEUE_Test;

int Count (void)
{
	return QUEUE_CoreTestMockEnv::GetInstance()->Count();
}

int Size (void)
{
	return QUEUE_CoreTestMockEnv::GetInstance()->Size();
}

T Pop (void)
{
	return QUEUE_CoreTestMockEnv::GetInstance()->Pop();
}

void Pop (T)
{
	return ;
}

void Queue (T)
{
	return ;
}

