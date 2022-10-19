#ifndef NUMCELL_H
#define NUMCELL_H

#include<QPushButton>

class NumCell : public QPushButton
{
    Q_OBJECT
private:
    int row, col, num;

public slots:
    void on_clicked();

signals:
    void operate_signal(int row, int col);

public:
    NumCell(QWidget *parent);
    int get_row();
    void set_row(int row);
    int get_col();
    void set_col(int col);
    int get_num();
    void set_num(int num);
};

#endif // NUMCELL_H
