////////////////////////////////////////////////////////////////////////////////
/// @file AbstractScene.h
/// @author Ramon Blanquer
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#ifndef ABSTRACTSCENE_H
#define ABSTRACTSCENE_H

// Qt
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWindow>

////////////////////////////////////////////////////////////////////////////////
/// @class AbstractScene
/// @brief Prepares OpenGL so the user just needs to subclass it and
/// redefine initialize() and paint()
///
/// This class will be a member of the OpenGL Window and is in
/// charge to initialize all the OpenGL functions (responsible for function
/// binding).
////////////////////////////////////////////////////////////////////////////////
class AbstractScene : protected QOpenGLFunctions_3_3_Core
{

public:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief Constructor.
  /// @param[in] _window The OpenGL window to associate the scene with.
  //////////////////////////////////////////////////////////////////////////////
  AbstractScene(QOpenGLWindow *_window = 0);

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Virtual destructor. The subclassed one will be called.
  //////////////////////////////////////////////////////////////////////////////
  virtual ~AbstractScene();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Window getter.
  //////////////////////////////////////////////////////////////////////////////
  QOpenGLWindow* window() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Window context getter.
  //////////////////////////////////////////////////////////////////////////////
  QOpenGLContext* context();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Window context getter.
  //////////////////////////////////////////////////////////////////////////////
  const QOpenGLContext* context() const;

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Must get called after doing any initialization on the subclassed
  /// variant, as it will bind the OpenGL functions and make them available.
  ///
  /// So subclass, and then call AbstractScene::initialize().
  /// Check Scene::initialize() to see an example.
  //////////////////////////////////////////////////////////////////////////////
  virtual void initialize();

  //////////////////////////////////////////////////////////////////////////////
  /// @brief Pure virtual method for drawing the OpenGL scene. Must be
  /// overwritten when subclassing AbstractScene. See Scene as an example.
  //////////////////////////////////////////////////////////////////////////////
  virtual void paint() = 0;

private:
  //////////////////////////////////////////////////////////////////////////////
  /// @brief [Window](@ref Window) associated with the scene.
  //////////////////////////////////////////////////////////////////////////////
  QOpenGLWindow *m_window = nullptr;

public slots:
  virtual void keyPressEvent(QKeyEvent* ev) = 0;

};

#endif // ABSTRACTSCENE_H
