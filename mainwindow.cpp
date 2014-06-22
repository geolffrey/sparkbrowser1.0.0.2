#include "mainwindow.h"
#include "ui_mainwindow.h"

// example tab layout


int total = 0 ;
int current = 0;
int selectedpast = 0;
QUrl*newtabhome = new QUrl ("");
QString newtab = "google";
QString homepage = "http://google.com";





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView_7->setVisible(false);
    ui->webView_5->setVisible(false);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    ui->webView->settings()->setAttribute(QWebSettings::DnsPrefetchEnabled,true);
    ui->webView_2->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView_2->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView_2->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webView_2->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    ui->webView_2->settings()->setAttribute(QWebSettings::DnsPrefetchEnabled,true);
    ui->webView_2->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView_3->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView_3->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webView_3->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    ui->webView_3->settings()->setAttribute(QWebSettings::DnsPrefetchEnabled,true);
    ui->webView_4->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView_4->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView_4->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    ui->webView_4->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    ui->webView_4->settings()->setAttribute(QWebSettings::DnsPrefetchEnabled,true);


// end of initinalizing quad view plugins/ prefetching    

    QWebView*webview11 = new QWebView;

      buttons.append(webview11);


   ui->verticalLayout->addWidget(webview11);



   connect(buttons[current], SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));

   connect(buttons[current], SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));




  buttons[total]->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
  buttons[total]->load(QUrl("qrc:/home.html"));
  buttons[total]->show();
      buttons[total]->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
     buttons[total]->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
      buttons[total]->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
      buttons[total]->settings()->setAttribute(QWebSettings::DnsPrefetchEnabled,true);

      buttons[total]->setRenderHints(QPainter::Antialiasing);

    ui->webView_5->page()->setLinkDelegationPolicy(QWebPage:: DelegateAllLinks);
     ui->webView_7->page()->setLinkDelegationPolicy(QWebPage:: DelegateAllLinks);

    ui->widget_3->setVisible(false);
   ui->tabWidget->setTabText(current,(buttons[current]->title()).mid(0,20));



}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::finishLoading(bool)
{
    setWindowTitle(buttons[current]->title());
    ui->tabWidget->setTabText(current,(buttons[current]->title()).mid(0,20));

}
void MainWindow::adjustTitle()
{

}
void MainWindow::urlchanged()
{

}


