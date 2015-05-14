TEMPLATE = app
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


include(deployment.pri)
qtcAddDeployment()


include(model/model.pri)
include(view/view.pri)
include(utilities/utilities.pri)

SOURCES += main.cpp
