win32 {
    DIR_DEBUG = "C:\OpenPASS\BinDebug"
    DIR_RELEASE = "C:\OpenPASS\BinRelease"
}

unix {
    DIR_DEBUG = "/OpenPASS/BinDebug"
    DIR_RELEASE = "/OpenPASS/BinRelease"
}

Debug:DESTDIR=$$DIR_DEBUG
Release:DESTDIR=$$DIR_RELEASE

#debug/release predicates are buggy on linux qmake
unix:DESTDIR=$$DIR_DEBUG
#unix:DESTDIR=$$DIR_RELEASE

# adjust path to your needs
EXTRA_LIBS=$$(HOME)/repos/ThirdParty/lib

#CONFIG += USEOPENPASSSLAVEASLIBRARY
#CONFIG += USEOPENPASSMASTERASLIBRARY

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

# prefer bundled libs in OpenPassSlave directory over system libraries
QMAKE_LFLAGS += -Wl,-rpath=\'\$\$ORIGIN\'

##################################################################
# Configuration specific for open pass libraries                 #
# Usage:                                                         #
# set "CONFIG += OPENPASS_LIBRARY" before including this file    #
##################################################################
OPENPASS_LIBRARY {
    message("[$$TARGET] Set library configuration")
    TEMPLATE = lib
    CONFIG += shared
    CONFIG -= lib_bundle
    DESTDIR = $$system_path($$DESTDIR/$$LIB_DIR)
    message("[$$TARGET] Build path set to $$DESTDIR")
}
