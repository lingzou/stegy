//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef STEGYAPP_H
#define STEGYAPP_H

#include "MooseApp.h"

class StegyApp;

template <>
InputParameters validParams<StegyApp>();

class StegyApp : public MooseApp
{
public:
  StegyApp(InputParameters parameters);
  virtual ~StegyApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* STEGYAPP_H */
