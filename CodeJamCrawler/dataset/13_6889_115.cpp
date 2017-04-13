#include "specifictester.h"
#include <QDebug>

SpecificTester::SpecificTester(const QStringList& lines)
{
	QStringList bounds = lines[0].split(" ");

	bool ok1, ok2;
	smallest = bounds[0].toLongLong(&ok1);
	biggest = bounds[1].toLongLong(&ok2);

	if (!ok1 || !ok2)
		qDebug("Input parse error");
}

QString SpecificTester::analyze(const QVector<quint64>& candidates) const
{

	QVector<quint64> local = candidates;

	while (!local.isEmpty() && local.last() > biggest)
		local.pop_back();

	while (!local.isEmpty() && local.first() < smallest)
		local.pop_front();

	return QString::number(local.size());
}
