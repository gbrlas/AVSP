#include "specifictester.h"
#include <QDebug>

SpecificTester::SpecificTester(const QStringList& lines)
	: squaresLeft(false)
{
	for (int row = 0; row < 4; ++row)
	{
		qDebug() << lines[row];
		for (int col = 0; col < 4; ++col)
		{
			grid[row][col] = lines[row][col].toLatin1();
		}
	}
}

QString SpecificTester::analyze()
{
	// Search for winners
	for (int row = 0; row < 4; ++row)
	{
		Pieces pieces = scanRow(row);

		if (pieces.o > 4 || pieces.x > 4)
		{
			qDebug("Counting error");
			return QString();
		}
		else if (pieces.o == 4)
			return "O won";
		else if (pieces.x == 4)
			return "X won";
	}

	for (int col = 0; col < 4; ++col)
	{
		Pieces pieces = scanCol(col);

		if (pieces.o > 4 || pieces.x > 4)
		{
			qDebug("Counting error");
			return QString();
		}
		else if (pieces.o == 4)
			return "O won";
		else if (pieces.x == 4)
			return "X won";
	}

	Pieces pieces = scanDiag1();
	if (pieces.o > 4 || pieces.x > 4)
	{
		qDebug("Counting error");
		return QString();
	}
	else if (pieces.o == 4)
		return "O won";
	else if (pieces.x == 4)
		return "X won";

	pieces = scanDiag2();
	if (pieces.o > 4 || pieces.x > 4)
	{
		qDebug("Counting error");
		return QString();
	}
	else if (pieces.o == 4)
		return "O won";
	else if (pieces.x == 4)
		return "X won";


	// Nobody won
	if (squaresLeft)
		return "Game has not completed";
	else
		return "Draw";
}

SpecificTester::Pieces SpecificTester::scanRow(int row)
{
	Pieces pieces;
	for (int col = 0; col < 4; ++col)
	{
		switch(grid[row][col])
		{
		case 'O':
			pieces.o++;
			break;

		case 'X':
			pieces.x++;
			break;

		case 'T':
			pieces.o++;
			pieces.x++;
			break;

		case '.':
			squaresLeft = true;
			break;

		default:
			qDebug() << "Illegal character:" << grid[row][col];
		}
	}

	return pieces;
}


SpecificTester::Pieces SpecificTester::scanCol(int col)
{
	Pieces pieces;
	for (int row = 0; row < 4; ++row)
	{
		switch(grid[row][col])
		{
		case 'O':
			pieces.o++;
			break;

		case 'X':
			pieces.x++;
			break;

		case 'T':
			pieces.o++;
			pieces.x++;
			break;

		case '.':
			squaresLeft = true;
			break;

		default:
			qDebug() << "Illegal character:" << grid[row][col];
		}
	}

	return pieces;
}

SpecificTester::Pieces SpecificTester::scanDiag1()
{
	Pieces pieces;
	for (int row = 0; row < 4; ++row)
	{
		switch(grid[row][row])
		{
		case 'O':
			pieces.o++;
			break;

		case 'X':
			pieces.x++;
			break;

		case 'T':
			pieces.o++;
			pieces.x++;
			break;

		case '.':
			squaresLeft = true;
			break;

		default:
			qDebug() << "Illegal character:" << grid[row][row];
		}
	}

	return pieces;
}

SpecificTester::Pieces SpecificTester::scanDiag2()
{
	Pieces pieces;
	for (int row = 0; row < 4; ++row)
	{
		switch(grid[row][3-row])
		{
		case 'O':
			pieces.o++;
			break;

		case 'X':
			pieces.x++;
			break;

		case 'T':
			pieces.o++;
			pieces.x++;
			break;

		case '.':
			squaresLeft = true;
			break;

		default:
			qDebug() << "Illegal character:" << grid[row][3-row];
		}
	}

	return pieces;
}
