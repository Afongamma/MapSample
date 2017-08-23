
#ifndef CONFIG_H
#define CONFIG_H

#define SCALE_MAX 80
#define SCALE_MIN 5
#define HR_APP_PATH       "D:/HR2D/"
#define HR_DATA_REC_PATH  "D:/HR2D/RecordData/"
#define HR_CONFIG_FILE    "C:/FlameRun/map_config.xml"
#define HR_CONFIG_FILE_DF "C:/FlameRun/map_config_default.xml"
#define XML_ELEM_NAME     "map_config"
#define DEFAULT_LAT		20.707f
#define DEFAULT_LONG	106.78f
#include <QFile>
#include <QHash>
#include <QXmlStreamReader>

class CConfig
{
public:
    CConfig(void);
    ~CConfig(void);
    QHash<QString, QString> hashData;
    void    setValue(QString key, double value);
    void    setValue(QString key,QString value);
    double  getDouble(QString key, double defaultValue = 0);
    QString getString(QString key, QString defaultValue = "");
    void    setDefault();
    int getInt(QString key, int defaultValue = 0);
private:
    QXmlStreamReader xml;

    void readFile();
    void SaveToFile();
};

#endif
