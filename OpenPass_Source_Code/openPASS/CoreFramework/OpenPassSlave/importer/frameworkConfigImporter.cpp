/*********************************************************************
* Copyright (c) 2017 ITK Engineering GmbH
*
* This program and the accompanying materials are made
* available under the terms of the Eclipse Public License 2.0
* which is available at https://www.eclipse.org/legal/epl-2.0/
*
* SPDX-License-Identifier: EPL-2.0
**********************************************************************/

#include <QApplication>
#include <QCommandLineParser>
#include <iostream>
#include <sstream>
#include <QDomDocument>
#include <QDir>
#include <QFile>
#include "log.h"
#include "frameworkConfig.h"
#include "frameworkConfigImporter.h"
#include "xmlParser.h"

// local helper macros
#define CHECKFALSE(element) \
    do { \
    if(!(element)) \
{ \
    LOG_INTERN(LogLevel::Error) << "an error occurred during configuration import"; \
    return nullptr; \
    } \
    } \
    while(0);

namespace SimulationSlave {

FrameworkConfig *FrameworkConfigImporter::Import(int argc, char *argv[])
{
    QString libraryPath = QCoreApplication::applicationDirPath() + "/lib"; // SUBDIR_LIB_SIM;
    QString resultPath = QCoreApplication::applicationDirPath();
    QString runConfigFile = QCoreApplication::applicationDirPath() + "/runConfiguration.xml";
    QString agentConfigFile = QCoreApplication::applicationDirPath() + "/systemConfiguration.xml";
    QString sceneryConfigFile = QCoreApplication::applicationDirPath() + "/sceneryConfiguration.xml";
    QString openScenarioConfigFile = QCoreApplication::applicationDirPath() + "/scenarioConfiguration.xosc";
    QString logFile = QCoreApplication::applicationDirPath() + "/OpenPassSlave.log";
    int logLevel = 5;

    for (int i = 1; i < argc; i++)
    {
        QString arg = argv[i];
        if (arg == "--libraryPath")
        {
            if (++i < argc)
            {
                libraryPath = argv[i];
            }
        }
        else if (arg == "--observationResultPath")
        {
            if (++i < argc)
            {
                resultPath = argv[i];
            }
        }
        else if (arg == "--agentConfiguration")
        {
            if (++i < argc)
            {
                agentConfigFile = argv[i];
            }
        }
        else if (arg == "--sceneryConfiguration")
        {
            if (++i < argc)
            {
                sceneryConfigFile = argv[i];
            }
        }
        else if (arg == "--openScenarioConfiguration")
        {
            if (++i < argc)
            {
                openScenarioConfigFile = argv[i];
            }
        }
        else if (arg == "--runConfiguration")
        {
            if (++i < argc)
            {
                runConfigFile = argv[i];
            }
        }
        else if (arg == "--logFile")
        {
            if (++i < argc)
            {
                logFile = argv[i];
            }
        }
        else if (arg == "--logLevel")
        {
            if (++i < argc)
            {
                logLevel = QString::fromStdString(argv[i]).toInt();
            }
        }
    }

    FrameworkConfig *configuration = new (std::nothrow) FrameworkConfig(libraryPath.toStdString(),
                                                                        resultPath.toStdString(),
                                                                        agentConfigFile.toStdString(),
                                                                        sceneryConfigFile.toStdString(),
                                                                        openScenarioConfigFile.toStdString(),
                                                                        runConfigFile.toStdString(),
                                                                        logFile.toStdString(),
                                                                        logLevel);

    if (!configuration)
    {
        LOG_INTERN(LogLevel::Error) << "an error occurred during configuration import";
        return nullptr;
    }

    return configuration;
}

} // namespace SimulationSlave
