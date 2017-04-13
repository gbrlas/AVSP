#include <QtCore/QCoreApplication>

#include <QFile>
#include <QDebug>

#include <cstdlib>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char lookup[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

    QFile f("test.txt");
    QFile out("result.txt");

    out.open(QFile::WriteOnly);

    f.open( QFile::ReadOnly );

    char original[500];
    char num[30];

    f.readLine(num, 30);

    int times = atoi(num);

    for (int i=1; i<=times;i++) {
        QString translation = "";
        qint64 len = f.readLine(original, 500);
        for (int x=0;x<len-1;x++) {
            if (original[x] == ' ') {
                translation.append(QChar::fromAscii(' '));
                continue;
            }

            QChar appender = QChar::fromAscii(lookup[original[x] - 'a']);
            translation.append(appender);
            qDebug() << appender;
        }

        QString cText = QString::fromAscii("Case #%1: %2");
        cText.append(QChar::fromAscii('\n'));
        cText = cText.arg(i).arg(translation);
        out.write(cText.toUtf8());
        qDebug() << cText;
    }

    out.close();
    f.close();

    //eturn a.exec();
    return 0;
}
