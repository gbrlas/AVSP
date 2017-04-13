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
	qint64 r;
	qint64 t;
};

#endif // TESTER_H
