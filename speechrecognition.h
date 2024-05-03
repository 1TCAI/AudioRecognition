#ifndef SPEECHRECOGNITION_H
#define SPEECHRECOGNITION_H

#include <QObject>
#include "httppost.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QHostInfo>
#include <QFile>
#include <QMessageBox>
#include <QIODevice>


//获取access_token相关
const QString baiduTokenUrl = "https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=%1&client_secret=%2&";
const QString client_id = "UpqgRgb6ugYnhv0E1I2O9MB0";
const QString client_secret = "gG0jHKso0n6wTWMwVtYxbz6fFFKPhaRm";

//语音识别相关
//普通话测试
const QString baiduSpeechurl = "http://vop.baidu.com/server_api?dev_pid=1537&cuid=%1&token=%2";



class speechRecognition : public QObject
{
    Q_OBJECT
public:
    explicit speechRecognition(QObject *parent = nullptr);
    QString speechIdentify(QString filename);  //开始识别

    QString getJsonvalue(QByteArray ba,QString key);
signals:

public slots:
private:
    QString  accessToken;
};

#endif // SPEECHRECOGNITION_H
