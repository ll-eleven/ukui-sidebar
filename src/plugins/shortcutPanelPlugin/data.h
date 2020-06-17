#ifndef DATA_H
#define DATA_H

#include <QMetaType>

enum InterfaceEnum {
    PAD,
    WIFI,
    NODISTURB,
    SETTING,
    BLUETOOTH,
    HOTSPOT,
    CALCULATOR,
    SCREENSHOT,
    Else
};

struct MyClass
{
    QString desktopfp;
    QString IconName;
    QString programName;
    bool    status;
    InterfaceEnum Interface;
};
Q_DECLARE_METATYPE(MyClass)

#endif // DATA_H
