#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <OpenXLSX.hpp>
#include <QTableWidget>
#include <QMessageBox>
#include <QDebug>
#include <QInputDialog>
#include <cctype>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //translit file
    void on_openFileAction_triggered();
    void on_openFileButton_clicked();
    //void on_createFileAction_triggered();
    void on_openAndTranslitButton_clicked();
    void on_saveButton_clicked();
    void on_workSheetSelect_currentTextChanged(const QString& newSheetName);
    //translit text
    void on_translitButton_clicked();
    //about window
    void on_aboutAction_triggered();
    void on_instructAction_triggered();
    void on_instructButton_clicked();

private:
    Ui::MainWindow *ui;
    void openSelectedFile();
    QString translitText(const QString& text);
    QString translitWord(const QString& word);
    QString translitWord_(const QString& word);
    OpenXLSX::XLDocument xlFile;
    OpenXLSX::XLWorksheet currentSheet;
    QString file;
    int selectedColumn;
    QRegularExpression qRegExp = QRegularExpression("[^a-zA-Z']+");
    QRegularExpression qRegExpIgnore = QRegularExpression("[^a-zA-Z',\\s]");
};
#endif // MAINWINDOW_H
