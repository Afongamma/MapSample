#include "c_camera.h"

#include <QEventLoop>
#include <QtGui>

//#include <QEventLoop>

CCamera::CCamera()
{

    mIP = "192.168.100.100";
    mUserName = "service";
    mPassword = "12345678";
    mAziRad = 0;
    mAlarm = false;
    reply = 0;

}

bool CCamera::CheckLastReply()
{
    if(!reply)return true;
    if(!reply->isFinished())
    {
        reply->abort();
        return true;
    }
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(reply);
    xmlReader.readNext();
    while (!xmlReader.atEnd() && !xmlReader.hasError())
    {
        if (xmlReader.isStartElement())
        {
            QString name = xmlReader.name().toString();
            if (name == "str" )
            {
                //name = name;
                //QMessageBox::information(this,name,xmlReader.readElementText());
                name = xmlReader.readElementText();
                QStringList strList = name.split(' ');
                bool ok;
                double aziRad =  strList.at(6).toInt(&ok,16)*255 + strList.at(7).toInt(&ok,16);

                mAziRad = aziRad/ 10000.0 ;//aziRad/3.1415926535*180.0;
                if(mAziRad<0)mAziRad = 0;
                if(mAziRad>=(3.1415926535*2.0))mAziRad = 0;
            }
            if (xmlReader.hasError())
            {break;}
        }
        xmlReader.readNext();

    }

    reply=0;
    return true;
}
void CCamera::requestAzi()
{

    if(!CheckLastReply())return;
    QNetworkAccessManager *qnam = new QNetworkAccessManager();
    reply = qnam->get(QNetworkRequest(QUrl("http://"
                                           +mUserName+":"+mPassword+"@"+ mIP
                                           +"/rcp.xml?command=0x09A5&type=P_OCTET&direction=WRITE&num=1&payload=0x810006011201")));
    //http://192.168.100.100/rcp.xml?command=0x09A5&type=P_OCTET&direction=WRITE&num=1&payload=0x810006011201*/
    //reply = qnam->get(QNetworkRequest(QUrl("http://127.0.0.1/index.xml")));
//    QEventLoop loop;
//    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//    QObject::connect(reply, SIGNAL(error()), &loop, SLOT(quit()));
//    loop.exec();



}

void CCamera::requestElevation()
{

}

QString CCamera::iP() const
{
    return mIP;
}

void CCamera::setIP(const QString &iP)
{
    mIP = iP;
}

double CCamera::lat() const
{
    return mLat;
}

void CCamera::setLat(double lat)
{
    mLat = lat;
}

double CCamera::lon() const
{
    return mLon;
}

void CCamera::setLon(double lon)
{
    mLon = lon;
}

double CCamera::azi() const
{
    return (mAziRad+mAziNorth/180.0*3.1415926535);
}

void CCamera::setAzi(double azi)
{
    mAziRad = azi;
}

bool CCamera::alarm() const
{
    return mAlarm;
}

void CCamera::setAlarm(bool alarm)
{
    mAlarm = alarm;
}

double CCamera::aziNorth() const
{
    return mAziNorth;
}

void CCamera::setAziNorth(double aziNorth)
{
    mAziNorth = aziNorth;
}

QString CCamera::password() const
{
    return mPassword;
}

void CCamera::setPassword(const QString &password)
{
    mPassword = password;
}

QString CCamera::userName() const
{
    return mUserName;
}

void CCamera::setUserName(const QString &userName)
{
    mUserName = userName;
}

QString CCamera::camName() const
{
    return mCamName;
}

void CCamera::setCamName(const QString &camName)
{
    mCamName = camName;
}
