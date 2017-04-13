#include <QCoreApplication>

#include <QFile>
#include "specifictester.h"
#include <QDebug>

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
		int nCases = getCaseCount(input);
		for (int i = 0; i < nCases; ++i)
		{
			QStringList lines;

			for (int j = 0; j < linesPerCase; ++j)
				lines << QString(input.readLine()).remove("\n");

			qDebug() << "=== Analyzing Case" << i+1 << "===";

			Tester* tester = new SpecificTester(lines);

			QString caseResult = "Case #";
			caseResult += QString::number(i+1) + ": ";
			caseResult += tester->analyze();
			caseResult += '\n';

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
