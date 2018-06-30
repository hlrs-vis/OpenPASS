#-----------------------------------------------------------------------------
# \file  openPASS-Scenery.pro
# \brief This file is the building project of the plugin manging the window
#        and the interface that includes data related to the Scenery
#
#
# Copyright (c) 2017 Volkswagen Group of America.
#
# This program and the accompanying materials are made
# available under the terms of the Eclipse Public License 2.0
# which is available at https://www.eclipse.org/legal/epl-2.0/
#
# SPDX-License-Identifier: EPL-2.0
#-----------------------------------------------------------------------------/

TARGET = Scenery
TEMPLATE = lib
CONFIG += plugin c++11 no_keywords
QT += core gui widgets

VERSION = 0.5
QMAKE_TARGET_PRODUCT = openPASS
QMAKE_TARGET_DESCRIPTION = openPASS Scenery
QMAKE_TARGET_COMPANY = Volkswagen Group of America
QMAKE_TARGET_COPYRIGHT = Volkswagen Group of America

release: DESTDIR = ../build/release
debug: DESTDIR = ../build/debug
win32: TARGET_EXT = .dll


include(Interfaces/Interfaces.pri)
include(Models/Models.pri)
include(Presenters/Presenters.pri)
include(Views/Views.pri)

HEADERS += \
    SceneryPlugin.h

SOURCES += \
    SceneryPlugin.cpp
