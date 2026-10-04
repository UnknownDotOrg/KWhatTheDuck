#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label(QStringLiteral("WHAT THE DUCK"));
    label.setAlignment(Qt::AlignCenter);
    label.setMinimumSize(500, 300);
    label.setWindowTitle(QStringLiteral("KWhatTheDuck"));

    label.show();

    return app.exec();
}
