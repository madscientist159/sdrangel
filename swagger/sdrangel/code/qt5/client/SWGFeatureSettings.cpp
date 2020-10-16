/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 5.9.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGFeatureSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGFeatureSettings::SWGFeatureSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFeatureSettings::SWGFeatureSettings() {
    feature_type = nullptr;
    m_feature_type_isSet = false;
    originator_feature_set_index = 0;
    m_originator_feature_set_index_isSet = false;
    originator_feature_index = 0;
    m_originator_feature_index_isSet = false;
    afc_settings = nullptr;
    m_afc_settings_isSet = false;
    simple_ptt_settings = nullptr;
    m_simple_ptt_settings_isSet = false;
    rig_ctl_server_settings = nullptr;
    m_rig_ctl_server_settings_isSet = false;
}

SWGFeatureSettings::~SWGFeatureSettings() {
    this->cleanup();
}

void
SWGFeatureSettings::init() {
    feature_type = new QString("");
    m_feature_type_isSet = false;
    originator_feature_set_index = 0;
    m_originator_feature_set_index_isSet = false;
    originator_feature_index = 0;
    m_originator_feature_index_isSet = false;
    afc_settings = new SWGAFCSettings();
    m_afc_settings_isSet = false;
    simple_ptt_settings = new SWGSimplePTTSettings();
    m_simple_ptt_settings_isSet = false;
    rig_ctl_server_settings = new SWGRigCtlServerSettings();
    m_rig_ctl_server_settings_isSet = false;
}

void
SWGFeatureSettings::cleanup() {
    if(feature_type != nullptr) { 
        delete feature_type;
    }


    if(afc_settings != nullptr) { 
        delete afc_settings;
    }
    if(simple_ptt_settings != nullptr) { 
        delete simple_ptt_settings;
    }
    if(rig_ctl_server_settings != nullptr) { 
        delete rig_ctl_server_settings;
    }
}

SWGFeatureSettings*
SWGFeatureSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFeatureSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&feature_type, pJson["featureType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&originator_feature_set_index, pJson["originatorFeatureSetIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&originator_feature_index, pJson["originatorFeatureIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&afc_settings, pJson["AFCSettings"], "SWGAFCSettings", "SWGAFCSettings");
    
    ::SWGSDRangel::setValue(&simple_ptt_settings, pJson["SimplePTTSettings"], "SWGSimplePTTSettings", "SWGSimplePTTSettings");
    
    ::SWGSDRangel::setValue(&rig_ctl_server_settings, pJson["RigCtlServerSettings"], "SWGRigCtlServerSettings", "SWGRigCtlServerSettings");
    
}

QString
SWGFeatureSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFeatureSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(feature_type != nullptr && *feature_type != QString("")){
        toJsonValue(QString("featureType"), feature_type, obj, QString("QString"));
    }
    if(m_originator_feature_set_index_isSet){
        obj->insert("originatorFeatureSetIndex", QJsonValue(originator_feature_set_index));
    }
    if(m_originator_feature_index_isSet){
        obj->insert("originatorFeatureIndex", QJsonValue(originator_feature_index));
    }
    if((afc_settings != nullptr) && (afc_settings->isSet())){
        toJsonValue(QString("AFCSettings"), afc_settings, obj, QString("SWGAFCSettings"));
    }
    if((simple_ptt_settings != nullptr) && (simple_ptt_settings->isSet())){
        toJsonValue(QString("SimplePTTSettings"), simple_ptt_settings, obj, QString("SWGSimplePTTSettings"));
    }
    if((rig_ctl_server_settings != nullptr) && (rig_ctl_server_settings->isSet())){
        toJsonValue(QString("RigCtlServerSettings"), rig_ctl_server_settings, obj, QString("SWGRigCtlServerSettings"));
    }

    return obj;
}

QString*
SWGFeatureSettings::getFeatureType() {
    return feature_type;
}
void
SWGFeatureSettings::setFeatureType(QString* feature_type) {
    this->feature_type = feature_type;
    this->m_feature_type_isSet = true;
}

qint32
SWGFeatureSettings::getOriginatorFeatureSetIndex() {
    return originator_feature_set_index;
}
void
SWGFeatureSettings::setOriginatorFeatureSetIndex(qint32 originator_feature_set_index) {
    this->originator_feature_set_index = originator_feature_set_index;
    this->m_originator_feature_set_index_isSet = true;
}

qint32
SWGFeatureSettings::getOriginatorFeatureIndex() {
    return originator_feature_index;
}
void
SWGFeatureSettings::setOriginatorFeatureIndex(qint32 originator_feature_index) {
    this->originator_feature_index = originator_feature_index;
    this->m_originator_feature_index_isSet = true;
}

SWGAFCSettings*
SWGFeatureSettings::getAfcSettings() {
    return afc_settings;
}
void
SWGFeatureSettings::setAfcSettings(SWGAFCSettings* afc_settings) {
    this->afc_settings = afc_settings;
    this->m_afc_settings_isSet = true;
}

SWGSimplePTTSettings*
SWGFeatureSettings::getSimplePttSettings() {
    return simple_ptt_settings;
}
void
SWGFeatureSettings::setSimplePttSettings(SWGSimplePTTSettings* simple_ptt_settings) {
    this->simple_ptt_settings = simple_ptt_settings;
    this->m_simple_ptt_settings_isSet = true;
}

SWGRigCtlServerSettings*
SWGFeatureSettings::getRigCtlServerSettings() {
    return rig_ctl_server_settings;
}
void
SWGFeatureSettings::setRigCtlServerSettings(SWGRigCtlServerSettings* rig_ctl_server_settings) {
    this->rig_ctl_server_settings = rig_ctl_server_settings;
    this->m_rig_ctl_server_settings_isSet = true;
}


bool
SWGFeatureSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(feature_type && *feature_type != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_originator_feature_set_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_originator_feature_index_isSet){
            isObjectUpdated = true; break;
        }
        if(afc_settings && afc_settings->isSet()){
            isObjectUpdated = true; break;
        }
        if(simple_ptt_settings && simple_ptt_settings->isSet()){
            isObjectUpdated = true; break;
        }
        if(rig_ctl_server_settings && rig_ctl_server_settings->isSet()){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

