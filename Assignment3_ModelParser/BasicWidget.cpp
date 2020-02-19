#include "BasicWidget.h"
#include "Parser.h"
#include <vector>
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Publics
BasicWidget::BasicWidget(QWidget* parent) : QOpenGLWidget(parent), vbo_(QOpenGLBuffer::VertexBuffer), cbo_(QOpenGLBuffer::VertexBuffer), ibo_(QOpenGLBuffer::IndexBuffer)
{
  setFocusPolicy(Qt::StrongFocus);
}

BasicWidget::~BasicWidget()
{
  vbo_.release();
  vbo_.destroy();
  ibo_.release();
  ibo_.destroy();
  // cbo_.release();
  // cbo_.destroy();
  vao_.release();
  vao_.destroy();
}

//////////////////////////////////////////////////////////////////////
// Privates
QString BasicWidget::vertexShaderString() const
{
  QString str =
	"#version 330\n"
	"layout(location = 0) in vec3 position;\n"
    "layout(location = 1) in vec4 color;\n"
    "out vec4 vertColor;\n"
	"void main()\n"
	"{\n"
	"  gl_Position = vec4(position, 1.0);\n"
    "  vertColor = color;\n"
    "}\n";
  return str;
}

QString BasicWidget::fragmentShaderString() const
{
  QString str =
	"#version 330\n"
    "in vec4 vertColor;\n"
	"out vec4 color;\n"
	"void main()\n"
	"{\n"
	"  color = vertColor;\n"
	"}\n";
  return str;
}

///////////////////////////////////////////////////////////////////////
// Protected
void BasicWidget::keyReleaseEvent(QKeyEvent* keyEvent)
{
  // TODO
  // Handle key events here.
  qDebug() << "You Pressed an unsupported Key!";
  // ENDTODO
}

void BasicWidget::createShader()
{
  QOpenGLShader vert(QOpenGLShader::Vertex);
  vert.compileSourceCode(vertexShaderString());
  QOpenGLShader frag(QOpenGLShader::Fragment);
  frag.compileSourceCode(fragmentShaderString());
  bool ok = shaderProgram_.addShader(&vert);
  if(!ok) {
	qDebug() << shaderProgram_.log();
  }
  ok = shaderProgram_.addShader(&frag);
  if(!ok) {
	qDebug() << shaderProgram_.log();
  }
  ok = shaderProgram_.link();
  if(!ok) {
	qDebug() << shaderProgram_.log();
  }
}

void BasicWidget::initializeGL()
{
  makeCurrent();
  initializeOpenGLFunctions();

  QOpenGLContext* curContext = this->context();
  qDebug() << "[BasicWidget]::initializeGL() -- Context Information:";
  qDebug() << "  Context Valid: " << std::string(curContext->isValid() ? "true" : "false").c_str();
  qDebug() << "  GL Version Used: " << curContext->format().majorVersion() << "." << curContext->format().minorVersion();
  qDebug() << "  Vendor: " << reinterpret_cast<const char*>(glGetString(GL_VENDOR));
  qDebug() << "  Renderer: " << reinterpret_cast<const char*>(glGetString(GL_RENDERER));
  qDebug() << "  Version: " << reinterpret_cast<const char*>(glGetString(GL_VERSION));
  qDebug() << "  GLSL Version: " << reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));

  createShader();
 
  Parser p;
 
  p.parse("../objects/cube.obj");

  vertices = p.getVertices();
  indices = p.getVertexIndices();

  vector<float> colors;

  for (unsigned int i = 0; i < vertices.size() + (vertices.size() / 3); i++) {
    colors.push_back(1.0f);
  }

  shaderProgram_.bind();
  vbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
  vbo_.create();

  vbo_.bind();
  vbo_.allocate(vertices.data(), vertices.size() * sizeof(GL_FLOAT));

  cbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
  cbo_.create();
  // Bind our vbo inside our vao
  cbo_.bind();
  cbo_.allocate(colors.data(), colors.size() * sizeof(GL_FLOAT));

  ibo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
  ibo_.create();
  ibo_.bind();
  ibo_.allocate(indices.data(), indices.size() * sizeof(GL_INT));

  vao_.create();
  vao_.bind();
  vbo_.bind();

  shaderProgram_.enableAttributeArray(0);
  shaderProgram_.setAttributeBuffer(0, GL_FLOAT, 0, 3);
  cbo_.bind();
  shaderProgram_.enableAttributeArray(1);
  shaderProgram_.setAttributeBuffer(1, GL_FLOAT, 0, 4);

  ibo_.bind();
  vao_.release();
  shaderProgram_.release();
  
  glViewport(0, 0, width(), height());
}

void BasicWidget::resizeGL(int w, int h)
{
  glViewport(0, 0, w, h);
}

void BasicWidget::paintGL()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glClearColor(0.f, 0.f, 0.f, 1.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shaderProgram_.bind();
  vao_.bind();

  glDrawElements(GL_TRIANGLES, vertices.size() / 3, GL_UNSIGNED_INT, 0);

  vao_.release();
  shaderProgram_.release();

}
