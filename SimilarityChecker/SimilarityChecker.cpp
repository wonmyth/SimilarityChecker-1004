#include <string>
#include <stdexcept>

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

	static const int MAX_SCORE_STRING_LENGTH = 60;
	static const int MIN_SCORE_STRING_LENGTH = 0;

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
};