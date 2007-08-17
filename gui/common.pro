TEMPLATE = app
DESTDIR = .
DEPENDPATH += . include src ui
INCLUDEPATH += . include ../main/include
LIBS += -L../main
win32 {
  LIBS += -llibeudaq -L../extern/pthread-win32/lib -lpthreadGC2
} else {
  LIBS += -leudaq
}

FORMS += ui/$${TARGET}.ui
SOURCES += src/$${TARGET}.cc
HEADERS += include/$${TARGET}.hh

macx {
  DEFINES += EUDAQ_PLATFORM=PF_MACOSX
  ICON = ../images/$${TARGET}.icns
  QMAKE_POST_LINK += cp ../main/libeudaq.dylib $${TARGET}.app/Contents/MacOS/ &&
  QMAKE_POST_LINK += install_name_tool -change libeudaq.dylib @executable_path/libeudaq.dylib $${TARGET}.app/Contents/MacOS/$${TARGET}
} else {
  win32 {
    DEFINES += EUDAQ_PLATFORM=PF_WIN32
    RC_FILE = src/$${TARGET}.rc
  } else {
    DEFINES += EUDAQ_PLATFORM=PF_LINUX
  }
}

UI_DIR = tmp
MOC_DIR = tmp
OBJECTS_DIR = tmp