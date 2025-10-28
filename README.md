# SFML Simple GUI Library

## Overview
A lightweight, easy-to-use GUI library built on top of SFML, providing simple and intuitive UI components for SFML-based applications.

## Prerequisites

### Required Dependencies
- <b>SFML Library</b>
  - Recommended version: 2.5.1 or higher
  - Download from: https://www.sfml-dev.org/download.php

### Development Environment
- <b>MinGW Compiler</b>
- <b>SFML Development Files</b>
  - Include (.h) files
  - Static/Dynamic library (.lib/.a) files
- <b>Make</b> (MinGW32-make)

## Setup and Compilation

### Setting Up SFML
1. Download SFML for MinGW
2. Extract to a known directory (e.g., `C:\SFML`)
3. Set environment variables:
   - Add SFML bin directory to PATH
   - Set SFML_ROOT to SFML installation path

### Compilation Instructions
```bash
# Clone the repository
git clone https://github.com/[your-username]/sfml-simple-gui.git
cd sfml-simple-gui

# Compile using MinGW-make
mingw32-make
