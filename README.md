# Metroid Prime Practice Mod Patcher
This project can produce a release & patch a metroid prime iso to be the practice mod

# NOTE: THESE INSTALL INSTRUCTIONS ARE OUT OF DATE
For now, you need to have python 3.7+ installed. This should be easy to install on linux or macOS. I'll have a Windows solution soon.
## How to install (Windows)
Youtube video: [https://www.youtube.com/watch?v=SpSQNYHwMjY](https://www.youtube.com/watch?v=SpSQNYHwMjY)
- Get a metroid prime .iso (i.e. using a hacked wii and cleanrip)
- Copy a metroid prime iso to 'prime.iso in this directory'
- Run `patch.bat`

## How to install (Non-windows)
Youtube video on macOS (Linux is similar): [https://www.youtube.com/watch?v=fyz6855ffjg](https://www.youtube.com/watch?v=fyz6855ffjg)
- Get a metroid prime .iso (i.e. using a hacked wii and cleanrip)
- Copy a metroid prime iso to 'prime.iso in this directory'
- Run `patch.sh`

## Usage
- Launch the iso in Dolphin
- Copy to your wii, and launch using Nintendont
  - If your Nintendont is really old, update Nintendont
  - Note this mod is not currently compatible with some settings, at the very least:
     - Cheats
     - Force progressive
     - Force Widescreen
  - There may be others, not a lot of testing has been done yet
  
## Controls
- `Z` on pause screen - Open menu
- `left analog`/`dpad` - Navigate menu
- `c-stick` - Scroll
- `a` - Select item in menu
- `b` - Go back a menu

## Known Issues
- Soft reset (`b + x + start`) crashes in Nintendont
- Non-menu text is garbled
- Rare crashes (so far, inconsistent)
- Warps to a couple rooms will put you out of bounds

# Menu docs are a bit out of date, and still under development

## Menus
- Inventory
  - Edit your item inventory
  - Artifacts do nothing in your inventory, and must be collected to have any effect, and so are not current editable
- Player
  - Save/load position
  - Edit position
  - Toggle Floaty Jump
  - Player state information (careful editing this!)
- Warp
  - Warp to any room
- Config
  - Adjust which HUD elements appear

# HUD docs are a bit out of date, and still under development

## HUD
- Input
  - Current IGT
  - Digital Inputs
  - Analog Main Stick
- Player Speed
  - Current speed (x, y, z, horizontal total)
  - Currrent rotational speed (x, y, z, total)
- Room timers
  - Current room IGT, in seconds
  - Current room IGT, in frames
  - Previous room IGT, in seconds
  - Previous room IGT, in frames
- FPS
  - Game-measured FPS

## Changelog

### 2.0.0 (beta)
- Complete rewrite! Not feature complete
- Press Z with pause menu open to access the menu

### 1.2.5
- Fix warps, so they warp you to the destination, instead of the credits

### 1.2.4
- Remove ZOOM from next to the IGT on save select
- Allow IGT and input to be configured separately

### 1.2.3
- Add position/precise position displays
- Change file select to show mm:ss instead of hh:mm

### 1.2.2
- Rewrote patcher to native (much smaller, faster)

### 1.2.1
- IS enabler (requires morph)
- Lightshow Fix (requires unmorphed)
- Update patcher
- May have fixed soft-reset crash

### 1.2.0
- Add trigger rendering

### 1.1.2
- Minor performance improvements
- Internal rework of how native is built

### 1.1.1
- Minor fixes

### 1.1.0
- Add Player menu
- Add FPS counter

### 1.0.0
 - Initial Release
