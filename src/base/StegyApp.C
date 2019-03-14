#include "StegyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<StegyApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

StegyApp::StegyApp(InputParameters parameters) : MooseApp(parameters)
{
  StegyApp::registerAll(_factory, _action_factory, _syntax);
}

StegyApp::~StegyApp() {}

void
StegyApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"StegyApp"});
  Registry::registerActionsTo(af, {"StegyApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
StegyApp::registerApps()
{
  registerApp(StegyApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
StegyApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  StegyApp::registerAll(f, af, s);
}
extern "C" void
StegyApp__registerApps()
{
  StegyApp::registerApps();
}
