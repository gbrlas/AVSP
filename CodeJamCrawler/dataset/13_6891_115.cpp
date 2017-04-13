#ifndef SPECIFICTESTER_H
#define SPECIFICTESTER_H

#include <QStringList>
#include <QVector>

const int linesPerCase = 1;

class SpecificTester
{
public:
	SpecificTester(const QStringList& lines);
	QString analyze(const QVector<quint64>& candidates) const;

private:
	bool isFair(quint64 num) const;

	quint64 smallest;
	quint64 biggest;
};

#endif // SPECIFICTESTER_H
