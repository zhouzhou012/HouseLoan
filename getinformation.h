
#ifndef GETINFORMATION_H
#define GETINFORMATION_H

#include <QMainWindow>

class GetInformation : public QMainWindow
{
    Q_OBJECT
public:
    explicit GetInformation(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

};

#endif // GETINFORMATION_H
