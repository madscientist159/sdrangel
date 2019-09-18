///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QtPlugin>

#include <string>

#include "lime/LimeSuite.h"
#include "plugin/pluginapi.h"
#include "util/simpleserializer.h"
#include "limesdr/devicelimesdr.h"

#ifdef SERVER_MODE
#include "limesdrinput.h"
#else
#include "limesdrinputgui.h"
#endif
#include "limesdrinputplugin.h"
#include "limesdrinputwebapiadapter.h"

const PluginDescriptor LimeSDRInputPlugin::m_pluginDescriptor = {
    QString("LimeSDR Input"),
    QString("4.11.10"),
    QString("(c) Edouard Griffiths, F4EXB"),
    QString("https://github.com/f4exb/sdrangel"),
    true,
    QString("https://github.com/f4exb/sdrangel")
};

const QString LimeSDRInputPlugin::m_hardwareID = "LimeSDR";
const QString LimeSDRInputPlugin::m_deviceTypeID = LIMESDR_DEVICE_TYPE_ID;

LimeSDRInputPlugin::LimeSDRInputPlugin(QObject* parent) :
    QObject(parent)
{
}

const PluginDescriptor& LimeSDRInputPlugin::getPluginDescriptor() const
{
    return m_pluginDescriptor;
}

void LimeSDRInputPlugin::initPlugin(PluginAPI* pluginAPI)
{
    pluginAPI->registerSampleSource(m_deviceTypeID, this);
}

void LimeSDRInputPlugin::enumOriginDevices(QStringList& listedHwIds, OriginDevices& originDevices)
{
    if (listedHwIds.contains(m_hardwareID)) { // check if it was done
        return;
    }

    DeviceLimeSDR::enumOriginDevices(m_hardwareID, originDevices);
	listedHwIds.append(m_hardwareID);
}

PluginInterface::SamplingDevices LimeSDRInputPlugin::enumSampleSources(const OriginDevices& originDevices)
{
	SamplingDevices result;

	for (OriginDevices::const_iterator it = originDevices.begin(); it != originDevices.end(); ++it)
    {
        if (it->hardwareId == m_hardwareID)
        {
            for (unsigned int j = 0; j < it->nbRxStreams; j++)
            {
                qDebug("LimeSDRInputPlugin::enumSampleSources: device #%d channel %u: %s", it->sequence, j, qPrintable(it->serial));
                QString displayedName = it->displayableName;
                displayedName.replace(QString("$1]"), QString("%1]").arg(j));
                result.append(SamplingDevice(
                    displayedName,
                    it->hardwareId,
                    m_deviceTypeID,
                    it->serial,
                    it->sequence,
                    PluginInterface::SamplingDevice::PhysicalDevice,
                    PluginInterface::SamplingDevice::StreamSingleRx,
                    it->nbRxStreams,
                    j
                ));
            }
        }
    }

    return result;
}

#ifdef SERVER_MODE
PluginInstanceGUI* LimeSDRInputPlugin::createSampleSourcePluginInstanceGUI(
        const QString& sourceId,
        QWidget **widget,
        DeviceUISet *deviceUISet)
{
    (void) sourceId;
    (void) widget;
    (void) deviceUISet;
    return 0;
}
#else
PluginInstanceGUI* LimeSDRInputPlugin::createSampleSourcePluginInstanceGUI(
        const QString& sourceId,
        QWidget **widget,
        DeviceUISet *deviceUISet)
{
    if(sourceId == m_deviceTypeID)
    {
        LimeSDRInputGUI* gui = new LimeSDRInputGUI(deviceUISet);
        *widget = gui;
        return gui;
    }
    else
    {
        return 0;
    }
}
#endif

DeviceSampleSource *LimeSDRInputPlugin::createSampleSourcePluginInstance(const QString& sourceId, DeviceAPI *deviceAPI)
{
    if (sourceId == m_deviceTypeID)
    {
        LimeSDRInput* input = new LimeSDRInput(deviceAPI);
        return input;
    }
    else
    {
        return 0;
    }
}

DeviceWebAPIAdapter *LimeSDRInputPlugin::createDeviceWebAPIAdapter() const
{
    return new LimeSDRInputWebAPIAdapter();
}
