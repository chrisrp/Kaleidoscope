# Kaleidoscope-Colormap

![status][st:stable] [![Build Status][travis:image]][travis:status]

 [travis:image]: https://travis-ci.org/keyboardio/Kaleidoscope-Colormap.svg?branch=master
 [travis:status]: https://travis-ci.org/keyboardio/Kaleidoscope-Colormap

 [st:stable]: https://img.shields.io/badge/stable-✔-black.svg?style=flat&colorA=44cc11&colorB=494e52
 [st:broken]: https://img.shields.io/badge/broken-X-black.svg?style=flat&colorA=e05d44&colorB=494e52
 [st:experimental]: https://img.shields.io/badge/experimental----black.svg?style=flat&colorA=dfb317&colorB=494e52

The `Colormap` extension provides an easier way to set up a different - static -
color map per-layer. This means that we can set up a map of colors for each key,
on a per-layer basis, and whenever a layer becomes active, the color map for
that layer is applied. Colors are picked from a 16-color palette, provided by
the [LED-Palette-Theme][plugin:l-p-t] plugin. The color map is stored in
`EEPROM`, and can be easily changed via the [FocusSerial][plugin:focusserial]
plugin, which also provides palette editing capabilities.

 [plugin:focusserial]: https://github.com/keyboardio/Kaleidoscope-FocusSerial
 [plugin:l-p-t]: https://github.com/keyboardio/Kaleidoscope-LED-Palette-Theme

## Using the extension

To use the extension, include the header, tell it the number of layers you have,
register the `Focus` hooks, and it will do the rest.

```c++
#include <Kaleidoscope.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-Colormap.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-LED-Palette-Theme.h>

KALEIDOSCOPE_INIT_PLUGINS(EEPROMSettings,
                          LEDPaletteTheme,
                          ColormapEffect,
                          Focus);

void setup(void) {
  Kaleidoscope.setup();

  ColormapEffect.max_layers(1);
}
```

## Plugin methods

The extension provides an `ColormapEffect` singleton object, with a single method:

### `.max_layers(max)`

> Tells the extension to reserve space in EEPROM for up to `max` layers. Can
> only be called once, any subsequent call will be a no-op.

## Focus commands

### `colormap.map`

> Without arguments, prints the color map: palette indexes for all layers.
>
> With arguments, updates the color map with new indexes. One does not need to
> give the full map, the plugin will process as many arguments as available, and
> ignore anything past the last key on the last layer (as set by the
> `.max_layers()` method).

## Dependencies

* [Kaleidoscope-EEPROM-Settings](https://github.com/keyboardio/Kaleidoscope-EEPROM-Settings)
* [Kaleidoscope-FocusSerial](https://github.com/keyboardio/Kaleidoscope-FocusSerial)
* [Kaleidoscope-LED-Palette-Theme](https://github.com/keyboardio/Kaleidoscope-LED-Palette-Theme)

## Further reading

Starting from the [example][plugin:example] is the recommended way of getting
started with the plugin.

 [plugin:example]: https://github.com/keyboardio/Kaleidoscope-Colormap/blob/master/examples/Colormap/Colormap.ino
