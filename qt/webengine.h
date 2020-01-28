#ifndef WEBENGINE_H
#define WEBENGINE_H

#include <QWebEngineView>

class WebEngine : public QWebEngineView
{
public:
    WebEngine(QWidget *parent = nullptr);
};

#endif // WEBENGINE_H
