#ifndef TESTER_H
#define TESTER_H

#include <QStringList>

class Tester
{
public:
	Tester() {}
	virtual ~Tester() {}
	virtual QString analyze() = 0;
};

#endif // TESTER_H
