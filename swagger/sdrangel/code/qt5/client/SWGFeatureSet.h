/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGFeatureSet.h
 *
 * Grouping of features
 */

#ifndef SWGFeatureSet_H_
#define SWGFeatureSet_H_

#include <QJsonObject>


#include "SWGFeature.h"
#include <QList>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGFeatureSet: public SWGObject {
public:
    SWGFeatureSet();
    SWGFeatureSet(QString* json);
    virtual ~SWGFeatureSet();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGFeatureSet* fromJson(QString &jsonString) override;

    qint32 getIndex();
    void setIndex(qint32 index);

    qint32 getFeaturecount();
    void setFeaturecount(qint32 featurecount);

    QList<SWGFeature*>* getFeatures();
    void setFeatures(QList<SWGFeature*>* features);


    virtual bool isSet() override;

private:
    qint32 index;
    bool m_index_isSet;

    qint32 featurecount;
    bool m_featurecount_isSet;

    QList<SWGFeature*>* features;
    bool m_features_isSet;

};

}

#endif /* SWGFeatureSet_H_ */