void MainWindow::on_pushButton_9_clicked()
{
    if (ui->webView_5->isVisible() == true)
    {
        ui->webView_5->setVisible(false);
    }

    else
    {
        ui->webView_5->setVisible(true);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if (ui->widget_3->isVisible()==false)
    {
        ui->webView->setZoomFactor(.5);
        ui->webView_2->setZoomFactor(.5);
        ui->webView_3->setZoomFactor(.5);
        ui->webView_4->setZoomFactor(.5);
        ui->widget_3->setVisible(true);
        buttons[current]->setVisible(false);
       ui->webView->setVisible(true);
       ui->webView_2->setVisible(true);
       ui->webView_3->setVisible(true);
       ui->webView_4->setVisible(true);
       ui->webView_7->setVisible(true);
    }
    else
    {
        ui->webView_7->setVisible(false);
        ui->webView->setZoomFactor(.5);
        ui->webView_2->setZoomFactor(.5);
        ui->webView_3->setZoomFactor(.5);
        ui->webView_4->setZoomFactor(.5);
        ui->webView->setVisible(true);
        ui->webView_2->setVisible(true);
        ui->webView_3->setVisible(true);
        ui->webView_4->setVisible(true);
        ui->widget_3->setVisible(false);
        buttons[current]->setVisible(true);
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{


    if (index == total+1)
    {
        total = total+1;

        QWebView*webview11 = new QWebView;

          buttons.append(webview11);


       ui->verticalLayout->addWidget(webview11);
       buttons[total]->show();

        buttons[current]->setVisible(false);


        buttons[total]->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
        // buttons[total]->load(QUrl("qrc:/home.html"));
        buttons[total]->load(QUrl("http://google.com"));
          buttons[total]->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
         buttons[total]->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
          buttons[total]->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
          buttons[total]->settings()->setAttribute(QWebSettings::DnsPrefetchEnabled,true);

        ui->webView_5->page()->setLinkDelegationPolicy(QWebPage:: DelegateAllLinks);

        ui->widget_3->setVisible(false);
        current = total;
        connect(buttons[current], SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));

        ui->tabWidget->setTabText(current,newtab.mid(0,20));
        QTabWidget*tab = new QTabWidget;

        ui->tabWidget->addTab(tab, tr("+"));
        setWindowTitle(newtab);

    }
    else
    {

        buttons[current]->setVisible(false);
        buttons[index]->setVisible(true);
        current = index;
        connect(buttons[current], SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));
        ui->tabWidget->setTabText(current,(buttons[current]->title()).mid(0,20));

        setWindowTitle(buttons[current]->title());


    }
}

void MainWindow::on_webView_5_linkClicked(const QUrl link)
{
    buttons[current]->load(link);
}





void MainWindow::on_webView_2_urlChanged(const QUrl urll)
{
    ui->lineEdit->setText(urll.toString());
}

void MainWindow::on_pushButton_2_clicked()
{
    buttons[current]->load(QUrl("http://google.com"));
}

void MainWindow::on_pushButton_4_clicked()
{
    buttons[current]->back();
}

void MainWindow::on_pushButton_3_clicked()
{
    buttons[current]->forward();
}

void MainWindow::on_pushButton_clicked()
{
    buttons[current]->reload();
}

void MainWindow::on_webView_7_linkClicked(const QUrl theurl)
{
    if (theurl == QUrl("http://yahoo.com/"))
    {
        ui->webView->setZoomFactor(.5);
        ui->webView->setVisible(true);
        ui->webView_2->setZoomFactor(.5);
        ui->webView_2->setVisible(true);
        ui->webView_3->setZoomFactor(.5);
        ui->webView_3->setVisible(true);
        ui->webView_4->setZoomFactor(.5);
        ui->webView_4->setVisible(true);

    }

    if (theurl == QUrl("http://yahoo1.com/"))
    {
       ui->webView->setZoomFactor(1);
       ui->webView->setVisible(true);
       ui->webView_2->setVisible(false);
       ui->webView_3->setVisible(false);
       ui->webView_4->setVisible(false);
    }
    if (theurl == QUrl("http://yahoo2.com/"))
    {
        ui->webView_2->setZoomFactor(1);
        ui->webView->setVisible(false);
        ui->webView_2->setVisible(true);
        ui->webView_3->setVisible(false);
        ui->webView_4->setVisible(false);

    }
    if (theurl == QUrl("http://yahoo3.com/"))
    {
        ui->webView_4->setZoomFactor(1);
        ui->webView->setVisible(false);
        ui->webView_2->setVisible(false);
        ui->webView_3->setVisible(false);
        ui->webView_4->setVisible(true);
    }
    if (theurl == QUrl("http://yahoo4.com/"))
    {
        ui->webView_3->setZoomFactor(1);
        ui->webView->setVisible(false);
        ui->webView_2->setVisible(false);
        ui->webView_3->setVisible(true);
        ui->webView_4->setVisible(false);

    }


}


void MainWindow::on_webView_5_destroyed()
{

}

void MainWindow::on_pushButton_6_clicked()
{


}





void MainWindow::on_webView_4_selectionChanged()
{

}

void MainWindow::on_webView_7_selectionChanged()
{

}

void MainWindow::on_tabWidget_tabCloseRequested(int tabreq)
{




    if (total == 0)
    {

    }
    else
    {

        if (tabreq == total)
        {
            ui->tabWidget->removeTab(tabreq-1);
            buttons[total]->hide();
            buttons.removeAt(total);
            total=total-1;

        }
        else
        {


    if (tabreq != total+1)
   {


       if (tabreq != current)
       {
           if (tabreq>current)
           {
                ui->tabWidget->removeTab(tabreq);
                buttons[tabreq]->setVisible(false);
                //current = current-1;
                buttons.removeAt(tabreq);
                buttons[current]->setVisible(true);
                ui->tabWidget->setTabText(current,(buttons[current]->title()).mid(0,20));
                total= total-1;
           }
           else
           {
               ui->tabWidget->removeTab(tabreq);
               buttons[tabreq]->setVisible(false);
                current = current-1;
                buttons.removeAt(tabreq);
                buttons[current]->setVisible(true);
                ui->tabWidget->setTabText(current,(buttons[current]->title()).mid(0,20));
                total= total-1;
           }
       }
       else
       {
           ui->tabWidget->removeTab(tabreq);
            buttons[tabreq]->setVisible(false);
            buttons.removeAt(tabreq);
            buttons[current]->setVisible(true);
            ui->tabWidget->setTabText(current,(buttons[current]->title()).mid(0,20));
            total= total-1;
       }

     }




    else
    {

    }

}
    }//end of else








}  //end of the part

void MainWindow::on_webView_destroyed()
{

}
