#pragma once

#include <gtest/gtest.h>
#ifdef _DEBUG
#pragma comment(lib,"gtestd.lib")
#pragma comment(lib,"gtest_maind.lib")
#else
#pragma comment(lib,"gtest.lib")
#pragma comment(lib,"gtest_main.lib")
#endif


class CGT
	: public ::testing::Test
{
public:
	CGT()
	{
		printf("CGT\n");
	};

	~CGT()
	{
		printf("~CGT\n");
	};
	//����У��
	bool COdd(int nValue)
	{
		return (1 == (nValue % 2)) ? true : false;
	}
	//ż��У��
	bool CEven(int nValue)
	{
		return (0 == (nValue % 2)) ? true : false;
	}

	//ÿ������[-][����]��ʼǰ����ִ��һ�� Suite
	void SetUp()
	{
		printf("CGT SetUp\n");
	};
	//ÿ������[-][����]�����󽫻�ִ��һ�� Suite
	void TearDown()
	{
		printf("CGT TearDown\n");
	};
	//ÿ������[����][-]��ʼǰ����ִ��һ�� Case
	static void SetUpTestCase()
	{
		printf("CGT SetUpTestCase\n");
	}
	//ÿ������[����][-]�����󽫻�ִ��һ�� Case
	static void TearDownTestCase()
	{
		printf("CGT TearDownTestCase\n");
	}

};
