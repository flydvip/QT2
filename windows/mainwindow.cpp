#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTime>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->pushButton->setText(tr("新窗口")); //将界面上按钮的显示文本更改为“新窗口”
    //ui->statusBar->showMessage(tr("欢迎访问Qt开源社区！"),3000);

//    QLabel *statusLabel=new QLabel;
//    statusLabel->setMinimumSize(150, 20); // 设置标签最小大小
//    statusLabel->setFrameShape(QFrame::WinPanel); // 设置标签形状
//    statusLabel->setFrameShadow(QFrame::Sunken); // 设置标签阴影
//    ui->statusBar->addWidget(statusLabel);
//    statusLabel->setText(tr("欢迎访问Qt开源社区！"));

    QLabel *permanent = new QLabel;
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText(
      tr("<a href=\"http://www.baidu.com\">baidu.com</a>"));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);

    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(10000);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
   ui->pushButton_3->setText(tr("(%1, %2)").arg(e->x()).arg(e->y()));
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
   int x = ui->pushButton_2->x();
   int y = ui->pushButton_2->y();
   switch (e->key())
   {
   case Qt::Key_W : ui->pushButton_2->move(x, y-10); break;
   case Qt::Key_S : ui->pushButton_2->move(x, y+10); break;
   case Qt::Key_A : ui->pushButton_2->move(x-10, y); break;
   case Qt::Key_D : ui->pushButton_2->move(x+10, y); break;
   }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
   if (event->timerId() == id1) { // 判断是哪个定时器
       ui->label->setText(tr("%1").arg(qrand()%10));
   }

   else if (event->timerId() == id2) {
       ui->label_2->setText(tr("hello world!"));
   }

   else {
       qApp->quit();
   }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //QPainter painter(this);
    //painter.drawLine(QPointF(0, 0), QPointF(100, 100));
//    QPainter painter(this);
//    QPen pen; //画笔
//    pen.setColor(QColor(255, 0, 0));
//    QBrush brush(QColor(0, 255, 0, 125)); //画刷
//    painter.setPen(pen); //添加画笔
//    painter.setBrush(brush); //添加画刷
//    painter.drawRect(50, 50, 200, 100); //绘制矩形

    QPainter painter(this);
    QPixmap pix;
    pix.load("../windows/t1.png");
    qreal width = pix.width();
    qreal height = pix.height();
    //将图片的宽和高都缩小，并且在给定的矩形内保持宽高的比值不变
    pix = pix.scaled(width*0.2, height*0.2,
                     Qt::KeepAspectRatio);
    painter.translate(100, 100);
    painter.drawPixmap(0, 0, 80, 100, pix);
}
