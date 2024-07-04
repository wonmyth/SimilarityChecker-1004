#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

#include <iostream>

using namespace std;

TEST(SimilarityCheckerFixture, CheckStringLengthTest_MAX) {
	SimilarityChecker chk;
	string A = { "ABCDEF" };
	string B = { "ABCDEF" };
	int ret = chk.getStringLengthScore(A, B);

	EXPECT_EQ(ret, SimilarityChecker::MAX_SCORE_STRING_LENGTH);
}
TEST(SimilarityCheckerFixture, CheckStringLengthTest_MIN) {
	SimilarityChecker chk;
	string A = { "ABCDEF" };
	string B = { "ABC" };
	int ret = chk.getStringLengthScore(A, B);

	EXPECT_EQ(ret, SimilarityChecker::MIN_SCORE_STRING_LENGTH);
}
TEST(SimilarityCheckerFixture, CheckStringLengthTest_MIN2) {
	SimilarityChecker chk;
	string A = { "ABCDEF" };
	string B = { "ABCDEFABCDEF" };
	int ret = chk.getStringLengthScore(A, B);

	EXPECT_EQ(ret, SimilarityChecker::MIN_SCORE_STRING_LENGTH);
}

TEST(SimilarityCheckerFixture, CheckStringLengthTest_MID) {
	SimilarityChecker chk;
	string A = { "ABCDEF" };
	string B = { "ABCDEFG" };
	int ret = chk.getStringLengthScore(A, B);
	// 60 - 60 * 1 / 6;
	EXPECT_EQ(ret, 50);
}

TEST(SimilarityCheckerFixture, CheckStringLengthTest_MID2) {
	SimilarityChecker chk;
	string A = { "ABCDEF" };
	string B = { "ABCDEFGHI" };
	int ret = chk.getStringLengthScore(A, B);
	// 60 - 60 * 3 / 6;
	EXPECT_EQ(ret, 30);
}