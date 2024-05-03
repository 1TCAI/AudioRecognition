#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButtonStop->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonStart_clicked()
{
    ui->pushButtonStop->setEnabled(true);
    ui->pushButtonStart->setEnabled(false);
    //开始录音
    //创建录音设备对象
    m_audio.startRecord("D:\\1.pcm");
    // ffplay.exe -i .\1.pcm -f s16le -ar 48000 -ac 2
}

void Widget::on_pushButtonStop_clicked()
{

    //停止录音
    m_audio.stopRecord();
    ui->pushButtonStop->setEnabled(false);
    ui->pushButtonStart->setEnabled(true);
    //开始识别
    QString text = m_speech.speechIdentify("D:\\1.pcm");
    if(text != "")
    {
        ui->textEdit->setText(text);
        ///ui->pushButton->setText("按住说话");
    }
    else
        QMessageBox::warning(NULL,"错误提示","识别失败");
}
