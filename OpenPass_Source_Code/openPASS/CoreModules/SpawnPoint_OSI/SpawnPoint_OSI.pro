#-----------------------------------------------------------------------------
# \file  SpawnPoint_OSI.pro
# \brief This file contains the information for the QtCreator-project of the
#        SpawnPoint_OSI module
#
# Copyright (c) 2016 ITK Engineering AG.
# Copyright (c) 2018 in-tech GmbH.
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# https://www.eclipse.org/legal/epl-2.0/
#
# SPDX-License-Identifier: EPL-2.0
#-----------------------------------------------------------------------------
include(../../../Global.pri)

QT       -= gui

win32 {
QMAKE_CXXFLAGS += -std=c++11 -DWIN32
LIBS += -lws2_32
} else {
QMAKE_CXXFLAGS += -std=c++11 -Dunix
}

TARGET = SpawnPoint_OSI
TEMPLATE = lib

OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui

DEFINES += SPAWNPOINT_OSI_LIBRARY

# accumulate list of files for given directories (first parameter)
# according to file name ending (second parameter)
defineReplace(getFiles) {
    variable = $$1
    files = $$eval($$variable)
    result =
    for(file, files) {
        result += $$files($$file/*.$$2)
    }
    return($$result)
}

SUBDIRS +=  . \
            ../../Common \
            ../../Interfaces \

INCLUDEPATH += $$SUBDIRS \
    ..

SOURCES += \
    $$getFiles(SUBDIRS, cpp) \
    $$getFiles(SUBDIRS, cc) \
    $$getFiles(SUBDIRS, c)

HEADERS += \
    $$getFiles(SUBDIRS, hpp) \
    $$getFiles(SUBDIRS, h)
