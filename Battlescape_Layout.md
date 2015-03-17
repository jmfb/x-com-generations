# Battlescape #

The **battlescape** is the view of a battle that the user will interact with.  The term battlescape is a compound form of "battle landscape".

## Maps ##

The **map** behind the battlescape consists of a series of large map tiles called **sections**.  Different style maps will contain a different number of sections.  For example, a terror mission might consist of a 3 by 3 set of sections whereas a base mission might consist of a 4 by 4 set of sections.  Maps will generally be perfect squares.  Maps will always be rectangular and not irregular shapes.  Map sections are numbered from zero starting with the upper left square and going right then down.

## Map Sections ##

A section of map is a 10 by 10 series of map **squares** of a given **height**.  The height of a map is fixed for all sections and therefore all units.  Only one unit of height is required and missing levels can be assumed empty air (mission outside) or indestructible rock (mission underground).  A map section is useful for generating random map layouts since the 10 by 10 grid will have a coherent structure and should be designed such that it can be placed next to other sections of the same style as the map.  Sections are numbered from 0 to 99 starting with the upper left square and going right then down.

## Map Square ##

An individual map square is the smallest unit of a map.  When viewed isometrically it has the following properties:
  * 32 pixels across and 35 pixels talls.  The corners are always transparent to given the illusion of an isometric view.
  * Origin (0,0) is located in the upper left corner of the image (note that this is in the transparent region).
  * Image supports transparent pixels.
  * Square contains information about the ability for projectiles and units to pass through the square.  This includes the ability for the square to cause units to rise to the next level (both as ramps/hills/stairs and as elevators).
  * Square contains information about what it will become if it is destroyed and whether it is destructible and how much damage that requires.
  * An animation can be applied to a square.  This is used to simulate fire and smoke effects.
  * A square is lit based on a scale of 0-32 based on nearby light sources and time of day.
  * Squares are hidden by fog of war until initially seen unless the mission is a base defense mission (because you better know the layout of your own base).
  * No more than one unit (x-com agent, alien, civilian, tank) can occupy the same square.
  * If the square has a floor, then any number of items may occupy the floor of the square.
  * The visibility through a square for the purpose of line of sight is determined by the combined values of light, permeability, and added effects such as smoke/fire.