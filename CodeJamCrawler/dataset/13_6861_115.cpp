#ifndef TESTER_H
#define TESTER_H

#include <QStringList>
#include <QVector>

class Tester
{
public:
	Tester(const QStringList& lines);
	QString analyze();

private:

	int nRows;
	int nCols;

	QVector<QVector<int>> heightGrid;
//	QVector<QVector<bool>> coverGrid;
//	QVector<int> sortedHeights;
};

#endif // TESTER_H
