# Numerical-Analysis

Installing WSL (Windows Subsystem Linux) and setting up X11 for FPToolkit

The first step is installing WSL. I used Windows 11, so process may be different for Windows 10. I used Ubuntu as my distribution
```
Step 1: Start CMD with administrative privileges.
Step 2: Execute "wsl --install" command.
Step 3: Run "wsl -l -o" to list other Linux releases.
Step 4: You can install your favorite Linux distribution, use "wsl --install -d
```
Once, you've installed WSL a linux terminal will likely have opened automatically. If not you can open powershell and enter the command
```
wsl
```
Which should open your linux terminal. If you pin powershell to your taskbar, when right clicking the icon, you can open up the linux terminal by clicking on the name of your distribution.

Next if you are looking to develop on your WSL using VScode, there is a WSL extension. Follow this guide https://code.visualstudio.com/docs/remote/wsl

Finally to get X11 set up. Open your linux terminal and enter these commands
```
sudo apt update
apt search Xlib.h
sudo apt install libx11-dev
```
And any FPToolkit programs should run like a charm. You may also have to install gcc, but that will be prompted to you if not already installed.
