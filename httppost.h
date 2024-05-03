#ifndef HTTPPOST_H
#define HTTPPOST_H

#include <QObject>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
class httppost : public QObject
{
    Q_OBJECT
public:
    explicit httppost(QObject *parent = nullptr);
    bool postSyn(QString url, QMap<QString, QString> headerdata, QByteArray requestData, QByteArray &replydata);
signals:

public slots:
};

#endif // HTTPPOST_H
