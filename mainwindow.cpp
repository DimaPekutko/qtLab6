#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::printTree() {
    ui->bt_list->clear();
    while(!tree.traverseQueue.isEmpty()) {
        Node<User*> *node = tree.traverseQueue.dequeue();
        User *user = node->data;
        QListWidgetItem *item = new QListWidgetItem();
        QString itemText = "";
        itemText.append(user->getName());
        itemText.append(" : ");
        itemText.append(QString::number(user->getNumber()));
        item->setText(itemText);
        ui->bt_list->addItem(item);
    }
}

void MainWindow::pushToTreeWidget(Node<User*> *node, QTreeWidgetItem *item) {
    if(node != nullptr) {
        QTreeWidgetItem *newItem;
        if(item == nullptr) {
            newItem = new QTreeWidgetItem(ui->bt_tree);
            newItem->setText(0, QString::number(node->data->getNumber()));
            newItem->setText(1, node->data->getName());
            ui->bt_tree->addTopLevelItem(newItem);
        }
        else {
            newItem = new QTreeWidgetItem();
            newItem->setText(0, QString::number(node->data->getNumber()));
            newItem->setText(1, node->data->getName());
            item->addChild(newItem);
        }
        pushToTreeWidget(node->left, newItem);
        pushToTreeWidget(node->right, newItem);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_create_arr_btn_clicked()
{
    if(startArrAdded)
        return;
    ui->start_arr_list->clear();
//    startUsersList.append(new User("Jack Vilson", 80291234312));
//    startUsersList.append(new User("John Travolta", 80294326515));
//    startUsersList.append(new User("Alex Cranston", 80297846743));
//    startUsersList.append(new User("Lucas Serbov", 80294566541));
//    startUsersList.append(new User("James Roberts", 80294956437));
//    startUsersList.append(new User("Andrew Tarkovsky", 80296863433));
//    startUsersList.append(new User("Garry Scalby", 80293254657));
//    startUsersList.append(new User("Scott Luter", 80296895438));
//    startUsersList.append(new User("Sam Martinson", 80293123943));
//    startUsersList.append(new User("Dave Oldman", 80294326534));
//     7 digits
    startUsersList.append(new User("Jack Vilson", 3));
    startUsersList.append(new User("John Travolta", 7));
    startUsersList.append(new User("Alex Cranston", 9));
    startUsersList.append(new User("Lucas Serbov", 6));
    startUsersList.append(new User("James Roberts", 10));
    startUsersList.append(new User("Andrew Tarkovsky", 8));
    startUsersList.append(new User("Garry Scalby", 1));
    startUsersList.append(new User("Scott Luter", 4));
//    startUsersList.append(new User("Sam Martinson", 4));
//    startUsersList.append(new User("Dave Oldman", 8));
    for(int i = 0; i < startUsersList.length(); i++) {
        QListWidgetItem *item = new QListWidgetItem();
        QString itemText = "";
        itemText.append(startUsersList[i]->getName());
        itemText.append(" : ");
        itemText.append(QString::number(startUsersList[i]->getNumber()));
        item->setText(itemText);
        ui->start_arr_list->addItem(item);
    }
    startArrAdded = true;
}

void MainWindow::on_push_to_bt_btn_clicked()
{
    if(tree.length()) {
        return;
    }
    for(int i = 0; i < startUsersList.length(); i++) {
        tree.push(
            startUsersList[i], startUsersList[i]->getNumber(), tree.getRoot());
    }
    startArrAdded = true;
    ui->direct_btn->click();

    ui->bt_tree->setColumnCount(2);
    QStringList headerLabels;
    headerLabels << "Numbers" << "Names";
    ui->bt_tree->setHeaderLabels(headerLabels);
    pushToTreeWidget(tree.getRoot());
}

void MainWindow::on_add_new_btn_clicked()
{
    if(!ui->add_new_name_edit->text().count())
        return;
    if(!ui->add_new_number_edit->text().toLong())
        return;
    long int key = ui->add_new_number_edit->text().toLong();
    tree.traverseQueue.clear();
    tree.searchByKey(key, tree.getRoot());
    if(!tree.traverseQueue.isEmpty())
        return;
    tree.traverseQueue.clear();
    User *user = new User(ui->add_new_name_edit->text(), key);
    tree.push(user, ui->add_new_number_edit->text().toLong(), tree.getRoot());
    ui->bt_tree->clear();
    pushToTreeWidget(tree.getRoot());
}

void MainWindow::on_direct_btn_clicked()
{
    if(!tree.length())
        return;
    tree.traveNLR(tree.getRoot());
    this->printTree();
}

void MainWindow::on_reverse_btn_clicked()
{
    if(!tree.length())
        return;
    tree.traveLRN(tree.getRoot());
    this->printTree();
}

void MainWindow::on_ascending_btn_clicked()
{
    if(!tree.length())
        return;
    tree.traveLNR(tree.getRoot());
    this->printTree();
}

void MainWindow::on_search_btn_clicked()
{
    if(!ui->search_delete_edit->text().toLong()) {
        return;
    }
    tree.searchByKey(ui->search_delete_edit->text().toLong(), tree.getRoot());
    printTree();
}

void MainWindow::on_balance_btn_clicked()
{
    if(!tree.length())
        return;
    tree.traveLNR(tree.getRoot());
    tree.preBalance();
    tree.balance(0, tree.traverseQueue.length()-1);
    tree.traverseQueue.clear();
    ui->bt_tree->clear();
    pushToTreeWidget(tree.getRoot());
//    qDebug() << tree.getRoot()->left->data->getNumber();
}

void MainWindow::on_nodes_count_btn_clicked()
{
    if(!tree.length())
        return;
    QList<int> nodesCount = tree.countNodes();
    QString nodesCountStr = "";
    for(int i = 0; i < nodesCount.length(); i++) {
        if(!nodesCount[i])
            break;
        nodesCountStr.append(QString::number(nodesCount[i]));
        nodesCountStr.append(" ");
    }
    ui->nodes_count_label->setText(nodesCountStr);
}

void MainWindow::on_delete_btn_clicked()
{
    long int key = ui->search_delete_edit->text().toLong();
    if(!tree.length())
        return;
    tree.traveNLR(tree.getRoot());
    tree.preBalance();
    tree.remove(key);
    ui->bt_tree->clear();
    pushToTreeWidget(tree.getRoot());
}
