#include <QCoreApplication>

#include <QFile>
#include "specifictester.h"
#include <QDebug>

bool isFair(quint64 num)
{
	QByteArray str = QByteArray::number(num);
	QByteArray rev = str;
	std::reverse(rev.begin(), rev.end());

	return str == rev;
}

int getCaseCount(QFile &input)
{
	bool ok;

	QString str(input.readLine());

	int count = str.remove("\n").toInt(&ok);

	if (!ok)
		qDebug("Error getting case count");

	return count;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QFile input("input.txt");
	QFile output("output.txt");

	if ( input.open(QFile::ReadOnly|QFile::Text)
			&& output.open(QFile::WriteOnly|QFile::Text) )
	{
		QVector<quint64> candidates;
		for (quint64 i = 1; i <= 10000000; ++i)
		{
			if (isFair(i) && isFair(i*i))
				candidates << i*i;
		}
		qDebug() << candidates;

		int nCases = getCaseCount(input);
		for (int i = 0; i < nCases; ++i)
		{
			QStringList lines;

			for (int j = 0; j < linesPerCase; ++j)
				lines << QString(input.readLine()).remove("\n");

			qDebug() << "=== Analyzing Case" << i+1 << "===";

			SpecificTester tester(lines);

			QString caseResult;

			// Don't prepend newline for the first one
			if (i > 0)
				caseResult += '\n';

			caseResult += "Case #";
			caseResult += QString::number(i+1) + ": ";
			caseResult += tester.analyze(candidates);

			output.write(caseResult.toUtf8());
		}

		input.close();
		output.close();
	}
	else
	{
		qDebug("Could not open files");
	}

    return a.exec();
}
