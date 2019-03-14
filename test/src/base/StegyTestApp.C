//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "StegyTestApp.h"
#include "StegyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<StegyTestApp>()
{
  InputParameters params = validParams<StegyApp>();
  return params;
}

StegyTestApp::StegyTestApp(InputParameters parameters) : MooseApp(parameters)
{
  StegyTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

StegyTestApp::~StegyTestApp() {}

void
StegyTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  StegyApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"StegyTestApp"});
    Registry::registerActionsTo(af, {"StegyTestApp"});
  }
}

void
StegyTestApp::registerApps()
{
  registerApp(StegyApp);
  registerApp(StegyTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
StegyTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  StegyTestApp::registerAll(f, af, s);
}
extern "C" void
StegyTestApp__registerApps()
{
  StegyTestApp::registerApps();
}
