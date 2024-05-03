#ifndef AUDIOCAPTURE_H
#define AUDIOCAPTURE_H

#include <QObject>
#include <QAudioInput>
#include <QFile>
#include <QAudioDeviceInfo>
#include <QMessageBox>
class AudioCapture : public QObject
{
    Q_OBJECT
public:
    explicit AudioCapture(QObject *parent = nullptr);

    void startRecord(QString filename);   //开始录音
    void stopRecord();                    //停止录音
    ~AudioCapture();

signals:

public slots:

private:
    QAudioInput *m_audioInput = nullptr;           //录音对象
    QFile       *m_file = nullptr;                 //存储的文件路径
};

#endif // AUDIOCAPTURE_H
