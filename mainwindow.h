#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include <QtCore>
#include <Qdialog>

#include "QWebView"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void urlchanged();

    void adjustTitle();

    void finishLoading(bool);

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_webView_5_linkClicked(const QUrl link);







    void on_webView_2_urlChanged(const QUrl urll);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_webView_7_linkClicked(const QUrl theurl);

    void on_webView_5_destroyed();

    void on_pushButton_6_clicked();






    void on_webView_4_selectionChanged();

    void on_webView_7_selectionChanged();

    void on_tabWidget_tabCloseRequested(int tabreq);

    void on_webView_destroyed();

private:
    Ui::MainWindow *ui;
         QList<QWebView*> buttons;

};

#endif // MAINWINDOW_H
