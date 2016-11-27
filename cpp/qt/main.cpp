

#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    qDebug() << "Testo";
    QPushButton w;
    // Notepad w;
    w.show();

    QObject::connect(w, &QPushButton::clicked, [&](bool pushed) {
        qDebug() << "Testo";
    });

    return a.exec();
}
