/*
* Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
*
*/
#include "verticalScroll60.h"
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>

VerticalScroll_60::VerticalScroll_60(QWidget *parent) :
    QWidget(parent),
    m_minRange(0),      //最小值默认为0   // The minimum value defaults to 0
    m_maxRange(59),    //最大值默认60     // Max default 24
    m_currentValue(0), //当前值默认0     // Current value defaults to 0
    isDragging(false),
    m_deviation(0),     //默认偏移量为0    // The default offset is 0
    m_numSize(4),
    interval(1),      //间隔默认1        // Interval default 1
    devide(4)           //默认分成4格    // Divided into 4 grids by default
{

    setupUi(this);

    homingAni = new QPropertyAnimation(this, "deviation");
    homingAni->setDuration(300);
    homingAni->setEasingCurve(QEasingCurve::OutQuad);
}

VerticalScroll_60::~VerticalScroll_60()
{
    delete homingAni;
    qDebug()<<"-------VerticalScroll_60---------";

    //delete ui;
}
/*
 * 设置范围  set range
 * int min 最小值
 * int max 最大值
*/
void VerticalScroll_60::setRange(int min, int max)
{
    m_minRange = min;
    m_maxRange = max;
    if (m_currentValue < min)
        m_currentValue = min;

    if (m_currentValue > max)
        m_currentValue = max;
    repaint();
}
//获取当前值
//Get current value
int VerticalScroll_60::readValue()
{
    return m_currentValue;
}

void VerticalScroll_60::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<"mouse pressed on vertical scroll";
    homingAni->stop();
    isDragging = true;
    m_mouseSrcPos = e->pos().y();
    QWidget::mousePressEvent(e);
}

void VerticalScroll_60::mouseMoveEvent(QMouseEvent *e)
{
    if (isDragging) {
        if( m_currentValue == m_minRange && e->pos().y() >= m_mouseSrcPos ) {
            m_currentValue = m_maxRange;
        } else if( m_currentValue == m_maxRange && e->pos().y() <= m_mouseSrcPos ) {
            m_currentValue = m_minRange;
        }

        m_deviation = e->pos().y() - m_mouseSrcPos;
        //若移动速度过快，则进行限制
        // If the movement speed is too fast, limit it
        if (m_deviation > (height() - 1) / devide) {
            m_deviation = (height() - 1) / devide;
        } else if (m_deviation < -(height() - 1) / devide) {
            m_deviation = -( height() - 1) / devide;
        }
        emit deviationChange((int)m_deviation / ((height() - 1) / devide));
        repaint();
    }
}

void VerticalScroll_60::mouseReleaseEvent(QMouseEvent *)
{
    if (isDragging) {
        isDragging = false;
        homing();
    }
}

void VerticalScroll_60::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0) {
        if(m_currentValue <= m_minRange)
            m_currentValue = m_maxRange;
        else
            m_currentValue-=1;
    } else {
        if (m_currentValue >= m_maxRange)
            m_currentValue = m_minRange;
        else
            m_currentValue+=1;
    }
    update();
    event->accept();
}

