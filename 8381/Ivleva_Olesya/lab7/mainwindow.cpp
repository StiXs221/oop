#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->print->setReadOnly(true);
    ui->print_item->setReadOnly(true);
    set_disabled(true);
    QPixmap bkgnd(":/icons/land.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->menu->setPalette(QPalette(QColor(248, 251, 234)));
    facade = nullptr;
    //facade = new Facade(ui, field);
}

MainWindow::~MainWindow()
{
    delete facade;
    delete ui;
}

void MainWindow::set_disabled(bool flag)
{
    ui->attack->setDisabled(flag);
    ui->bonus->setDisabled(flag);
    ui->add_green_dr->setDisabled(flag);
    ui->add_red_dr->setDisabled(flag);
    ui->add_sen_fire->setDisabled(flag);
    ui->add_sen_lion->setDisabled(flag);
    ui->add_war_fight->setDisabled(flag);
    ui->add_war_ronin->setDisabled(flag);
    // все кнопки, которые надо выключить
}

void MainWindow::on_add_green_dr_clicked()
{
    facade->add_green_dr();
}

void MainWindow::on_add_red_dr_clicked()
{
    facade->add_red_dr();
}

void MainWindow::on_delete_item_clicked()
{
    facade->delete_item();
}

void MainWindow::on_move_unit_clicked()
{
    facade->move_unit();
}

void MainWindow::on_add_war_fight_clicked()
{
    facade->add_war_fight();
}

void MainWindow::on_add_war_ronin_clicked()
{
    facade->add_war_ronin();
}

void MainWindow::on_add_sen_fire_clicked()
{
    facade->add_sen_fire();
}

void MainWindow::on_add_sen_lion_clicked()
{
    facade->add_sen_lion();
}

void MainWindow::on_bonus_clicked()
{
    facade->bonus();
}

void MainWindow::on_action_triggered()
{
    facade->print_base();
}

void MainWindow::on_attack_clicked()
{
    if (facade->attack()) {
        set_disabled(true);
        //заблокировать все кнопки
    }
}

void MainWindow::on_action_2_triggered()
{
    facade->set_flag(1);
}

void MainWindow::on_action_3_triggered()
{
    facade->set_flag(2);
}

void MainWindow::on_action_5_triggered()
{
    facade->set_form(2);
}

void MainWindow::on_action_4_triggered()
{
    facade->set_form(1);
}

void MainWindow::on_action_6_triggered()
{
    facade->save();
}

void MainWindow::on_action_7_triggered()
{
    facade->read();
}

void MainWindow::on_action_8_triggered()
{
    f_game = 1;
    if (facade)
        delete facade;
    facade = new Facade(ui, 1);
    set_disabled(false);
}

void MainWindow::on_action_9_triggered()
{
    f_game = 2;
    if (facade)
        delete facade;
    facade = new Facade(ui, 2);
    set_disabled(false);
}

void MainWindow::on_action_10_triggered()
{
    f_game = 3;
    if (facade)
        delete facade;
    facade = new Facade(ui, 3);
    set_disabled(false);
}

void MainWindow::on_action_11_triggered()
{
    f_game = 4;
    if (facade)
        delete facade;
    facade = new Facade(ui, 4);
    set_disabled(false);
}

void MainWindow::on_action_12_triggered()
{
    if (facade)
        delete facade;
    facade = new Facade(ui, f_game);
    set_disabled(false);
}
