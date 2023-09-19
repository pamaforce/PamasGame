#include "mainwindow.h"
#include "namedialog.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include <QDir>
#include <ctime>
#include <QFile>
#include <QTime>
#include <QDebug>
#include <QEvent>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <Qpixmap>
#include <windows.h>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QPushButton>
#include <QTableWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QAbstractSlider>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,600);
    //初始设置
    name="";
    memset(foot,0,sizeof(foot));
    memset(hour,0,sizeof(hour));
    memset(map2,0,sizeof(map2));
    foot[0][0]=1;QString path0 = QDir::currentPath();
    setFocusPolicy(Qt::StrongFocus);
    for(int i=1;i<=20;i++)
    {
        foot[i][0]=2000;
        hour[i][0]=2000;
    }
    ui->stackedWidget->setCurrentIndex(0);pages[0]=ui->choosepage;
    pages[1]=ui->levelpage1;pages[2]=ui->levelpage2;pages[3]=ui->levelpage3;pages[4]=ui->levelpage4;
    pages[5]=ui->levelpage5;pages[6]=ui->levelpage6;pages[7]=ui->levelpage7;pages[8]=ui->levelpage8;
    pages[9]=ui->levelpage9;pages[10]=ui->levelpage10;pages[11]=ui->levelpage11;pages[12]=ui->levelpage12;
    pages[13]=ui->levelpage13;pages[14]=ui->levelpage14;pages[15]=ui->levelpage15;pages[16]=ui->levelpage16;
    pages[17]=ui->levelpage17;pages[18]=ui->levelpage18;pages[19]=ui->levelpage19;pages[20]=ui->levelpage20;
    pages[21]=ui->widget_21;
    widgets[1]=ui->widget_1;widgets[2]=ui->widget_2;widgets[3]=ui->widget_3;widgets[4]=ui->widget_4;widgets[5]=ui->widget_5;
    widgets[6]=ui->widget_6;widgets[7]=ui->widget_7;widgets[8]=ui->widget_8;widgets[9]=ui->widget_9;widgets[10]=ui->widget_10;
    widgets[11]=ui->widget_11;widgets[12]=ui->widget_12;widgets[13]=ui->widget_13;widgets[14]=ui->widget_14;widgets[15]=ui->widget_15;
    widgets[16]=ui->widget_16;widgets[17]=ui->widget_17;widgets[18]=ui->widget_18;widgets[19]=ui->widget_19;widgets[20]=ui->widget_20;    
    //结局  美好
    ui->label->setPixmap(QPixmap(":/res/pic/View.jpg"));
    ui->label_0->setPixmap(QPixmap(":/res/pic/View.jpg"));
    ui->label_00->setPixmap(QPixmap(":/res/pic/View.jpg"));
    MyPushButton * Le = new MyPushButton(":/res/pic/letter.png");
    Le->setParent(ui->lastpage0);
    Le->setGeometry(325,80,Le->width(),Le->height());
    connect(Le,&MyPushButton::clicked,[=](){
        if(Tflag == true) T2->play();
        QTimer * Ler = new QTimer(this);
        Ler->start(300);
        Le->btnup();
        Le->btndown();
        connect(Ler,QTimer::timeout,[=](){
            ui->stackedWidget->setCurrentIndex(23);
            Ler->stop();
        });
    });
    MyPushButton * Ne0 = new MyPushButton(":res/pic/Love.png");
    Ne0->setParent(ui->lastpagemore);
    Ne0->move(850,450);
    connect(Ne0,&MyPushButton::clicked,[=](){
        QTimer * btntimer0 = new QTimer(this);
        btntimer0->start(300);
        Ne0->btnup();
        Ne0->btndown();
        connect(btntimer0,QTimer::timeout,[=](){
            ui->stackedWidget->setCurrentIndex(0);
            btntimer0->stop();
        });
    });
    MyPushButton * Ne = new MyPushButton(":res/pic/Heart.png");
    Ne->setParent(ui->lastpage);
    Ne->move(900,560);
    connect(Ne,&MyPushButton::clicked,[=](){
        QTimer * btntimer = new QTimer(this);
        btntimer->start(300);
        Ne->btnup();
        Ne->btndown();
        connect(btntimer,QTimer::timeout,[=](){
            ui->stackedWidget->setCurrentIndex(24);
            btntimer->stop();
        });
    });
    //
    //背景设置
    QLabel * startback = new QLabel(ui->startpage);
    startback->setGeometry(0,0,1000,600);
    startback->setPixmap(QPixmap(":/res/pic/main.jpg"));
    QLabel * chooseback = new QLabel(ui->choosepage);
    chooseback->setGeometry(0,0,1000,600);
    chooseback->setPixmap(QPixmap(":/res/pic/chp.jpg"));
    //
    //主窗口设置
    setWindowIcon(QIcon(":/res/pic/Rocket.png"));
    setWindowTitle("Pama'sGame");
    //
    //音效T1设置
    T1->setParent(this);
    T1->setMedia(QUrl("qrc:/res/mus/T1.wav"));
    T1->setVolume(100);
    //
    //音效T2设置
    T2->setParent(this);
    T2->setMedia(QUrl("qrc:/res/mus/T2.wav"));
    T2->setVolume(100);
    //
    //音效T3设置
    T3->setParent(this);
    T3->setMedia(QUrl("qrc:/res/mus/T3.wav"));
    T3->setVolume(100);
    //
    //音效T4设置
    T4->setParent(this);
    T4->setMedia(QUrl("qrc:/res/mus/T4.wav"));
    T4->setVolume(100);
    //
    //音效T5设置
    T5->setParent(this);
    T5->setMedia(QUrl("qrc:/res/mus/T5.wav"));
    T5->setVolume(100);
    //
    //音效胜利设置
    Victory->setParent(this);
    Victory->setMedia(QUrl("qrc:/res/mus/Victory.mp3"));
    Victory->setVolume(100);
    //
    //帮助
    MyPushButton * help = new MyPushButton(":/res/pic/book.png");
    help->setParent(ui->startpage);
    help->move(30,210);
    connect(help,&MyPushButton::clicked,[=](){
        if(Tflag == true) T2->play();
        QTimer * bbabtntimer = new QTimer(this);
        bbabtntimer->start(300);
        help->btnup();
        help->btndown();
        QDialog * helps = new QDialog(this);
        helps->setAttribute(Qt::WA_DeleteOnClose);
        helps->setFixedSize(500,600);
        helps->setWindowTitle("Pama'sGame 帮助");
        QLabel * hh0 = new QLabel(helps);
        hh0->setGeometry(0,0,500,600);
        hh0->setPixmap(QPixmap(":/res/pic/sky.jpg"));
        hh0->setScaledContents(true);
        QLabel * hh1 = new QLabel(helps);
        hh1->setGeometry(0,0,500,600);
        hh1->setText("操作指南\n\n"
                     "用W/S/A/D键控制上/下/左/右\n"
                     "或↑/↓/←/→键控制上/下/左/右\n"
                     "B:返回 R:重开 Ctrl+Z:撤回 \n\n\n"
                     "游戏玩法\n\n"
                     "本游戏玩法与经典游戏\n“推箱子”一致\n"
                     "关卡设计也基本相同\n"
                     "故具体玩法可参考原游戏\n谢谢您的理解\n"
                     "祝您游戏愉快！\n\n"
                     "作者联系方式:QQ 1327374483");
        hh1->setAlignment(Qt::AlignHCenter);
        hh1->setStyleSheet("QLabel{color:rgb(255,0,127);}");
        hh1->setFont(QFont("华文琥珀",20));
        connect(bbabtntimer,QTimer::timeout,[=](){
            helps->show();
            bbabtntimer->stop();
        });
    });
    //
    //文件操作
    QFile f1(QString(path0+"/mydata/Fo.txt"));
    if(f1.open(QIODevice::ReadOnly)==true)
    {
        int li=0;
        while(f1.atEnd()==false)
        {
            QByteArray Foo = f1.readLine();
            QString xx= QString(Foo);
            int mm=xx.toInt();
            li++;
            if(li==21) li=0;
            foot[li][0]=mm;
        }
        f1.close();
    }
    int tr=foot[0][0];
    connect(this,&MainWindow::destroyed,[=](){
        QFile f2(QString(path0+"/mydata/Fo.txt"));
        if(f2.open(QIODevice::WriteOnly)==true)
        {
            for(int i=1;i<=20;i++)
            {
                QString xx=QString::number(foot[i][0]);
                f2.write(xx.toUtf8());
                f2.write("\r\n");
            }
            if(tr<foot[0][0])
            {
                QString xx=QString::number(foot[0][0]);
                f2.write(xx.toUtf8());
                f2.write("\r\n");
            }
            else
            {
                QString xx=QString::number(tr);
                f2.write(xx.toUtf8());
                f2.write("\r\n");
            }
            f2.close();
        }
    });
    QFile h1(QString(path0+"/mydata/Ho.txt"));
    if(h1.open(QIODevice::ReadOnly)==true)
    {
        int li=0;
        while(h1.atEnd()==false)
        {
            QByteArray Foo = h1.readLine();
            QString xx= QString(Foo);
            double mm=xx.toDouble();
            li++;
            hour[li][0]=mm;
        }
        h1.close();
    }
    connect(this,&MainWindow::destroyed,[=](){
        QFile h2(QString(path0+"/mydata/Ho.txt"));
        if(h2.open(QIODevice::WriteOnly)==true)
        {
            for(int i=1;i<=20;i++)
            {
                QString xx=QString::number(hour[i][0]);
                h2.write(xx.toUtf8());
                h2.write("\r\n");
            }
            h2.close();
        }
    });
    QFile n1(QString(path0+"/mydata/Na.txt"));
    if(n1.open(QIODevice::ReadOnly)==true)
    {
        QByteArray nana =n1.readLine();
        name=QString(nana);
    }
    connect(this,&MainWindow::destroyed,[=](){
        QFile n2(QString(path0+"/mydata/Na.txt"));
        if(n2.open(QIODevice::WriteOnly)==true)
        {
            n2.write(name.toUtf8());
            n2.write("\r\n");
        }
    });
    //
    //主界面设置 欢迎
    QLabel * welcome = new QLabel(ui->startpage);
    welcome->setText("欢迎来到 Pama'sGame ！");
    welcome->setFont(QFont("阿里汉仪智能黑体",24));
    welcome->setGeometry(20,0,500,70);
    welcome->setStyleSheet("QLabel{color:rgb(127,0,255);}");
    welcome0->setParent(ui->startpage);
    if(name=="")
        welcome0->setText(QString("你好!"));
    else
        welcome0->setText(QString("你好！%1").arg(name));
    welcome0->setFont(QFont("阿里汉仪智能黑体",24));
    welcome0->setGeometry(20,90,500,100);
    welcome0->setStyleSheet("QLabel{color:rgb(127,0,255);}");
    //
    //成就设置
    MyPushButton * phrasebutton = new MyPushButton(":/res/pic/pr.png");
    phrasebutton->setParent(ui->startpage);
    phrasebutton->setGeometry(50,this->height()*0.75,phrasebutton->width(),phrasebutton->height());
    connect(phrasebutton,&MyPushButton::clicked,[=](){
        if(name=="")
        {
        NameDialog *d=new NameDialog;
        connect(d,&NameDialog::senddata,this,&MainWindow::receivedata);
        d->show();d->exec();
        }
        if(Tflag == true) T2->play();
        QTimer * prbtntimer = new QTimer(this);
        prbtntimer->start(300);
        phrasebutton->btnup();
        phrasebutton->btndown();
        QDialog * phra = new QDialog(this);
        phra->setFixedSize(400,880);
        phra->setWindowTitle(QString("Pama'sGame 成就墙"));
        phra->setAttribute(Qt::WA_DeleteOnClose);
        QLabel * phra0 =new QLabel(phra);
        phra0->setGeometry(0,0,400,880);
        phra0->setPixmap(QPixmap(":/res/pic/backph.jpg"));
        phra0->setScaledContents(true);
        QLabel * h1 = new QLabel(phra);
        h1->setGeometry(125,60,130,30);
        h1->setText("最少步数");
        h1->setFont(QFont("华文新魏",20));
        h1->setStyleSheet("QLabel{color:rgb(127,40,255);}");
        QLabel * h2 = new QLabel(phra);
        h2->setGeometry(255,60,130,30);
        h2->setText("最短时间");
        h2->setFont(QFont("华文新魏",20));
        h2->setStyleSheet("QLabel{color:rgb(127,40,255);}");
        QLabel * namelabel = new QLabel(phra);
        namelabel->setGeometry(0,2,360,58);
        namelabel->setAlignment(Qt::AlignHCenter);
        namelabel->setText(name);
        namelabel->setFont(QFont("华文新魏",40));
        namelabel->setStyleSheet("QLabel{color:rgb(0,80,255);}");
        MyPushButton * changename = new MyPushButton(":/res/pic/change.png");
        changename->setParent(phra);
        changename->move(365,30);
        connect(changename,&MyPushButton::clicked,[=](){
            NameDialog *d=new NameDialog;
            d->setAttribute(Qt::WA_DeleteOnClose);
            connect(d,&NameDialog::senddata,this,&MainWindow::receivedata);
            connect(d,&NameDialog::destroyed,[=](){
                phra->close();
                bool fff = Tflag;
                Tflag=false;phrasebutton->click();
                Tflag=fff;
            });
            d->show();d->exec();

        });
        for(int i = 1 ; i <= 20 ; i++ )
        {
            QLabel * l = new QLabel(phra);
            l->setGeometry(20,56+i*37,98,37);
            if(i<=9||i==11)
            l->setText(QString("第 %1 关:").arg(i));
            else
            l->setText(QString("第 %1关:").arg(i));
            l->setFont(QFont("阿里汉仪智能黑体",15));
            l->setStyleSheet("QLabel{color:rgb(255,40,255);}");
            QTableWidgetItem * item0 = new  QTableWidgetItem(QString("    %1").arg(foot[i][0]));
            if(foot[i][0]==2000)    *item0 =QTableWidgetItem(QString(" 暂无数据"));
            QTableWidgetItem * item00 = new  QTableWidgetItem(QString(" %1").arg(hour[i][0]));
            if(hour[i][0]==2000)    *item00 =QTableWidgetItem(QString(" 暂无数据"));
            ui->tableWidget->setItem(i-1,0,item0);
            ui->tableWidget->setItem(i-1,1,item00);
            ui->tableWidget->item(i-1,0)->setFont(QFont("Comic Sans MS",15,QFont::Bold));
            ui->tableWidget->item(i-1,1)->setFont(QFont("Comic Sans MS",15,QFont::Bold));
        }
        int total1=0;double total2=0;
        for(int i = 1 ; i <= 20 ; i++ )
        {
            total1+=foot[i][0];
            total2+=hour[i][0];
        }
        QLabel * l0 = new QLabel(phra);
        l0->setGeometry(20,833,98,37);
        l0->setText(QString(" 总 计 :"));
        l0->setFont(QFont("阿里汉仪智能黑体",15));
        l0->setStyleSheet("QLabel{color:rgb(255,40,255);}");
        QTableWidgetItem * item000 = new  QTableWidgetItem(QString("   %1").arg(total1));
        if(total1==40000)    *item000 =QTableWidgetItem(QString(" 暂无数据"));
        QTableWidgetItem * item0000 = new  QTableWidgetItem(QString(" %1").arg(total2));
        if(total2==40000)    *item0000 =QTableWidgetItem(QString(" 暂无数据"));
        ui->tableWidget->setItem(20,0,item000);
        ui->tableWidget->setItem(20,1,item0000);
        ui->tableWidget->item(20,0)->setFont(QFont("Comic Sans MS",15,QFont::Bold));
        ui->tableWidget->item(20,1)->setFont(QFont("Comic Sans MS",15,QFont::Bold));
        QGraphicsOpacityEffect * wow = new QGraphicsOpacityEffect;
        ui->tableWidget->setParent(phra);
        wow->setOpacity(0.4);
        ui->tableWidget->setGraphicsEffect(wow);
        ui->tableWidget->move(130,90);
        connect(phra,&QDialog::rejected,[=](){
            ui->tableWidget->setParent(ui->page);
           this->show();
        });
        connect(prbtntimer,QTimer::timeout,[=](){
            phra->show();
            prbtntimer->stop();
        });
    });
    //
    //设置音乐播放器及播放列表
    QMediaPlayer * backm = new QMediaPlayer(this);
    QMediaPlaylist * backmlist = new QMediaPlaylist(this);
    backmlist->addMedia(QUrl("qrc:/res/mus/M1.mp3"));
    backmlist->addMedia(QUrl("qrc:/res/mus/M2.mp3"));
    backmlist->addMedia(QUrl("qrc:/res/mus/M3.mp3"));
    backmlist->addMedia(QUrl("qrc:/res/mus/M4.mp3"));
    backmlist->addMedia(QUrl("qrc:/res/mus/M5.mp3"));
    backmlist->setPlaybackMode(QMediaPlaylist::Loop);
    backm->setPlaylist(backmlist);
    backm->setVolume(80);
    if(Mflag == true)   backm->play();
    MyPushButton * musicbutton = new MyPushButton(":/res/pic/mu.png");
    musicbutton->setParent(ui->startpage);
    musicbutton->setGeometry(950-musicbutton->width(),this->height()*0.75,musicbutton->width(),musicbutton->height());
    connect(musicbutton,&MyPushButton::clicked,[=](){
        if(Tflag == true) T2->play();
        QTimer * mubtntimer = new QTimer(this);
        mubtntimer->start(300);
        musicbutton->btnup();
        musicbutton->btndown();
        //声音设置窗口布局及功能设置
        QDialog * Mu = new QDialog(this);
        Mu->setFixedSize(400,300);
        QLabel * Mub = new QLabel(Mu);
        Mub->setFixedSize(400,300);
        //Mub->setText("00000000000");
        Mub->setPixmap(QPixmap(":/res/pic/mup.jpg"));
        Mu->setAttribute(Qt::WA_DeleteOnClose);
        Mu->setWindowTitle("Pama'sGame 声音设置");
        QLabel * Mu1 = new QLabel(Mu);
        Mu1->setText("声音开关:");
        Mu1->setGeometry(50,25,100,40);
        QLabel * Mu2 = new QLabel(Mu);
        Mu2->setText("音量设置:");
        Mu2->setGeometry(50,150,100,40);
        QLabel * Mu3 = new QLabel(Mu);
        Mu3->setText("音乐:");
        Mu3->setGeometry(70,190,75,40);
        QLabel * Mu4 = new QLabel(Mu);
        Mu4->setText("音效:");
        Mu4->setGeometry(70,230,75,40);
        QPushButton * P1 = new QPushButton(Mu);
        P1->setGeometry(70,75,90,60);
        P1->setStyleSheet("QPushButton{color:rgb(255,0,127);}");
        if(Mflag == true) P1->setText("音乐: 开");
        else P1->setText("音乐: 关");
        QPushButton * P2 = new QPushButton(Mu);
        P2->setGeometry(160,75,50,30);
        P2->setStyleSheet("QPushButton{color:rgb(127,0,255);}");
        P2->setText("上一首");
        QPushButton * P3 = new QPushButton(Mu);
        P3->setGeometry(160,105,50,30);
        P3->setStyleSheet("QPushButton{color:rgb(127,0,255);}");
        P3->setText("下一首");
        QPushButton * P4 = new QPushButton(Mu);
        P4->setGeometry(250,75,90,60);
        P4->setStyleSheet("QPushButton{color:rgb(255,0,127);}");
        if(Tflag == true) P4->setText("音效: 开");
        else P4->setText("音效: 关");
        QSlider * Ms = new QSlider(Qt::Horizontal,Mu);
        Ms->setGeometry(155,198,180,25);Ms->setValue(backm->volume());
        QSlider * Ts = new QSlider(Qt::Horizontal,Mu);
        Ts->setGeometry(155,238,180,25);Ts->setValue(T1->volume());
        connect(Ms,&QSlider::valueChanged,[=](){
            backm->setVolume(Ms->value());
        });
        connect(Ts,&QSlider::valueChanged,[=](){
            T1->setVolume(Ts->value());
            T2->setVolume(Ts->value());
            T3->setVolume(Ts->value());
            T4->setVolume(Ts->value());
            T5->setVolume(Ts->value());
            Victory->setVolume(Ts->value());
        });
        connect(P1,&QPushButton::clicked,[=](){
           if(Tflag == true) T2->play();
           Mflag = !Mflag;
           if(Mflag == true)
           {
               backm->play();
               P1->setText("音乐: 开");
           }
           else
           {
               backm->pause();
               P1->setText("音乐: 关");
           }
        });
        connect(P2,&QPushButton::clicked,[=](){
           if(Tflag == true) T2->play();
           backmlist->setCurrentIndex((backmlist->currentIndex()+backmlist->mediaCount()-1)%backmlist->mediaCount());
        });
        connect(P3,&QPushButton::clicked,[=](){
           if(Tflag == true) T2->play();
           backmlist->setCurrentIndex((backmlist->currentIndex()+1)%backmlist->mediaCount());
        });
        connect(P4,&QPushButton::clicked,[=](){
           if(Tflag == true) T2->play();
           Tflag = !Tflag;
           if(Tflag == true)
           {
               P4->setText("音效: 开");
           }
           else
           {
               P4->setText("音效: 关");
           }
        });
        //
        connect(mubtntimer,QTimer::timeout,[=](){
            Mu->show();
            mubtntimer->stop();
        });
    });
    //
    //开始按钮设置
    MyPushButton * startbutton = new MyPushButton(":/res/pic/Rocket.png");
    startbutton->setParent(ui->startpage);
    startbutton->setGeometry((this->width()-startbutton->width())*0.5,this->height()*0.6,startbutton->width(),startbutton->height());
    //
    //开始按钮功能
    connect(startbutton,&MyPushButton::clicked,[=](){
       if(Tflag == true) T1->play();
       QTimer * stbtntimer = new QTimer(this);
       stbtntimer->start(300);
       startbutton->btnup();
       startbutton->btndown();
       connect(stbtntimer,QTimer::timeout,[=](){
           ui->stackedWidget->setCurrentIndex(1);
           stbtntimer->stop();
       });
    });
    //
    //选择关卡返回按钮设置
    MyPushButton * backbutton0 = new MyPushButton(":/res/pic/Back.png");
    backbutton0->setParent(pages[0]);
    backbutton0->setGeometry((this->width()-backbutton0->width())*0.97,this->height()*0.77,backbutton0->width(),backbutton0->height());
    connect(backbutton0,&MyPushButton::clicked,[=](){
        if(Tflag == true) T2->play();
        QTimer * babtntimer0 = new QTimer(this);
        babtntimer0->start(300);
        backbutton0->btnup();
        backbutton0->btndown();
        connect(babtntimer0,QTimer::timeout,[=](){
            ui->stackedWidget->setCurrentIndex(0);
            babtntimer0->stop();
        });
    });
    //
    //关卡界面返回按钮设置及背景布置及重开按钮设置及 撤回按钮设置
    for(int i = 1; i <= 20; i++ )
    {
        QLabel * backp = new QLabel(pages[i]);
        backp->setGeometry(0,0,1000,600);
        backp->setPixmap(QPixmap(":/res/pic/BianJi.png"));
        backp->setScaledContents(true);
        labels[i]=backp;
        MyPushButton * backbutton = new MyPushButton(":/res/pic/Back2.png");
        MyPushButton * backbutton1 = new MyPushButton(":/res/pic/restart.png");
        MyPushButton * backbutton2 = new MyPushButton(":/res/pic/drawback.png");
        backbutton->setParent(pages[i]);
        backbutton1->setParent(pages[i]);
        backbutton2->setParent(pages[i]);
        backbutton->setGeometry((this->width()-backbutton->width())*0.95,this->height()*0.82,backbutton->width(),backbutton->height());
        backbutton1->setGeometry((backbutton1->width())*0.95,this->height()*0.82,backbutton->width(),backbutton->height());
        backbutton2->setGeometry((backbutton1->width())*2.40,this->height()*0.82,backbutton->width(),backbutton->height());
        backbutton->setShortcut(QKeySequence(QLatin1String("B")));
        backbutton1->setShortcut(QKeySequence(QLatin1String("R")));
        backbutton2->setShortcut(QKeySequence(QLatin1String("Ctrl+Z")));
        connect(backbutton,&MyPushButton::clicked,[=](){
            if(Tflag == true) {T2->stop();T2->play();}
            QTimer * babtntimer = new QTimer(this);
            babtntimer->start(300);
            backbutton->btnup();
            backbutton->btndown();
            connect(babtntimer,QTimer::timeout,[=](){
                ui->stackedWidget->setCurrentIndex(1);
                if(i == 0) ui->stackedWidget->setCurrentIndex(0);
                babtntimer->stop();
            });
        });
        connect(backbutton1,&MyPushButton::clicked,[=](){
            if(Tflag == true) {T2->stop();T2->play();}
            QTimer * babtntimer = new QTimer(this);
            babtntimer->start(300);
            backbutton1->btnup();
            backbutton1->btndown();
            connect(babtntimer,QTimer::timeout,[=](){
                ui->stackedWidget->setCurrentIndex(1);
                bool f =Tflag;Tflag=false;
                emit buttons[i]->click();Tflag=f;
                babtntimer->stop();
            });
        });
        connect(backbutton2,&MyPushButton::clicked,[=](){
            if(be==0&&bef[0]!=0)
            {
                bef[2000]=bef[0];
                bef[0]=0;be=2000;
            }
            if(be>=1)
            {
                if(Tflag == true) {T5->stop();T5->play();}
                backbutton2->btnup();
                backbutton2->btndown();
                int direction = bef[be]/10;
                int situation = bef[be]%10;
                if(direction == 1||direction == -1)
                {
                    //x1:Me to Floor
                    //x2:Me to Target
                    //x3:Me Push Box to Target
                    //x4:Me Push Box to Floor
                    //x5:Me Push BoxOnTarget to Target
                    //x6:Me Push BoxOnTarget to Floor
                    //-xAns:Me to MeOnTarget
                    //x: 1=W 2=S 3=A 4=D
                    if(situation == 1)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=4;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == 2)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == 3)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][0]++;
                        winnum[i][1]--;
                    }
                    else if (situation == 4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == 5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=5;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == 6)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][0]++;
                        winnum[i][1]++;
                    }
                    else if (situation == -1)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == -2)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == -3)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][0]++;
                        winnum[i][1]--;
                    }
                    else if (situation == -4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == -5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=7;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                        curplace[i][0]++;
                    }
                    else if (situation == -6)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][0]++;
                        winnum[i][1]++;
                    }
                }
                else if(direction == 2||direction == -2)
                {
                    if(situation == 1)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=4;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == 2)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == 3)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][0]--;
                        winnum[i][1]--;
                    }
                    else if (situation == 4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == 5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=5;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == 6)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][0]--;
                        winnum[i][1]++;
                    }
                    else if (situation == -1)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == -2)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == -3)
                    {
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][0]--;
                        winnum[i][1]--;
                    }
                    else if (situation == -4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == -5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=2;
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=7;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                        curplace[i][0]--;
                    }
                    else if (situation == -6)
                    {
                        map2[i-1][curplace[i][0]-1][curplace[i][1]]=7;
                        map2[i-1][curplace[i][0]+1][curplace[i][1]]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]-1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                        maps[i][curplace[i][0]+1][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][0]--;
                        winnum[i][1]++;
                    }
                }
                else if(direction == 3||direction == -3)
                {
                    if(situation == 1)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=4;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == 2)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == 3)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][1]++;
                        winnum[i][1]--;
                    }
                    else if (situation == 4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == 5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=5;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == 6)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][1]++;
                        winnum[i][1]++;
                    }
                    else if (situation == -1)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == -2)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == -3)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][1]++;
                        winnum[i][1]--;
                    }
                    else if (situation == -4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == -5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=7;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                        curplace[i][1]++;
                    }
                    else if (situation == -6)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][1]++;
                        winnum[i][1]++;
                    }
                }
                else if(direction == 4||direction == -4)
                {
                    if(situation == 1)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=4;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == 2)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == 3)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][1]--;
                        winnum[i][1]--;
                    }
                    else if (situation == 4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == 5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=5;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == 6)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][1]--;
                        winnum[i][1]++;
                    }
                    else if (situation == -1)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=5;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == -2)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=2;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == -3)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        curplace[i][1]--;
                        winnum[i][1]--;
                    }
                    else if (situation == -4)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=3;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=4;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == -5)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=2;
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=7;
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Target.png"));
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                        curplace[i][1]--;
                    }
                    else if (situation == -6)
                    {
                        map2[i-1][curplace[i][0]][curplace[i][1]-1]=7;
                        map2[i-1][curplace[i][0]][curplace[i][1]+1]=4;
                        map2[i-1][curplace[i][0]][curplace[i][1]]=6;
                        maps[i][curplace[i][0]][curplace[i][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                        maps[i][curplace[i][0]][curplace[i][1]+1]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                        maps[i][curplace[i][0]][curplace[i][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                        curplace[i][1]--;
                        winnum[i][1]++;
                    }
                }
                foot[i][1]--;be--;
            }
        });
    }
    //
    //选关按钮及关卡场景铺设
    for(int i = 1;i <= 4; i++ )
    {
        for(int j = 1;j <= 5; j++ )
        {
            MyPushButton * levelbutton = new MyPushButton(QString(":/res/pic/l%1.png").arg(i*5+j-5));
            levelbutton->setParent(ui->choosepage);
            levelbutton->setGeometry(-65+j*165,-75+i*110,levelbutton->width(),levelbutton->height());
            levelbutton->setEnabled(false);
            buttons[i*5+j-5]=levelbutton;
            levelbutton->show();
            connect(levelbutton,&MyPushButton::clicked,[=](){
                if(Tflag == true) T2->play();
                foot[i*5+j-5][1]=0;
                hour[i*5+j-5][1]=0;
                memset(bef,0,sizeof(bef));be=0;
                memset(winnum,0,sizeof(winnum));
                QTimer * lvbtntimer = new QTimer(this);
                lvbtntimer->start(300);
                levelbutton->btndown();
                connect(lvbtntimer,QTimer::timeout,[=](){
                    ui->stackedWidget->setCurrentIndex(i*5+j-4);
                    times[i*5+j-5]=clock();
                    lvbtntimer->stop();
                });
                for(int n = 0 ; n <= 11 ; n++ )
                {
                    for(int m = 0; m <= 11; m++ )
                    {
                        if( map[i*5+j-6][n][m] == 1 )
                        {
                            map2[i*5+j-6][n][m]=1;
                            QLabel * Wall = new QLabel(labels[i*5+j-5]);
                            Wall->setPixmap(QPixmap(":/res/pic/BianKuang.png"));
                            Wall->setScaledContents(true);
                            Wall->setGeometry(150+m*50,n*50,50,50);
                            maps[i*5+j-5][n][m]=Wall;
                        }
                        else if(map[i*5+j-6][n][m] == 2)
                        {
                            map2[i*5+j-6][n][m]=2;
                            winnum[i*5+j-5][0]++;
                            QLabel * Target = new QLabel(labels[i*5+j-5]);
                            Target->setPixmap(QPixmap(":/res/pic/Target.png"));
                            Target->setScaledContents(true);
                            Target->setGeometry(150+m*50,n*50,50,50);
                            maps[i*5+j-5][n][m]=Target;
                        }
                        else if(map[i*5+j-6][n][m] == 3)
                        {
                            map2[i*5+j-6][n][m]=3;
                            QLabel * Box = new QLabel(labels[i*5+j-5]);
                            Box->setPixmap(QPixmap(":/res/pic/Box.png"));
                            Box->setScaledContents(true);
                            Box->setGeometry(150+m*50,n*50,50,50);
                            maps[i*5+j-5][n][m]=Box;
                        }
                        else if(map[i*5+j-6][n][m] == 4)
                        {
                            map2[i*5+j-6][n][m]=4;
                            QLabel * Floor = new QLabel(labels[i*5+j-5]);
                            Floor->setPixmap(QPixmap(":/res/pic/Floor.png"));
                            Floor->setScaledContents(true);
                            Floor->setGeometry(150+m*50,n*50,50,50);
                            maps[i*5+j-5][n][m]=Floor;
                        }
                        else if(map[i*5+j-6][n][m] == 5)
                        {
                            map2[i*5+j-6][n][m]=5;
                            curplace[i*5+j-5][0]=n;
                            curplace[i*5+j-5][1]=m;
                            QLabel * Me = new QLabel(labels[i*5+j-5]);
                            Me->setPixmap(QPixmap(":/res/pic/Me.png"));
                            Me->setScaledContents(true);
                            Me->setGeometry(150+m*50,n*50,50,50);
                            maps[i*5+j-5][n][m]=Me;
                        }
                        else if(map[i*5+j-6][n][m] == 6)
                        {
                            map2[i*5+j-6][n][m]=6;
                            QLabel * BoxOnTarget = new QLabel(labels[i*5+j-5]);
                            BoxOnTarget->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                            BoxOnTarget->setScaledContents(true);
                            BoxOnTarget->setGeometry(150+m*50,n*50,50,50);
                            maps[i*5+j-5][n][m]=BoxOnTarget;
                        }
                        else if(map[i*5+j-6][n][m] == 7)
                        {
                            map2[i*5+j-6][n][m]=7;
                            QLabel * MeOnTarget = new QLabel(labels[i*5+j-5]);
                            MeOnTarget->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                            MeOnTarget->setScaledContents(true);
                            MeOnTarget->setGeometry(150+m*50,n*50,50,50);
                            maps[i*5+j-5][n][m]=MeOnTarget;
                        }
                    }
                }
            });
        }
    }
    //
    //闯关设置
    for(int i=1;i<=foot[0][0];i++)
        buttons[i]->setEnabled(true);
    //
    //关卡命名
    QLabel * ch = new QLabel(ui->choosepage);
    ch->setText("请选择关卡(●'v'●)");
    ch->setGeometry(50,480,700,125);
    ch->setFont(QFont("华文彩云",48));
    ch->setStyleSheet("QLabel{color:rgb(255,0,127);}");
    for(int i = 1; i <= 20; i++ )
    {
        QLabel * level = new QLabel(pages[i]);
        level->setText(QString("第%1关").arg(i));
        level->setFont(QFont("华文彩云",36));
        level->setStyleSheet("QLabel{color:rgb(255,0,127);}");
        level->setGeometry(0,0,200,80);
    }
    //
    //自定义模式
    MyPushButton * self = new MyPushButton(":/res/pic/creative.png");
    self->setParent(ui->startpage);
    self->move(980-self->width(),200);
    connect(self,&MyPushButton::clicked,[=](){
        if(Tflag == true) T2->play();
        QTimer * babtntimerr = new QTimer(this);
        babtntimerr->start(300);
        self->btnup();
        self->btndown();
        /*QDialog * news = new QDialog(this);
        news->setAttribute(Qt::WA_DeleteOnClose);
        news->setFixedSize(400,400);
        news->setWindowTitle("Pama'sGame 自定义模式 敬请期待");
        QLabel * nnn = new QLabel(news);
        nnn->setGeometry(0,0,400,400);
        nnn->setPixmap(QPixmap(":/res/pic/MeOnBox.png"));
        nnn->setScaledContents(true);*/
        connect(babtntimerr,QTimer::timeout,[=](){
            //news->show();
            ui->stackedWidget->setCurrentIndex(26);
            babtntimerr->stop();
        });
    });
    MyPushButton * backbutton00 = new MyPushButton(":/res/pic/Back.png");
    backbutton00->setParent(pages[21]);
    backbutton00->setGeometry((this->width()-backbutton00->width())*0.97,this->height()*0.77,backbutton00->width(),backbutton00->height());
    connect(backbutton00,&MyPushButton::clicked,[=](){
        if(Tflag == true) T2->play();
        QTimer * babtntimer00 = new QTimer(this);
        babtntimer00->start(300);
        backbutton00->btnup();
        backbutton00->btndown();
        connect(babtntimer00,QTimer::timeout,[=](){
            ui->stackedWidget->setCurrentIndex(0);
            babtntimer00->stop();
        });
    });
    //
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    int now = ui->stackedWidget->currentIndex();now--;
    int nown = now -1;
    if(ev->key() == 87 ||ev->key() == 16777235) //按W或上方向键
    {
        if(map2[nown][curplace[now][0]][curplace[now][1]] == 5)  //如果自己在空地上
        {
            if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 4) //如果上方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=11;
                map2[nown][curplace[now][0]-1][curplace[now][1]]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][0]--;
            }
            else if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 3)  //如果上方是空地上的箱子
            {
                if (map2[nown][curplace[now][0]-2][curplace[now][1]] == 4)  //如果上方的上方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=14;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]--;
                }
                else if(map2[nown][curplace[now][0]-2][curplace[now][1]] == 2)  //如果上方的上方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=13;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]--;
                    winnum[now][1]++;
                    if(winnum[now][1]==winnum[now][0])
                    {        
                        double total = (clock()-times[now])/(double)CLOCKS_PER_SEC;
                        QDialog * Winn = new QDialog(this);
                        QLabel * T = new QLabel(Winn);
                        if(foot[now][1]<=foot[now][0])
                        {
                            foot[now][0]=foot[now][1];
                        }
                        hour[now][1]=total;
                        if(hour[now][1]<=hour[now][0])
                        {
                            hour[now][0]=hour[now][1];
                        }
                        T->setText(QString("恭喜您通关啦！第 %2 关:\n"
                                           "所用步数: %3 步\n最少步数: %4 步\n"
                                           "所用时间: %1 秒\n最短时间: %5 秒\n\n"
                                           ).arg(hour[now][1]).arg(now).arg(foot[now][1]).arg(foot[now][0]).arg(hour[now][0]));
                        T->setFont(QFont("阿里汉仪智能黑体",38));
                        T->setGeometry(0,-10,1000,610);
                        T->setStyleSheet("QLabel{color:rgb(0, 170, 255);background-color: rgb(85, 255, 255);}");
                        MyPushButton * H =new MyPushButton(":/res/pic/home.png");
                        H->setParent(Winn);
                        H->move(200,400);
                        connect(H,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            H->btnup();
                            H->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();
                                ui->stackedWidget->setCurrentIndex(1);
                                babtntimer->stop();
                            });
                        });
                        MyPushButton * N =new MyPushButton(":/res/pic/next.png");
                        N->setParent(Winn);
                        N->move(600,400);
                        connect(N,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            N->btnup();
                            N->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();bool ff = Tflag;Tflag =false;
                                ui->stackedWidget->setCurrentIndex(1);
                                buttons[now+1]->click();Tflag=ff;
                                babtntimer->stop();
                            });
                        });
                        if(now==20)
                        {
                            N->hide();
                            MyPushButton * W =new MyPushButton(":/res/pic/Win.png");
                            W->setParent(Winn);
                            W->move(600,400);
                            connect(W,&MyPushButton::clicked,[=](){
                                if(Tflag == true) T2->play();
                                QTimer * babtntimer = new QTimer(this);
                                babtntimer->start(300);
                                W->btnup();
                                W->btndown();
                                connect(babtntimer,QTimer::timeout,[=](){
                                    Winn->close();
                                    ui->stackedWidget->setCurrentIndex(22);
                                    babtntimer->stop();
                                });
                            });
                        }
                        else
                        {
                            buttons[now+1]->setEnabled(true);
                            foot[0][0]=now+1;
                        }
                        Winn->setFixedSize(1000,600);
                        Winn->move(this->pos());
                        Winn->setWindowTitle(QString("Pama'sGame 恭喜您通过第%1关").arg(now));
                        Winn->setAttribute(Qt::WA_DeleteOnClose);
                        Winn->show();this->hide();
                        Victory->play();
                        connect(Winn,&QDialog::rejected,[=](){
                            this->show();
                        });
                    }
                }
            }
            else if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 2)  //如果上方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=12;
                map2[nown][curplace[now][0]-1][curplace[now][1]]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][0]--;
            }
            else if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 6)  //如果上方是目的地上的箱子
            {
                if (map2[nown][curplace[now][0]-2][curplace[now][1]] == 4)  //如果上方的上方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=16;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]--;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]-2][curplace[now][1]] == 2)  //如果上方的上方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=15;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]--;
                }
            }
        }
        else if(map2[nown][curplace[now][0]][curplace[now][1]] == 7)  //如果自己在目的地上
        {
            if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 4) //如果上方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-11;
                map2[nown][curplace[now][0]-1][curplace[now][1]]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][0]--;
            }
            else if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 3)  //如果上方是空地上的箱子
            {
                if (map2[nown][curplace[now][0]-2][curplace[now][1]] == 4)  //如果上方的上方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-14;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]--;
                }
                else if(map2[nown][curplace[now][0]-2][curplace[now][1]] == 2)  //如果上方的上方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-13;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Me.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]--;
                    winnum[now][1]++;
                }
            }
            else if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 2)  //如果上方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-12;
                map2[nown][curplace[now][0]-1][curplace[now][1]]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][0]--;
            }
            else if(map2[nown][curplace[now][0]-1][curplace[now][1]] == 6)  //如果上方是目的地上的箱子
            {
                if (map2[nown][curplace[now][0]-2][curplace[now][1]] == 4)  //如果上方的上方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-16;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]--;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]-2][curplace[now][1]] == 2)  //如果上方的上方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-15;
                    map2[nown][curplace[now][0]-2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]-1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]-2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]-1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]--;
                }
            }

        }
    }
    else if(ev->key() == 83 ||ev->key() == 16777237)  //按S或下方向键
    {
        if(map2[nown][curplace[now][0]][curplace[now][1]] == 5)  //如果自己在空地上
        {
            if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 4) //如果下方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=21;
                map2[nown][curplace[now][0]+1][curplace[now][1]]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][0]++;
            }
            else if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 3)  //如果下方是空地上的箱子
            {
                if (map2[nown][curplace[now][0]+2][curplace[now][1]] == 4)  //如果下方的下方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=24;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]++;
                }
                else if(map2[nown][curplace[now][0]+2][curplace[now][1]] == 2)  //如果下方的下方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=23;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]++;
                    winnum[now][1]++;
                    if(winnum[now][1]==winnum[now][0])
                    {
                        double total = (clock()-times[now])/(double)CLOCKS_PER_SEC;
                        QDialog * Winn = new QDialog(this);
                        QLabel * T = new QLabel(Winn);
                        if(foot[now][1]<=foot[now][0])
                        {
                            foot[now][0]=foot[now][1];
                        }
                        hour[now][1]=total;
                        if(hour[now][1]<=hour[now][0])
                        {
                            hour[now][0]=hour[now][1];
                        }
                        T->setText(QString("恭喜您通关啦！第 %2 关:\n"
                                           "所用步数: %3 步\n最少步数: %4 步\n"
                                           "所用时间: %1 秒\n最短时间: %5 秒\n\n"
                                           ).arg(hour[now][1]).arg(now).arg(foot[now][1]).arg(foot[now][0]).arg(hour[now][0]));
                        T->setFont(QFont("阿里汉仪智能黑体",38));
                        T->setGeometry(0,-10,1000,610);
                        T->setStyleSheet("QLabel{color:rgb(0, 170, 255);background-color: rgb(85, 255, 255);}");
                        MyPushButton * H =new MyPushButton(":/res/pic/home.png");
                        H->setParent(Winn);
                        H->move(200,400);
                        connect(H,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            H->btnup();
                            H->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();
                                ui->stackedWidget->setCurrentIndex(1);
                                babtntimer->stop();
                            });
                        });
                        MyPushButton * N =new MyPushButton(":/res/pic/next.png");
                        N->setParent(Winn);
                        N->move(600,400);
                        connect(N,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            N->btnup();
                            N->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();bool ff = Tflag;Tflag =false;
                                ui->stackedWidget->setCurrentIndex(1);
                                buttons[now+1]->click();Tflag=ff;
                                babtntimer->stop();
                            });
                        });
                        if(now==20)
                        {
                            N->hide();
                            MyPushButton * W =new MyPushButton(":/res/pic/Win.png");
                            W->setParent(Winn);
                            W->move(600,400);
                            connect(W,&MyPushButton::clicked,[=](){
                                if(Tflag == true) T2->play();
                                QTimer * babtntimer = new QTimer(this);
                                babtntimer->start(300);
                                W->btnup();
                                W->btndown();
                                connect(babtntimer,QTimer::timeout,[=](){
                                    Winn->close();
                                    ui->stackedWidget->setCurrentIndex(22);
                                    babtntimer->stop();
                                });
                            });
                        }
                        else
                        {
                            buttons[now+1]->setEnabled(true);
                            foot[0][0]=now+1;
                        }
                        Winn->setFixedSize(1000,600);
                        Winn->move(this->pos());
                        Winn->setWindowTitle(QString("Pama'sGame 恭喜您通过第%1关").arg(now));
                        Winn->setAttribute(Qt::WA_DeleteOnClose);
                        Winn->show();this->hide();
                        Victory->play();
                        connect(Winn,&QDialog::rejected,[=](){
                           this->show();
                        });
                    }
                }
            }
            else if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 2)  //如果下方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=22;
                map2[nown][curplace[now][0]+1][curplace[now][1]]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][0]++;
            }
            else if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 6)  //如果下方是目的地下的箱子
            {
                if (map2[nown][curplace[now][0]+2][curplace[now][1]] == 4)  //如果下方的下方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=26;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]++;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]+2][curplace[now][1]] == 2)  //如果下方的下方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=25;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][0]++;
                }
            }
        }
        else if(map2[nown][curplace[now][0]][curplace[now][1]] == 7)  //如果自己在目的地上
        {
            if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 4) //如果下方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-21;
                map2[nown][curplace[now][0]+1][curplace[now][1]]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][0]++;
            }
            else if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 3)  //如果下方是空地上的箱子
            {
                if (map2[nown][curplace[now][0]+2][curplace[now][1]] == 4)  //如果下方的下方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-24;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]++;
                }
                else if(map2[nown][curplace[now][0]+2][curplace[now][1]] == 2)  //如果下方的下方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-23;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]++;
                    winnum[now][1]++;
                }
            }
            else if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 2)  //如果下方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-22;
                map2[nown][curplace[now][0]+1][curplace[now][1]]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][0]++;
            }
            else if(map2[nown][curplace[now][0]+1][curplace[now][1]] == 6)  //如果下方是目的地上的箱子
            {
                if (map2[nown][curplace[now][0]+2][curplace[now][1]] == 4)  //如果下方的下方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-26;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=3;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]++;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]+2][curplace[now][1]] == 2)  //如果下方的下方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-25;
                    map2[nown][curplace[now][0]+2][curplace[now][1]]=6;
                    map2[nown][curplace[now][0]+1][curplace[now][1]]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]+2][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]+1][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/MeOnTargetS.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][0]++;
                }
            }

        }
    }
    else if(ev->key() == 65||ev->key() == 16777234)  //按A或左方向键
    {
        if(map2[nown][curplace[now][0]][curplace[now][1]] == 5)  //如果自己在空地上
        {
            if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 4) //如果左方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=31;
                map2[nown][curplace[now][0]][curplace[now][1]-1]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][1]--;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 3)  //如果左方是空地上的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]-2] == 4)  //如果左方的左方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=34;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]--;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]-2] == 2)  //如果左方的左方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=33;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]--;
                    winnum[now][1]++;
                    if(winnum[now][1]==winnum[now][0])
                    {
                        double total = (clock()-times[now])/(double)CLOCKS_PER_SEC;
                        QDialog * Winn = new QDialog(this);
                        QLabel * T = new QLabel(Winn);
                        if(foot[now][1]<=foot[now][0])
                        {
                            foot[now][0]=foot[now][1];
                        }
                        hour[now][1]=total;
                        if(hour[now][1]<=hour[now][0])
                        {
                            hour[now][0]=hour[now][1];
                        }
                        T->setText(QString("恭喜您通关啦！第 %2 关:\n"
                                           "所用步数: %3 步\n最少步数: %4 步\n"
                                           "所用时间: %1 秒\n最短时间: %5 秒\n\n"
                                           ).arg(hour[now][1]).arg(now).arg(foot[now][1]).arg(foot[now][0]).arg(hour[now][0]));
                        T->setFont(QFont("阿里汉仪智能黑体",38));
                        T->setGeometry(0,-10,1000,610);
                        T->setStyleSheet("QLabel{color:rgb(0, 170, 255);background-color: rgb(85, 255, 255);}");
                        MyPushButton * H =new MyPushButton(":/res/pic/home.png");
                        H->setParent(Winn);
                        H->move(200,400);
                        connect(H,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            H->btnup();
                            H->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();
                                ui->stackedWidget->setCurrentIndex(1);
                                babtntimer->stop();
                            });
                        });
                        MyPushButton * N =new MyPushButton(":/res/pic/next.png");
                        N->setParent(Winn);
                        N->move(600,400);
                        connect(N,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            N->btnup();
                            N->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();bool ff = Tflag;Tflag =false;
                                ui->stackedWidget->setCurrentIndex(1);
                                buttons[now+1]->click();Tflag=ff;
                                babtntimer->stop();
                            });
                        });
                        if(now==20)
                        {
                            N->hide();
                            MyPushButton * W =new MyPushButton(":/res/pic/Win.png");
                            W->setParent(Winn);
                            W->move(600,400);
                            connect(W,&MyPushButton::clicked,[=](){
                                if(Tflag == true) T2->play();
                                QTimer * babtntimer = new QTimer(this);
                                babtntimer->start(300);
                                W->btnup();
                                W->btndown();
                                connect(babtntimer,QTimer::timeout,[=](){
                                    Winn->close();
                                    ui->stackedWidget->setCurrentIndex(22);
                                    babtntimer->stop();
                                });
                            });
                        }
                        else
                        {
                            buttons[now+1]->setEnabled(true);
                            foot[0][0]=now+1;
                        }
                        Winn->setFixedSize(1000,600);
                        Winn->move(this->pos());
                        Winn->setWindowTitle(QString("Pama'sGame 恭喜您通过第%1关").arg(now));
                        Winn->setAttribute(Qt::WA_DeleteOnClose);
                        Winn->show();this->hide();
                        Victory->play();
                        connect(Winn,&QDialog::rejected,[=](){
                           this->show();
                        });
                    }
                }
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 2)  //如果左方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=32;
                map2[nown][curplace[now][0]][curplace[now][1]-1]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][1]--;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 6)  //如果左方是目的地下的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]-2] == 4)  //如果左方的左方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=36;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]--;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]-2] == 2)  //如果左方的左方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=35;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]--;
                }
            }
        }
        else if(map2[nown][curplace[now][0]][curplace[now][1]] == 7)  //如果自己在目的地上
        {
            if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 4) //如果左方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-31;
                map2[nown][curplace[now][0]][curplace[now][1]-1]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][1]--;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 3)  //如果左方是空地上的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]-2] == 4)  //如果左方的左方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-34;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]--;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]-2] == 2)  //如果左方的左方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-33;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]--;
                    winnum[now][1]++;
                }
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 2)  //如果左方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-32;
                map2[nown][curplace[now][0]][curplace[now][1]-1]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][1]--;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]-1] == 6)  //如果左方是目的地上的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]-2] == 4)  //如果左方的左方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-36;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]--;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]-2] == 2)  //如果左方的左方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-35;
                    map2[nown][curplace[now][0]][curplace[now][1]-2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]-1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]-2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]-1]->setPixmap(QPixmap(":/res/pic/MeOnTargetA.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]--;
                }
            }

        }
    }
    else if(ev->key() == 68||ev->key() == 16777236)  //按D或右方向键
    {
        if(map2[nown][curplace[now][0]][curplace[now][1]] == 5)  //如果自己在空地上
        {
            if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 4) //如果右方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=41;
                map2[nown][curplace[now][0]][curplace[now][1]+1]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][1]++;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 3)  //如果右方是空地上的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]+2] == 4)  //如果右方的右方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=44;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]++;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]+2] == 2)  //如果右方的右方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=43;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]++;
                    winnum[now][1]++;
                    if(winnum[now][1]==winnum[now][0])
                    {
                        double total = (clock()-times[now])/(double)CLOCKS_PER_SEC;
                        QDialog * Winn = new QDialog(this);
                        QLabel * T = new QLabel(Winn);
                        if(foot[now][1]<=foot[now][0])
                        {
                            foot[now][0]=foot[now][1];
                        }
                        hour[now][1]=total;
                        if(hour[now][1]<=hour[now][0])
                        {
                            hour[now][0]=hour[now][1];
                        }
                        T->setText(QString("恭喜您通关啦！第 %2 关:\n"
                                           "所用步数: %3 步\n最少步数: %4 步\n"
                                           "所用时间: %1 秒\n最短时间: %5 秒\n\n"
                                           ).arg(hour[now][1]).arg(now).arg(foot[now][1]).arg(foot[now][0]).arg(hour[now][0]));
                        T->setFont(QFont("阿里汉仪智能黑体",38));
                        T->setGeometry(0,-10,1000,610);
                        T->setStyleSheet("QLabel{color:rgb(0, 170, 255);background-color: rgb(85, 255, 255);}");
                        MyPushButton * H =new MyPushButton(":/res/pic/home.png");
                        H->setParent(Winn);
                        H->move(200,400);
                        connect(H,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            H->btnup();
                            H->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();
                                ui->stackedWidget->setCurrentIndex(1);
                                babtntimer->stop();
                            });
                        });
                        MyPushButton * N =new MyPushButton(":/res/pic/next.png");
                        N->setParent(Winn);
                        N->move(600,400);
                        connect(N,&MyPushButton::clicked,[=](){
                            if(Tflag == true) T2->play();
                            QTimer * babtntimer = new QTimer(this);
                            babtntimer->start(300);
                            N->btnup();
                            N->btndown();
                            connect(babtntimer,QTimer::timeout,[=](){
                                Winn->close();bool ff = Tflag;Tflag =false;
                                ui->stackedWidget->setCurrentIndex(1);
                                buttons[now+1]->click();Tflag=ff;
                                babtntimer->stop();
                            });
                        });
                        if(now==20)
                        {
                            N->hide();
                            MyPushButton * W =new MyPushButton(":/res/pic/Win.png");
                            W->setParent(Winn);
                            W->move(600,400);
                            connect(W,&MyPushButton::clicked,[=](){
                                if(Tflag == true) T2->play();
                                QTimer * babtntimer = new QTimer(this);
                                babtntimer->start(300);
                                W->btnup();
                                W->btndown();
                                connect(babtntimer,QTimer::timeout,[=](){
                                    Winn->close();
                                    ui->stackedWidget->setCurrentIndex(22);
                                    babtntimer->stop();
                                });
                            });
                        }
                        else
                        {
                            buttons[now+1]->setEnabled(true);
                            foot[0][0]=now+1;
                        }
                        Winn->setFixedSize(1000,600);
                        Winn->move(this->pos());
                        Winn->setWindowTitle(QString("Pama'sGame 恭喜您通过第%1关").arg(now));
                        Winn->setAttribute(Qt::WA_DeleteOnClose);
                        Winn->show();this->hide();
                        Victory->play();
                        connect(Winn,&QDialog::rejected,[=](){
                           this->show();
                        });
                    }
                }
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 2)  //如果右方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=42;
                map2[nown][curplace[now][0]][curplace[now][1]+1]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=4;
                maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                curplace[now][1]++;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 6)  //如果右方是目的地下的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]+2] == 4)  //如果右方的右方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=46;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]++;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]+2] == 2)  //如果右方的右方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=45;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=4;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Floor.png"));
                    curplace[now][1]++;
                }
            }
        }
        else if(map2[nown][curplace[now][0]][curplace[now][1]] == 7)  //如果自己在目的地上
        {
            if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 4) //如果右方是空地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-41;
                map2[nown][curplace[now][0]][curplace[now][1]+1]=5;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][1]++;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 3)  //如果右方是右地上的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]+2] == 4)  //如果右方的右方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-44;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]++;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]+2] == 2)  //如果右方的右方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-43;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=5;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]++;
                    winnum[now][1]++;
                }
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 2)  //如果右方是目的地
            {
                if(Tflag == true)   {T3->stop();T3->play();}
                foot[now][1]++;
                be++;
                if(be==2000) be=0;
                bef[be]=-42;
                map2[nown][curplace[now][0]][curplace[now][1]+1]=7;
                map2[nown][curplace[now][0]][curplace[now][1]]=2;
                maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                curplace[now][1]++;
            }
            else if(map2[nown][curplace[now][0]][curplace[now][1]+1] == 6)  //如果右方是目的地上的箱子
            {
                if (map2[nown][curplace[now][0]][curplace[now][1]+2] == 4)  //如果右方的右方是空地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-46;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=3;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/Box.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]++;
                    winnum[now][1]--;
                }
                else if(map2[nown][curplace[now][0]][curplace[now][1]+2] == 2)  //如果右方的右方是目的地
                {
                    if(Tflag == true)   {T4->stop();T4->play();}
                    foot[now][1]++;
                    be++;
                    if(be==2000) be=0;
                    bef[be]=-45;
                    map2[nown][curplace[now][0]][curplace[now][1]+2]=6;
                    map2[nown][curplace[now][0]][curplace[now][1]+1]=7;
                    map2[nown][curplace[now][0]][curplace[now][1]]=2;
                    maps[now][curplace[now][0]][curplace[now][1]+2]->setPixmap(QPixmap(":/res/pic/BoxOnTarget.png"));
                    maps[now][curplace[now][0]][curplace[now][1]+1]->setPixmap(QPixmap(":/res/pic/MeOnTargetD.png"));
                    maps[now][curplace[now][0]][curplace[now][1]]->setPixmap(QPixmap(":/res/pic/Target.png"));
                    curplace[now][1]++;
                }
            }

        }

    }
}

void MainWindow::receivedata(QString str)
{
    name=str;
    if(name=="")
        welcome0->setText(QString("你好!"));
    else
        welcome0->setText(QString("你好！%1").arg(name));
}

MainWindow::~MainWindow()
{
    delete ui;
}
