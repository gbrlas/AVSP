#include "tester.h"
#include <QDebug>

#include <qmath.h>

Tester::Tester(const QStringList& lines)
{
	QStringList list = lines[0].split(" ");

	bool ok1, ok2;
	r = list[0].toLongLong(&ok1);
	t = list[1].toLongLong(&ok2);

	if (!ok1 || !ok2)
		qFatal("Input parse error");
}

QString Tester::analyze()
{
	qDebug () << "r =" << r;
	qDebug () << "t =" << t;

	qint64 n = 0;
	while (t >= 0)
	{
		++n;
		t -= (2*r-3+4*n);
	}

	return QString::number(n-1);
}
