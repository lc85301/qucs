/***************************************************************************
                                  main.h
                                 --------
    begin                : Mon May 24  2004
    copyright            : (C) 2003 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
/*!
 * \file main.h
 * \brief Definitions and declarations for the main application.
 */

#ifndef QUCS_MAIN_H
#define QUCS_MAIN_H

#include <QFont>
#include <QColor>
#include <QStringList>
#include <QDir>
#include <QVector>
#include <QPair>

#include "wire.h"
#include "node.h"
#include "diagrams/diagram.h"

class QucsApp;
class Component;

// constants may be missing on windows systems
#ifndef M_PI
#define M_PI     3.1415926535897932384626433832795029
#endif

struct tQucsSettings {
  int x, y, dx, dy;    // position and size of main window
  QFont font;
  float largeFontSize;
  QColor BGColor;      // background color of view area
  QString Language;

  // syntax highlighting
  QColor Comment, String, Integer, Real, Character, Type,
    Attribute, Directive, Task;

  unsigned int maxUndo;    // size of undo stack
  QString Editor;
  QString BinDir;
  QString LangDir;
  QString LibDir;
  QString OctaveDir;  // m-files location
  QString ExamplesDir;
  QString DocDir;

  unsigned int NodeWiring;
  QDir QucsWorkDir;
  QDir QucsHomeDir;
  QDir AdmsXmlBinDir;  // dir of admsXml executable
  QDir AscoBinDir;     // dir of asco executable
  QDir OctaveBinDir;   // dir of octave executable

  // registered filename extensions with program to open the file
  QStringList FileTypes;

  unsigned int numRecentDocs;
  QStringList RecentDocs;

  bool IgnoreFutureVersion;
  bool GraphAntiAliasing;
  bool TextAntiAliasing;

  //shortcut
  QVector<QPair<QString, QMap<QString, QString>* > > Shortcut;
};

extern tQucsSettings QucsSettings;  // extern because nearly everywhere used
extern QucsApp *QucsMain;  // the Qucs application itself
extern QString lastDir;    // to remember last directory for several dialogs
extern QStringList qucsPathList;

void setDefaultShortcut();
void clearShortcutMap();
bool loadSettings();
bool saveApplSettings(QucsApp*);
void qucsMessageOutput(QtMsgType type, const char *msg);

#endif // ifndef QUCS_MAIN_H
