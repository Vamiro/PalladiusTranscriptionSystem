#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());

    Q_INIT_RESOURCE(icon);
    //setWindowIcon(QIcon(":/Icon.ico"));

    ui->spinBoxColumn->setMinimum(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::map<QString, QString> translitMap[] {
{
    {"chuang", "чуан"},
    {"zhuang", "чжуан"},
    {"shuang", "шуан"},
},

{
    {"chang", "чан"},
    {"cheng", "чэн"},
    {"chong", "чун"},
    {"chuai", "чуай"},
    {"chuan", "чуань"},
    {"diang", "дян"},
    {"guang", "гуан"},
    {"huang", "хуан"},
    {"jiang", "цзян"},
    {"jiong", "цзюн"},
    {"zhang", "чжан"},
    {"zheng", "чжэн"},
    {"zhong", "чжун"},
    {"zhuai", "чжуай"},
    {"zhuan", "чжуань"},
    {"kuang", "куан"},
    {"liang", "лян"},
    {"niang", "нян"},
    {"piang", "пян"},
    {"qiang", "цян"},
    {"qiong", "цюн"},
    {"shang", "шан"},
    {"sheng", "шэн"},
    {"shuai", "шуай"},
    {"shuan", "шуань"},
    {"tiang", "тян"},
    {"xiang", "сян"},
    {"xiong", "сюн"},
},

{
    {"bang", "бан"},
    {"beng", "бэн"},
    {"bian", "бянь"},
    {"biao", "бяо"},
    {"bing", "бин"},
    {"cang", "цан"},
    {"ceng", "цэн"},
    {"cong", "цун"},
    {"cuan", "цуань"},
    {"chai", "чай"},
    {"chan", "чань"},
    {"chao", "чао"},
    {"chen", "чэнь"},
    {"chou", "чоу"},
    {"chua", "чуа"},
    {"chui", "чуй"},
    {"chun", "чунь"},
    {"chuo", "чо"},
    {"dang", "дан"},
    {"deng", "дэн"},
    {"dian", "дянь"},
    {"diao", "дяо"},
    {"ding", "дин"},
    {"dong", "дун"},
    {"duan", "дуань"},
    {"fang", "фан"},
    {"feng", "фэн"},
    {"fiao", "фяо"},
    {"gang", "ган"},
    {"geng", "гэн"},
    {"gong", "гун"},
    {"guai", "гуай"},
    {"guan", "гуань"},
    {"hang", "хан"},
    {"heng", "хэн"},
    {"hong", "хун"},
    {"huai", "хуай"},
    {"huan", "хуань"},
    {"jian", "цзянь"},
    {"jiao", "цзяо"},
    {"jing", "цзин"},
    {"juan", "цзюань"},
    {"kang", "кан"},
    {"zang", "цзан"},
    {"zeng", "цзэн"},
    {"zong", "цзун"},
    {"zuan", "цзуань"},
    {"zhai", "чжай"},
    {"zhan", "чжань"},
    {"zhao", "чжао"},
    {"zhei", "чжэй"},
    {"zhen", "чжэнь"},
    {"zhou", "чжоу"},
    {"zhua", "чжуа"},
    {"zhui", "чжуй"},
    {"zhun", "чжунь"},
    {"zhuo", "чжо"},
    {"keng", "кэн"},
    {"kong", "кун"},
    {"kuai", "куай"},
    {"kuan", "куань"},
    {"lang", "лан"},
    {"leng", "лэн"},
    {"lian", "лянь"},
    {"liao", "ляо"},
    {"ling", "лин"},
    {"long", "лун"},
    {"luan", "луань"},
    {"lüan", "люань"},
    {"mang", "ман"},
    {"meng", "мэн"},
    {"mian", "мянь"},
    {"miao", "мяо"},
    {"ming", "мин"},
    {"nang", "нан"},
    {"neng", "нэн"},
    {"nian", "нянь"},
    {"niao", "няо"},
    {"ning", "нин"},
    {"nong", "нун"},
    {"nuan", "нуань"},
    {"pang", "пан"},
    {"peng", "пэн"},
    {"pian", "пянь"},
    {"piao", "пяо"},
    {"ping", "пин"},
    {"qian", "цянь"},
    {"qiao", "цяо"},
    {"qing", "цин"},
    {"quan", "цюань"},
    {"rang", "жан"},
    {"reng", "жэн"},
    {"rong", "жун"},
    {"ruan", "жуань"},
    {"sang", "сан"},
    {"seng", "сэн"},
    {"song", "сун"},
    {"suan", "суань"},
    {"shai", "шай"},
    {"shan", "шань"},
    {"shao", "шао"},
    {"shei", "шэй"},
    {"shen", "шэнь"},
    {"shou", "шоу"},
    {"shua", "шуа"},
    {"shui", "шуй"},
    {"shun", "шунь"},
    {"shuo", "шо"},
    {"tang", "тан"},
    {"teng", "тэн"},
    {"tian", "тянь"},
    {"tiao", "тяо"},
    {"ting", "тин"},
    {"tong", "тун"},
    {"tuan", "туань"},
    {"wang", "ван"},
    {"weng", "вэн"},
    {"xian", "сянь"},
    {"xiao", "сяо"},
    {"xing", "син"},
    {"xuan", "сюань"},
    {"yang", "ян"},
    {"ying", "ин"},
    {"yong", "юн"},
    {"yuan", "юань"},
},

{
    {"ang", "ан"},
    {"bai", "бай"},
    {"ban", "бань"},
    {"bao", "бао"},
    {"bei", "бэй"},
    {"ben", "бэнь"},
    {"bie", "бе"},
    {"bin", "бинь"},
    {"cai", "цай"},
    {"can", "цань"},
    {"cao", "цао"},
    {"cei", "цэй"},
    {"cen", "цэнь"},
    {"cou", "цоу"},
    {"cui", "цуй"},
    {"cun", "цунь"},
    {"cuo", "цо"},
    {"cha", "ча"},
    {"che", "чэ"},
    {"chi", "чи"},
    {"chu", "чу"},
    {"dai", "дай"},
    {"dan", "дань"},
    {"dao", "дао"},
    {"dei", "дэй"},
    {"den", "дэнь"},
    {"dia", "дя"},
    {"die", "де"},
    {"diu", "дю"},
    {"dou", "доу"},
    {"dui", "дуй"},
    {"dun", "дунь"},
    {"duo", "до"},
    {"eng", "эн"},
    {"fan", "фань"},
    {"fei", "фэй"},
    {"fen", "фэнь"},
    {"fou", "фоу"},
    {"gai", "гай"},
    {"gan", "гань"},
    {"gao", "гао"},
    {"gei", "гэй"},
    {"gen", "гэнь"},
    {"gou", "гоу"},
    {"gua", "гуа"},
    {"gui", "гуй"},
    {"gun", "гунь"},
    {"guo", "го"},
    {"hai", "хай"},
    {"han", "хань"},
    {"hao", "хао"},
    {"hei", "хэй"},
    {"hen", "хэнь"},
    {"hng", "хн"},
    {"hou", "хоу"},
    {"hua", "хуа"},
    {"hui", "хуэй"},
    {"hun", "хунь"},
    {"huo", "хо"},
    {"jia", "цзя"},
    {"jie", "цзе"},
    {"jin", "цзинь"},
    {"jiu", "цзю"},
    {"jue", "цзюэ"},
    {"jun", "цзюнь"},
    {"kai", "кай"},
    {"kan", "кань"},
    {"kao", "као"},
    {"yun", "юнь"},
    {"zai", "цзай"},
    {"zan", "цзань"},
    {"zao", "цзао"},
    {"zei", "цзэй"},
    {"zem", "цзэм"},
    {"zen", "цзэнь"},
    {"zou", "цзоу"},
    {"zui", "цзуй"},
    {"zun", "цзунь"},
    {"zuo", "цзо"},
    {"zha", "чжа"},
    {"zhe", "чжэ"},
    {"zhi", "чжи"},
    {"zhu", "чжу"},
    {"kei", "кэй"},
    {"ken", "кэнь"},
    {"kou", "коу"},
    {"kua", "куа"},
    {"kui", "куй"},
    {"kun", "кунь"},
    {"kuo", "ко"},
    {"lai", "лай"},
    {"lan", "лань"},
    {"lao", "лао"},
    {"lei", "лэй"},
    {"lia", "ля"},
    {"lie", "ле"},
    {"lin", "линь"},
    {"liu", "лю"},
    {"lou", "лоу"},
    {"lüe", "люэ"},
    {"lun", "лунь"},
    {"lün", "люнь"},
    {"luo", "ло"},
    {"mai", "май"},
    {"man", "мань"},
    {"mao", "мао"},
    {"mei", "мэй"},
    {"men", "мэнь"},
    {"mie", "ме"},
    {"min", "минь"},
    {"miu", "мю"},
    {"mou", "моу"},
    {"nai", "най"},
    {"nan", "нань"},
    {"nao", "нао"},
    {"nei", "нэй"},
    {"nen", "нэнь"},
    {"nia", "ня"},
    {"nie", "не"},
    {"nin", "нинь"},
    {"niu", "ню"},
    {"nou", "ноу"},
    {"nun", "нунь"},
    {"nüe", "нюэ"},
    {"nuo", "но"},
    {"pai", "пай"},
    {"pan", "пань"},
    {"pao", "пао"},
    {"pei", "пэй"},
    {"pen", "пэнь"},
    {"pie", "пе"},
    {"pin", "пинь"},
    {"pou", "поу"},
    {"qia", "ця"},
    {"qie", "це"},
    {"qin", "цинь"},
    {"qiu", "цю"},
    {"que", "цюэ"},
    {"qun", "цюнь"},
    {"ran", "жань"},
    {"rao", "жао"},
    {"rem", "жэм"},
    {"ren", "жэнь"},
    {"rou", "жоу"},
    {"rua", "жуа"},
    {"rui", "жуй"},
    {"run", "жунь"},
    {"ruo", "жо"},
    {"sai", "сай"},
    {"san", "сань"},
    {"sao", "сао"},
    {"sei", "сэй"},
    {"sen", "сэнь"},
    {"sou", "соу"},
    {"sui", "суй"},
    {"sun", "сунь"},
    {"suo", "со"},
    {"sha", "ша"},
    {"she", "шэ"},
    {"shi", "ши"},
    {"shu", "шу"},
    {"tai", "тай"},
    {"tan", "тань"},
    {"tao", "тао"},
    {"tei", "тэй"},
    {"ten", "тэнь"},
    {"tie", "те"},
    {"tou", "тоу"},
    {"tui", "туй"},
    {"tun", "тунь"},
    {"tuo", "то"},
    {"wai", "вай"},
    {"wan", "вань"},
    {"wao", "вао"},
    {"wei", "вэй"},
    {"wen", "вэнь"},
    {"xia", "ся"},
    {"xie", "се"},
    {"xin", "синь"},
    {"xiu", "сю"},
    {"xue", "сюэ"},
    {"xun", "сюнь"},
    {"yai", "яй"},
    {"yan", "янь"},
    {"yao", "яо"},
    {"yin", "инь"},
    {"you", "ю"},
    {"yue", "юэ"},
},

{
    {"ai", "ай"},
    {"an", "ань"},
    {"ao", "ао"},
    {"ba", "ба"},
    {"bi", "би"},
    {"bo", "бо"},
    {"bu", "бу"},
    {"ca", "ца"},
    {"ce", "цэ"},
    {"ci", "цы"},
    {"cu", "цу"},
    {"da", "да"},
    {"de", "дэ"},
    {"di", "ди"},
    {"du", "ду"},
    {"ei", "эй"},
    {"en", "энь"},
    {"er", "эр"},
    {"fa", "фа"},
    {"fo", "фо"},
    {"fu", "фу"},
    {"ga", "га"},
    {"ge", "гэ"},
    {"go", "го"},
    {"gu", "гу"},
    {"ha", "ха"},
    {"he", "хэ"},
    {"hm", "хм"},
    {"hu", "ху"},
    {"ji", "цзи"},
    {"ju", "цзюй"},
    {"ka", "ка"},
    {"za", "цза"},
    {"ze", "цзэ"},
    {"zi", "цзы"},
    {"zu", "цзу"},
    {"ke", "кэ"},
    {"ku", "ку"},
    {"la", "ла"},
    {"le", "лэ"},
    {"li", "ли"},
    {"lo", "ло"},
    {"lu", "лу"},
    {"lü", "люй"},
    {"ma", "ма"},
    {"me", "мэ"},
    {"mi", "ми"},
    {"mm", "мм"},
    {"mo", "мо"},
    {"mu", "му"},
    {"na", "на"},
    {"ne", "нэ"},
    {"ng", "нг"},
    {"ni", "ни"},
    {"nu", "ну"},
    {"nü", "нюй"},
    {"ou", "оу"},
    {"pa", "па"},
    {"pi", "пи"},
    {"po", "по"},
    {"pu", "пу"},
    {"qi", "ци"},
    {"qu", "цюй"},
    {"re", "жэ"},
    {"ri", "жи"},
    {"ru", "жу"},
    {"sa", "са"},
    {"se", "сэ"},
    {"si", "сы"},
    {"su", "су"},
    {"ta", "та"},
    {"te", "тэ"},
    {"ti", "ти"},
    {"tu", "ту"},
    {"wa", "ва"},
    {"wo", "во"},
    {"wu", "у"},
    {"xi", "си"},
    {"xu", "сюй"},
    {"ya", "я"},
    {"ye", "е"},
    {"yi", "и"},
    {"yo", "йо"},
    {"yu", "юй"},
},

{
    {"a", "а"},
    {"e", "э"},
    {"ê", "эй"},
    {"m", "м"},
    {"n", "н"},
    {"o", "о"},
}
};

QString MainWindow::translitText(const QString& text){
    QStringList qStrList = text.simplified().split(qRegExp, Qt::SkipEmptyParts);

    for(int i = 0; i < qStrList.size(); i++){
        QString tmp = translitWord(qStrList[i]);

        if (!tmp.isEmpty()){
            qStrList[i] = tmp;
            qStrList[i][0] = qStrList[i][0].toUpper();
        }
        else{
            return "";
        }
    }

    return qStrList.join(' ');
}

QString MainWindow::translitWord(const QString& word) {
    QStringList qStrList = word.toLower().split('\'', Qt::SkipEmptyParts);
    for(int i = 0; i < qStrList.size(); i++){
        qStrList[i] = translitWord_(qStrList[i]);
        if(qStrList[i].isEmpty()) return "";
    }
    return qStrList.join("");
}

QString MainWindow::translitWord_(const QString& word) {
    int len = word.size();

    for (int i = std::min(len, 6); i > 0; i--)
    {
        auto iter = translitMap[6 - i].find(word.first(i));
        if (iter != translitMap[6 - i].end()) {
            if (len > i) {
                QString result = translitWord_(word.last(len - i));
                if (!result.isEmpty()) {
                    return iter->second + result;
                }
            } else {
                return iter->second;
            }
        }
    }
    return QString("");
}

void MainWindow::on_openFileAction_triggered() {
    QString userProfile = std::getenv("USERPROFILE");
    userProfile.append("\\Downloads");
    QString qfile = QFileDialog::getOpenFileName(this, tr("Открыть файл"), userProfile , "Excel Files (*.xlsx *.xls)");
    if(!qfile.isEmpty()){
        file = qfile;
        openSelectedFile();
    }
}

void MainWindow::on_openFileButton_clicked(){
    on_openFileAction_triggered();
}

void MainWindow::openSelectedFile() {
    if(xlFile.isOpen()){
        xlFile.close();
    }

    ui->tableWidget->clear();

    ui->openAndTranslitButton->setEnabled(false);

    ui->lineNameNewSheet->clear();
    ui->lineNameNewSheet->setEnabled(false);

    {
        const QSignalBlocker workSheetSelect_blocker(ui->workSheetSelect);
        ui->workSheetSelect->clear();
        ui->workSheetSelect->setEnabled(false);
    }

    ui->spinBoxColumn->setValue(1);
    ui->spinBoxColumn->setEnabled(false);

    ui->saveButton->setEnabled(false);

    selectedColumn = 0;

    xlFile.open(file.toStdString());

    if(xlFile.isOpen()){
        auto sheetNames = xlFile.workbook().worksheetNames();

        for(auto& sheetName: sheetNames){
            ui->workSheetSelect->addItem(QString::fromStdString(sheetName));
        }
        ui->openAndTranslitButton->setEnabled(true);
        ui->workSheetSelect->setEnabled(true);
        ui->spinBoxColumn->setEnabled(true);
    }
    else{
        QMessageBox::critical(this, "error", "Excel file can not be opened.");
    }
}

void MainWindow::on_workSheetSelect_currentTextChanged(const QString& newSheetName) {
    currentSheet = xlFile.workbook().worksheet(newSheetName.toStdString());
    currentSheet.setSelected(true);
    ui->spinBoxColumn->setMaximum(currentSheet.columnCount());
}

void MainWindow::on_openAndTranslitButton_clicked() {
    ui->tableWidget->clear();

    if(currentSheet.isSelected()){
        int numRows = currentSheet.rowCount();
        int col = ui->spinBoxColumn->value();

        ui->tableWidget->setRowCount(numRows);
        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->setColumnWidth(0, 198);
        ui->tableWidget->setColumnWidth(1, 198);


        for (int row = 1; row <= numRows; ++row) {
            if(currentSheet.cell(row, col).value().type() == OpenXLSX::XLValueType::String) {
                QString cellValue = QString::fromStdString(currentSheet.cell(row, col).value());

                if(!cellValue.isNull() || !cellValue.isEmpty()) {
                    QTableWidgetItem *item = new QTableWidgetItem(cellValue);
                    ui->tableWidget->setItem(row - 1, 0, item);
                    QString translited = translitText(cellValue);

                    if(translited.isEmpty()){
                        item = new QTableWidgetItem(cellValue);
                        ui->tableWidget->setItem(row - 1, 1, item);
                        ui->tableWidget->item(row - 1, 1)->setBackground(Qt::darkRed);
                    }
                    else{
                        item = new QTableWidgetItem(translited);
                        ui->tableWidget->setItem(row - 1, 1, item);
                        if(cellValue.contains(qRegExpIgnore)){
                            ui->tableWidget->item(row - 1, 1)->setBackground(Qt::darkYellow);
                        }
                    }
                }
            }
        }
        ui->lineNameNewSheet->setText("Translited " + QString::fromStdString(currentSheet.name()));
        ui->saveButton->setEnabled(true);
        ui->lineNameNewSheet->setEnabled(true);
    }
}

void MainWindow::on_saveButton_clicked(){
    if(xlFile.isOpen()){
        QString newSheetName = ui->lineNameNewSheet->text();

        //////////////////////////////////////////////////////////////////////
        QString newSheetNameBuf = newSheetName;
        for (int copyCounter = 0; xlFile.workbook().worksheetExists(newSheetNameBuf.toStdString()); copyCounter++){
            newSheetNameBuf = newSheetName + " copy";
            if(copyCounter != 0){
                newSheetNameBuf.append(std::to_string(copyCounter));
            }
        }
        newSheetName = newSheetNameBuf;
        //////////////////////////////////////////////////////////////////////

        xlFile.workbook().addWorksheet(newSheetName.toStdString());
        OpenXLSX::XLWorksheet newSheet = xlFile.workbook().worksheet(newSheetName.toStdString());
        newSheet.setSelected(true);

        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            if(ui->tableWidget->item(i, 1) != nullptr){
                newSheet.cell(i + 1, 1).value() = ui->tableWidget->item(i, 0)->text().toStdString();
                newSheet.cell(i + 1, 2).value() = ui->tableWidget->item(i, 1)->text().toStdString();
            }
        }
        xlFile.save();
        newSheet.setSelected(false);
        QMessageBox::information(this, "Сохранение", "Файл успешно сохранен.\nДобавлен новый лист: " + newSheetName);
        openSelectedFile();
    }
}

