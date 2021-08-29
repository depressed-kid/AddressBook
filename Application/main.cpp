#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "contactsmodel.h"

// нужно сделать как в iphone

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ContactsModel::registerMe("Contacts");

	const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.addImportPath(":/qml");
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
