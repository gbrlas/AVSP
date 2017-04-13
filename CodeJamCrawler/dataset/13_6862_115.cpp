#include "tester.h"
#include <QDebug>

//#include <QSet>

Tester::Tester(const QStringList& lines)
{
	QStringList dim = lines[0].split(" ");

	bool ok1, ok2;
	nRows = dim[0].toInt(&ok1);
	nCols = dim[1].toInt(&ok2);

	if (!ok1 || !ok2)
		qFatal("Input parse error");

	qDebug() << nRows << nCols;

//	QSet<int> heightSet;
	for (int row = 0; row < nRows; ++row)
	{
		QStringList heights = lines[row+1].split(" ");
		Q_ASSERT(heights.size() == nCols);
		QVector<int> heightStrip(nCols);

		for (int col = 0; col < nCols; ++col)
		{
			bool ok;
			int height = heights[col].toInt(&ok);
			Q_ASSERT(ok);

//			heightSet.insert(height);
			heightStrip[col] = height;
		}
		heightGrid << heightStrip;

		qDebug() << heightStrip;

//		QVector<bool> coverStrip(nCols, false);
//		coverGrid << coverStrip;
	}

//	sortedHeights = heightSet.toList().toVector();
//	qSort(sortedHeights);
}

QString Tester::analyze()
{
	for (int row = 0; row < nRows; ++row)
	{
		for (int col = 0; col < nCols; ++col)
		{
			bool clear_N = true;
			bool clear_S = true;
			bool clear_E = true;
			bool clear_W = true;

			int refHeight = heightGrid[row][col];
			for (int x = col-1; x >= 0; --x)
			{
				if (heightGrid[row][x] > refHeight)
				{
					clear_W = false;
					break;
				}
			}
			for (int x = col+1; x < nCols; ++x)
			{
				if (heightGrid[row][x] > refHeight)
				{
					clear_E = false;
					break;
				}
			}
			if ( !(clear_W && clear_E) )
			{
				for (int y = row-1; y >= 0; --y)
				{
					if (heightGrid[y][col] > refHeight)
					{
						clear_N = false;
						break;
					}
				}
				for (int y = row+1; y < nRows; ++y)
				{
					if (heightGrid[y][col] > refHeight)
					{
						clear_S = false;
						break;
					}
				}
			}

			if (  !( (clear_W && clear_E) || (clear_N && clear_S) )  )
			{
				qDebug() << row << col << clear_W << clear_E << clear_N << clear_S;
				return "NO";
			}

		}
	}

	return "YES";
}
