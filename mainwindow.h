﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>


namespace Ui {
class MainWindow;
}


class QPicThread;
class QGraphicsScene;
class QTreeWidgetItem;
class QGraphicsView;
class QLabel;

struct DisplayImage
{
    DisplayImage();
    ~DisplayImage();
    QString fileName;
    QImage *image{nullptr};
    QGraphicsScene *scene{nullptr};
};

struct TreeViewImageInfo
{
    QString   fileName;
    int       width;
    int       height;
    int       component;
    QFileInfo fileInfo;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetGroupResult(const std::vector<std::vector<TreeViewImageInfo>> & group) { pictureGroup = group; }
    void RefreshGraphicImage(const QString &filename, DisplayImage *img, QGraphicsView *view, QLabel *filenameLabel, bool loadFile = true);

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void closeEvent(QCloseEvent *event);

private:
    void InitMenuBar();
    void InitStatusBar();
    QString GetSizeString(qint64 size);

public slots:
    void OnPictureProcessFinish();
    void OnTableItemClicked(bool left, QTreeWidgetItem* item, int colume);
    void MenuAct_Exit();
    void MenuAct_About();
    void MenuAct_StopSearch();
    void MenuAct_Option();
    void MenuAct_DeleteCheckedFile();
    void MenuAct_CheckAll();
    void MenuAct_UncheckAll();
    void MenuAct_ResetCheck();
    void MenuAct_RemoveSelectRecord();

private slots:
    void on_addPath_Btn_clicked();
    void on_removePath_Btn_clicked();
    void on_startSearchBtn_clicked();

private:
    Ui::MainWindow *ui;
    DisplayImage imageLeft, imageRight;
    QPicThread *procThread;

    float Threshold;
    std::vector<std::vector<TreeViewImageInfo>> pictureGroup;
};

#endif // MAINWINDOW_H
