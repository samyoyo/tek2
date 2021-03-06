#include "Monitor.hpp"
#include "Module.hpp"

Monitor::Monitor()
{}

Monitor::~Monitor()
{}

void  Monitor::stop()
{
  this->_isRunning = false;
}

void  Monitor::run(ScreenNCurse disp)
{
  this->_isRunning = true;
  Module	mod1(1);
  Module	mod2(10);
  Module	mod3(11);
  Module	mod4(124);
  Module	mod5(2);
  Module	mod6(20);
  while (this->_isRunning)
  {
    disp._win = subwin(stdscr, 0, 0, 1, 1);
    box(disp._win, ACS_VLINE, ACS_HLINE);
    scrollok(disp._win, TRUE);
    wmove(disp._win, 0, 0);
    doupdate();
    mod1.create();
    mod2.create();
    mod3.create();
    mod4.create();
    mod5.create();
    mod6.create();
    wrefresh(disp._win);
    refresh();
  }
  delete this->_display;
}

void Monitor::setDisplay(IMonitorDisplay* display)
{
  this->_display = display;
}

void Monitor::addModule(IMonitorModule* module)
{
  this->_modules.push_back(module);
}

void Monitor::removeModule(IMonitorModule* module)
{
  this->_modules.remove(module);
}

void Monitor::refresh()
{
  this->_display->refresh();
  std::list<IMonitorModule*>::const_iterator module;
  for (module = this->_modules.begin(); module != this->_modules.end(); module++)
  {
    if (this->_elapsedTime - (*module)->getLastRefresh() >= (*module)->getRefreshRate())
    {
      (*module)->setLastRefresh(this->_elapsedTime);
      (*module)->refresh();
    }
  }
}

void Monitor::dump()
{
  this->_display->dump();
}

Monitor* Monitor::getInstance() {
  static Monitor instance;
  return &instance;
}

std::list<IMonitorModule*>& Monitor::getModules()
{
  return this->_modules;
}
