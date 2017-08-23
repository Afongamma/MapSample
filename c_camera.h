#ifndef C_CAMERA_H
#define C_CAMERA_H

#include <QtNetwork/QNetworkAccessManager>
#include <QXmlStreamReader>
#include <QNetworkReply>
//extern CConfig *mConfig;
class CCamera
{
public:
    CCamera();
    void    requestAzi();
    void    requestElevation();
    QString camName() const;
    void setCamName(const QString &camName);
    QString userName() const;
    void setUserName(const QString &userName);
    QString password() const;
    void setPassword(const QString &password);
    QString iP() const;
    void setIP(const QString &iP);
    double lat() const;
    void setLat(double lat);

    double lon() const;
    void setLon(double lon);

    double azi() const;
    void setAzi(double azi);

    bool alarm() const;
    void setAlarm(bool alarm);

    double aziNorth() const;
    void setAziNorth(double aziNorth);

private:
    QNetworkReply *reply;
    double  mLat,mLon;
    bool mAlarm;
    double  mAziRad,mElevation,mAziNorth;
    QString mIP,mUserName,mPassword,mCamName;
    bool CheckLastReply();
};

#endif // C_CAMERA_H
