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
 * SWGSatelliteDeviceSettings.h
 *
 * Device set settings
 */

#ifndef SWGSatelliteDeviceSettings_H_
#define SWGSatelliteDeviceSettings_H_

#include <QJsonObject>


#include <QList>
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGSatelliteDeviceSettings: public SWGObject {
public:
    SWGSatelliteDeviceSettings();
    SWGSatelliteDeviceSettings(QString* json);
    virtual ~SWGSatelliteDeviceSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGSatelliteDeviceSettings* fromJson(QString &jsonString) override;

    qint32 getDeviceSetIndex();
    void setDeviceSetIndex(qint32 device_set_index);

    QString* getPresetGroup();
    void setPresetGroup(QString* preset_group);

    qint64 getPresetFrequency();
    void setPresetFrequency(qint64 preset_frequency);

    QString* getPresetDescription();
    void setPresetDescription(QString* preset_description);

    QList<QString*>* getDoppler();
    void setDoppler(QList<QString*>* doppler);

    qint32 getStartOnAos();
    void setStartOnAos(qint32 start_on_aos);

    qint32 getStopOnLos();
    void setStopOnLos(qint32 stop_on_los);

    qint32 getStartStopFileSinks();
    void setStartStopFileSinks(qint32 start_stop_file_sinks);

    qint64 getFrequency();
    void setFrequency(qint64 frequency);

    QString* getAosCommand();
    void setAosCommand(QString* aos_command);

    QString* getLosCommand();
    void setLosCommand(QString* los_command);


    virtual bool isSet() override;

private:
    qint32 device_set_index;
    bool m_device_set_index_isSet;

    QString* preset_group;
    bool m_preset_group_isSet;

    qint64 preset_frequency;
    bool m_preset_frequency_isSet;

    QString* preset_description;
    bool m_preset_description_isSet;

    QList<QString*>* doppler;
    bool m_doppler_isSet;

    qint32 start_on_aos;
    bool m_start_on_aos_isSet;

    qint32 stop_on_los;
    bool m_stop_on_los_isSet;

    qint32 start_stop_file_sinks;
    bool m_start_stop_file_sinks_isSet;

    qint64 frequency;
    bool m_frequency_isSet;

    QString* aos_command;
    bool m_aos_command_isSet;

    QString* los_command;
    bool m_los_command_isSet;

};

}

#endif /* SWGSatelliteDeviceSettings_H_ */
