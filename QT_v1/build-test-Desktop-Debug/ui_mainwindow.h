/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *box_button_control;
    QLabel *lbl_fastest_press;
    QLabel *lbl_press_info;
    QFrame *line;
    QRadioButton *rb_buzzer_beater;
    QRadioButton *rb_free_buzzer;
    QPushButton *btn_unlock_buzzers;
    QGroupBox *box_green_button;
    QLabel *lbl_green_short_audio;
    QLabel *lbl_green_long_audio;
    QPushButton *btn_green_set_short_audio;
    QPushButton *btn_green_set_long_audio;
    QGroupBox *box_yellow_button;
    QLabel *lbl_yellow_short_audio;
    QLabel *lbl_yellow_long_audio;
    QPushButton *btn_yellow_set_short_audio;
    QPushButton *btn_yellow_set_long_audio;
    QGroupBox *box_blue_button;
    QLabel *lbl_blue_short_audio;
    QLabel *lbl_blue_long_audio;
    QPushButton *btn_blue_set_short_audio;
    QPushButton *btn_blue_set_long_audio;
    QGroupBox *box_red_button;
    QLabel *lbl_red_short_audio;
    QLabel *lbl_red_long_audio;
    QPushButton *btn_red_set_short_audio;
    QPushButton *btn_red_set_long_audio;
    QGroupBox *box_audiocontrol;
    QLabel *lbl_now_playing;
    QLabel *lbl_audio_info;
    QFrame *line_2;
    QRadioButton *rb_play_short;
    QRadioButton *rb_play_long;
    QCheckBox *chb_mute;
    QCheckBox *chb_simultaneous;
    QGroupBox *box_blinkspeed;
    QLabel *lbl_blinkspeed;
    QSlider *sld_blinkspeed;
    QGroupBox *box_backgrounds;
    QListWidget *lst_backgrounds;
    QGroupBox *scorebox_red;
    QLabel *lbl_red_score;
    QPushButton *btn_red_m10;
    QPushButton *btn_red_m5;
    QPushButton *btn_red_m1;
    QPushButton *btn_red_p1;
    QPushButton *btn_red_p5;
    QPushButton *btn_red_p10;
    QGroupBox *scorebox_yellow;
    QLabel *lbl_yellow_score;
    QPushButton *btn_yellow_m10;
    QPushButton *btn_yellow_m5;
    QPushButton *btn_yellow_m1;
    QPushButton *btn_yellow_p1;
    QPushButton *btn_yellow_p5;
    QPushButton *btn_yellow_p10;
    QGroupBox *scorebox_blue;
    QLabel *lbl_blue_score;
    QPushButton *btn_blue_m10;
    QPushButton *btn_blue_m5;
    QPushButton *btn_blue_m1;
    QPushButton *btn_blue_p1;
    QPushButton *btn_blue_p5;
    QPushButton *btn_blue_p10;
    QGroupBox *scorebox_green;
    QLabel *lbl_green_score;
    QPushButton *btn_green_m10;
    QPushButton *btn_green_m5;
    QPushButton *btn_green_m1;
    QPushButton *btn_green_p1;
    QPushButton *btn_green_p5;
    QPushButton *btn_green_p10;
    QGroupBox *forbidden_answer_box;
    QComboBox *drd_questions;
    QLabel *lbl_question;
    QListWidget *lst_answers;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1114, 581);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        box_button_control = new QGroupBox(centralWidget);
        box_button_control->setObjectName(QStringLiteral("box_button_control"));
        box_button_control->setGeometry(QRect(10, 10, 231, 171));
        box_button_control->setStyleSheet(QStringLiteral(""));
        lbl_fastest_press = new QLabel(box_button_control);
        lbl_fastest_press->setObjectName(QStringLiteral("lbl_fastest_press"));
        lbl_fastest_press->setGeometry(QRect(10, 20, 211, 21));
        lbl_press_info = new QLabel(box_button_control);
        lbl_press_info->setObjectName(QStringLiteral("lbl_press_info"));
        lbl_press_info->setGeometry(QRect(30, 40, 191, 21));
        line = new QFrame(box_button_control);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 60, 231, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        rb_buzzer_beater = new QRadioButton(box_button_control);
        rb_buzzer_beater->setObjectName(QStringLiteral("rb_buzzer_beater"));
        rb_buzzer_beater->setGeometry(QRect(10, 110, 211, 18));
        rb_free_buzzer = new QRadioButton(box_button_control);
        rb_free_buzzer->setObjectName(QStringLiteral("rb_free_buzzer"));
        rb_free_buzzer->setGeometry(QRect(10, 80, 211, 21));
        rb_free_buzzer->setChecked(true);
        btn_unlock_buzzers = new QPushButton(box_button_control);
        btn_unlock_buzzers->setObjectName(QStringLiteral("btn_unlock_buzzers"));
        btn_unlock_buzzers->setGeometry(QRect(10, 140, 211, 23));
        box_green_button = new QGroupBox(centralWidget);
        box_green_button->setObjectName(QStringLiteral("box_green_button"));
        box_green_button->setGeometry(QRect(10, 490, 441, 73));
        lbl_green_short_audio = new QLabel(box_green_button);
        lbl_green_short_audio->setObjectName(QStringLiteral("lbl_green_short_audio"));
        lbl_green_short_audio->setGeometry(QRect(10, 20, 291, 23));
        lbl_green_long_audio = new QLabel(box_green_button);
        lbl_green_long_audio->setObjectName(QStringLiteral("lbl_green_long_audio"));
        lbl_green_long_audio->setGeometry(QRect(10, 50, 291, 23));
        btn_green_set_short_audio = new QPushButton(box_green_button);
        btn_green_set_short_audio->setObjectName(QStringLiteral("btn_green_set_short_audio"));
        btn_green_set_short_audio->setGeometry(QRect(310, 20, 131, 23));
        btn_green_set_long_audio = new QPushButton(box_green_button);
        btn_green_set_long_audio->setObjectName(QStringLiteral("btn_green_set_long_audio"));
        btn_green_set_long_audio->setGeometry(QRect(310, 50, 131, 23));
        box_yellow_button = new QGroupBox(centralWidget);
        box_yellow_button->setObjectName(QStringLiteral("box_yellow_button"));
        box_yellow_button->setGeometry(QRect(10, 330, 441, 73));
        lbl_yellow_short_audio = new QLabel(box_yellow_button);
        lbl_yellow_short_audio->setObjectName(QStringLiteral("lbl_yellow_short_audio"));
        lbl_yellow_short_audio->setGeometry(QRect(10, 20, 291, 23));
        lbl_yellow_long_audio = new QLabel(box_yellow_button);
        lbl_yellow_long_audio->setObjectName(QStringLiteral("lbl_yellow_long_audio"));
        lbl_yellow_long_audio->setGeometry(QRect(10, 50, 291, 23));
        btn_yellow_set_short_audio = new QPushButton(box_yellow_button);
        btn_yellow_set_short_audio->setObjectName(QStringLiteral("btn_yellow_set_short_audio"));
        btn_yellow_set_short_audio->setGeometry(QRect(310, 20, 131, 23));
        btn_yellow_set_long_audio = new QPushButton(box_yellow_button);
        btn_yellow_set_long_audio->setObjectName(QStringLiteral("btn_yellow_set_long_audio"));
        btn_yellow_set_long_audio->setGeometry(QRect(310, 50, 131, 23));
        box_blue_button = new QGroupBox(centralWidget);
        box_blue_button->setObjectName(QStringLiteral("box_blue_button"));
        box_blue_button->setGeometry(QRect(10, 410, 441, 73));
        lbl_blue_short_audio = new QLabel(box_blue_button);
        lbl_blue_short_audio->setObjectName(QStringLiteral("lbl_blue_short_audio"));
        lbl_blue_short_audio->setGeometry(QRect(10, 20, 291, 23));
        lbl_blue_long_audio = new QLabel(box_blue_button);
        lbl_blue_long_audio->setObjectName(QStringLiteral("lbl_blue_long_audio"));
        lbl_blue_long_audio->setGeometry(QRect(10, 50, 291, 23));
        btn_blue_set_short_audio = new QPushButton(box_blue_button);
        btn_blue_set_short_audio->setObjectName(QStringLiteral("btn_blue_set_short_audio"));
        btn_blue_set_short_audio->setGeometry(QRect(310, 20, 131, 23));
        btn_blue_set_long_audio = new QPushButton(box_blue_button);
        btn_blue_set_long_audio->setObjectName(QStringLiteral("btn_blue_set_long_audio"));
        btn_blue_set_long_audio->setGeometry(QRect(310, 50, 131, 23));
        box_red_button = new QGroupBox(centralWidget);
        box_red_button->setObjectName(QStringLiteral("box_red_button"));
        box_red_button->setGeometry(QRect(10, 250, 441, 73));
        lbl_red_short_audio = new QLabel(box_red_button);
        lbl_red_short_audio->setObjectName(QStringLiteral("lbl_red_short_audio"));
        lbl_red_short_audio->setGeometry(QRect(10, 20, 291, 23));
        lbl_red_long_audio = new QLabel(box_red_button);
        lbl_red_long_audio->setObjectName(QStringLiteral("lbl_red_long_audio"));
        lbl_red_long_audio->setGeometry(QRect(10, 50, 291, 23));
        btn_red_set_short_audio = new QPushButton(box_red_button);
        btn_red_set_short_audio->setObjectName(QStringLiteral("btn_red_set_short_audio"));
        btn_red_set_short_audio->setGeometry(QRect(310, 20, 131, 23));
        btn_red_set_long_audio = new QPushButton(box_red_button);
        btn_red_set_long_audio->setObjectName(QStringLiteral("btn_red_set_long_audio"));
        btn_red_set_long_audio->setGeometry(QRect(310, 50, 131, 23));
        box_audiocontrol = new QGroupBox(centralWidget);
        box_audiocontrol->setObjectName(QStringLiteral("box_audiocontrol"));
        box_audiocontrol->setGeometry(QRect(250, 10, 191, 171));
        lbl_now_playing = new QLabel(box_audiocontrol);
        lbl_now_playing->setObjectName(QStringLiteral("lbl_now_playing"));
        lbl_now_playing->setGeometry(QRect(10, 20, 171, 21));
        lbl_audio_info = new QLabel(box_audiocontrol);
        lbl_audio_info->setObjectName(QStringLiteral("lbl_audio_info"));
        lbl_audio_info->setGeometry(QRect(30, 40, 151, 21));
        line_2 = new QFrame(box_audiocontrol);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 60, 191, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        rb_play_short = new QRadioButton(box_audiocontrol);
        rb_play_short->setObjectName(QStringLiteral("rb_play_short"));
        rb_play_short->setGeometry(QRect(10, 80, 171, 21));
        rb_play_long = new QRadioButton(box_audiocontrol);
        rb_play_long->setObjectName(QStringLiteral("rb_play_long"));
        rb_play_long->setGeometry(QRect(10, 100, 171, 21));
        rb_play_long->setChecked(true);
        chb_mute = new QCheckBox(box_audiocontrol);
        chb_mute->setObjectName(QStringLiteral("chb_mute"));
        chb_mute->setGeometry(QRect(10, 120, 171, 21));
        chb_simultaneous = new QCheckBox(box_audiocontrol);
        chb_simultaneous->setObjectName(QStringLiteral("chb_simultaneous"));
        chb_simultaneous->setGeometry(QRect(10, 140, 171, 21));
        chb_simultaneous->setChecked(true);
        box_blinkspeed = new QGroupBox(centralWidget);
        box_blinkspeed->setObjectName(QStringLiteral("box_blinkspeed"));
        box_blinkspeed->setGeometry(QRect(10, 190, 431, 51));
        lbl_blinkspeed = new QLabel(box_blinkspeed);
        lbl_blinkspeed->setObjectName(QStringLiteral("lbl_blinkspeed"));
        lbl_blinkspeed->setGeometry(QRect(370, 24, 59, 21));
        lbl_blinkspeed->setAlignment(Qt::AlignCenter);
        sld_blinkspeed = new QSlider(box_blinkspeed);
        sld_blinkspeed->setObjectName(QStringLiteral("sld_blinkspeed"));
        sld_blinkspeed->setGeometry(QRect(20, 28, 311, 16));
        sld_blinkspeed->setMinimum(0);
        sld_blinkspeed->setMaximum(5000);
        sld_blinkspeed->setSingleStep(50);
        sld_blinkspeed->setValue(1000);
        sld_blinkspeed->setOrientation(Qt::Horizontal);
        sld_blinkspeed->setTickPosition(QSlider::TicksBelow);
        sld_blinkspeed->setTickInterval(500);
        box_backgrounds = new QGroupBox(centralWidget);
        box_backgrounds->setObjectName(QStringLiteral("box_backgrounds"));
        box_backgrounds->setGeometry(QRect(460, 10, 251, 231));
        lst_backgrounds = new QListWidget(box_backgrounds);
        lst_backgrounds->setObjectName(QStringLiteral("lst_backgrounds"));
        lst_backgrounds->setGeometry(QRect(1, 20, 250, 211));
        scorebox_red = new QGroupBox(centralWidget);
        scorebox_red->setObjectName(QStringLiteral("scorebox_red"));
        scorebox_red->setGeometry(QRect(460, 250, 251, 73));
        lbl_red_score = new QLabel(scorebox_red);
        lbl_red_score->setObjectName(QStringLiteral("lbl_red_score"));
        lbl_red_score->setGeometry(QRect(10, 20, 231, 23));
        btn_red_m10 = new QPushButton(scorebox_red);
        btn_red_m10->setObjectName(QStringLiteral("btn_red_m10"));
        btn_red_m10->setGeometry(QRect(10, 50, 31, 23));
        btn_red_m5 = new QPushButton(scorebox_red);
        btn_red_m5->setObjectName(QStringLiteral("btn_red_m5"));
        btn_red_m5->setGeometry(QRect(50, 50, 31, 23));
        btn_red_m1 = new QPushButton(scorebox_red);
        btn_red_m1->setObjectName(QStringLiteral("btn_red_m1"));
        btn_red_m1->setGeometry(QRect(90, 50, 31, 23));
        btn_red_p1 = new QPushButton(scorebox_red);
        btn_red_p1->setObjectName(QStringLiteral("btn_red_p1"));
        btn_red_p1->setGeometry(QRect(130, 50, 31, 23));
        btn_red_p5 = new QPushButton(scorebox_red);
        btn_red_p5->setObjectName(QStringLiteral("btn_red_p5"));
        btn_red_p5->setGeometry(QRect(170, 50, 31, 23));
        btn_red_p10 = new QPushButton(scorebox_red);
        btn_red_p10->setObjectName(QStringLiteral("btn_red_p10"));
        btn_red_p10->setGeometry(QRect(210, 50, 31, 23));
        scorebox_yellow = new QGroupBox(centralWidget);
        scorebox_yellow->setObjectName(QStringLiteral("scorebox_yellow"));
        scorebox_yellow->setGeometry(QRect(460, 330, 251, 73));
        lbl_yellow_score = new QLabel(scorebox_yellow);
        lbl_yellow_score->setObjectName(QStringLiteral("lbl_yellow_score"));
        lbl_yellow_score->setGeometry(QRect(10, 20, 231, 23));
        btn_yellow_m10 = new QPushButton(scorebox_yellow);
        btn_yellow_m10->setObjectName(QStringLiteral("btn_yellow_m10"));
        btn_yellow_m10->setGeometry(QRect(10, 50, 31, 23));
        btn_yellow_m5 = new QPushButton(scorebox_yellow);
        btn_yellow_m5->setObjectName(QStringLiteral("btn_yellow_m5"));
        btn_yellow_m5->setGeometry(QRect(50, 50, 31, 23));
        btn_yellow_m1 = new QPushButton(scorebox_yellow);
        btn_yellow_m1->setObjectName(QStringLiteral("btn_yellow_m1"));
        btn_yellow_m1->setGeometry(QRect(90, 50, 31, 23));
        btn_yellow_p1 = new QPushButton(scorebox_yellow);
        btn_yellow_p1->setObjectName(QStringLiteral("btn_yellow_p1"));
        btn_yellow_p1->setGeometry(QRect(130, 50, 31, 23));
        btn_yellow_p5 = new QPushButton(scorebox_yellow);
        btn_yellow_p5->setObjectName(QStringLiteral("btn_yellow_p5"));
        btn_yellow_p5->setGeometry(QRect(170, 50, 31, 23));
        btn_yellow_p10 = new QPushButton(scorebox_yellow);
        btn_yellow_p10->setObjectName(QStringLiteral("btn_yellow_p10"));
        btn_yellow_p10->setGeometry(QRect(210, 50, 31, 23));
        scorebox_blue = new QGroupBox(centralWidget);
        scorebox_blue->setObjectName(QStringLiteral("scorebox_blue"));
        scorebox_blue->setGeometry(QRect(460, 410, 251, 73));
        lbl_blue_score = new QLabel(scorebox_blue);
        lbl_blue_score->setObjectName(QStringLiteral("lbl_blue_score"));
        lbl_blue_score->setGeometry(QRect(10, 20, 231, 23));
        btn_blue_m10 = new QPushButton(scorebox_blue);
        btn_blue_m10->setObjectName(QStringLiteral("btn_blue_m10"));
        btn_blue_m10->setGeometry(QRect(10, 50, 31, 23));
        btn_blue_m5 = new QPushButton(scorebox_blue);
        btn_blue_m5->setObjectName(QStringLiteral("btn_blue_m5"));
        btn_blue_m5->setGeometry(QRect(50, 50, 31, 23));
        btn_blue_m1 = new QPushButton(scorebox_blue);
        btn_blue_m1->setObjectName(QStringLiteral("btn_blue_m1"));
        btn_blue_m1->setGeometry(QRect(90, 50, 31, 23));
        btn_blue_p1 = new QPushButton(scorebox_blue);
        btn_blue_p1->setObjectName(QStringLiteral("btn_blue_p1"));
        btn_blue_p1->setGeometry(QRect(130, 50, 31, 23));
        btn_blue_p5 = new QPushButton(scorebox_blue);
        btn_blue_p5->setObjectName(QStringLiteral("btn_blue_p5"));
        btn_blue_p5->setGeometry(QRect(170, 50, 31, 23));
        btn_blue_p10 = new QPushButton(scorebox_blue);
        btn_blue_p10->setObjectName(QStringLiteral("btn_blue_p10"));
        btn_blue_p10->setGeometry(QRect(210, 50, 31, 23));
        scorebox_green = new QGroupBox(centralWidget);
        scorebox_green->setObjectName(QStringLiteral("scorebox_green"));
        scorebox_green->setGeometry(QRect(460, 490, 251, 73));
        lbl_green_score = new QLabel(scorebox_green);
        lbl_green_score->setObjectName(QStringLiteral("lbl_green_score"));
        lbl_green_score->setGeometry(QRect(10, 20, 231, 23));
        btn_green_m10 = new QPushButton(scorebox_green);
        btn_green_m10->setObjectName(QStringLiteral("btn_green_m10"));
        btn_green_m10->setGeometry(QRect(10, 50, 31, 23));
        btn_green_m5 = new QPushButton(scorebox_green);
        btn_green_m5->setObjectName(QStringLiteral("btn_green_m5"));
        btn_green_m5->setGeometry(QRect(50, 50, 31, 23));
        btn_green_m1 = new QPushButton(scorebox_green);
        btn_green_m1->setObjectName(QStringLiteral("btn_green_m1"));
        btn_green_m1->setGeometry(QRect(90, 50, 31, 23));
        btn_green_p1 = new QPushButton(scorebox_green);
        btn_green_p1->setObjectName(QStringLiteral("btn_green_p1"));
        btn_green_p1->setGeometry(QRect(130, 50, 31, 23));
        btn_green_p5 = new QPushButton(scorebox_green);
        btn_green_p5->setObjectName(QStringLiteral("btn_green_p5"));
        btn_green_p5->setGeometry(QRect(170, 50, 31, 23));
        btn_green_p10 = new QPushButton(scorebox_green);
        btn_green_p10->setObjectName(QStringLiteral("btn_green_p10"));
        btn_green_p10->setGeometry(QRect(210, 50, 31, 23));
        forbidden_answer_box = new QGroupBox(centralWidget);
        forbidden_answer_box->setObjectName(QStringLiteral("forbidden_answer_box"));
        forbidden_answer_box->setGeometry(QRect(730, 10, 371, 553));
        drd_questions = new QComboBox(forbidden_answer_box);
        drd_questions->setObjectName(QStringLiteral("drd_questions"));
        drd_questions->setGeometry(QRect(88, 30, 271, 23));
        lbl_question = new QLabel(forbidden_answer_box);
        lbl_question->setObjectName(QStringLiteral("lbl_question"));
        lbl_question->setGeometry(QRect(10, 30, 81, 23));
        lst_answers = new QListWidget(forbidden_answer_box);
        lst_answers->setObjectName(QStringLiteral("lst_answers"));
        lst_answers->setGeometry(QRect(1, 70, 370, 483));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QuizBro - QuizMaster", Q_NULLPTR));
        box_button_control->setTitle(QApplication::translate("MainWindow", "Button control:", Q_NULLPTR));
        lbl_fastest_press->setText(QApplication::translate("MainWindow", "Fastest press:", Q_NULLPTR));
        lbl_press_info->setText(QApplication::translate("MainWindow", "<name>", Q_NULLPTR));
        rb_buzzer_beater->setText(QApplication::translate("MainWindow", "\"Beat the buzzer\" Mode", Q_NULLPTR));
        rb_free_buzzer->setText(QApplication::translate("MainWindow", "\"Free buzzer\" Mode", Q_NULLPTR));
        btn_unlock_buzzers->setText(QApplication::translate("MainWindow", "Unlock buzzers", Q_NULLPTR));
        box_green_button->setTitle(QApplication::translate("MainWindow", "Green button", Q_NULLPTR));
        lbl_green_short_audio->setText(QApplication::translate("MainWindow", "Short audio:", Q_NULLPTR));
        lbl_green_long_audio->setText(QApplication::translate("MainWindow", "Long audio:", Q_NULLPTR));
        btn_green_set_short_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        btn_green_set_long_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        box_yellow_button->setTitle(QApplication::translate("MainWindow", "Yellow button", Q_NULLPTR));
        lbl_yellow_short_audio->setText(QApplication::translate("MainWindow", "Short audio:", Q_NULLPTR));
        lbl_yellow_long_audio->setText(QApplication::translate("MainWindow", "Long audio:", Q_NULLPTR));
        btn_yellow_set_short_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        btn_yellow_set_long_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        box_blue_button->setTitle(QApplication::translate("MainWindow", "Blue button", Q_NULLPTR));
        lbl_blue_short_audio->setText(QApplication::translate("MainWindow", "Short audio:", Q_NULLPTR));
        lbl_blue_long_audio->setText(QApplication::translate("MainWindow", "Long audio:", Q_NULLPTR));
        btn_blue_set_short_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        btn_blue_set_long_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        box_red_button->setTitle(QApplication::translate("MainWindow", "Red button", Q_NULLPTR));
        lbl_red_short_audio->setText(QApplication::translate("MainWindow", "Short audio:", Q_NULLPTR));
        lbl_red_long_audio->setText(QApplication::translate("MainWindow", "Long audio:", Q_NULLPTR));
        btn_red_set_short_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        btn_red_set_long_audio->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        box_audiocontrol->setTitle(QApplication::translate("MainWindow", "Audio control", Q_NULLPTR));
        lbl_now_playing->setText(QApplication::translate("MainWindow", "Now playing:", Q_NULLPTR));
        lbl_audio_info->setText(QApplication::translate("MainWindow", "<color/length>", Q_NULLPTR));
        rb_play_short->setText(QApplication::translate("MainWindow", "Play short fragment", Q_NULLPTR));
        rb_play_long->setText(QApplication::translate("MainWindow", "Play long fragment", Q_NULLPTR));
        chb_mute->setText(QApplication::translate("MainWindow", "Mute", Q_NULLPTR));
        chb_simultaneous->setText(QApplication::translate("MainWindow", "Allow simultaneous", Q_NULLPTR));
        box_blinkspeed->setTitle(QApplication::translate("MainWindow", "Blink speed", Q_NULLPTR));
        lbl_blinkspeed->setText(QApplication::translate("MainWindow", "1.0 sec", Q_NULLPTR));
        box_backgrounds->setTitle(QApplication::translate("MainWindow", "Background - (beamer: available?)", Q_NULLPTR));
        scorebox_red->setTitle(QApplication::translate("MainWindow", "Red score", Q_NULLPTR));
        lbl_red_score->setText(QApplication::translate("MainWindow", "Score: 0", Q_NULLPTR));
        btn_red_m10->setText(QApplication::translate("MainWindow", "-10", Q_NULLPTR));
        btn_red_m5->setText(QApplication::translate("MainWindow", "-5", Q_NULLPTR));
        btn_red_m1->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        btn_red_p1->setText(QApplication::translate("MainWindow", "+1", Q_NULLPTR));
        btn_red_p5->setText(QApplication::translate("MainWindow", "+5", Q_NULLPTR));
        btn_red_p10->setText(QApplication::translate("MainWindow", "+10", Q_NULLPTR));
        scorebox_yellow->setTitle(QApplication::translate("MainWindow", "Yellow score", Q_NULLPTR));
        lbl_yellow_score->setText(QApplication::translate("MainWindow", "Score: 0", Q_NULLPTR));
        btn_yellow_m10->setText(QApplication::translate("MainWindow", "-10", Q_NULLPTR));
        btn_yellow_m5->setText(QApplication::translate("MainWindow", "-5", Q_NULLPTR));
        btn_yellow_m1->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        btn_yellow_p1->setText(QApplication::translate("MainWindow", "+1", Q_NULLPTR));
        btn_yellow_p5->setText(QApplication::translate("MainWindow", "+5", Q_NULLPTR));
        btn_yellow_p10->setText(QApplication::translate("MainWindow", "+10", Q_NULLPTR));
        scorebox_blue->setTitle(QApplication::translate("MainWindow", "Blue score", Q_NULLPTR));
        lbl_blue_score->setText(QApplication::translate("MainWindow", "Score: 0", Q_NULLPTR));
        btn_blue_m10->setText(QApplication::translate("MainWindow", "-10", Q_NULLPTR));
        btn_blue_m5->setText(QApplication::translate("MainWindow", "-5", Q_NULLPTR));
        btn_blue_m1->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        btn_blue_p1->setText(QApplication::translate("MainWindow", "+1", Q_NULLPTR));
        btn_blue_p5->setText(QApplication::translate("MainWindow", "+5", Q_NULLPTR));
        btn_blue_p10->setText(QApplication::translate("MainWindow", "+10", Q_NULLPTR));
        scorebox_green->setTitle(QApplication::translate("MainWindow", "Green score", Q_NULLPTR));
        lbl_green_score->setText(QApplication::translate("MainWindow", "Score: 0", Q_NULLPTR));
        btn_green_m10->setText(QApplication::translate("MainWindow", "-10", Q_NULLPTR));
        btn_green_m5->setText(QApplication::translate("MainWindow", "-5", Q_NULLPTR));
        btn_green_m1->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        btn_green_p1->setText(QApplication::translate("MainWindow", "+1", Q_NULLPTR));
        btn_green_p5->setText(QApplication::translate("MainWindow", "+5", Q_NULLPTR));
        btn_green_p10->setText(QApplication::translate("MainWindow", "+10", Q_NULLPTR));
        forbidden_answer_box->setTitle(QApplication::translate("MainWindow", "Forbidden Answers", Q_NULLPTR));
        lbl_question->setText(QApplication::translate("MainWindow", "Question:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
