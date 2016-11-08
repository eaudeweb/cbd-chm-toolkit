# Introduction

    This module is a wrapper around the Amcharts map module and allows you to integrate the library with Drupal to draw
    maps displaying a list of countries.

# Installation instructions

    - Install the libraries project https://www.drupal.org/project/libraries
    - Create a new directory sites/all/libraries/ammap
    - Download the latest JavaScript Maps library and copy the ammap folder
        (the result must be sites/all/libraries/ammap/ammap.js)
    - Install and enable this module the usual way

# Usage

Currently the only supported way of using the module is throughout the views module.

## Using with views module

    This module create a new view formatter in your views called "Ammap countries map". Create a new view and under the
    "Format" option select 'Ammap countries map' and proper settings.
        - Select the field that contains the country ISO 2-letter code
        - (Optional) Select the field that contains the description in the tooltip balloon
        - Save the view and visit the front-end page.