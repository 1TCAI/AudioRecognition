#include "audiocapture.h"

AudioCapture::AudioCapture(QObject *parent) : QObject(parent)
{

}

void AudioCapture::startRecord(QString filename)
{
    // 判断本地设备是否支持该格式
    // 打开默认的音频输入设备
    QAudioDeviceInfo audioDeviceInfo = QAudioDeviceInfo::defaultInputDevice();
    // 判断本地是否有录音设备;
    if (!audioDeviceInfo.isNull())
    {
        ///Qt中级：内存管理机制，对象管理机制、
        m_file = new QFile;
        m_file->setFileName(filename);
        m_file->open(QIODevice::WriteOnly | QIODevice::Truncate);

        // 设置音频文件格式;
        QAudioFormat format;
        // 设置采样频率;
        format.setSampleRate(48000);
        // 设置通道数;
        format.setChannelCount(2);
        // 设置每次采样得到的样本数据位值;
        format.setSampleSize(16);
        // 设置编码方法;
        format.setCodec("audio/pcm");
        // 设置采样字节存储顺序;
        //format.setByteOrder(QAudioFormat::LittleEndian);
        // 设置采样类型;
        //format.setSampleType(QAudioFormat::UnSignedInt);

        // 判断当前设备设置是否支持该音频格式(重点);
        if (!audioDeviceInfo.isFormatSupported(format))
        {
            format = audioDeviceInfo.nearestFormat(format);
         }
        // 创建录音对象;
        m_audioInput = new QAudioInput(format, this);
        //开始录音
        m_audioInput->start(m_file);
    }
    else
    {
        // 没有录音设备;
        QMessageBox::information(NULL, tr("Record"), tr("Current No Record Device"));
    }
}

void AudioCapture::stopRecord()
{
    //停止录音
    m_audioInput->stop();
    //关闭文件
    m_file->close();
    //删除文件对象，所以需要手工删除：
    delete m_file;     //删除只是删除了指针指向的内存空间，没有删除指针，需要将指针指为NULL
    m_file = nullptr;  // 防止悬浮指针（野指针）

}
AudioCapture::~AudioCapture()
{
    delete m_audioInput;
    delete m_file;
}
