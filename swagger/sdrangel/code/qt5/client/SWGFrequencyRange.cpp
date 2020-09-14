/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.15.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGFrequencyRange.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGFrequencyRange::SWGFrequencyRange(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFrequencyRange::SWGFrequencyRange() {
    min = 0L;
    m_min_isSet = false;
    max = 0L;
    m_max_isSet = false;
    step = 0;
    m_step_isSet = false;
    scale = 0.0f;
    m_scale_isSet = false;
}

SWGFrequencyRange::~SWGFrequencyRange() {
    this->cleanup();
}

void
SWGFrequencyRange::init() {
    min = 0L;
    m_min_isSet = false;
    max = 0L;
    m_max_isSet = false;
    step = 0;
    m_step_isSet = false;
    scale = 0.0f;
    m_scale_isSet = false;
}

void
SWGFrequencyRange::cleanup() {




}

SWGFrequencyRange*
SWGFrequencyRange::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFrequencyRange::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&min, pJson["min"], "qint64", "");
    
    ::SWGSDRangel::setValue(&max, pJson["max"], "qint64", "");
    
    ::SWGSDRangel::setValue(&step, pJson["step"], "qint32", "");
    
    ::SWGSDRangel::setValue(&scale, pJson["scale"], "float", "");
    
}

QString
SWGFrequencyRange::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFrequencyRange::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_min_isSet){
        obj->insert("min", QJsonValue(min));
    }
    if(m_max_isSet){
        obj->insert("max", QJsonValue(max));
    }
    if(m_step_isSet){
        obj->insert("step", QJsonValue(step));
    }
    if(m_scale_isSet){
        obj->insert("scale", QJsonValue(scale));
    }

    return obj;
}

qint64
SWGFrequencyRange::getMin() {
    return min;
}
void
SWGFrequencyRange::setMin(qint64 min) {
    this->min = min;
    this->m_min_isSet = true;
}

qint64
SWGFrequencyRange::getMax() {
    return max;
}
void
SWGFrequencyRange::setMax(qint64 max) {
    this->max = max;
    this->m_max_isSet = true;
}

qint32
SWGFrequencyRange::getStep() {
    return step;
}
void
SWGFrequencyRange::setStep(qint32 step) {
    this->step = step;
    this->m_step_isSet = true;
}

float
SWGFrequencyRange::getScale() {
    return scale;
}
void
SWGFrequencyRange::setScale(float scale) {
    this->scale = scale;
    this->m_scale_isSet = true;
}


bool
SWGFrequencyRange::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_min_isSet){
            isObjectUpdated = true; break;
        }
        if(m_max_isSet){
            isObjectUpdated = true; break;
        }
        if(m_step_isSet){
            isObjectUpdated = true; break;
        }
        if(m_scale_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

