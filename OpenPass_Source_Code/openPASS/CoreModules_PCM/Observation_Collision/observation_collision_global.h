/*********************************************************************
* Copyright (c) 2017 ITK Engineering GmbH
*
* This program and the accompanying materials are made
* available under the terms of the Eclipse Public License 2.0
* which is available at https://www.eclipse.org/legal/epl-2.0/
*
* SPDX-License-Identifier: EPL-2.0
**********************************************************************/

//-----------------------------------------------------------------------------
//! @file  observation_collision_global.h
//! @brief This file contains DLL export declarations
//-----------------------------------------------------------------------------

#ifndef OBSERVATION_COLLISION_GLOBAL_H
#define OBSERVATION_COLLISION_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef Observation_Collision_EXPORTS
#define OBSERVATION_COLLISION_LIBRARY
#endif
#if defined(OBSERVATION_COLLISION_LIBRARY)
#  define OBSERVATION_COLLISIONSHARED_EXPORT Q_DECL_EXPORT   //! Export of the dll-functions
#else
#  define OBSERVATION_COLLISIONSHARED_EXPORT Q_DECL_IMPORT   //! Import of the dll-functions
#endif

#endif // OBSERVATION_COLLISION_GLOBAL_H
