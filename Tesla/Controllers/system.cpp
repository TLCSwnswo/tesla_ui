#include "system.h"
#include <QDateTime>

System::System(QObject *parent)
    : QObject{parent}
    , m_carLocked( true )
    , m_outdoorTemp( 6 )
    , m_userName( "Lee" )
{
    m_currentTimeTimer = new QTimer(this);
    m_currentTimeTimer->setInterval(500);
    m_currentTimeTimer->setSingleShot(true);
    connect(m_currentTimeTimer, &QTimer::timeout, this, &System::setCurrentTimeTimerout);

    setCurrentTimeTimerout();
}

bool System::carLocked() const {
    return m_carLocked;
}

void System::setCarLocked(bool carLocked)
{
    if(m_carLocked == carLocked)
        return;

    m_carLocked = carLocked;
    emit carLockedChanged(m_carLocked);
}

int System::outdoorTemp() const
{
    return m_outdoorTemp;
}

void System::setOutdoorTemp(int newOutdoorTemp)
{
    if (m_outdoorTemp == newOutdoorTemp)
        return;
    m_outdoorTemp = newOutdoorTemp;
    emit outdoorTempChanged();
}

const QString &System::userName() const
{
    return m_userName;
}

void System::setuserName(const QString &newUserName)
{
    if (m_userName == newUserName)
        return;
    m_userName = newUserName;
    emit userNameChanged();
}

const QString &System::currentTime() const
{
    return m_currentTime;
}

void System::setcurrentTime(const QString &newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

void System::setCurrentTimeTimerout()
{
    QDateTime dateTime;
    QString currentTime = dateTime.currentDateTime().toString("hh:mm ap");

    setcurrentTime( currentTime );
    m_currentTimeTimer->start();
}
