#ifndef SPECIFICTESTER_H
#define SPECIFICTESTER_H

#include "tester.h"

const int linesPerCase = 5;

class SpecificTester : public Tester
{
public:
	SpecificTester(const QStringList& lines);
	QString analyze() override;

	struct Pieces
	{
		Pieces() : o(0), x(0) {}

		int o;
		int x;
	};

private:
	enum Party
	{
		None,
		O,
		X
	};

	Pieces scanRow(int row);
	Pieces scanCol(int col);
	Pieces scanDiag1();
	Pieces scanDiag2();

	void checkForWinner(const Pieces& pieces);

	bool squaresLeft;
	char grid[4][4];
};

#endif // SPECIFICTESTER_H
