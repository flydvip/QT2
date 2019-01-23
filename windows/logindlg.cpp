#include "logindlg.h"
#include "ui_logindlg.h"


LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_pushButton_clicked()
{
//    //QDialog *dlg = new QDialog(this);
//    //dlg->show();
//    QMessageBox::warning(this, tr("警告！"),
//                       tr("用户名或密码错误！"),
//                       QMessageBox::Yes);
}
