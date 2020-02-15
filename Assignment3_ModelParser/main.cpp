/**
 * Support code written by Erik W. Anderson
 */

#include <QtCore>
#include <QtGui>
#include <QtOpenGL>

// Lab application
#include "Parser.h"
#include "Parser.cpp"

#include <iostream>

int main(int argc, char** argv) {

  Parser p;

  p.parse("../objects/bunny.obj");

  // QApplication a(argc, argv);
  // QString appDir = a.applicationDirPath();
  // QDir::setCurrent(appDir);

  // QSurfaceFormat fmt;
  // fmt.setDepthBufferSize(24);
  // fmt.setStencilBufferSize(8);
  // fmt.setVersion(3,3);
  // fmt.setProfile(QSurfaceFormat::CoreProfile);
  // QSurfaceFormat::setDefaultFormat(fmt);
  
  // Application app;
  // app.show();
  // return QApplication::exec();
}
