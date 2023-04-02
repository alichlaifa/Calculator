#ifndef CALC_H
#define CALC_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QWidget
{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();

private slots:
    void digit_pressed();

    void on_b_cl_released();

    void on_b_plus_released();

    void on_b_min_released();

    void on_b_div_released();

    void on_b_mul_released();

    void on_b_eq_released();

private:
    Ui::calc *ui;
};
#endif // CALC_H
