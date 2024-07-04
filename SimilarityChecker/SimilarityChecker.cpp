#include <string>
#include <stdexcept>
#include <vector>


using namespace std;

class SimilarityChecker {
public:	
	int getStringLengthScore(const string& A, const string& B) {
		int A_Length = A.length();
		int B_Length = B.length();
		
		if (isSameLength(A_Length, B_Length)) return MAX_SCORE_STRING_LENGTH;
		if (isDoubleLength(A_Length, B_Length)) return MIN_SCORE_STRING_LENGTH;

		return calLengthScore(A_Length, B_Length);
	}

	int getStringAlphaScore(const string& A, const string& B) {
		int A_check[ALPHABET_LENGTH] = {0,}, B_check[ALPHABET_LENGTH] = {0,};
		
		for (int i = 0; i < A.length(); i++) {
			int index = A[i] - 'A';
			A_check[index] = 1;
		}
		for (int i = 0; i < B.length(); i++) {
			int index = B[i] - 'A';
			B_check[index] = 1;
		}

		int diffCnt = 0, sameCnt = 0;
		int totalCnt = 0;

		for (int i = 0; i < ALPHABET_LENGTH; i++) {
			if (A_check[i] != B_check[i]) diffCnt++;
			if (A_check[i] == 1 && B_check[i] == 1) sameCnt++;
			if (A_check[i] == 1 || B_check[i] == 1) totalCnt++;

		}

		if (diffCnt == 0) return MAX_SCORE_STRING_ALPHA;
		if (sameCnt == 0) return MIN_SCORE_STRING_ALPHA;

		int score = MAX_SCORE_STRING_ALPHA * sameCnt / totalCnt;
		return score;

	}

	static const int MAX_SCORE_STRING_LENGTH = 60;
	static const int MIN_SCORE_STRING_LENGTH = 0;

	static const int MAX_SCORE_STRING_ALPHA = 40;
	static const int MIN_SCORE_STRING_ALPHA = 0;

private:
	bool isSameLength(int a, int b) {
		return (a == b);
	}
	bool isDoubleLength(int a, int b) {
		return (a >= b * 2 || b >= a * 2);
	}
	int getLongLength(int a, int b) {
		if (a > b) return a;
		else return b;
	}
	int getShortLength(int a, int b) {
		if (a > b) return b;
		else return a;
	}
	int calLengthScore(int a, int b) {
		double gap, ret;

		int long_length  = getLongLength(a,b);
		int short_length = getShortLength(a, b);

		gap = long_length - short_length;
		ret = (1 - gap / short_length) * MAX_SCORE_STRING_LENGTH;
		
		return (int)ret;
	}

	static const int ALPHABET_LENGTH = 26;
};