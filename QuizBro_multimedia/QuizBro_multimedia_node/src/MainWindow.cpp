#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_central_pane = new QWidget;
    this->setCentralWidget(m_central_pane);
    
    m_images = new ImagePane(m_central_pane);
    m_images->setObjectName(QStringLiteral("m_images"));

    m_videos = new VideoPane(m_central_pane);
    m_videos->setObjectName(QStringLiteral("m_videos"));
    m_videos->hide();

    QRect window_rect(QPoint(), QSize(1376, 768));
    window_rect.moveCenter(QApplication::desktop()->availableGeometry().center());
    this->setGeometry(window_rect);
}

MainWindow::~MainWindow()
{
    delete m_images;
    delete m_central_pane;
}

void MainWindow::display_image(const QString &file)
{
    //overgang?
    m_videos->hide();
    m_images->show();

    m_images->display_image(file);
}

void MainWindow::display_video(const QString &file)
{
    //overgang?
    m_images->hide();
    m_videos->show();

    m_videos->display_video(file);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_images->setGeometry(0, 0, event->size().width(), event->size().height());
    m_videos->setGeometry(0, 0, event->size().width(), event->size().height());
}