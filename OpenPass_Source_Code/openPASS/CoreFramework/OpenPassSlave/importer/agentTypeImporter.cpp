/******************************************************************************
* Copyright (c) 2017 ITK Engineering GmbH.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

#include <climits>
#include <cfloat>
#include <iostream>
#include <sstream>
#include <string>
#include <QDomDocument>
#include <QFile>
#include "agentTypeImporter.h"
#include "componentType.h"
#include "agentType.h"
#include "component.h"
#include "parameters.h"
#include "log.h"
#include "xmlParser.h"
#include "parameterParser.h"
#include "agentConfigImporter.h"
#include "agentSystemImporter.h"

// local helper macros
#define CHECKFALSE(element) \
    do { \
    if(!(element)) \
{ \
    LOG_INTERN(LogLevel::Warning) << "an error occurred during agent type import"; \
    return false; \
    } \
    } \
    while(0);

namespace SimulationSlave
{

bool AgentTypeImporter::Import(const std::string &filename, std::map<int, const AgentType*> &agentTypes)
{
    std::locale::global(std::locale("C"));

    QFile xmlFile(filename.c_str()); // automatic object will be closed on destruction
    if(!xmlFile.open(QIODevice::ReadOnly))
    {
        LOG_INTERN(LogLevel::Warning) << "an error occurred during agent type import";
        return false;
    }

    QByteArray xmlData(xmlFile.readAll());
    QDomDocument document;
    QString errorMsg;
    int errorLine;
    if(!document.setContent(xmlData, &errorMsg, &errorLine))
    {
        LOG_INTERN(LogLevel::Warning) << "invalid xml file format of file " << filename;
        LOG_INTERN(LogLevel::Warning) << "in line " << errorLine << " : " << errorMsg.toStdString();
        return false;
    }

    QDomElement documentRoot = document.documentElement();
    if(documentRoot.isNull())
    {
        return false;
    }

    if(documentRoot.tagName() == "Agents"){
        return SimulationSlave::AgentConfigImporter::Import(filename, agentTypes);
    }else if(documentRoot.tagName() == "systems"){
        return SimulationSlave::AgentSystemImporter::Import(filename, agentTypes);
    }else{
        return false;
    }

}

} // namespace SimulationSlave