void VerticalScroll_60::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    int Height = height() - 1;

    if ( m_deviation >= Height / devide && m_currentValue > m_minRange ) {
        m_mouseSrcPos += Height / devide;
        m_deviation -= Height / devide;
        m_currentValue -= interval;
    }

    if ( m_deviation <= -Height / devide && m_currentValue < m_maxRange ) {
        m_mouseSrcPos -= Height / devide;
        m_deviation += Height / devide;
        m_currentValue += interval;
    }

    // 中间数
    //middle number
    paintNum(painter, m_currentValue, m_deviation);

    //两侧数字
    // Numbers on both sides
    if (m_currentValue != m_minRange) {
        paintNum(painter, m_currentValue - interval, m_deviation - Height / devide);
    } else {
        paintNum(painter, m_maxRange, m_deviation - Height / devide);
    }

    if (m_currentValue != m_maxRange) {
        paintNum(painter, m_currentValue + interval, m_deviation + Height / devide);
    } else {
        paintNum(painter, m_minRange, m_deviation + Height / devide);
    }

    for (int i=2; i <= devide/2; ++i) {
        if (m_currentValue - interval * i >= m_minRange)
            paintNum(painter, m_currentValue - interval * i, m_deviation - Height / devide * i);
        if (m_currentValue + interval * i <= m_maxRange)
            paintNum(painter, m_currentValue + interval * i, m_deviation + Height / devide * i);
    }
}
/*
 * 根据偏移量描绘数字
 * Drawing numbers
 * int num 需要显示的数字
 * int deviation 数字相对中间的偏移量
*/
void VerticalScroll_60::paintNum(QPainter &painter, int num, int deviation)
{
    int Width = width() - 1;
    int Height = height() - 1;
    int size = (Height - qAbs(deviation)) / (m_numSize*1.5); //偏移量越大，数字越小
    //The larger the offset, the smaller the number
    int transparency = 255 - 255 * qAbs(deviation) / Height;
    int height = Height / devide;
    int y = Height / 2 + deviation - height / 2;

    QFont font;
    font.setPixelSize(size);
    painter.setFont(font);
    painter.setPen(QColor(255,255,255,transparency));

    QStyleOption opt;
    opt.init(this);
    painter.setBrush(opt.palette.color(QPalette::Base));

    //偏移量越大颜色越浅
    if(QColor(255,255,255) == opt.palette.color(QPalette::Base) || QColor(248,248,248) == opt.palette.color(QPalette::Base))
    {
        painter.setPen(QColor(34+(qAbs(deviation)*2),34+(qAbs(deviation)*2),34+(qAbs(deviation)*2),transparency));
    }else{
        painter.setPen(QColor(255-(qAbs(deviation)*2),255-(qAbs(deviation)*2),255-(qAbs(deviation)*2),transparency));
    }

    if ( y >= 0 && y + height < Height) {
        painter.drawText(QRectF(0, y, Width, height),
                         Qt::AlignCenter,
                         change_NUM_to_str(num));
    }
}

//单位变双位
// Unit to double
QString VerticalScroll_60::change_NUM_to_str(int alarmHour)
{
    QString str;
    if(alarmHour < 10){
        QString hours_str = QString::number(alarmHour);
        str = "0"+hours_str;
    } else {
        str = QString::number(alarmHour);
    }
    return str;
}

/*
 * 使选中的数字回到屏幕中间
 * Bring the selected number back to the middle of the screen
*/
void VerticalScroll_60::homing()
{
    if ( m_deviation > height() / 10) {
        homingAni->setStartValue( ( height() - 1 ) / 8 - m_deviation);
        homingAni->setEndValue(0);
        m_currentValue -= interval;
    } else if ( m_deviation > -height() / 10 ) {
        homingAni->setStartValue(m_deviation);
        homingAni->setEndValue(0);
    } else if ( m_deviation < -height() / 10 ) {
        homingAni->setStartValue(-(height() - 1) / 8 - m_deviation);
        homingAni->setEndValue(0);
        m_currentValue += interval;
    }
    emit currentValueChanged(m_currentValue);
    homingAni->start();
}

int VerticalScroll_60::readDeviation()
{
    return m_deviation;
}

void VerticalScroll_60::setDeviation(int n)
{
    m_deviation = n;
    repaint();
}

void VerticalScroll_60::setupUi(QWidget *VerticalScroll_60)
{
    if (VerticalScroll_60->objectName().isEmpty())
        VerticalScroll_60->setObjectName(QString::fromUtf8("VerticalScroll_60"));
    VerticalScroll_60->resize(53, 200);

    retranslateUi(VerticalScroll_60);

    QMetaObject::connectSlotsByName(VerticalScroll_60);
} // setupUi

void VerticalScroll_60::retranslateUi(QWidget *VerticalScroll_60)
{
    VerticalScroll_60->setWindowTitle(QApplication::translate("VerticalScroll_60", "VerticalScroll_60", nullptr));
} // retranslateUi
