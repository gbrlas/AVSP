#include <QtCore/QCoreApplication>

#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QList>

#include <cstdlib>

struct ScoreSet {
    int total;
    int biggest;
    int middle;
    int smallest;

    int sum() {
        return biggest + middle + smallest;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile f("test.txt");
    QFile out("result.txt");

    out.open(QFile::WriteOnly);

    f.open( QFile::ReadOnly );

    QByteArray buffer;

    buffer = f.readLine(40);
    int inputs = QString(buffer).toInt();
    qDebug() << inputs;

    for (int i=1; i<=inputs;i++) {
        buffer = f.readLine(500);

        QString inputs(buffer);
        inputs.remove("\n");
        QStringList inputList = inputs.split(" ");
        qDebug() << inputList;

        int numberOfGooglers = inputList.at(0).toInt();
        int numberOfSurprises = inputList.at(1).toInt();
        int maxy = inputList.at(2).toInt();

        QList<ScoreSet*> scores;
        for (int i=3; i<inputList.length(); i++) {
            ScoreSet* s = new ScoreSet;
            s->total = inputList.at(i).toInt();

            scores.append(s);
        }

        foreach(ScoreSet* ss, scores) {
            int tot = ss->total;
            int div = tot / 3;
            ss->biggest = div;
            ss->middle = div;
            ss->smallest = div;
            if (ss->sum() != ss->total) {
                int diff = ss->total - ss->sum();
                if (diff > 0) {
                    if (diff > 1) {
                    ss->middle++;
                    ss->biggest++;
                    }
                    else {
                    ss->biggest ++;
                    }
                }
                else {
                    ss->smallest += diff;
                }
            }
            qDebug() << ss->biggest << ss->middle << ss->smallest << ss->total;
        }

        // find which scores have a max and remove them
        qDebug() << "Looking for" << maxy;
        qDebug() << "Already max";
        int numMaxs = 0;
        foreach(ScoreSet* ss, scores) {
            if (ss->biggest >= maxy) {
                numMaxs++;
                qDebug() << ss->biggest << ss->middle << ss->smallest << ss->total;
                int index = scores.indexOf(ss);
                qDebug() << "Removing index" << index;
                scores.removeAt(index);
            }
        }

        qDebug() << "Made Max";
        // find which scores can be made max until we run out of maxs
        foreach( ScoreSet* ss, scores) {
            if (numberOfSurprises == 0) {
                break;
            }

            ss->biggest = maxy;
            int diff = ss->total - ss->biggest;
            if (diff < 0) {
                continue;
            }

            ss->middle = (diff / 2) + (diff % 2);
            ss->smallest = (diff / 2);

            Q_ASSERT(ss->total == ss->sum());

            if (ss->biggest - ss->smallest <= 2) {
                numberOfSurprises--;
                numMaxs++;
                qDebug() << ss->biggest << ss->middle << ss->smallest << ss->total << "SURPRISE" << numberOfSurprises;
            }
        }

        qDebug() << "Number of maxs" << numMaxs;
        qDebug();


        QString cText = QString::fromAscii("Case #%1: %2");
        cText.append(QChar::fromAscii('\n'));
        cText = cText.arg(i).arg(numMaxs);
        out.write(cText.toUtf8());
        qDebug() << cText;
    }

    out.close();
    f.close();

    //eturn a.exec();
    return 0;
}
