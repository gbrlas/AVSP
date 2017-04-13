// Using a Debug build of Qt 5.0.2 (MSVC 2012 x64)

#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include "tester.h"

int getCaseCount(QFile &input)
{
	QString str(input.readLine());

	bool ok;
	int count = str.remove("\n").toInt(&ok);
	if (!ok)
		qFatal("Error getting case count");

	return count;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QFile input("../input.txt");
	QFile output("../output.txt");

	if ( input.open(QFile::ReadOnly|QFile::Text)
			&& output.open(QFile::WriteOnly|QFile::Text) )
	{
		int nCases = getCaseCount(input);
		for (int i = 0; i < nCases; ++i)
		{
			// Generate input
			QStringList lines;
			lines << QString(input.readLine()).remove("\n");

			qDebug() << "=== Analyzing Case" << i+1 << "===";
			Tester tester(lines);

			QString caseResult;
			if (i > 0)
				caseResult += '\n'; // Don't prepend newline for the first one

			caseResult += "Case #";
			caseResult += QString::number(i+1) + ": ";
			caseResult += tester.analyze();


			// Write output
			output.write(caseResult.toUtf8());
		}

		qDebug() << "=== Done ===";

		input.close();
		output.close();
	}
	else
	{
		qFatal("Could not open files");
	}

    return a.exec();
}
