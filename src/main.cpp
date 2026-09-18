#include "gui/mainwindow.h"

#include <QLabel>
#include <QLocale>
#include <QPixmap>
#include <QThread>
#include <QTranslator>
#include <QProgressBar>
#include <QApplication>
#include <QSplashScreen>

static void setupTranslations(QApplication &app)
{
    auto *translator = new QTranslator(&app);
    const QStringList uiLanguages = QLocale::system().uiLanguages();

    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "Tournament2000QT_" + QLocale(locale).name();

        if (translator->load(":/i18n/" + baseName))
        {
            app.installTranslator(translator);
            break;
        }
    }
}

static void showSplashScreen(QApplication &app, QWidget *nextWindow)
{
    QPixmap pixmap(":/Tournament2000.png");

    if (pixmap.isNull())
    {
        pixmap = QPixmap(500, 300);
        pixmap.fill(QColor(40, 44, 52));
    }

    QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint);

    splash.show();

    int margin = 20;
    int barHeight = 15;
    int labelHeight = 20;
    int spacing = 6;
    int width = pixmap.width() - (2 * margin);
    int barY = pixmap.height() - barHeight - margin;
    int labelY = barY - labelHeight - spacing;

    QLabel label(&splash);

    label.setGeometry(margin, labelY, width, labelHeight);
    label.setAlignment(Qt::AlignCenter);
    label.setStyleSheet("color: white; font-size: 16px;");
    label.show();

    QProgressBar progressBar(&splash);

    progressBar.setGeometry(margin, barY, width, barHeight);
    progressBar.setRange(0, 100);
    progressBar.setValue(0);
    progressBar.setTextVisible(false);
    progressBar.show();

    for (int i = 0; i <= 100; i += 2)
    {
        progressBar.setValue(i);
        label.setText(QString("Chargement des composants... %1%").arg(i));
        app.processEvents();
        QThread::msleep(50);
    }

    nextWindow->show();
    splash.finish(nextWindow);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setupTranslations(a);

    MainWindow w;

    showSplashScreen(a, &w);

    return (a.exec());
}