void MainWindow::on_translitButton_clicked() {
    QString result = ui->inputTranslit->text();
    if(!result.isEmpty()){
        result = translitText(result);
        if(result.isEmpty()) result = "Ошибка перевода";
    }
    ui->outputTranslit->setText(result);
}

void MainWindow::on_aboutAction_triggered() {
    QMessageBox::information(this, "О программе", "Palladius Transcription System\n"
                                                  "Copyright (C) 2023, VamiroCP");
}

void MainWindow::on_instructAction_triggered() {
    QMessageBox::information(this, "Инструкция", "Ячейка \"красного\" цвета - перевода не существует.\n"
                                                  "Ячейка \"желтого\" цвета - перевод может быть неккоректным.\n");
}

void MainWindow::on_instructButton_clicked() {
    on_instructAction_triggered();
}

//void MainWindow::on_createFileAction_triggered(){
//    QString userProfile = std::getenv("USERPROFILE");
//    userProfile.append("\\Downloads");
//    QString qfile = QFileDialog::getSaveFileName(this, tr("Создать файл"), userProfile , "Excel Files (*.xlsx *.xls)");
//    if (!qfile.isEmpty()){
//        QMessageBox::information(this, "Создание", "Файл успешно создан: " + qfile);
//        file = qfile;
//        OpenXLSX::XLDocument().create(file.toStdString());
//        openSelectedFile();
//    }
//}
