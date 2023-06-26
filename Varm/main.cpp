#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    qmlRegisterSingletonType(QUrl("qrc:/Constants/uischeme.qml"), "UiSchemes", 1, 0, "UiSchemes");
    qmlRegisterSingletonType(QUrl("qrc:/Constants/colorscheme.qml"), "ColorSchemes", 1, 0, "ColorSchemes");


    return app.exec();
}
