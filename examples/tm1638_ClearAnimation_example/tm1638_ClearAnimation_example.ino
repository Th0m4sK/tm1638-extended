#include <Arduino.h>

/*
Library examples for TM1638.

Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


Th0m4sK (2020)
New Funtions to clear the Display
*/

#include <TM1638.h>

// define a module on data pin D2, clock pin D3 and strobe pin D1
TM1638 module(D2, D3, D1);
int progNumber = 0;
boolean Trigger = false;
void setup()
{
  // display a hexadecimal number and set the left 4 dots
  module.setDisplayToHexNumber(0x88888888, 0xF0);
}

void loop()
{
  byte keys = module.getButtons();
  if (keys==0){  Trigger=false;}
  module.setDisplayToHexNumber(0x88888888, 0xF0);
  if ((keys != 0) & (Trigger==false))
  {
    Trigger=true;
    switch (progNumber)
    {
    case 0:
      module.ClearDisplayVertical(Left2Right);
      progNumber++;
      break;
    case 1:
      module.ClearDisplayVertical(Right2Left, 200);
      progNumber++;
      break;
    case 2:
      module.ClearDisplayVertical(Middle2End,10);
      progNumber++;
      break;
    case 3:
      module.ClearDisplayVertical(End2Middle,5);
      progNumber = 0;
      break;

    default:
      break;
    }
  }
  
  
  
}