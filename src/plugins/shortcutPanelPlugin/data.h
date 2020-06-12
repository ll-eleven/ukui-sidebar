#ifndef DATA_H
#define DATA_H

#include <QMetaType>
struct MyClass
{
    QString desktopfp;
    bool status;
};
Q_DECLARE_METATYPE(MyClass)

#endif // DATA_H
