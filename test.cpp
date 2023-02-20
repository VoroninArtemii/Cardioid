#include <iostream>
#include <cmath>
#include "header.h"
#include <typeinfo>
#include <gtest/gtest.h>

TEST (Constuctor, Default){
	Cardioid test;
	ASSERT_EQ(0, test.get());
}

TEST (Constuctor, Initialization){
	ASSERT_EQ(1, Cardioid(1).get());
	ASSERT_EQ(3, Cardioid(3).get());
	ASSERT_EQ(2.8, Cardioid(2.8).get());
}

TEST (Constuctor, Exception){
	ASSERT_ANY_THROW(Cardioid(-1));
	ASSERT_ANY_THROW(Cardioid(-7));
	ASSERT_ANY_THROW(Cardioid(-8.9));
}

TEST (Getting, Exception){
	ASSERT_ANY_THROW(Cardioid(-1).get());
	ASSERT_ANY_THROW(Cardioid(-7).get());
	ASSERT_ANY_THROW(Cardioid(-8.9).get());
}

TEST (Distance, Initialization){
	ASSERT_EQ(4, Cardioid(1).distance(M_PI));
	ASSERT_EQ(0, Cardioid(1).distance(2*M_PI));
	ASSERT_EQ(8, Cardioid(2).distance(M_PI));
}

TEST (Curvature, Initialization){
	ASSERT_NEAR(8.0/3.0, Cardioid(1).curvature(M_PI), 0.001);
	ASSERT_NEAR(24.0/3.0, Cardioid(3).curvature(M_PI), 0.001);
	ASSERT_NEAR(16.0/3.0, Cardioid(2).curvature(M_PI), 0.001);
}

TEST (Square, Initialization){
	ASSERT_NEAR(M_PI*6, Cardioid(1).square(), 0.001);
	ASSERT_NEAR(M_PI*54, Cardioid(3).square(), 0.001);
	ASSERT_NEAR(M_PI*24, Cardioid(2).square(), 0.001);
}

TEST (Length, Initialization){
	ASSERT_NEAR(8, Cardioid(1).length(M_PI), 0.001);
	ASSERT_NEAR(16, Cardioid(2).length(M_PI), 0.001);
	ASSERT_NEAR(32, Cardioid(2).length(2*M_PI), 0.001);
}

int main(){
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
