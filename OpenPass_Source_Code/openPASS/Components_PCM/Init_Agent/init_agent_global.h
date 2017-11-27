/******************************************************************************
* Copyright (c) 2017 ITK Engineering GmbH.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
******************************************************************************/

//-----------------------------------------------------------------------------
//! @file  init_agent_global.h
//! @brief This file contains DLL export declarations
//!
//! This class contains all functionality of the module.
//-----------------------------------------------------------------------------

#ifndef INIT_AGENT_GLOBAL_H
#define INIT_AGENT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(INIT_AGENT_LIBRARY)
#  define INIT_AGENTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define INIT_AGENTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // INIT_AGENT_GLOBAL_H